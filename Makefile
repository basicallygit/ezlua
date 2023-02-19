# Compiler and linker flags
CXXFLAGS = -Wall -Wextra -pedantic -fPIC
LDFLAGS = -shared

# Source file
SRCS = src/main.cpp

# Object file
OBJS = $(SRCS:.cpp=.o)

# Output file
ifeq ($(OS),Windows_NT)
	OUTFILE = libezlua.dll
else
	OUTFILE = libezlua.so
endif

# Build targets
all: $(OUTFILE)

$(OUTFILE): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(OUTFILE)

install:
	cp libezlua.so /usr/local/lib/
	cp lib/ezlua.hpp /usr/local/include/
