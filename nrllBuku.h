#ifndef NRLL_H
#define NRLL_H


typedef char* infotype1;
typedef double infotype2;
typedef struct buku *addressBuku;
typedef struct buku{
	infotype1 Judul;
	infotype2 Harga;
	addressBuku next;
} Buku;

#include "common.h"

void Isi_Buku (addressBuku *p, char* title, double price);

void insertBuku (addressBuku *head, addressBuku *new);

void delSearch (addressBuku *head, char* titleTarget);

addressBuku searchBuku (addressBuku head, char * titleTarget);

#endif
