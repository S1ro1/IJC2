# makefile
# Řešení IJC-DU2, příklad b), 19.4.2022
# Autor: Matej Sirovatka, FIT
# Přeloženo: gcc 10.2.1 20210110
CC=gcc
CFLAGS=-g -Wall -Wextra -pedantic -std=c99
CPFLAGS=-O2 -pedantic -Wall -std=c++17
TARGETS=tail wordcount wordcount-dynamic libhtab.a libhtab.so
LIB_OBJS=htab_bucket_count.o htab_clear.o htab_erase.o htab_find.o htab_free.o htab_hash_function.o htab_init.o htab_lookup_add.o htab_resize.o htab_size.o htab_for_each.o
TAIL_OBJS=tail.o
WORDCOUNT_OBJS=wordcount.o libhtab.a io.o
WORDCOUNT_DYN_OBJS=wordcount.o io.o libhtab.so

all: $(TARGETS)

tail: $(TAIL_OBJS)
	$(CC) $(CFLAGS) -o tail $(TAIL_OBJS) -lm

%.o: %.c htab.h hash_tab_struct.h
	$(CC) $(CFLAGS) -fpic -c $<

libhtab.a: $(LIB_OBJS)
	ar rcs $@ $^

libhtab.so: $(LIB_OBJS)
	$(CC) -fpic -shared $^ -o $@

wordcount-: wordcount-.cc
	g++ $(CPP_FLAGS) $^ -o $@

wordcount: $(WORDCOUNT_OBJS)
	$(CC) $(CFLAGS) -static $^ -o $@

wordcount-dynamic: $(WORDCOUNT_DYN_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm *.o $(TARGETS)

zip: 
	zip xsirov00.zip *.c *.h *.cc makefile
