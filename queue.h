#ifndef Stack_H
#define Stack_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef int infotype1;
typedef char* infotype2;
typedef struct stack *address;
typedef struct stack {
	infotype1 Antri;
	infotype2 Name;
	address next;
} stackList;

#include "convention.h"

void Create_Q(address *p);

void Isi_Q (address *p, int antrian, char* nama);

void Show_List (address p);

void enqueue (address *p, address *pNew);

void dequeue (address *p, unsigned short *x);

int NbElement(address p);

#endif
