extern ISR_Handler

%include "macros.inc"


; cpu pushes to the stack: ss, rsp, flags, cs, rip

%macro ISR_NOERRORCODE 1

global X64_ISR%1:
X64_ISR%1:
    push 0              ; push dummy error code for compatibility with the handler
    push %1             ; push interrupt number
    jmp isr_common

%endmacro

%macro ISR_ERRORCODE 1
global X64_ISR%1:
X64_ISR%1:
                        ; cpu pushes an error code to the stack automatically
    push %1             ; push interrupt number
    jmp isr_common

%endmacro

global isr_common
isr_common:
    cld     ;DF may be set by cpu, clearing it is required when calling c function using sysvabi
    pusha64

    mov rdi, rsp    ; push stack to the handler
    call ISR_Handler
    mov rsp, rax    ;update stack from the rax returned by function
    popa64
    add rsp, 8 ; pop error code from the stack
    iretq       ;interrupt return


; !!! THIS FILE IS AUTOGENERATED !!!
ISR_NOERRORCODE 0
ISR_NOERRORCODE 1
ISR_NOERRORCODE 2
ISR_NOERRORCODE 3
ISR_NOERRORCODE 4
ISR_NOERRORCODE 5
ISR_NOERRORCODE 6
ISR_NOERRORCODE 7
ISR_ERRORCODE 8
ISR_NOERRORCODE 9
ISR_ERRORCODE 10
ISR_ERRORCODE 11
ISR_ERRORCODE 12
ISR_ERRORCODE 13
ISR_ERRORCODE 14
ISR_NOERRORCODE 15
ISR_NOERRORCODE 16
ISR_ERRORCODE 17
ISR_NOERRORCODE 18
ISR_NOERRORCODE 19
ISR_NOERRORCODE 20
ISR_ERRORCODE 21
ISR_NOERRORCODE 22
ISR_NOERRORCODE 23
ISR_NOERRORCODE 24
ISR_NOERRORCODE 25
ISR_NOERRORCODE 26
ISR_NOERRORCODE 27
ISR_NOERRORCODE 28
ISR_NOERRORCODE 29
ISR_NOERRORCODE 30
ISR_NOERRORCODE 31
ISR_NOERRORCODE 32
ISR_NOERRORCODE 33
ISR_NOERRORCODE 34
ISR_NOERRORCODE 35
ISR_NOERRORCODE 36
ISR_NOERRORCODE 37
ISR_NOERRORCODE 38
ISR_NOERRORCODE 39
ISR_NOERRORCODE 40
ISR_NOERRORCODE 41
ISR_NOERRORCODE 42
ISR_NOERRORCODE 43
ISR_NOERRORCODE 44
ISR_NOERRORCODE 45
ISR_NOERRORCODE 46
ISR_NOERRORCODE 47
ISR_NOERRORCODE 48
ISR_NOERRORCODE 49
ISR_NOERRORCODE 50
ISR_NOERRORCODE 51
ISR_NOERRORCODE 52
ISR_NOERRORCODE 53
ISR_NOERRORCODE 54
ISR_NOERRORCODE 55
ISR_NOERRORCODE 56
ISR_NOERRORCODE 57
ISR_NOERRORCODE 58
ISR_NOERRORCODE 59
ISR_NOERRORCODE 60
ISR_NOERRORCODE 61
ISR_NOERRORCODE 62
ISR_NOERRORCODE 63
ISR_NOERRORCODE 64
ISR_NOERRORCODE 65
ISR_NOERRORCODE 66
ISR_NOERRORCODE 67
ISR_NOERRORCODE 68
ISR_NOERRORCODE 69
ISR_NOERRORCODE 70
ISR_NOERRORCODE 71
ISR_NOERRORCODE 72
ISR_NOERRORCODE 73
ISR_NOERRORCODE 74
ISR_NOERRORCODE 75
ISR_NOERRORCODE 76
ISR_NOERRORCODE 77
ISR_NOERRORCODE 78
ISR_NOERRORCODE 79
ISR_NOERRORCODE 80
ISR_NOERRORCODE 81
ISR_NOERRORCODE 82
ISR_NOERRORCODE 83
ISR_NOERRORCODE 84
ISR_NOERRORCODE 85
ISR_NOERRORCODE 86
ISR_NOERRORCODE 87
ISR_NOERRORCODE 88
ISR_NOERRORCODE 89
ISR_NOERRORCODE 90
ISR_NOERRORCODE 91
ISR_NOERRORCODE 92
ISR_NOERRORCODE 93
ISR_NOERRORCODE 94
ISR_NOERRORCODE 95
ISR_NOERRORCODE 96
ISR_NOERRORCODE 97
ISR_NOERRORCODE 98
ISR_NOERRORCODE 99
ISR_NOERRORCODE 100
ISR_NOERRORCODE 101
ISR_NOERRORCODE 102
ISR_NOERRORCODE 103
ISR_NOERRORCODE 104
ISR_NOERRORCODE 105
ISR_NOERRORCODE 106
ISR_NOERRORCODE 107
ISR_NOERRORCODE 108
ISR_NOERRORCODE 109
ISR_NOERRORCODE 110
ISR_NOERRORCODE 111
ISR_NOERRORCODE 112
ISR_NOERRORCODE 113
ISR_NOERRORCODE 114
ISR_NOERRORCODE 115
ISR_NOERRORCODE 116
ISR_NOERRORCODE 117
ISR_NOERRORCODE 118
ISR_NOERRORCODE 119
ISR_NOERRORCODE 120
ISR_NOERRORCODE 121
ISR_NOERRORCODE 122
ISR_NOERRORCODE 123
ISR_NOERRORCODE 124
ISR_NOERRORCODE 125
ISR_NOERRORCODE 126
ISR_NOERRORCODE 127
ISR_NOERRORCODE 128
ISR_NOERRORCODE 129
ISR_NOERRORCODE 130
ISR_NOERRORCODE 131
ISR_NOERRORCODE 132
ISR_NOERRORCODE 133
ISR_NOERRORCODE 134
ISR_NOERRORCODE 135
ISR_NOERRORCODE 136
ISR_NOERRORCODE 137
ISR_NOERRORCODE 138
ISR_NOERRORCODE 139
ISR_NOERRORCODE 140
ISR_NOERRORCODE 141
ISR_NOERRORCODE 142
ISR_NOERRORCODE 143
ISR_NOERRORCODE 144
ISR_NOERRORCODE 145
ISR_NOERRORCODE 146
ISR_NOERRORCODE 147
ISR_NOERRORCODE 148
ISR_NOERRORCODE 149
ISR_NOERRORCODE 150
ISR_NOERRORCODE 151
ISR_NOERRORCODE 152
ISR_NOERRORCODE 153
ISR_NOERRORCODE 154
ISR_NOERRORCODE 155
ISR_NOERRORCODE 156
ISR_NOERRORCODE 157
ISR_NOERRORCODE 158
ISR_NOERRORCODE 159
ISR_NOERRORCODE 160
ISR_NOERRORCODE 161
ISR_NOERRORCODE 162
ISR_NOERRORCODE 163
ISR_NOERRORCODE 164
ISR_NOERRORCODE 165
ISR_NOERRORCODE 166
ISR_NOERRORCODE 167
ISR_NOERRORCODE 168
ISR_NOERRORCODE 169
ISR_NOERRORCODE 170
ISR_NOERRORCODE 171
ISR_NOERRORCODE 172
ISR_NOERRORCODE 173
ISR_NOERRORCODE 174
ISR_NOERRORCODE 175
ISR_NOERRORCODE 176
ISR_NOERRORCODE 177
ISR_NOERRORCODE 178
ISR_NOERRORCODE 179
ISR_NOERRORCODE 180
ISR_NOERRORCODE 181
ISR_NOERRORCODE 182
ISR_NOERRORCODE 183
ISR_NOERRORCODE 184
ISR_NOERRORCODE 185
ISR_NOERRORCODE 186
ISR_NOERRORCODE 187
ISR_NOERRORCODE 188
ISR_NOERRORCODE 189
ISR_NOERRORCODE 190
ISR_NOERRORCODE 191
ISR_NOERRORCODE 192
ISR_NOERRORCODE 193
ISR_NOERRORCODE 194
ISR_NOERRORCODE 195
ISR_NOERRORCODE 196
ISR_NOERRORCODE 197
ISR_NOERRORCODE 198
ISR_NOERRORCODE 199
ISR_NOERRORCODE 200
ISR_NOERRORCODE 201
ISR_NOERRORCODE 202
ISR_NOERRORCODE 203
ISR_NOERRORCODE 204
ISR_NOERRORCODE 205
ISR_NOERRORCODE 206
ISR_NOERRORCODE 207
ISR_NOERRORCODE 208
ISR_NOERRORCODE 209
ISR_NOERRORCODE 210
ISR_NOERRORCODE 211
ISR_NOERRORCODE 212
ISR_NOERRORCODE 213
ISR_NOERRORCODE 214
ISR_NOERRORCODE 215
ISR_NOERRORCODE 216
ISR_NOERRORCODE 217
ISR_NOERRORCODE 218
ISR_NOERRORCODE 219
ISR_NOERRORCODE 220
ISR_NOERRORCODE 221
ISR_NOERRORCODE 222
ISR_NOERRORCODE 223
ISR_NOERRORCODE 224
ISR_NOERRORCODE 225
ISR_NOERRORCODE 226
ISR_NOERRORCODE 227
ISR_NOERRORCODE 228
ISR_NOERRORCODE 229
ISR_NOERRORCODE 230
ISR_NOERRORCODE 231
ISR_NOERRORCODE 232
ISR_NOERRORCODE 233
ISR_NOERRORCODE 234
ISR_NOERRORCODE 235
ISR_NOERRORCODE 236
ISR_NOERRORCODE 237
ISR_NOERRORCODE 238
ISR_NOERRORCODE 239
ISR_NOERRORCODE 240
ISR_NOERRORCODE 241
ISR_NOERRORCODE 242
ISR_NOERRORCODE 243
ISR_NOERRORCODE 244
ISR_NOERRORCODE 245
ISR_NOERRORCODE 246
ISR_NOERRORCODE 247
ISR_NOERRORCODE 248
ISR_NOERRORCODE 249
ISR_NOERRORCODE 250
ISR_NOERRORCODE 251
ISR_NOERRORCODE 252
ISR_NOERRORCODE 253
ISR_NOERRORCODE 254
ISR_NOERRORCODE 255

