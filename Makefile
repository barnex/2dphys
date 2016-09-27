all:
	rm -f a.out;
	g++ -c -std=c++11 -Wall -Werror *.h *.cpp
	g++ -std=c++11 main.cpp
	./a.out

clean:
	rm -f a.out *.o *.gch
