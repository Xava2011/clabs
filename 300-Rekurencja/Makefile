CFLAGS=-std=c99 -Wall 

csources =  fact.c fib1.c fib2.c fib3.c palindrome.c isoe.c isoe-1.c \
  permutacje.c digit-sum.c div.c

objects = $(csources:.c=.o)
programs = $(csources:.c=)

fact : fact.c
	cc $(CFLAGS) -o $@ $<
fib1 : fib1.c
	cc $(CFLAGS) -o $@ $<
fib2 : fib2.c
	cc $(CFLAGS) -o $@ $<
fib3 : fib3.c
	cc $(CFLAGS) -o $@ $<
palindrome : palindrome.c
	gccx $(CFLAGS) -o $@ $<
isoe : isoe.c
	gccx $(CFLAGS) -o $@ $<
isoe-1 : isoe-1.c
	gccx $(CFLAGS) -o $@ $<
permutacje : permutacje.c
	gccx $(CFLAGS) -o $@ $<
digit-sum : digit-sum.c
	cc $(CFLAGS) -o $@ $<

div : div.c
	cc $(CFLAGS) -o $@ $<

.PHONY : clean 

clean:
	rm -f core \#* *~ $(objects) $(programs) programs.{ps,ljet4}

# programs.ps: $(csources)
# 	enscript -GE -p$@ $^

# programs.ljet4 : programs.ps
# 	gs -dNOPAUSE -dBATCH -sDEVICE=ljet4 -sOutputFile=programs.ljet4 $<