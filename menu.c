#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "menu.h"

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

void clearInput_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void mainMenu(){
	printf("1.Masuk antrian\n");
	printf("2.Memproses antrian\n");
	printf("3.Memperlihatkan antrian\n");
	printf("\n0.Keluar");
	printf("\npilihan:");
}

void menuEnqueue(int x, int y){
	printf("Antrian 1 tersisa %d antrian\n", x);
	printf("Antrian 2 tersisa %d antrian\n", y);

	printf("\npilihan:");
}

void pengumumanQ(int x, int y){
	printf("Nomor antrian %d untuk line 1\n", x);
	printf("Nomor antrian %d untuk line 2\n", y);
}
