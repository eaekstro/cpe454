;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Eric Ekstrom
; CPE454
; Last Update: 2019-04-25 12:30:08.808001
;
; Interrupt Service Routines
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

global ISR0
global ISR1
global ISR2
global ISR3
global ISR4
global ISR5
global ISR6
global ISR7
global ISR8
global ISR9
global ISR10
global ISR11
global ISR12
global ISR13
global ISR14
global ISR15
global ISR16
global ISR17
global ISR18
global ISR19
global ISR20
global ISR21
global ISR22
global ISR23
global ISR24
global ISR25
global ISR26
global ISR27
global ISR28
global ISR29
global ISR30
global ISR31
global ISR32
global ISR33
global ISR34
global ISR35
global ISR36
global ISR37
global ISR38
global ISR39
global ISR40
global ISR41
global ISR42
global ISR43
global ISR44
global ISR45
global ISR46
global ISR47
global ISR48
global ISR49
global ISR50
global ISR51
global ISR52
global ISR53
global ISR54
global ISR55
global ISR56
global ISR57
global ISR58
global ISR59
global ISR60
global ISR61
global ISR62
global ISR63
global ISR64
global ISR65
global ISR66
global ISR67
global ISR68
global ISR69
global ISR70
global ISR71
global ISR72
global ISR73
global ISR74
global ISR75
global ISR76
global ISR77
global ISR78
global ISR79
global ISR80
global ISR81
global ISR82
global ISR83
global ISR84
global ISR85
global ISR86
global ISR87
global ISR88
global ISR89
global ISR90
global ISR91
global ISR92
global ISR93
global ISR94
global ISR95
global ISR96
global ISR97
global ISR98
global ISR99
global ISR100
global ISR101
global ISR102
global ISR103
global ISR104
global ISR105
global ISR106
global ISR107
global ISR108
global ISR109
global ISR110
global ISR111
global ISR112
global ISR113
global ISR114
global ISR115
global ISR116
global ISR117
global ISR118
global ISR119
global ISR120
global ISR121
global ISR122
global ISR123
global ISR124
global ISR125
global ISR126
global ISR127
global ISR128
global ISR129
global ISR130
global ISR131
global ISR132
global ISR133
global ISR134
global ISR135
global ISR136
global ISR137
global ISR138
global ISR139
global ISR140
global ISR141
global ISR142
global ISR143
global ISR144
global ISR145
global ISR146
global ISR147
global ISR148
global ISR149
global ISR150
global ISR151
global ISR152
global ISR153
global ISR154
global ISR155
global ISR156
global ISR157
global ISR158
global ISR159
global ISR160
global ISR161
global ISR162
global ISR163
global ISR164
global ISR165
global ISR166
global ISR167
global ISR168
global ISR169
global ISR170
global ISR171
global ISR172
global ISR173
global ISR174
global ISR175
global ISR176
global ISR177
global ISR178
global ISR179
global ISR180
global ISR181
global ISR182
global ISR183
global ISR184
global ISR185
global ISR186
global ISR187
global ISR188
global ISR189
global ISR190
global ISR191
global ISR192
global ISR193
global ISR194
global ISR195
global ISR196
global ISR197
global ISR198
global ISR199
global ISR200
global ISR201
global ISR202
global ISR203
global ISR204
global ISR205
global ISR206
global ISR207
global ISR208
global ISR209
global ISR210
global ISR211
global ISR212
global ISR213
global ISR214
global ISR215
global ISR216
global ISR217
global ISR218
global ISR219
global ISR220
global ISR221
global ISR222
global ISR223
global ISR224
global ISR225
global ISR226
global ISR227
global ISR228
global ISR229
global ISR230
global ISR231
global ISR232
global ISR233
global ISR234
global ISR235
global ISR236
global ISR237
global ISR238
global ISR239
global ISR240
global ISR241
global ISR242
global ISR243
global ISR244
global ISR245
global ISR246
global ISR247
global ISR248
global ISR249
global ISR250
global ISR251
global ISR252
global ISR253
global ISR254
global ISR255
extern c_intr_handler

