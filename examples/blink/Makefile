all: build flash cleanup

build:
	sdcc -c ../../source/stm8s103f3.c -lstm8 -mstm8 -o stm8s103f3_compiled.rel
	sdcc blink.c stm8s103f3_compiled.rel -lstm8 -mstm8 --out-fmt-ihx -o blink_hex.ihx
	
flash:
	stm8flash -p stm8s103f3 -c stlinkv2 -w blink_hex.ihx

verify:
	# NOTE: You need to reconect board after verify
	stm8flash -p stm8s103f3 -c stlinkv2 -v MAIN_HEX.ihx 

cleanup:
	rm blink_hex.*
	rm stm8s103f3_compiled.*
