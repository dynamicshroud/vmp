CC = g++
FLAGS = -Wall -Wextra -O3
LINKS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -ltag -lz

default: build

vmp.o: vmp.cc
	$(CC) $(FLAGS) -c vmp.cc $(LINKS)

tags.o: tags.cc
	$(CC) $(FLAGS) -c tags.cc $(LINKS)
			
build: vmp.o tags.o
	$(CC) $(FLAGS) -o vmp vmp.o tags.o $(LINKS)
		
clean:
	rm vmp *.o