section .text
bits 64
isr_normal:
	call	c_intr_handler
	pop	rdi
	; TODO (stack cleanup)
	iretq

isr_error:
	push	rsi
	mov	rsi, [rsp + 16]
	call	c_intr_handler
	pop	rsi
	pop	rdi
	add	rsp, 8
	; TODO (stack cleanup)
	iretq


ISR0:
	push	rdi
	mov 	rdi, 0
	jmp	isr_normal

ISR1:
	push	rdi
	mov 	rdi, 1
	jmp	isr_normal

ISR2:
	push	rdi
	mov 	rdi, 2
	jmp	isr_normal

ISR3:
	push	rdi
	mov 	rdi, 3
	jmp	isr_normal

ISR4:
	push	rdi
	mov 	rdi, 4
	jmp	isr_normal

ISR5:
	push	rdi
	mov 	rdi, 5
	jmp	isr_normal

ISR6:
	push	rdi
	mov 	rdi, 6
	jmp	isr_normal

ISR7:
	push	rdi
	mov 	rdi, 7
	jmp	isr_normal

ISR8:
	push	rdi
	mov 	rdi, 8
	jmp	isr_error

ISR9:
	push	rdi
	mov 	rdi, 9
	jmp	isr_normal

ISR10:
	push	rdi
	mov 	rdi, 10
	jmp	isr_error

ISR11:
	push	rdi
	mov 	rdi, 11
	jmp	isr_error

ISR12:
	push	rdi
	mov 	rdi, 12
	jmp	isr_error

ISR13:
	push	rdi
	mov 	rdi, 13
	jmp	isr_error

ISR14:
	push	rdi
	mov 	rdi, 14
	jmp	isr_error

ISR15:
	push	rdi
	mov 	rdi, 15
	jmp	isr_normal

ISR16:
	push	rdi
	mov 	rdi, 16
	jmp	isr_normal

ISR17:
	push	rdi
	mov 	rdi, 17
	jmp	isr_error

ISR18:
	push	rdi
	mov 	rdi, 18
	jmp	isr_normal

ISR19:
	push	rdi
	mov 	rdi, 19
	jmp	isr_normal

ISR20:
	push	rdi
	mov 	rdi, 20
	jmp	isr_normal

ISR21:
	push	rdi
	mov 	rdi, 21
	jmp	isr_normal

ISR22:
	push	rdi
	mov 	rdi, 22
	jmp	isr_normal

ISR23:
	push	rdi
	mov 	rdi, 23
	jmp	isr_normal

ISR24:
	push	rdi
	mov 	rdi, 24
	jmp	isr_normal

ISR25:
	push	rdi
	mov 	rdi, 25
	jmp	isr_normal

ISR26:
	push	rdi
	mov 	rdi, 26
	jmp	isr_normal

ISR27:
	push	rdi
	mov 	rdi, 27
	jmp	isr_normal

ISR28:
	push	rdi
	mov 	rdi, 28
	jmp	isr_normal

ISR29:
	push	rdi
	mov 	rdi, 29
	jmp	isr_normal

ISR30:
	push	rdi
	mov 	rdi, 30
	jmp	isr_error

ISR31:
	push	rdi
	mov 	rdi, 31
	jmp	isr_normal

ISR32:
	push	rdi
	mov 	rdi, 32
	jmp	isr_normal

ISR33:
	push	rdi
	mov 	rdi, 33
	jmp	isr_normal

ISR34:
	push	rdi
	mov 	rdi, 34
	jmp	isr_normal

ISR35:
	push	rdi
	mov 	rdi, 35
	jmp	isr_normal

ISR36:
	push	rdi
	mov 	rdi, 36
	jmp	isr_normal

ISR37:
	push	rdi
	mov 	rdi, 37
	jmp	isr_normal

