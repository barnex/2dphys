all:
	g++ -std=c++11 -Wall -Werror *.cpp -o test
	./test

clean:
	rm -f a.out *.o *.gch *.orig
