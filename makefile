all:ShiftRegisterLeds_Prog.c	##hna name elfile ely 3ais t3ml link m3 el .o eltany  
	 #gcc -E SSD_prog.c -o SSD_prog.i
	 #gcc -E Switch_prog.c -o Switch_prog.i
	 ##hna hi3ml file intermidate
	 avr-gcc -g -Os -mmcu=atmega32 -c ShiftRegisterLeds_Prog.c
	 ##hna hitl3 .o lltarget mcu=atmega32
	 ar cr ShiftRegisterLeds_Prog.a ShiftRegisterLeds_Prog.o ShiftRegisterLeds_Prog.o 
	 ##hi7ot elfile bat3k elasly ely hwa SSD_prog.o m3 DIO_prog_1.o
	 ## w y7thm fy file wa7d asmo SSD_All.a 3mlnaha 3shan tb2a 
	 ## static libarary , mmkn tzwd 3n atnin file.o
	 avr-gcc -g -mmcu=atmega32 -o ShiftRegisterLeds_Prog.elf ShiftRegisterLeds_Prog.a
	 ## hilt3 file asmo SSD_prog.elf m3 SSD_All.a
	 avr-objcopy -j .text -j .data -O ihex ShiftRegisterLeds_Prog.elf ShiftRegisterLeds_Prog.hex
	 ## dh hitl3 file bta3k  .hex
	 