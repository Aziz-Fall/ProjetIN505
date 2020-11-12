OPTIONS=-Wall -g3 -O3 
run: main
	./main 

main: main.o ArbreB.o Sommet.o 
	g++ *.o -o main ${OPTIONS} 

main.o: main.cc 
	g++ -c main.cc ${OPTIONS}

ArbreB.o: ArbreB.cc 
	g++ -c ArbreB.cc ${OPTIONS}

Sommet.o: Sommet.cc 
	g++ -c Sommet.cc ${OPTIONS}

debug: 
	valgrind ./main 

clean: 
	rm -fr *.o main 
	clear
	
generate:
	dot tree.dot -Tpng -o tree.png