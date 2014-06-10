CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
AR=arm-none-eabi-ar
CFLAGS=-c -g -Os -w -ffunction-sections -fdata-sections -nostdlib \
	-I/usr/lib/arm-none-eabi/include/ \
	--param max-inline-insns-single=500 -fno-rtti -fno-exceptions \
	-Dprintf=iprintf -mcpu=cortex-m3 -DF_CPU=84000000L \
	-DARDUINO=156 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ \
	-mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON \
	-DUSB_MANUFACTURER="Unknown" -DUSB_PRODUCT="Arduino Due"
LDFLAGS=-Os -Wl,--gc-sections -mcpu=cortex-m3 -Tflash.ld \
	-Wl,-Map,main.c.map -o main.c.elf -lm -lgcc -mthumb \
	-Wl,--cref -Wl,--check-sections -Wl,--gc-sections \
	-Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all \
	-Wl,--warn-common -Wl,--warn-section-align \
	-Wl,--warn-unresolved-symbols

all: core

main.c.o:
	$(CC) $(CFLAGS) -o main.c.o main.c

startup_sam3xa.c.o:
	$(CC) $(CFLAGS) -o startup_sam3xa.c.o startup_sam3xa.c

core.a: startup_sam3xa.c.o main.c.o
	$(AR) rcs core.a startup_sam3xa.c.o
	$(AR) rcs core.a main.c.o

core: core.a
	cd ./sam/libsam/build_gcc/ && make
	$(CC) $(LDFLAGS) -Wl,--start-group core.a -Wl,--end-group
	$(OBJCOPY) -O binary main.c.elf main.c.bin

prog: core
	stty -F /dev/ttyACM0 1200
	bossac -i -d --port=ttyACM0 -U false -e -w -v -b main.c.bin -R

clean:
	rm -f test *.elf *.a *.o *.map *.bin
	cd ./sam/libsam/build_gcc/ && make clean
