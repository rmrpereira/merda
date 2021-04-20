CC=gcc
.PHONY : clean run

testRunner : testRunner.o doorLock.o doorLockSM.o

clean:
	rm -f *.o *~
	rm -f testRunner

run: testRunner
	./testRunner
