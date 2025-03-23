#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "nrllBuku.h"
#include "queuePelanggan.h"
#include "common.h"


bool isEmpty (void * node){
	return node == NULL;
}

void Create_memory (void ** node, DataType data){
	switch(data){
		case NRLL:{
			(*node) = (addressBuku)malloc(sizeof(Buku));
			if(isEmpty((void *)(*node))){
				printf("\nMEMORI GAGAL DIALOKASI\n");
				return;
			}
			
			addressBuku buku = (addressBuku)(*node);
			buku->Judul = NULL;
			buku->Harga = 0;
			buku->next = NULL;

			break;
		}
		case Q:{
			(*node) = (addressPelanggan)malloc(sizeof(Pelanggan));
			if(isEmpty(*node)){
				printf("\nGAGAL MENGALOKASIKAN MEMORI UNTUK PELANGGAN\n");
				return;
			}
			addressPelanggan pelanggan = (addressPelanggan)(*node);
			pelanggan->Antrian = 0;
			pelanggan->Nama = NULL;
			pelanggan->Buku = NULL;
			pelanggan->next = NULL;
			break;
		}
		case STACK:{
			(*node) = (addressRiwayat)malloc(sizeof(Pelanggan));
			if(isEmpty(*node)){
				printf("\nGAGAL MENGALOKASIKAN MEMORI UNTUK RIWAYAT\n");
				return;
			}
			addressRiwayat riwayat = (addressRiwayat)(*node);
			riwayat->Rekap = NULL;
			riwayat->next = NULL;
			break;
		}
		default:{
			printf("\nTIPE DATA TIDAK DIKETAHUI, TIDAK MENGALOKASIKAN MEMORI\n");
			break;
		}
	}
}

void DeAlokasiBuku (addressBuku *node){
	if(isEmpty(node) || isEmpty(*node)) return;
	free((*node)->Judul);
	(*node)->Judul = NULL;
	free(*node);
	(*node) = NULL;
}

void DeAlokasiPelanggan (addressPelanggan *node){
	if(isEmpty(node) || isEmpty(*node)) return;
	free((*node)->Nama);
	(*node)->Nama = NULL;
	DeAlokasiBuku (&(*node)->Buku);
	(*node)->Buku = NULL;
	free(*node);
	(*node) = NULL;
}

void DeAlokasiRiwayat (addressRiwayat *node){
	if(isEmpty(node) || isEmpty(*node)) return;
	
	free((*node)->Rekap);
	(*node)->Rekap = NULL;
	free(*node);
	(*node) = NULL;
}

void Tampil_List (void * node, DataType data){
	switch(data){
		case NRLL:{
			printf("DAFTAR BUKU:\n");
			addressBuku temp = (addressBuku)(node);
			while (!isEmpty((void *)temp)){
				printf("%s\n\t%lf\n", (temp)->Judul, (temp)->Harga);
				temp = temp->next;
			}
			break;
		}
		case Q:{
			printf("DAFTAR PELANGGAN:\n");
			addressPelanggan temp = (addressPelanggan)(node);
			while(!isEmpty(temp)){
				printf("%hu.%s\n\t%s\n", temp->Antrian, temp->Nama, temp->Buku->Judul);
				temp = temp->next;
			}
			break;
		}
		case STACK:{
			printf("DAFTAR RIWAYAT PENJUALAN:\n");
			addressRiwayat temp = (addressRiwayat)(node);
			while(!isEmpty(temp)){
				printf("%s\n", (temp)->Rekap);
				temp = temp->next;
			}
			break;
		}
	}
	printf("\n");
}

void Tampil_Node (void * node, DataType data){
	if(isEmpty(node)){printf("KOSONG\n"); return;}
	switch(data){
		case NRLL:{
			addressBuku temp = (addressBuku)(node);
			printf("%s\n\t%lf\n", (temp)->Judul, (temp)->Harga);	
			break;
		}
		case Q:{
			addressPelanggan temp = (addressPelanggan)(node);
			printf("%hu.%s\n\t%s\n", temp->Antrian, temp->Nama, temp->Buku->Judul);
			break;
		}
		case STACK:{
			addressRiwayat temp = (addressRiwayat)(node);
			printf("%s\n", (temp)->Rekap);
			break;
		}
	}
}



char * UShortToString (unsigned short X, char * Result){
	unsigned short index = 0;

	char result[15] = {0};
	while(X != 0){
		result[index] = (char)((X%10)+48);
		X /= 10;
		index++;
	}
	for(int i = 0; i < strlen(result); i++){
		Result[i] = result[strlen(result)-1-i];
	}

	return Result;
}

char * FloatToString (float Y, char * result){
	unsigned short index = 0;
	
	Y *= 1000;
	int X = (int)Y;
	

	while(X != 0){
		result[(sizeof(result)-1)-index] = (char)((X%10)+48);
		X /= 10;
		index++;
	}

	return result;
}

void clearScreen() {
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void secureInputString(char *buffer, int size) {
	if (fgets(buffer, size, stdin) == NULL) {
		printf("Error membaca input!\n");
		exit(EXIT_FAILURE);
	}
    
	size_t len = strlen(buffer);
	if (buffer[len - 1] == '\n') {
		buffer[len - 1] = '\0';
	} else {
		clearInput_buffer();
	}
}

int secureInputInt() {
	char buffer[5];
	int value;
	while (1) {
		secureInputString(buffer, sizeof(buffer));

		int valid = 1;
		for (size_t i = 0; buffer[i] != '\0'; i++) {
			if (!isdigit(buffer[i])) {
				valid = 0;
				break;
			}
		}
	
		if (valid) {
			value = atoi(buffer);
			return value;
		} else {
			printf("Input tidak valid! Masukkan angka: ");
		}
	}
}

double secureInputDouble() {
    char buffer[100];
    float value;
    while (1) {
        secureInputString(buffer, sizeof(buffer));
        
        int valid = 1, dot_count = 0;
        for (size_t i = 0; buffer[i] != '\0'; i++) {
            if (!isdigit(buffer[i]) && buffer[i] != '.') {
                valid = 0;
                break;
            }
            if (buffer[i] == '.') {
                dot_count++;
                if (dot_count > 1) {
                    valid = 0;
                    break;
                }
            }
        }

        if (valid) {
            value = strtof(buffer, NULL);
            return value;
        } else {
            printf("Input tidak valid! Masukkan angka desimal: ");
        }
    }
}

void clearInput_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void printEnter(){
	printf("Tekan ENTER untuk melanjutkan!!");
}
