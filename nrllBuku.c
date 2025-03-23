#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "nrllBuku.h"

void Isi_Buku (addressBuku *p, char* title, double price){
	if(isEmpty((void *)(*p))) return;
	
	(*p)->Judul = strdup(title);
	(*p)->Harga = price;
}

void insertBuku (addressBuku *head, addressBuku *new){
	if(isEmpty((void *)(*head))){
		(*head) = (*new);
		return;
	}
	
	(*new)->next = (*head);
	(*head) = (*new);
}

void delSearch (addressBuku *head, char* titleTarget){
	if(isEmpty((*head))) return;
	
	addressBuku temp = NULL;
	addressBuku T = (*head);
	if(strcmp((*head)->Judul, titleTarget) == 0){
		temp = (*head)->next;
		DeAlokasiBuku  (head);
		(*head) = temp;
		return;
	}	

	while(!isEmpty((*head)->next)){
		if(strcmp((*head)->next->Judul, titleTarget) == 0){
			temp = (*head)->next->next;
			DeAlokasiBuku(&(*head)->next);
			(*head)->next = temp;
			break;
		}		

		(*head) = (*head)->next;
	}
	(*head) = T;
}

addressBuku searchBuku (addressBuku head, char * titleTarget){
	unsigned short index = 0;
	
	while(!isEmpty(head)){
		if(strcmp((head)->Judul, titleTarget) == 0) return (head);
		index++;
		(head) = (head)->next;
	}

	return NULL;
}