ISR38:
	push	rdi
	mov 	rdi, 38
	jmp	isr_normal

ISR39:
	push	rdi
	mov 	rdi, 39
	jmp	isr_normal

ISR40:
	push	rdi
	mov 	rdi, 40
	jmp	isr_normal

ISR41:
	push	rdi
	mov 	rdi, 41
	jmp	isr_normal

ISR42:
	push	rdi
	mov 	rdi, 42
	jmp	isr_normal

ISR43:
	push	rdi
	mov 	rdi, 43
	jmp	isr_normal

ISR44:
	push	rdi
	mov 	rdi, 44
	jmp	isr_normal

ISR45:
	push	rdi
	mov 	rdi, 45
	jmp	isr_normal

ISR46:
	push	rdi
	mov 	rdi, 46
	jmp	isr_normal

ISR47:
	push	rdi
	mov 	rdi, 47
	jmp	isr_normal

ISR48:
	push	rdi
	mov 	rdi, 48
	jmp	isr_normal

ISR49:
	push	rdi
	mov 	rdi, 49
	jmp	isr_normal

ISR50:
	push	rdi
	mov 	rdi, 50
	jmp	isr_normal

ISR51:
	push	rdi
	mov 	rdi, 51
	jmp	isr_normal

ISR52:
	push	rdi
	mov 	rdi, 52
	jmp	isr_normal

ISR53:
	push	rdi
	mov 	rdi, 53
	jmp	isr_normal

ISR54:
	push	rdi
	mov 	rdi, 54
	jmp	isr_normal

ISR55:
	push	rdi
	mov 	rdi, 55
	jmp	isr_normal

ISR56:
	push	rdi
	mov 	rdi, 56
	jmp	isr_normal

ISR57:
	push	rdi
	mov 	rdi, 57
	jmp	isr_normal

ISR58:
	push	rdi
	mov 	rdi, 58
	jmp	isr_normal

ISR59:
	push	rdi
	mov 	rdi, 59
	jmp	isr_normal

ISR60:
	push	rdi
	mov 	rdi, 60
	jmp	isr_normal

ISR61:
	push	rdi
	mov 	rdi, 61
	jmp	isr_normal

ISR62:
	push	rdi
	mov 	rdi, 62
	jmp	isr_normal

ISR63:
	push	rdi
	mov 	rdi, 63
	jmp	isr_normal

ISR64:
	push	rdi
	mov 	rdi, 64
	jmp	isr_normal

ISR65:
	push	rdi
	mov 	rdi, 65
	jmp	isr_normal

ISR66:
	push	rdi
	mov 	rdi, 66
	jmp	isr_normal

ISR67:
	push	rdi
	mov 	rdi, 67
	jmp	isr_normal

ISR68:
	push	rdi
	mov 	rdi, 68
	jmp	isr_normal

ISR69:
	push	rdi
	mov 	rdi, 69
	jmp	isr_normal

ISR70:
	push	rdi
	mov 	rdi, 70
	jmp	isr_normal

ISR71:
	push	rdi
	mov 	rdi, 71
	jmp	isr_normal

ISR72:
	push	rdi
	mov 	rdi, 72
	jmp	isr_normal

ISR73:
	push	rdi
	mov 	rdi, 73
	jmp	isr_normal

ISR74:
	push	rdi
	mov 	rdi, 74
	jmp	isr_normal

ISR75:
	push	rdi
	mov 	rdi, 75
	jmp	isr_normal

ISR76:
	push	rdi
	mov 	rdi, 76
	jmp	isr_normal

ISR77:
	push	rdi
	mov 	rdi, 77
	jmp	isr_normal

ISR78:
	push	rdi
	mov 	rdi, 78
	jmp	isr_normal

ISR79:
	push	rdi
	mov 	rdi, 79
	jmp	isr_normal

ISR80:
	push	rdi
	mov 	rdi, 80
	jmp	isr_normal

ISR81:
	push	rdi
	mov 	rdi, 81
	jmp	isr_normal

