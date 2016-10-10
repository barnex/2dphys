CFLAGS=\
	-std=c++11 \
	-Wall \
	-Werror

LDFLAGS=\
	-L/usr/lib/x86_64-linux-gnu/ -lX11 

LIBFILES=\
	triangle.cpp \
	x11.cpp


all: test main


test: *.cpp *.h
	rm -f test
	g++ $(CFLAGS) $(LIBFILES) test.cpp $(LDFLAGS) -o test
	clang++ $(CFLAGS) $(LIBFILES) test.cpp $(LDFLAGS) -o test
	./test


main: *.cpp *.h
	g++ $(CFLAGS) $(LIBFILES) main.cpp $(LDFLAGS) -o main 
	clang++ $(CFLAGS) $(LIBFILES) main.cpp $(LDFLAGS) -o main 


clean:
	rm -f a.out *.o *.gch *.orig x11 test main
