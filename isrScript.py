import datetime

errorList = [8, 10, 11, 12, 13, 14, 17, 30]

file = open("src/arch/x86_64/isr.asm", "w")

file.write(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n")
file.write("; Eric Ekstrom\n")
file.write("; CPE454\n")
file.write("; Last Update: " + str(datetime.datetime.now()) + "\n")
file.write(";\n")
file.write("; Interrupt Service Routines\n")
file.write(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n\n")

for i in range(256):
   file.write("global ISR{}\n".format(i))
file.write("extern c_intr_handler\n\n")

file.write("section .text\n");
file.write("bits 64\n");

file.write("isr_normal:\n")
file.write("\tcall\tc_intr_handler\n")
file.write("\tpop\trdi\n")
file.write("\t; TODO (stack cleanup)\n")
file.write("\tiretq\n\n")
file.write("isr_error:\n")
file.write("\tpush\trsi\n")
file.write("\tmov\trsi, [rsp + 16]\n")
file.write("\tcall\tc_intr_handler\n")
file.write("\tpop\trsi\n")
file.write("\tpop\trdi\n")
file.write("\tadd\trsp, 8\n")
file.write("\t; TODO (stack cleanup)\n")
file.write("\tiretq\n\n\n")

for i in range(256):
   file.write("ISR{}:\n".format(i))
   file.write("\tpush\trdi\n")
   file.write("\tmov \trdi, {}\n".format(i))
   if (i in errorList):
      file.write("\tjmp\tisr_error\n\n")
   else:
      file.write("\tjmp\tisr_normal\n\n")

file = open("src/arch/x86_64/isr.h", "w")

file.write("/***************************************************************\n")
file.write(" * Eric Ekstrom\n")
file.write(" * CPE454\n")
file.write(" * Last Update: " + str(datetime.datetime.now()) + "\n")
file.write(" *\n")
file.write(" * ISR C Interface\n")
file.write(" ***************************************************************/\n\n")

file.write("#include \"interrupt.h\"\n\n");

for i in range(256):
   file.write("extern void ISR{}();\n".format(i))

file.write("\nvoid (*isr_table[256]) = {\n")
for i in range(256):
   if (i < 255):
      file.write("\tISR{},\n".format(i))
   else:
      file.write("\tISR{}\n".format(i))

file.write("};")
