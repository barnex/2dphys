all:
	g++ -std=c++11 -Wall -Werror *.cpp -o test
	./test

llvm:
	clang++ -std=c++11 -Wall -Werror *.cpp -o test

clean:
	rm -f a.out *.o *.gch *.orig
