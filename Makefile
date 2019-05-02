arch ?= x86_64
kernel := build/kernel-$(arch).bin
img := build/os-$(arch).img

linker_script := src/arch/$(arch)/linker.ld
grub_cfg := src/arch/$(arch)/grub.cfg
assembly_source_files := $(wildcard src/arch/$(arch)/*.asm)
assembly_object_files := $(patsubst src/arch/$(arch)/%.asm, \
	build/arch/$(arch)/%.o, $(assembly_source_files))
c_source_files := $(wildcard src/arch/$(arch)/*.c)
c_object_files := $(patsubst src/arch/$(arch)/%.c, \
	build/arch/$(arch)/%.o, $(c_source_files))

.PHONY: all clean run img

all: $(kernel)

clean:
	@rm -r build

run: $(img)
	@qemu-system-x86_64 -s -drive format=raw,file=$(img) -serial stdio

img: $(img)

$(img): $(kernel) $(grub_cfg)
	@mkdir -p build/imgfiles/boot/grub
	@cp $(kernel) build/imgfiles/boot/kernel.bin
	@cp $(grub_cfg) build/imgfiles/boot/grub
#	@grub-mkrescue -o $(img) build/imgfiles 2> /dev/null
	@dd if=/dev/zero of=$(img) bs=512 count=32768
	@parted $(img) mklabel msdos
	@parted $(img) mkpart primary fat32 2048s 30720s
	@parted $(img) set 1 boot on
	@losetup /dev/loop0 $(img)
	@losetup /dev/loop1 $(img) -o 1048576
	@mkdosfs -F32 -f 2 /dev/loop1
	@mount /dev/loop1 /mnt/fatgrub
	@grub-install --root-directory=mnt/fatgrub --no-floppy --modules="normal part_msdos ext2 multiboot" /dev/loop0
	@cp -r build/imgfiles/* /mnt/fatgrub
	@umount /mnt/fatgrub
	@losetup -d /dev/loop0
	@losetup -d /dev/loop1
	@rm -r build/imgfiles

$(kernel): $(c_object_files) $(assembly_object_files) $(linker_script)
	ld -n -T $(linker_script) -o $(kernel) $(c_object_files) $(assembly_object_files)

build/arch/$(arch)/%.o: src/arch/$(arch)/%.c
	@mkdir -p $(shell dirname $@)
	$(HOME)/opt/cross/bin/x86_64-elf-gcc -Wall -g -c $< -o $@

build/arch/$(arch)/%.o: src/arch/$(arch)/%.asm
	#@mkdir -p $(shell dirname $@)
	@nasm -f elf64 $< -o $@
