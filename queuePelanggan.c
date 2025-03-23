#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "common.h"
#include "queuePelanggan.h"
#include "stackRiwayat.h"

void Isi_Pelanggan (addressPelanggan *p, unsigned short Q, char* name, addressBuku book){
	if(isEmpty(*p) || isEmpty(book)) return;
	
	(*p)->Antrian = Q;
	(*p)->Nama = strdup(name);
	(*p)->Buku = book;
}

void insertPelanggan (addressPelanggan *head, addressPelanggan *new){
	if(isEmpty(*head) || isEmpty(*new)){
		(*head) = (*new);
		return;
	}
	addressPelanggan temp = (*head);
	while(!isEmpty((*head)->next)){
		(*head) = (*head)->next;
	}
	(*head)->next = (*new);
	(*head) = temp;
}

void prosesPelanggan (addressPelanggan *head, addressBuku *rak, addressRiwayat *note){
	if(isEmpty(head) || isEmpty(*head)) {return;}
	char tempS[15] = {0};
	
	addressPelanggan temp = (*head)->next;
	char X[100] = {0};
	strcat(X, "Antrian\t:");
	strcat(X, UShortToString((*head)->Antrian, tempS));
	strcat(X, "\n");
	strcat(X, "Nama\t:");
	strcat(X, (*head)->Nama);
	strcat(X, "\n");
	strcat(X, "Buku\t:");
	strcat(X, (*head)->Buku->Judul);
	strcat(X, "\n");
	strcat(X, "Harga\t:");
	strcat(X, FloatToString((*head)->Buku->Harga, tempS));
	strcat(X, "\n");
	

	addressRiwayat new = NULL;
	Create_memory((void *)&new, STACK);
	Isi_Riwayat(&new, X);
	pushRiwayat(note, &new);
	
	delSearch(rak, (*head)->Buku->Judul);
	(*head) = temp;
}

bool isOrdered (addressPelanggan head, addressBuku Buku){
	if(isEmpty(head)) return false;

	while(!isEmpty(head)){
		if((head)->Buku == Buku) return true;		

		(head) = (head)->next;
	}

	return false;
}
