################################################################################
# Manually-generated file. Do not edit!
# @copyright : Ahmed Aref
################################################################################
CC=arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s
INCS=-I.
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)
PROJECT_NAME=learnInDepth

all:$(PROJECT_NAME).bin
	@echo"--------- BUILD IS DONE SUCCESSFULLY----------"

startup.o:startup.s
	$(CC)as.exe $(CFLAGS) $(INCS) $< -o $@

%.o:%.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(PROJECT_NAME).elf:$(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linkerScript.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@

$(PROJECT_NAME).bin:$(PROJECT_NAME).elf
	$(CC)objcopy.exe -O binary $< $@

clean:
	rm *.elf *.bin
	@echo "Remove is done"
clean_all:
	rm *.o *.elf *.bin
	@echo "Remove all is done"
	