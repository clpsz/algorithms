CFLAGS = -Wall
LDFLAGS = 

target = _main
srcs = main.cpp quick_find.cpp quick_union.cpp weighted_quick_union.cpp
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

