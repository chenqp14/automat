FLAGS= -Wall -ansi -pedantic 
all: cos.out
cos.out: main.o read_from_file.o image.o cellular_automaton.o principles_of_neighborhood.o save_set.o
	$(CC) -g -o zycie.out main.o read_from_file.o image.o save_set.o cellular_automaton.o principles_of_neighborhood.o -lalleg
main.o: main.c image.h read_from_file.h cellular_automaton.h principles_of_neighborhood.h save_set.h
	$(CC) $(CFLAGS) -c main.c 
principles_of_neighborhood.o: principles_of_neighborhood.c principles_of_neighborhood.h read_from_file.h
	$(CC) $(CFLAGS) -c principles_of_neighborhood.c
cellular_automaton.o: cellular_automaton.c cellular_automaton.h
	$(CC) $(CFLAGS) -c cellular_automaton.c
image.o: image.c image.h read_from_file.h
	$(CC) $(CFLAGS) -c image.c 
save_set.o: save_set.c save_set.h read_from_file.h
	$(CC) $(CFLAGS) -c save_set.c
read_from_file.o: read_from_file.c read_from_file.h
	$(CC) $(CFLAGS) -c read_from_file.c
clean:
	rm -f image.o main.o principles_of_neighborhood.o read_from_file.o cellular_automaton.o
