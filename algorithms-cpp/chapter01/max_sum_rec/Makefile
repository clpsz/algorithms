CFLAGS = -Wall
LDFLAGS = 

.PHONY: all
all: usage

msr1: maxsumrec1.cpp
	g++ -o msr1 maxsumrec1.cpp

msr2: maxsumrec2.cpp
	g++ -o msr2 maxsumrec2.cpp

msr3: maxsumrec3.cpp
	g++ -o msr3 maxsumrec3.cpp

msr4: maxsumrec4.cpp
	g++ -o msr4 maxsumrec4.cpp


.PHONY: FORCE usage
FORCE: 

usage:
	@echo "usage:"
	@echo "      make msr[1-4]"
	@echo "      ./msr[1-4]"

clean:
	rm -f $(target) a.out *.o