;autogenerated
global X64_ISRHANDLERS
X64_ISRHANDLERS:
    dq X64_ISR0
    dq X64_ISR1
    dq X64_ISR2
    dq X64_ISR3
    dq X64_ISR4
    dq X64_ISR5
    dq X64_ISR6
    dq X64_ISR7
    dq X64_ISR8
    dq X64_ISR9
    dq X64_ISR10
    dq X64_ISR11
    dq X64_ISR12
    dq X64_ISR13
    dq X64_ISR14
    dq X64_ISR15
    dq X64_ISR16
    dq X64_ISR17
    dq X64_ISR18
    dq X64_ISR19
    dq X64_ISR20
    dq X64_ISR21
    dq X64_ISR22
    dq X64_ISR23
    dq X64_ISR24
    dq X64_ISR25
    dq X64_ISR26
    dq X64_ISR27
    dq X64_ISR28
    dq X64_ISR29
    dq X64_ISR30
    dq X64_ISR31
    dq X64_ISR32
    dq X64_ISR33
    dq X64_ISR34
    dq X64_ISR35
    dq X64_ISR36
    dq X64_ISR37
    dq X64_ISR38
    dq X64_ISR39
    dq X64_ISR40
    dq X64_ISR41
    dq X64_ISR42
    dq X64_ISR43
    dq X64_ISR44
    dq X64_ISR45
    dq X64_ISR46
    dq X64_ISR47
    dq X64_ISR48
    dq X64_ISR49
    dq X64_ISR50
    dq X64_ISR51
    dq X64_ISR52
    dq X64_ISR53
    dq X64_ISR54
    dq X64_ISR55
    dq X64_ISR56
    dq X64_ISR57
    dq X64_ISR58
    dq X64_ISR59
    dq X64_ISR60
    dq X64_ISR61
    dq X64_ISR62
    dq X64_ISR63
    dq X64_ISR64
    dq X64_ISR65
    dq X64_ISR66
    dq X64_ISR67
    dq X64_ISR68
    dq X64_ISR69
    dq X64_ISR70
    dq X64_ISR71
    dq X64_ISR72
    dq X64_ISR73
    dq X64_ISR74
    dq X64_ISR75
    dq X64_ISR76
    dq X64_ISR77
    dq X64_ISR78
    dq X64_ISR79
    dq X64_ISR80
    dq X64_ISR81
    dq X64_ISR82
    dq X64_ISR83
    dq X64_ISR84
    dq X64_ISR85
    dq X64_ISR86
    dq X64_ISR87
    dq X64_ISR88
    dq X64_ISR89
    dq X64_ISR90
    dq X64_ISR91
    dq X64_ISR92
    dq X64_ISR93
    dq X64_ISR94
    dq X64_ISR95
    dq X64_ISR96
    dq X64_ISR97
    dq X64_ISR98
    dq X64_ISR99
    dq X64_ISR100
    dq X64_ISR101
    dq X64_ISR102
    dq X64_ISR103
    dq X64_ISR104
    dq X64_ISR105
    dq X64_ISR106
    dq X64_ISR107
    dq X64_ISR108
    dq X64_ISR109
    dq X64_ISR110
    dq X64_ISR111
    dq X64_ISR112
    dq X64_ISR113
    dq X64_ISR114
    dq X64_ISR115
    dq X64_ISR116
    dq X64_ISR117
    dq X64_ISR118
    dq X64_ISR119
    dq X64_ISR120
    dq X64_ISR121
    dq X64_ISR122
    dq X64_ISR123
    dq X64_ISR124
    dq X64_ISR125
    dq X64_ISR126
    dq X64_ISR127
    dq X64_ISR128
    dq X64_ISR129
    dq X64_ISR130
    dq X64_ISR131
    dq X64_ISR132
    dq X64_ISR133
    dq X64_ISR134
    dq X64_ISR135
    dq X64_ISR136
    dq X64_ISR137
    dq X64_ISR138
    dq X64_ISR139
    dq X64_ISR140
    dq X64_ISR141
    dq X64_ISR142
    dq X64_ISR143
    dq X64_ISR144
    dq X64_ISR145
    dq X64_ISR146
    dq X64_ISR147
    dq X64_ISR148
    dq X64_ISR149
    dq X64_ISR150
    dq X64_ISR151
    dq X64_ISR152
    dq X64_ISR153
    dq X64_ISR154
    dq X64_ISR155
    dq X64_ISR156
    dq X64_ISR157
    dq X64_ISR158
    dq X64_ISR159
    dq X64_ISR160
    dq X64_ISR161
    dq X64_ISR162
    dq X64_ISR163
    dq X64_ISR164
    dq X64_ISR165
    dq X64_ISR166
    dq X64_ISR167
    dq X64_ISR168
    dq X64_ISR169
    dq X64_ISR170
    dq X64_ISR171
    dq X64_ISR172
    dq X64_ISR173
    dq X64_ISR174
    dq X64_ISR175
    dq X64_ISR176
    dq X64_ISR177
    dq X64_ISR178
    dq X64_ISR179
    dq X64_ISR180
    dq X64_ISR181
    dq X64_ISR182
    dq X64_ISR183
    dq X64_ISR184
    dq X64_ISR185
    dq X64_ISR186
    dq X64_ISR187
    dq X64_ISR188
    dq X64_ISR189
    dq X64_ISR190
    dq X64_ISR191
    dq X64_ISR192
    dq X64_ISR193
    dq X64_ISR194
    dq X64_ISR195
    dq X64_ISR196
    dq X64_ISR197
    dq X64_ISR198
    dq X64_ISR199
    dq X64_ISR200
    dq X64_ISR201
    dq X64_ISR202
    dq X64_ISR203
    dq X64_ISR204
    dq X64_ISR205
    dq X64_ISR206
    dq X64_ISR207
    dq X64_ISR208
    dq X64_ISR209
    dq X64_ISR210
    dq X64_ISR211
    dq X64_ISR212
    dq X64_ISR213
    dq X64_ISR214
    dq X64_ISR215
    dq X64_ISR216
    dq X64_ISR217
    dq X64_ISR218
    dq X64_ISR219
    dq X64_ISR220
    dq X64_ISR221
    dq X64_ISR222
    dq X64_ISR223
    dq X64_ISR224
    dq X64_ISR225
    dq X64_ISR226
    dq X64_ISR227
    dq X64_ISR228
    dq X64_ISR229
    dq X64_ISR230
    dq X64_ISR231
    dq X64_ISR232
    dq X64_ISR233
    dq X64_ISR234
    dq X64_ISR235
    dq X64_ISR236
    dq X64_ISR237
    dq X64_ISR238
    dq X64_ISR239
    dq X64_ISR240
    dq X64_ISR241
    dq X64_ISR242
    dq X64_ISR243
    dq X64_ISR244
    dq X64_ISR245
    dq X64_ISR246
    dq X64_ISR247
    dq X64_ISR248
    dq X64_ISR249
    dq X64_ISR250
    dq X64_ISR251
    dq X64_ISR252
    dq X64_ISR253
    dq X64_ISR254
    dq X64_ISR255
