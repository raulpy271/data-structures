
bin/linux:
	mkdir -p bin/linux

bin/linux/libdlist.o: src/dlist.*
	gcc -c src/dlist.c -o bin/linux/libdlist.o

bin/linux/libuset.o: src/uset.*
	gcc -c src/uset.c -o bin/linux/libuset.o

bin/linux/libdsets.o: src/dsets.*
	gcc -c src/dsets.c -o bin/linux/libdsets.o

bin/linux/libkruskal.o: src/kruskal.*
	gcc -c src/kruskal.c -o bin/linux/libkruskal.o

bin/linux/libpriority_queue.o: src/priority_queue.*
	gcc -c src/priority_queue.c -o bin/linux/libpriority_queue.o

bin/linux/libgraph.o: src/graph.*
	gcc -c src/graph.c -o bin/linux/libgraph.o

bin/linux/libprim.o: src/prim.*
	gcc -c src/prim.c -o bin/linux/libprim.o

bin/linux/libbellman.o: src/bellman_ford.*
	gcc -c src/bellman_ford.c -o bin/linux/libbellman.o

uset_example.out: bin/linux/libuset.o uset_example.c
	gcc uset_example.c bin/linux/libuset.o -o uset_example.out

dsets_example.out: bin/linux/libdsets.o dsets_example.c
	gcc dsets_example.c bin/linux/libdsets.o -o dsets_example.out

kruskal_example.out: bin/linux/libdsets.o bin/linux/libkruskal.o kruskal_example.c
	gcc kruskal_example.c bin/linux/libdsets.o bin/linux/libkruskal.o -o kruskal_example.out

bellman_ford_example.out: bin/linux/libbellman.o bellman_ford_example.c
	gcc bellman_ford_example.c bin/linux/libbellman.o -o bellman_ford_example.out

hash_table_example.out: bin/linux src/hash_table.* hash_table_example.c
	gcc -c src/hash_table.c -o bin/linux/libhashtable.o
	gcc hash_table_example.c bin/linux/libhashtable.o -lm -o hash_table_example.out

graph_example.out: graph_example.c bin/linux/libgraph.o bin/linux/libdlist.o
	gcc graph_example.c bin/linux/libgraph.o bin/linux/libdlist.o -o graph_example.out

prim_example.out: prim_example.c bin/linux/libprim.o bin/linux/libpriority_queue.o bin/linux/libdlist.o
	gcc prim_example.c bin/linux/libprim.o bin/linux/libpriority_queue.o bin/linux/libdlist.o -o prim_example.out

exec_hash_table_example: hash_table_example
	./hash_table_example.out

clean:
	rm bin/linux/*
	rm *.out

