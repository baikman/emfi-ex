EMFI_ROOT=.
LIB=../lib
INC=./inc
LDNAME=emfi.ld

DRIVERLIB_ARCHIVE=${LIB}/driverlib/bin/libdriver.a
UART_ARCHIVE=${LIB}/uart/bin/uart.a

include ${EMFI_ROOT}/../makedefs
CFLAGS += -I${LIB}
CFLAGS += -I${INC}

all: emfi

emfi : driverlib uart

driverlib:
	make -C ${LIB}/driverlib

uart:
	make -C ${LIB}/uart

TOOLCHAIN = /usr/bin/arm-none-eabi-

emfi: src/startup_gcc.o src/emfi.o

emfi:
	mkdir -p bin
	${LD} -T ${LDNAME} --entry ResetISR ${LDFLAGS} -o bin/emfi.elf \
		$(filter %.o %.a, ${^}) \
		${LIB}/driverlib/bin/aes.o ${LIB}/driverlib/bin/can.o ${LIB}/driverlib/bin/comp.o ${LIB}/driverlib/bin/cpu.o ${LIB}/driverlib/bin/crc.o ${LIB}/driverlib/bin/des.o ${LIB}/driverlib/bin/eeprom.o ${LIB}/driverlib/bin/emac.o ${LIB}/driverlib/bin/epi.o ${LIB}/driverlib/bin/flash.o ${LIB}/driverlib/bin/fpu.o ${LIB}/driverlib/bin/gpio.o ${LIB}/driverlib/bin/hibernate.o ${LIB}/driverlib/bin/i2c.o ${LIB}/driverlib/bin/interrupt.o ${LIB}/driverlib/bin/lcd.o ${LIB}/driverlib/bin/mpu.o ${LIB}/driverlib/bin/onewire.o ${LIB}/driverlib/bin/pwm.o ${LIB}/driverlib/bin/qei.o ${LIB}/driverlib/bin/shamd5.o ${LIB}/driverlib/bin/ssi.o ${LIB}/driverlib/bin/sw_crc.o ${LIB}/driverlib/bin/sysctl.o ${LIB}/driverlib/bin/sysexc.o ${LIB}/driverlib/bin/systick.o ${LIB}/driverlib/bin/timer.o ${LIB}/driverlib/bin/uart.o ${LIB}/driverlib/bin/udma.o ${LIB}/driverlib/bin/usb.o ${LIB}/driverlib/bin/watchdog.o \
		${UART_ARCHIVE} \
		${WOLFSSL_ARCHIVE} \
		'${LIBM}' '${LIBC}' '${LIBGCC}'

	${OBJCOPY} -O binary bin/emfi.elf bin/emfi.bin

clean:
	make -C ${LIB}/driverlib clean
	make -C ${LIB}/uart clean
	rm -rf bin/*
	rm -rf src/*.o
	rm -rf src/*.d