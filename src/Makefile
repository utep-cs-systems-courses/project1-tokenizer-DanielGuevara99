# compiler flags. -g for debug, -03 for optimization


CFLAGS =-g -O3


all: tokenizer



history.o: history.h

tokenizer.o: tokenizer.h


uimain.o: history.h tokenizer.h



#$@=target, $^=prerequisites



tokenizer: tokenizer.o main.o history.o

	cc -o $@ $^ $(CFLAGS)



#deletes files 

clean:

	rm -f *.o tokenizer

#Runs files

run: tokenizer

	./tokenizer