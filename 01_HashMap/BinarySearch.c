#include <stdio.h>
#include <string.h>

#include "Header.h"

/* Simple implementation of binary search. Assumes the array is pre-sorted*/
const item* binary_search(const item* items, size_t size, const char* key) {
    size_t  min;
    size_t  mid;
    size_t  max;
    int     cmpResult;

    min = 0;
    mid = 0;
    max = size;
    cmpResult = 0;

    if (items == NULL || key == NULL || size <= 0) {
        return NULL;
    }

    while (min < max) {
        mid = (min + max) / 2;
        cmpResult = strcmp(items[mid].key, key);
        if (!cmpResult) {
            return &items[mid];
        }
        if (cmpResult < 0) {
            min = mid +1;
        } else {
            max = mid;
        }
    }
    
    return NULL;
}

char*   extract_key_from_input( const int argc, char** argv ) {
    char* result;

    result = NULL;

    if (argc == 2 && argv[1] && strcmp(argv[1], "")) {
        result = argv[1];
    }

    return (result);
}

/* Example implementation of binary search over a pre-sorted array */
int main (int argc, char** argv) {
    const item*   found;
	char*	keyToSearch;

    const item    items[] = {
                {"bar", 42}, {"bazz", 36}, {"bob", 11}, {"buzz", 7},
                {"foo", 10}, {"jane", 100}, {"x", 200}};
    const size_t num_items = sizeof(items) / sizeof(item);

    keyToSearch = extract_key_from_input(argc, argv);
    if (keyToSearch == NULL) {
        return log_error(ERR_INPUT, "Usage: %s <search_key>\n", argv[0]);
    }

    found = binary_search(items, num_items, keyToSearch);
    if (found == NULL) {
        return log_error(ERR_KEY_MISSING, "Error: Couldn't find key %s!\n", keyToSearch);
    } else {
        printf("Key Found: %s, Value: %d\n", found->key, found->value);
    }

    return (0);
}