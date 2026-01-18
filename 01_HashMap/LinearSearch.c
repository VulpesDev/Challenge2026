#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Header.h"

/* A regukar linear search iterating an array */
item*	linear_search(item* items, size_t size, const char* key) {
  if (size <= 0 || !items || !key) {
		return (NULL);
	}

	for (size_t i=0; i<size; i++) {
		if (strcmp(items[i].key, key) == 0) {
			return &items[i];
		}
	}
	return (NULL);
}

/* Assign keyToSearch from stdin  */
char*	extract_key_from_input(const int argc, char** argv) {
  char* result;

  result = NULL;
	if (argc != 2) {
		printf("Usage: './a.out <key_to_search>'\n");
		return (NULL);
	}

	result = argv[1];
	return (result);
}

/* In the current style I tried keeping all methods modular and minimalistic.
My approach assumes readability relies onsplitting sections into many small parts */
int main ( int argc, char** argv ) {
  const item* found;
	char*	keyToSearch;

  item items[] = {
		      {"foo", 10}, {"bar", 42}, {"bazz", 36}, {"buzz", 7},
        	{"bob", 11}, {"jane", 100}, {"x", 200}
	};
	const size_t numItems = sizeof(items) / sizeof(item);

  keyToSearch = extract_key_from_input(argc, argv);
	if (keyToSearch == NULL) {
		return log_error(ERR_KEY_MISSING, "Error: Couldn'j find key %s\n", keyToSearch);
	}

  found = linear_search(items, numItems, keyToSearch);
	if (found == NULL){
		return log_error(ERR_KEY_MISSING, "Error: Couldn't find key %s\n", keyToSearch);
	} else {
    printf("Key Found: %s, Value: %d\n", found->key, found->value);
  }
	return (0);
}