ISR82:
	push	rdi
	mov 	rdi, 82
	jmp	isr_normal

ISR83:
	push	rdi
	mov 	rdi, 83
	jmp	isr_normal

ISR84:
	push	rdi
	mov 	rdi, 84
	jmp	isr_normal

ISR85:
	push	rdi
	mov 	rdi, 85
	jmp	isr_normal

ISR86:
	push	rdi
	mov 	rdi, 86
	jmp	isr_normal

ISR87:
	push	rdi
	mov 	rdi, 87
	jmp	isr_normal

ISR88:
	push	rdi
	mov 	rdi, 88
	jmp	isr_normal

ISR89:
	push	rdi
	mov 	rdi, 89
	jmp	isr_normal

ISR90:
	push	rdi
	mov 	rdi, 90
	jmp	isr_normal

ISR91:
	push	rdi
	mov 	rdi, 91
	jmp	isr_normal

ISR92:
	push	rdi
	mov 	rdi, 92
	jmp	isr_normal

ISR93:
	push	rdi
	mov 	rdi, 93
	jmp	isr_normal

ISR94:
	push	rdi
	mov 	rdi, 94
	jmp	isr_normal

ISR95:
	push	rdi
	mov 	rdi, 95
	jmp	isr_normal

ISR96:
	push	rdi
	mov 	rdi, 96
	jmp	isr_normal

ISR97:
	push	rdi
	mov 	rdi, 97
	jmp	isr_normal

ISR98:
	push	rdi
	mov 	rdi, 98
	jmp	isr_normal

ISR99:
	push	rdi
	mov 	rdi, 99
	jmp	isr_normal

ISR100:
	push	rdi
	mov 	rdi, 100
	jmp	isr_normal

ISR101:
	push	rdi
	mov 	rdi, 101
	jmp	isr_normal

ISR102:
	push	rdi
	mov 	rdi, 102
	jmp	isr_normal

ISR103:
	push	rdi
	mov 	rdi, 103
	jmp	isr_normal

ISR104:
	push	rdi
	mov 	rdi, 104
	jmp	isr_normal

ISR105:
	push	rdi
	mov 	rdi, 105
	jmp	isr_normal

ISR106:
	push	rdi
	mov 	rdi, 106
	jmp	isr_normal

ISR107:
	push	rdi
	mov 	rdi, 107
	jmp	isr_normal

ISR108:
	push	rdi
	mov 	rdi, 108
	jmp	isr_normal

ISR109:
	push	rdi
	mov 	rdi, 109
	jmp	isr_normal

ISR110:
	push	rdi
	mov 	rdi, 110
	jmp	isr_normal

ISR111:
	push	rdi
	mov 	rdi, 111
	jmp	isr_normal

ISR112:
	push	rdi
	mov 	rdi, 112
	jmp	isr_normal

ISR113:
	push	rdi
	mov 	rdi, 113
	jmp	isr_normal

ISR114:
	push	rdi
	mov 	rdi, 114
	jmp	isr_normal

ISR115:
	push	rdi
	mov 	rdi, 115
	jmp	isr_normal

ISR116:
	push	rdi
	mov 	rdi, 116
	jmp	isr_normal

ISR117:
	push	rdi
	mov 	rdi, 117
	jmp	isr_normal

ISR118:
	push	rdi
	mov 	rdi, 118
	jmp	isr_normal

ISR119:
	push	rdi
	mov 	rdi, 119
	jmp	isr_normal

ISR120:
	push	rdi
	mov 	rdi, 120
	jmp	isr_normal

ISR121:
	push	rdi
	mov 	rdi, 121
	jmp	isr_normal

ISR122:
	push	rdi
	mov 	rdi, 122
	jmp	isr_normal

ISR123:
	push	rdi
	mov 	rdi, 123
	jmp	isr_normal

ISR124:
	push	rdi
	mov 	rdi, 124
	jmp	isr_normal

