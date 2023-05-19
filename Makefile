CFLAGS = -Wall -Wextra -Werror

all: bin/units

bin/units: main.cpp
	g++ -o $(CFLAGS) -o $@ $^

clean:
	rm bin/units