WSPREP = Resources/wsprep.exe
TM = $(wildcard *.tm)





tm:
	echo $(TM)

%tm.c : %.tm
	echo $< -o $@
	$(WSPREP) $< -o $@