#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
  const char*     key; 
  void*           value;
} hTableEntry;

#define INITIAL_CAPACITY 16

typedef struct {
  hTableEntry*  entries;
  size_t        length;
  size_t        capacity;
} hTable;

hTable*     hTable_create();

void        hTable_free(hTable* hTable);

void*       hTable_get(hTable* table, const char* key);

const char* hTable_set(hTable* table, const char* key, void* value);

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

static uint64_t hash_key(const char* key); 
