

hash_table_example: src/hash_table.* hash_table_example.c
	gcc -c src/hash_table.c -o bin/linux/libhashtable.o
	gcc hash_table_example.c bin/linux/libhashtable.o -lm -o hash_table_example.out

exec_hash_table_example: hash_table_example
	./hash_table_example.out