ISR125:
	push	rdi
	mov 	rdi, 125
	jmp	isr_normal

ISR126:
	push	rdi
	mov 	rdi, 126
	jmp	isr_normal

ISR127:
	push	rdi
	mov 	rdi, 127
	jmp	isr_normal

ISR128:
	push	rdi
	mov 	rdi, 128
	jmp	isr_normal

ISR129:
	push	rdi
	mov 	rdi, 129
	jmp	isr_normal

ISR130:
	push	rdi
	mov 	rdi, 130
	jmp	isr_normal

ISR131:
	push	rdi
	mov 	rdi, 131
	jmp	isr_normal

ISR132:
	push	rdi
	mov 	rdi, 132
	jmp	isr_normal

ISR133:
	push	rdi
	mov 	rdi, 133
	jmp	isr_normal

ISR134:
	push	rdi
	mov 	rdi, 134
	jmp	isr_normal

ISR135:
	push	rdi
	mov 	rdi, 135
	jmp	isr_normal

ISR136:
	push	rdi
	mov 	rdi, 136
	jmp	isr_normal

ISR137:
	push	rdi
	mov 	rdi, 137
	jmp	isr_normal

ISR138:
	push	rdi
	mov 	rdi, 138
	jmp	isr_normal

ISR139:
	push	rdi
	mov 	rdi, 139
	jmp	isr_normal

ISR140:
	push	rdi
	mov 	rdi, 140
	jmp	isr_normal

ISR141:
	push	rdi
	mov 	rdi, 141
	jmp	isr_normal

ISR142:
	push	rdi
	mov 	rdi, 142
	jmp	isr_normal

ISR143:
	push	rdi
	mov 	rdi, 143
	jmp	isr_normal

ISR144:
	push	rdi
	mov 	rdi, 144
	jmp	isr_normal

ISR145:
	push	rdi
	mov 	rdi, 145
	jmp	isr_normal

ISR146:
	push	rdi
	mov 	rdi, 146
	jmp	isr_normal

ISR147:
	push	rdi
	mov 	rdi, 147
	jmp	isr_normal

ISR148:
	push	rdi
	mov 	rdi, 148
	jmp	isr_normal

ISR149:
	push	rdi
	mov 	rdi, 149
	jmp	isr_normal

ISR150:
	push	rdi
	mov 	rdi, 150
	jmp	isr_normal

ISR151:
	push	rdi
	mov 	rdi, 151
	jmp	isr_normal

ISR152:
	push	rdi
	mov 	rdi, 152
	jmp	isr_normal

ISR153:
	push	rdi
	mov 	rdi, 153
	jmp	isr_normal

ISR154:
	push	rdi
	mov 	rdi, 154
	jmp	isr_normal

ISR155:
	push	rdi
	mov 	rdi, 155
	jmp	isr_normal

ISR156:
	push	rdi
	mov 	rdi, 156
	jmp	isr_normal

ISR157:
	push	rdi
	mov 	rdi, 157
	jmp	isr_normal

ISR158:
	push	rdi
	mov 	rdi, 158
	jmp	isr_normal

ISR159:
	push	rdi
	mov 	rdi, 159
	jmp	isr_normal

ISR160:
	push	rdi
	mov 	rdi, 160
	jmp	isr_normal

ISR161:
	push	rdi
	mov 	rdi, 161
	jmp	isr_normal

ISR162:
	push	rdi
	mov 	rdi, 162
	jmp	isr_normal

ISR163:
	push	rdi
	mov 	rdi, 163
	jmp	isr_normal

ISR164:
	push	rdi
	mov 	rdi, 164
	jmp	isr_normal

ISR165:
	push	rdi
	mov 	rdi, 165
	jmp	isr_normal

ISR166:
	push	rdi
	mov 	rdi, 166
	jmp	isr_normal

ISR167:
	push	rdi
	mov 	rdi, 167
	jmp	isr_normal

ISR168:
	push	rdi
	mov 	rdi, 168
	jmp	isr_normal

