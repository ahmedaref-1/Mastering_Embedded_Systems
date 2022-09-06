
application.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	e92d4800 	push	{fp, lr}
   4:	e28db004 	add	fp, sp, #4
   8:	e59f0004 	ldr	r0, [pc, #4]	; 14 <main+0x14>
   c:	ebfffffe 	bl	0 <uartSendString>
  10:	e8bd8800 	pop	{fp, pc}
  14:	00000000 	andeq	r0, r0, r0

Disassembly of section .data:

00000000 <stringBuffer>:
   0:	7261654c 	rsbvc	r6, r1, #76, 10	; 0x13000000
   4:	6e49206e 	cdpvs	0, 4, cr2, cr9, cr14, {3}
   8:	70654420 	rsbvc	r4, r5, r0, lsr #8
   c:	3c206874 	stccc	8, cr6, [r0], #-464	; 0xfffffe30
  10:	6d684120 	stfvse	f4, [r8, #-128]!	; 0xffffff80
  14:	41206465 	teqmi	r0, r5, ror #8
  18:	20666572 	rsbcs	r6, r6, r2, ror r5
  1c:	0000003e 	andeq	r0, r0, lr, lsr r0
	...

Disassembly of section .rodata:

00000000 <stringBuffer3>:
   0:	43206f54 	teqmi	r0, #84, 30	; 0x150
   4:	74616572 	strbtvc	r6, [r1], #-1394	; 0x572
   8:	6f722065 	svcvs	0x00722065
   c:	61746164 	cmnvs	r4, r4, ror #2
  10:	63655320 	cmnvs	r5, #32, 6	; 0x80000000
  14:	6e6f6974 	mcrvs	9, 3, r6, cr15, cr4, {3}
	...

Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	; 0x3700
   4:	4728203a 			; <UNDEFINED> instruction: 0x4728203a
   8:	2029554e 	eorcs	r5, r9, lr, asr #10
   c:	2e372e34 	mrccs	14, 1, r2, cr7, cr4, {1}
  10:	Address 0x00000010 is out of bounds.


Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00003141 	andeq	r3, r0, r1, asr #2
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000027 	andeq	r0, r0, r7, lsr #32
  10:	4d524105 	ldfmie	f4, [r2, #-20]	; 0xffffffec
  14:	45363239 	ldrmi	r3, [r6, #-569]!	; 0x239
  18:	00532d4a 	subseq	r2, r3, sl, asr #26
  1c:	01080506 	tsteq	r8, r6, lsl #10
  20:	04120109 	ldreq	r0, [r2], #-265	; 0x109
  24:	01150114 	tsteq	r5, r4, lsl r1
  28:	01180317 	tsteq	r8, r7, lsl r3
  2c:	011a0119 	tsteq	sl, r9, lsl r1
  30:	Address 0x00000030 is out of bounds.

