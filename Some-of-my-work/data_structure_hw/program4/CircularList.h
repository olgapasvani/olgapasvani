#ifndef CIRC_LIST_H
#define CIRC_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "CircularListType.h"


void Create(CircularList *);
void Add(CircularList *, int);
int Remove(CircularList *);
void Advance(CircularList *);

#endif