ISR169:
	push	rdi
	mov 	rdi, 169
	jmp	isr_normal

ISR170:
	push	rdi
	mov 	rdi, 170
	jmp	isr_normal

ISR171:
	push	rdi
	mov 	rdi, 171
	jmp	isr_normal

ISR172:
	push	rdi
	mov 	rdi, 172
	jmp	isr_normal

ISR173:
	push	rdi
	mov 	rdi, 173
	jmp	isr_normal

ISR174:
	push	rdi
	mov 	rdi, 174
	jmp	isr_normal

ISR175:
	push	rdi
	mov 	rdi, 175
	jmp	isr_normal

ISR176:
	push	rdi
	mov 	rdi, 176
	jmp	isr_normal

ISR177:
	push	rdi
	mov 	rdi, 177
	jmp	isr_normal

ISR178:
	push	rdi
	mov 	rdi, 178
	jmp	isr_normal

ISR179:
	push	rdi
	mov 	rdi, 179
	jmp	isr_normal

ISR180:
	push	rdi
	mov 	rdi, 180
	jmp	isr_normal

ISR181:
	push	rdi
	mov 	rdi, 181
	jmp	isr_normal

ISR182:
	push	rdi
	mov 	rdi, 182
	jmp	isr_normal

ISR183:
	push	rdi
	mov 	rdi, 183
	jmp	isr_normal

ISR184:
	push	rdi
	mov 	rdi, 184
	jmp	isr_normal

ISR185:
	push	rdi
	mov 	rdi, 185
	jmp	isr_normal

ISR186:
	push	rdi
	mov 	rdi, 186
	jmp	isr_normal

ISR187:
	push	rdi
	mov 	rdi, 187
	jmp	isr_normal

ISR188:
	push	rdi
	mov 	rdi, 188
	jmp	isr_normal

ISR189:
	push	rdi
	mov 	rdi, 189
	jmp	isr_normal

ISR190:
	push	rdi
	mov 	rdi, 190
	jmp	isr_normal

ISR191:
	push	rdi
	mov 	rdi, 191
	jmp	isr_normal

ISR192:
	push	rdi
	mov 	rdi, 192
	jmp	isr_normal

ISR193:
	push	rdi
	mov 	rdi, 193
	jmp	isr_normal

ISR194:
	push	rdi
	mov 	rdi, 194
	jmp	isr_normal

ISR195:
	push	rdi
	mov 	rdi, 195
	jmp	isr_normal

ISR196:
	push	rdi
	mov 	rdi, 196
	jmp	isr_normal

ISR197:
	push	rdi
	mov 	rdi, 197
	jmp	isr_normal

ISR198:
	push	rdi
	mov 	rdi, 198
	jmp	isr_normal

ISR199:
	push	rdi
	mov 	rdi, 199
	jmp	isr_normal

ISR200:
	push	rdi
	mov 	rdi, 200
	jmp	isr_normal

ISR201:
	push	rdi
	mov 	rdi, 201
	jmp	isr_normal

ISR202:
	push	rdi
	mov 	rdi, 202
	jmp	isr_normal

ISR203:
	push	rdi
	mov 	rdi, 203
	jmp	isr_normal

ISR204:
	push	rdi
	mov 	rdi, 204
	jmp	isr_normal

ISR205:
	push	rdi
	mov 	rdi, 205
	jmp	isr_normal

ISR206:
	push	rdi
	mov 	rdi, 206
	jmp	isr_normal

ISR207:
	push	rdi
	mov 	rdi, 207
	jmp	isr_normal

ISR208:
	push	rdi
	mov 	rdi, 208
	jmp	isr_normal

ISR209:
	push	rdi
	mov 	rdi, 209
	jmp	isr_normal

ISR210:
	push	rdi
	mov 	rdi, 210
	jmp	isr_normal

ISR211:
	push	rdi
	mov 	rdi, 211
	jmp	isr_normal

