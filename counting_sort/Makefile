CC=cc
UNITY_INCLUDE=../Unity/src
UNITY_SRC=../Unity/src/unity.c

all: counting_sort counting_sort_key

counting_sort:
	$(CC) -I$(UNITY_INCLUDE) -o test_$@ $@.c test_$@.c $(UNITY_SRC)

counting_sort_key:
	$(CC) -I$(UNITY_INCLUDE) -o test_$@ $@.c test_$@.c $(UNITY_SRC)

clean:
	rm -f test_counting_sort test_counting_sort_key
