#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "convention.h"
#include "menu.h"

int main (void){
	address line = NULL;
	address Q = NULL;

	int choose = 0;
	int antri = 1;
	while(1){
		choose = 0;
		
		clearScreen();
		mainMenu();

		choose = secureInputInt();
		switch(choose){
			case 1:{
				char inputNama[50] = {0};
				printf("NAMA ANDA:");
				secureInputString(inputNama, sizeof(inputNama));
				Create_Q(&Q);
				Isi_Q(&Q, antri, inputNama);

				enqueue (&line, &Q);
				antri++;
				break;}
			case 2:{
				printf("Sedang diproses:\n\t%i.%s\n", getIndex(line), getName(line));
				dequeue(&line);

				getchar();
				break;}
			case 3:{
				Show_List(line);

				getchar();
				break;}
			case 0:{
				exit(0);}
				
		}
	}
	return 0;
}
