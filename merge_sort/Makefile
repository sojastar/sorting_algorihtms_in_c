CC=cc
UNITY_INCLUDE=../Unity/src
UNITY_SRC=../Unity/src/unity.c

all: merge_sort merge_sort_key

merge_sort:
	$(CC) -I$(UNITY_INCLUDE) -o test_$@ $@.c test_$@.c $(UNITY_SRC)

merge_sort_key:
	$(CC) -I$(UNITY_INCLUDE) -o test_$@ $@.c test_$@.c $(UNITY_SRC)

clean:
	rm -f test_merge_sort test_merge_sort_key
