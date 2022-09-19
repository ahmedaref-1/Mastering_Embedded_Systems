# @copyright : Ahmed Aref
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -mthumb -gdwarf-2
INCS=-I.
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)
PROJECT_NAME=ledToggleLabAdvanced

all: $(PROJECT_NAME).bin
	@echo "------- BUILD IS DONE SUCCESSFULLY --------"
$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(CC)objcopy.exe -O binary $< $@
$(PROJECT_NAME).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linkerScript.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=mapFile.map
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@
%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@
remove:
	rm -rf *.elf *.bin
	@echo "------ Removing .elf and .bin Files --------"
remove_all:
	rm -rf *.o *.elf *.bin
	@echo "------ Removing .o, .elf and .bin Files --------"
	