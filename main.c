#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "convention.h"
#include "menu.h"

int main (void){
	address line1 = NULL;
	address line2 = NULL;

	address Q = NULL;

	int choose = 0;
	unsigned short antri1 = 1;
	unsigned short antri2 = 1;
	unsigned short sisa1 = 0;
	unsigned short sisa2 = 0;
	while(1){
		choose = 0;
		
		clearScreen();
		mainMenu();

		while(1){
			choose = secureInputInt();
			if(choose == 1 || choose == 2 || choose == 3 || choose == 0 ) break;
		}
		switch(choose){
			case 1:{
				menuEnqueue(sisa1, sisa2);
				while(1){
					choose = secureInputInt();
					if(choose == 1 || choose == 2) break;
				}

				char inputNama[50] = {0};
				printf("NAMA ANDA:");
				secureInputString(inputNama, sizeof(inputNama));
				Create_Q(&Q);
				if(choose == 1){
					Isi_Q(&Q, antri1, inputNama);
					enqueue (&line1, &Q);
					antri1++;
					sisa1++;
				}else if(choose == 2){
					Isi_Q(&Q, antri2, inputNama);
					enqueue (&line2, &Q);
					antri2++;
					sisa2++;
				}
				break;}
			case 2:{
				menuEnqueue(sisa1, sisa2);
				while(1){
					choose = secureInputInt();
					if(choose == 1 || choose == 2) break;
				}
				if(choose == 1 && sisa1 > 0){
				printf("Sedang diproses:\n\t%i.%s\n", getIndex(line1), getName(line1));
				dequeue(&line1, &sisa1);
				}else if(choose==2 && sisa2 > 0){
				printf("Sedang diproses:\n\t%i.%s\n", getIndex(line2), getName(line2));
				dequeue(&line2, &sisa2);
				}

				getchar();
				break;}
			case 3:{
				Show_List(line1);
				Show_List(line2);

				getchar();
				break;}
			case 0:{
				exit(0);}
				
		}
	}
	return 0;
}
