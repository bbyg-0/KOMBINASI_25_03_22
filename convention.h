#ifndef Convention_H
#define Convention_H
#include <stdbool.h>


#include "queue.h"

bool isEmpty(address p);

void DeAlokasi (address *p);

int getIndex (address p);

char* getName (address p);

address getNext (address p);

void setIndex (address *p, int newNilai);

void setName (address *p, char* newNilai);

void setNext (address *p, address newNilai);

#endif

