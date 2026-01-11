#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Header.h"

/* A regukar linear search iterating an array */
item*	linear_search(item* items, size_t size, const char* key) {
	for (size_t i=0; i<size; i++) {
		if (strcmp(items[i].key, key) == 0) {
			return &items[i];
		}
	}
	return NULL;
}

/* Assign keyToSearch from stdin  */
int	handle_input(int argc, char** argv, char** keyToSearch) {
	if (argc != 2) {
		printf("Usage: './a.out <key_to_search>'\n");
		return (1);
	}

	*keyToSearch = argv[1];
	return (0);
}

/* Handles invalid arguments and calls linear_search*/
int handle_search(item* items, size_t size, char* key) {
	item*	foundItem;

	if (size <= 0 || !items || !key) {
		printf("Invalid Input!");
		return (1);
	}

	foundItem = linear_search(items, size, key);
	if (!foundItem) {
		printf("key '%s' doesn't exist\n", key);
		return (1);
	}
	printf("linear_search: value of '%s' is %d\n", key, foundItem->value);
	return (0);
}

/* In the current style I tried keeping all methods modular and minimalistic.
My approach assumes readability relies onsplitting sections into many small parts */
int main ( int argc, char** argv ) {
	
	char*	keyToSearch;
	size_t	numItems;

	item items[] = {
		{"foo", 10}, {"bar", 42}, {"bazz", 36}, {"buzz", 7},
        	{"bob", 11}, {"jane", 100}, {"x", 200}
	};
	numItems = sizeof(items) / sizeof(item);

	if (handle_input(argc, argv, &keyToSearch)) {
		return (1);
	}
	if (handle_search(items, numItems, keyToSearch)) {
		return (1);
	}
	return (0);
}
