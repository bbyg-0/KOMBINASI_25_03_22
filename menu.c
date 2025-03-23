#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "menu.h"
#include "common.h"
#include "nrllBuku.h"
#include "stackRiwayat.h"
#include "queuePelanggan.h"

void mainMenu(){
	printf("=============================\n");
	printf("|| === BABA BOOK STORE === ||\n");
	printf("=============================\n");
	printf("1.Tambah Antrian\n");
	printf("2.Proses Antrian\n");
	printf("3.Perlihatkan Antrian\n\n");
	
	printf("4.Tambah Buku\n");
	printf("5.Perlihatkan Stok Buku\n\n");
	
	printf("6.Perlihatkan Riwayat Penjualan\n");
	printf("7.Hapus Riwayat Penjualan Terbaru\n");
	printf("8.Hapus Semua Riwayat Penjualan\n\n");
	
	printf("0.Keluar");
	printf("\npilihan:");
}

void menuEnqueue(int x, int y){
	printf("Antrian 1 tersisa %d antrian\n", x);
	printf("Antrian 2 tersisa %d antrian\n", y);

	printf("\npilihan:");
}

