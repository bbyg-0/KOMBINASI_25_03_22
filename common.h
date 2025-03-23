#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>
#include "nrllBuku.h"
#include "queuePelanggan.h"
#include "stackRiwayat.h"

typedef enum{
	STACK,
	Q,
	NRLL
} DataType;

bool isEmpty (void * node);

void Create_memory (void ** node, DataType data);

void DeAlokasiBuku (addressBuku * node);

void DeAlokasiPelanggan (addressPelanggan *node);

void DeAlokasiRiwayat (addressRiwayat *node);

void Tampil_List (void * node, DataType data);

void Tampil_Node (void * node, DataType data);

char * UShortToString (unsigned short X, char * result);

char * FloatToString (float X, char * result);

void clearScreen();

void secureInputString(char *buffer, int size);

int secureInputInt();

double secureInputDouble();

void clearInput_buffer();

void printEnter();

#endif
