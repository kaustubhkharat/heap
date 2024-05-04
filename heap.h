#ifndef HEAP_H
#define HEAP_H

typedef struct
{
  const void *val;
}heapNode;

typedef struct
{
  heapNode **A;
  int size, len, (*cmp)(const void *, const void *);
}heap;

void initHeap(heap *h, int size, int (*cmp)(const void *, const void *));
void pushHeap(heap *h, const void *val);
const void *popHeap(heap *h);
void heapify(heap *h, int index);

#endif
