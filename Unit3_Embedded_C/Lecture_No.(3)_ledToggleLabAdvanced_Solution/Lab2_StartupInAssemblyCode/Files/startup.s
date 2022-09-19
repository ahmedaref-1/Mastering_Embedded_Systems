/*
LearnInDepth, UnitNo.(3), Embedded C, LessonNo.(3)
LabNo.(2), Toggle LED Lab, STM32F103Cx
@Copyright: Ahmed Aref Omaira
*/

.section .vectors
.word 0x20001000 	 /* Stack Top Address */
.word _resetHandler  /* 1.Reset Handler */
.word _VectorHandler /* 2.NMI */ 
.word _VectorHandler /* 3.Hard Fault */ 
.word _VectorHandler /* 4.MM Fault */ 
.word _VectorHandler /* 5.Bus Fault */ 
.word _VectorHandler /* 6.Usage Fault */ 
.word _VectorHandler /* 7.Reserved */ 
.word _VectorHandler /* 8.Reserved */  
.word _VectorHandler /* 9.Reserved */ 
.word _VectorHandler /* 10.Reserved */  
.word _VectorHandler /* 11.SV Call */ 
.word _VectorHandler /* 12.Debug Monitor */ 
.word _VectorHandler /* 13.Reserved */ 
.word _VectorHandler /* 14.PendSV */ 
.word _VectorHandler /* 15.SysTick */ 
.word _VectorHandler /* 16.WWDG */ 
.word _VectorHandler /* 17.PVD */ 
.word _VectorHandler /* 18.TAMPER */ 
.word _VectorHandler /* 19.RTC */ 
.word _VectorHandler /* 20.... */ 
      /* On to IRQ67 */

.section .text
_resetHandler:
	bl main
	b .

.thumb_func

_VectorHandler:
	b _resetHandler      
