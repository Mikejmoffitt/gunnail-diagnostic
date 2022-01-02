AS=asl
P2BIN=p2bin
SRC=src/patch.a68
BSPLIT=bsplit
MAME=mame

ASFLAGS=-i . -n -U

.PHONY: all clean prg.o data

all: prg.bin

data: gunnail.zip nmk004.zip
	mkdir -p $@
	cp gunnail.zip $@ && cd $@ && unzip -o $<
	cp nmk004.zip $@ && cd $@ && unzip -o $<

prg.orig: data
	$(BSPLIT) c data/3e.u131 data/3o.u133 $@

prg.o: prg.orig
	$(AS) $(SRC) $(ASFLAGS) -o prg.o

prg.bin: prg.o
	$(P2BIN) $< $@ -r \$$-0xFFFFF

gunnail: prg.bin data
	mkdir -p $@
	cp data/* $@
	$(BSPLIT) s $< $@/3e.u131 $@/3o.u133

test: gunnail
	$(MAME) $< -rompath $(shell pwd) -debug

package: gunnail
	zip gunnail-test.zip $</*

clean:
	@-rm -rf gunnail-test.zip
	@-rm -rf data
	@-rm -rf prg.orig
	@-rm -rf prg.bin
	@-rm -rf prg.o
