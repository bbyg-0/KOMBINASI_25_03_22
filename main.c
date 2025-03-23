#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "menu.h"
#include "common.h"
#include "nrllBuku.h"
#include "stackRiwayat.h"
#include "queuePelanggan.h"

int main (void){
	addressBuku headBuku = NULL;
	addressBuku Buku = NULL;
	
	addressRiwayat Rekap = NULL;

	Create_memory((void **)(&Buku), NRLL);
	Isi_Buku(&Buku, "The Silence of the Lambs", 400000);
	insertBuku(&headBuku, &Buku);

	Create_memory((void **)(&Buku), NRLL);
	Isi_Buku(&Buku, "Politik Militer Indonesia 1945-1967", 125000);
	insertBuku(&headBuku, &Buku);

	Create_memory((void **)(&Buku), NRLL);
	Isi_Buku(&Buku, "Massa Actie", 75000);
	insertBuku(&headBuku, &Buku);

	Create_memory((void **)(&Buku), NRLL);
	Isi_Buku(&Buku, "Dari Penjara ke Penjara", 115000);
	insertBuku(&headBuku, &Buku);

	Create_memory((void **)(&Buku), NRLL);
	Isi_Buku(&Buku, "Anarkis untuk Pemula", 75000);
	insertBuku(&headBuku, &Buku);

	Create_memory((void **)(&Buku), NRLL);
	Isi_Buku(&Buku, "Madilog", 75000);
	insertBuku(&headBuku, &Buku);

	Create_memory((void **)(&Buku), NRLL);
	Isi_Buku(&Buku, "il Principe: Buku Pedoman para Diktator", 55000);
	insertBuku(&headBuku, &Buku);

	addressPelanggan headPelanggan = NULL;
	addressPelanggan Pelanggan = NULL;


	unsigned short antrian = 1;
	
	Buku = searchBuku (headBuku, "Massa Actie");
	if(!isEmpty(Buku) && !isOrdered(headPelanggan, Buku)){
	Create_memory((void **)(&Pelanggan), Q);
	Isi_Pelanggan (&Pelanggan, antrian, "BABA YAGA", Buku);
	insertPelanggan (&headPelanggan, &Pelanggan);
	antrian++; Buku = NULL;}

	addressRiwayat headRiwayat = NULL;

	prosesPelanggan (&headPelanggan, &headBuku, &headRiwayat);

	int Input = -1;
	char InputS1[50] = {0};
	while(1){
		Input = -1;
		clearScreen();
		mainMenu();
		Input = secureInputInt();
		switch(Input){
			case 1:{
				clearScreen();
				Tampil_List(headBuku, NRLL);

				printf("JUDUL APA YANG ANDA INGINKAN:");
				secureInputString(InputS1, sizeof(InputS1));
				Buku = searchBuku (headBuku, InputS1);
				
				if(!isEmpty(Buku) && !isOrdered(headPelanggan, Buku)){
				printf("JUDUL DITEMUKAN\nNAMA ANDA:");
				secureInputString(InputS1, sizeof(InputS1));
				Create_memory((void **)(&Pelanggan), Q);
				Isi_Pelanggan (&Pelanggan, antrian, InputS1, Buku);
				insertPelanggan (&headPelanggan, &Pelanggan);
				antrian++; Buku = NULL;
				printf("\nPELANGGAN SUDAH MASUK KE ANTRIAN\n");
				Tampil_Node(Pelanggan, Q);
				printEnter();
				}
				else{
					printf("Judul tidak ditemukan atau telah dipesan oleh pelanggan lain\n");
				printEnter();
				}
				break;}
			case 2:{
				Tampil_Node(headPelanggan, Q);
				prosesPelanggan(&headPelanggan, &headBuku, &headRiwayat);
				printEnter();
				break;
			}
			case 3:{
				Tampil_List(headPelanggan, Q);
				printEnter();
				break;
			}
			case 4:{
				printf("JUDUL:");
				secureInputString(InputS1, sizeof(InputS1));
				printf("HARGA:");
				double InputD = secureInputDouble();
				Create_memory((void **)(&Buku), NRLL);
				Isi_Buku(&Buku, InputS1, InputD);
				insertBuku(&headBuku, &Buku);
				Tampil_Node(Buku, NRLL);
				printf("Telah dimasukkan ke rak buku\n");
				printEnter();
				break;
			}
			case 5:{
				Tampil_List(headBuku, NRLL);
				printEnter();
				break;
			}
			case 6:{
				Tampil_List(headRiwayat, STACK);
				printEnter();
				break;
			}
			case 7:{
				popRiwayat(&headRiwayat);
				printEnter();
				break;
			}
			case 8:{
				popAllRiwayat(&headRiwayat);
				printEnter();
				break;
			}
			case 0:{
				exit(0);
				}
			default:{
				printf("Input invalid, masukkan angka 1-8\n");
				printf("Tekan ENTER untuk melanjutkan");
				break;}
		}

		clearInput_buffer();
	}	
	
	
	return 0;
}
