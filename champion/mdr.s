.name "mdr"
.comment "mdr lol xd ptdr"

entry:
	sti	r1, %:mur, %1
	sti r1, %:next, %1
	sti r1, %:lol, %1
	sti r1, %:alive, %1
	sti r1, %:nono, %1
	sti r1, %:prep, %1
	fork %:alive

nono:
	live %42
	fork %:next
prep:
	live %42
	fork %:debut2
spawn:
	ld	%0, r2
mur:
	live %42
	st	r2, -16
	st	r2, -25
	st	r2, -34
	st	r2, -43
	st	r2, -52
	st	r2, -61
	st	r2, -70
	st	r2, -79
	st	r2, -88
	st	r2, -97
	st	r2, -106
	st	r2, -115
	st	r2, -124
	st	r2, -133
	st	r2, -142
	st	r2, -151
	st	r2, -160
	st	r2, -169
	st	r2, -178
	st	r2, -187
	st	r2, -196
	st	r2, -205
	st	r2, -214
	st	r2, -223
	st	r2, -232
	st	r2, -241
	st	r2, -250
	st	r2, -259
	st	r2, -268
	st	r2, -277
	st	r2, -286
	st	r2, -295
	st	r2, -304
	st	r2, -313
	st	r2, -322
	st	r2, -331
	st	r2, -340
	st	r2, -349
	st	r2, -358
	st	r2, -367
	st	r2, -376
	st	r2, -385
	st	r2, -394
	st	r2, -403
	st	r2, -412
	st	r2, -421
	st	r2, -430
	st	r2, -439
	st	r2, -448
	st	r2, -457
	st	r2, -456
	zjmp %:mur
next:
	live %42
	zjmp %3
	fork %:next
coeur:
	ld %0, r3
	zjmp %:spawn


alive:
	live %42
	ld %0, r3
	and %0, %0, r3
	fork %:alive
lol:
	live %42
	zjmp %:lol

debut2:
	sti r1, %:mur2, %1

next2:
	live %42
	zjmp %3
	fork %:next2

spawn2:
	ld	%0, r2
mur2:
	live %42
	st	r2, 258
	st	r2, 257
	st	r2, 256
	st	r2, 255
	st	r2, 254
	st	r2, 253
	st	r2, 252
	st	r2, 251
	st	r2, 250
	st	r2, 249
	st	r2, 248
	st	r2, 247 
	st	r2, 246
	st	r2, 245
	st	r2, 244
	st	r2, 243
	st	r2, 242
	st	r2, 241
	st	r2, 240
	st	r2, 239
	st	r2, 238
	st	r2, 237
	st	r2, 236
	st	r2, 235
	st	r2, 234
	st	r2, 233
	st	r2, 232
	st	r2, 231
	st	r2, 230
	st	r2, 229
	st	r2, 228
	st	r2, 227
	st	r2, 226
	st	r2, 225
	st	r2, 224
	st	r2, 223
	st	r2, 222
	st	r2, 221
	st	r2, 220
	st	r2, 219
	st	r2, 218
	st	r2, 217
	st	r2, 216
	st	r2, 215
	st	r2, 214
	st	r2, 213
	st	r2, 212
	st	r2, 211
	st	r2, 210
	st	r2, 209
	st	r2, 208
	zjmp %:mur2
