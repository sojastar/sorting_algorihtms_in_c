CC=cc
UNITY_INCLUDE=./Unity/src
UNITY_SRC=./Unity/src/unity.c

all: radix_sort radix_sort_key

radix_sort:
	$(CC) -I$(UNITY_INCLUDE) -o test_$@ $@.c test_$@.c $(UNITY_SRC)

radix_sort_key:
	$(CC) -I$(UNITY_INCLUDE) -o test_$@ $@.c test_$@.c $(UNITY_SRC)

clean:
	rm -f test_radix_sort test_radix_sort_key
