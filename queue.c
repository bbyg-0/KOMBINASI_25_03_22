#include "queue.h"
#include "convention.h"

void Create_Q(address *p){
	*p = (address)malloc(sizeof(stackList));
	if(isEmpty(*p)){
		printf("Memori gagal dialokasi");return;
	}
	setIndex(p, 0);
	setName(p, "None");
	setNext(p, NULL);
}

void Isi_Q (address *p, int Nilai, char* Nama){
	if(isEmpty(*p)) return;

	setIndex(p, Nilai);
	setName(p, Nama);
}

void Show_List (address p){
	printf("Barisan: \n");
	while(p != NULL){
		printf("\t%i.%s\n", getIndex(p), getName(p));
		p = getNext(p);
	}
}

void enqueue (address *p, address *pNew){
	if(isEmpty(*p)){
		(*p) = *pNew;
		return;
	}	
	address temp = (*p);
	while(!isEmpty((*p)->next)){
		(*p) = getNext(*p);
	}
	setNext(p, *pNew);
	
	(*p) = temp;

}

void dequeue (address *p, unsigned short *x){
	if(*x <= 0) return;
	if(isEmpty(*p)) return;
	
	address temp = getNext(*p);
	DeAlokasi(p);
	(*p) = temp;

	if(isEmpty(*p)) printf("List telah kosong");
	*x -=1;
}

int NbElement(address p){
	int result = 0;
	while(!isEmpty(p)){
		result++;
		p = p->next;
	}
	return result;
}
