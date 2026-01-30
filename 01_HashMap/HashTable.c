#include "HashTable.h"

hTable* hTable_create(void) {
  hTable* table = malloc(sizeof(hTable));
  if (table == NULL) {
    return NULL;
  }
  table->length = 0;
  table->capacity = INITIAL_CAPACITY;

  table->entries = calloc(table->capacity, sizeof(hTableEntry));
  if (table->entries == NULL) {
    free (table);
    return NULL;
  }
  return table;
}

void hTable_destroy(hTable* table) {
  for (size_t i = 0; i < table->capacity; i++) {
    free((void*)table->entries[i].key);
  }

  free(table->entries);
  free(table);
}

static uint64_t hash_key(const char* key) {
  uint64_t hash = FNV_OFFSET;
  for (const char* p = key; *p; p++) {
    hash ^= (uint64_t)(unsigned char)(*p);
    hash *= FNV_PRIME;
  }
  return hash;
}

void* hTable_get(hTable* table, const char* key) {
  uint64_t hash = hash_key(key);
  size_t index = (size_t)(hash & (uint64_t)(table->capacity - 1));

  while (table->entries[index].key != NULL) {
    if (strcmp(key, table->entries[index].key) == 0) {
      return table->entries[index].value;
    }
    index++;
    if (index >= table->capacity) {
      index = 0;
    }
  }
  return NULL;
}

const char* hTable_set(hTable* table, const char* key, void* value) {
  assert(value != NULL);
  if (value == NULL) {
    return NULL;
  }

  if (table->length >= table->capacity/2) {
    if (1/*!expand*/) {
      return NULL;
    }
  }
}
