#include <stdlib.h>
#include "heap.h"

void initHeap(heap *h, int size, int (*cmp)(const void *, const void * ))
{
  h->A=(heapNode **)calloc(size, sizeof(heapNode *));
  h->cmp=cmp;
  h->len=-1;
  h->size=size;
}

void pushHeap(heap *h, const void *val)
{
  if (h->len == h->size-1)
    return;
  heapNode *nn=(heapNode *)malloc(sizeof(heapNode));
  nn->val=val;
  h->A[++h->len]=nn;
  int i=h->len, r;
  while ((i>0) && (((h->cmp)(h->A[(i-1)/2]->val, h->A[i]->val) > 0)))
  {
    nn=h->A[i];
    h->A[i]=h->A[(i-1)/2];
    h->A[(i-1)/2]=nn;
    i=(i-1)/2;
  }
  return;
}

const void *popHeap(heap *h)
{
  if (h->len == -1)
    return NULL;
  heapNode *p=h->A[0];
  const void *val;
  val=p->val;
  free(p);
  if (h->len == 0)
  {
    h->A[0]=NULL;
    return val;
  }
  h->A[0]=h->A[h->len--];
  heapify(h, 0);
  return val;
}

void heapify(heap *h, int i)
{
  int lowest=i;
  heapNode *temp;
  if ((2*i+2 <= h->len) && ((h->cmp)(h->A[2*i+2]->val, h->A[lowest]->val) < 0))
  {
    lowest=2*i+2;
  }
  if ((2*i+1 <= h->len) && ((h->cmp)(h->A[2*i+1]->val, h->A[lowest]->val) < 0 ))
  {
    lowest=2*i+1;
  }

  if (lowest==i)
    return;

  temp=h->A[lowest];
  h->A[lowest]=h->A[i];
  h->A[i]=temp;

  heapify(h, lowest);

  return;
}
