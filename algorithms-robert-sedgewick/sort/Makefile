CFLAGS = -Wall -std=c++11
LDFLAGS = 

target = _main
srcs = main.cpp SelectionSort.cpp InsertionSort.cpp BubbleSort.cpp \
	ShellSort.cpp MergeSort.cpp QuickSort.cpp
objs = $(srcs:.cpp=.o)
headers = $(wildcard *.h)


.PHONY: all
all: $(target)

$(target): $(objs) $(headers) FORCE
	$(CXX) -o $@ $(objs) $(LDFLAGS)
	@-rm -f *.o

$(objs):%.o:%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: FORCE
FORCE: 

clean:
	rm -f $(target) *.o

