IMPRIME = @echo

all:
	msp430-gcc -Os -mmcu=msp430g2452 teste.c -o blink.elf

connect: all
	rlwrap mspdebug rf2500

ide:
	../../../ti/Code\ Composer\ Studio\ 6.2.0.desktop

help:
	$(IMPRIME) 'Para compilar, executar: msp430-gcc -Os -mmcu=msp430g2452 teste.c -o blink.elf'
	$(IMPRIME) 'Para gravar: mspdebug rf2500'
	$(IMPRIME) 'E depois:(mspdebug) prog blink.elf'
	$(IMPRIME) 'Para rodar: (mspdebug) run'
