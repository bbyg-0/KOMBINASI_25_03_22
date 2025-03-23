#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "nrllBuku.h"
#include "stackRiwayat.h"

typedef unsigned short infotype3;
typedef char* infotype4;
typedef struct p *addressPelanggan;
typedef struct p{
	infotype3 Antrian;
	infotype4 Nama;
	addressBuku Buku;
	addressPelanggan next;
} Pelanggan;

#include "common.h"

void Isi_Pelanggan (addressPelanggan *p, unsigned short Q, char* name, addressBuku book);

void insertPelanggan (addressPelanggan *head, addressPelanggan *new);

void prosesPelanggan (addressPelanggan *head, addressBuku *rak, addressRiwayat *note);

bool isOrdered (addressPelanggan head, addressBuku Buku);


#endif
