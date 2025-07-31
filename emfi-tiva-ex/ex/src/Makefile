# src/Makefile

PREFIX=arm-none-eabi
CC=$(PREFIX)-gcc
LD=$(PREFIX)-gcc
OBJCOPY=$(PREFIX)-objcopy

CFLAGS=-mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard \
       -ffunction-sections -fdata-sections -MD -std=c99 -Wall -O0 \
       -DPART_TM4C123GH6PM -Dgcc -I./inc -I../lib/uart -I../lib/driverlib

LDFLAGS=-T ../emfi.ld -Wl,-Map=../bin/emfi.map -Wl,--entry=ResetISR

LIBGCC=$(shell $(CC) $(CFLAGS) -print-libgcc-file-name)
LIBC=$(shell $(CC) $(CFLAGS) -print-file-name=libc.a)
LIBM=$(shell $(CC) $(CFLAGS) -print-file-name=libm.a)

SRC=emfi.c

OBJ=../bin/emfi.o
ELF=../bin/emfi.elf
BIN=../bin/emfi.bin

all: $(BIN)

../bin:
	mkdir -p ../bin

$(OBJ): $(SRC) | ../bin
	$(CC) $(CFLAGS) -c -o $@ $<

$(ELF): $(OBJ)
	$(LD) $(CFLAGS) $(LDFLAGS) -o $@ $^ \
		../lib/driverlib/bin/libdriver.a \
		../lib/uart/bin/uart.a \
		$(LIBM) $(LIBC) $(LIBGCC)

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

clean:
	rm -rf ../bin/emfi.*