All:
	gcc -c funcoesMat.c -o funcoesMat.o
	gcc -c funcoesVet.c -o funcoesVet.o
	gcc -c main.c -o main.o
	gcc main.o funcoesMat.o funcoesVet.o -o main
	
	./main
clean:  
	rm *.o
