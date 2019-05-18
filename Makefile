All: tst

tst: main.o ternary_search_tree.o
	gcc -Wall -o tst main.o ternary_search_tree.o

main.o: main.c
	gcc -Wall -o main.o -c main.c

ternary_search_tree.o: ternary_search_tree.c
	gcc -Wall -o ternary_search_tree.o -c ternary_search_tree.c

clean:
	rm -rf *.o tst
