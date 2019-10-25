    
all: menu

menu: menu.c abs_max.o abs_min.o diff.o sum.o
	gcc menu.c abs_max.o abs_min.o diff.o sum.o -o menu
abs_max.o: abs_max.c
	gcc -c  abs_max.c -o abs_max.o
abs_min.o: abs_min.c
	gcc -c abs_min.c -o abs_min.o
diff.o: abs_min.o abs_max.o diff.c
	gcc -c diff.c -o diff.o
sum.o: abs_max.o sum.c
	gcc -c sum.c -o sum.o
clear:
	rm -rf ./*.o
