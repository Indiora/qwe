all: menu.o min_abs.o max_abs.o diff.o sum.o
	gcc menu.c abs_min.c abs_max.c diff.c sum.o -o menu
min.o: abs_min.c
	gcc -c abs_min.c -o abs_min.o
max.o: abs_max.c
	gcc -c abs_max.c -o abs_max.o
diff.o: diff.c
	gcc -c diff.c -o diff.o
sum.o: sum.c
	gcc -c sum.c -o sum.o
clean:
	rm -rf *.0 menu
