
bin/linux:
	mkdir -p bin/linux

bin/linux/libdlist.o: src/dlist.*
	gcc -c src/dlist.c -o bin/linux/libdlist.o

bin/linux/libuset.o: src/uset.*
	gcc -c src/uset.c -o bin/linux/libuset.o

uset_example.out: bin/linux/libuset.o uset_example.c
	gcc uset_example.c bin/linux/libuset.o -o uset_example.out

hash_table_example.out: bin/linux src/hash_table.* hash_table_example.c
	gcc -c src/hash_table.c -o bin/linux/libhashtable.o
	gcc hash_table_example.c bin/linux/libhashtable.o -lm -o hash_table_example.out

graph_example.out: bin/linux src/graph.* graph_example.c bin/linux/libdlist.o
	gcc -c src/graph.c -o bin/linux/libgraph.o
	gcc graph_example.c bin/linux/libgraph.o bin/linux/libdlist.o -o graph_example.out

exec_hash_table_example: hash_table_example
	./hash_table_example.out

clean:
	rm bin/linux/*
	rm *.out

