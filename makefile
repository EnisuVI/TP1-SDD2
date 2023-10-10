c=gcc
op=-Wall -Wextra

all : es.o pile.o tp1sdd2.c 	
	$(c) $(op)  es.o pile.o tp1sdd2.c -o tp1sdd2
pile.o : pile.c pile.h
	$(c) $(op) -c pile.c	
es.o : es.c es.h
	$(c) $(op) -c es.c	