ISR212:
	push	rdi
	mov 	rdi, 212
	jmp	isr_normal

ISR213:
	push	rdi
	mov 	rdi, 213
	jmp	isr_normal

ISR214:
	push	rdi
	mov 	rdi, 214
	jmp	isr_normal

ISR215:
	push	rdi
	mov 	rdi, 215
	jmp	isr_normal

ISR216:
	push	rdi
	mov 	rdi, 216
	jmp	isr_normal

ISR217:
	push	rdi
	mov 	rdi, 217
	jmp	isr_normal

ISR218:
	push	rdi
	mov 	rdi, 218
	jmp	isr_normal

ISR219:
	push	rdi
	mov 	rdi, 219
	jmp	isr_normal

ISR220:
	push	rdi
	mov 	rdi, 220
	jmp	isr_normal

ISR221:
	push	rdi
	mov 	rdi, 221
	jmp	isr_normal

ISR222:
	push	rdi
	mov 	rdi, 222
	jmp	isr_normal

ISR223:
	push	rdi
	mov 	rdi, 223
	jmp	isr_normal

ISR224:
	push	rdi
	mov 	rdi, 224
	jmp	isr_normal

ISR225:
	push	rdi
	mov 	rdi, 225
	jmp	isr_normal

ISR226:
	push	rdi
	mov 	rdi, 226
	jmp	isr_normal

ISR227:
	push	rdi
	mov 	rdi, 227
	jmp	isr_normal

ISR228:
	push	rdi
	mov 	rdi, 228
	jmp	isr_normal

ISR229:
	push	rdi
	mov 	rdi, 229
	jmp	isr_normal

ISR230:
	push	rdi
	mov 	rdi, 230
	jmp	isr_normal

ISR231:
	push	rdi
	mov 	rdi, 231
	jmp	isr_normal

ISR232:
	push	rdi
	mov 	rdi, 232
	jmp	isr_normal

ISR233:
	push	rdi
	mov 	rdi, 233
	jmp	isr_normal

ISR234:
	push	rdi
	mov 	rdi, 234
	jmp	isr_normal

ISR235:
	push	rdi
	mov 	rdi, 235
	jmp	isr_normal

ISR236:
	push	rdi
	mov 	rdi, 236
	jmp	isr_normal

ISR237:
	push	rdi
	mov 	rdi, 237
	jmp	isr_normal

ISR238:
	push	rdi
	mov 	rdi, 238
	jmp	isr_normal

ISR239:
	push	rdi
	mov 	rdi, 239
	jmp	isr_normal

ISR240:
	push	rdi
	mov 	rdi, 240
	jmp	isr_normal

ISR241:
	push	rdi
	mov 	rdi, 241
	jmp	isr_normal

ISR242:
	push	rdi
	mov 	rdi, 242
	jmp	isr_normal

ISR243:
	push	rdi
	mov 	rdi, 243
	jmp	isr_normal

ISR244:
	push	rdi
	mov 	rdi, 244
	jmp	isr_normal

ISR245:
	push	rdi
	mov 	rdi, 245
	jmp	isr_normal

ISR246:
	push	rdi
	mov 	rdi, 246
	jmp	isr_normal

ISR247:
	push	rdi
	mov 	rdi, 247
	jmp	isr_normal

ISR248:
	push	rdi
	mov 	rdi, 248
	jmp	isr_normal

ISR249:
	push	rdi
	mov 	rdi, 249
	jmp	isr_normal

ISR250:
	push	rdi
	mov 	rdi, 250
	jmp	isr_normal

ISR251:
	push	rdi
	mov 	rdi, 251
	jmp	isr_normal

ISR252:
	push	rdi
	mov 	rdi, 252
	jmp	isr_normal

ISR253:
	push	rdi
	mov 	rdi, 253
	jmp	isr_normal

ISR254:
	push	rdi
	mov 	rdi, 254
	jmp	isr_normal

ISR255:
	push	rdi
	mov 	rdi, 255
	jmp	isr_normal

