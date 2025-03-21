#include "convention.h"
#include "queue.h"

bool isEmpty (address p){
	if(p == NULL) {return true;}
	else {return false;}
}
void DeAlokasi (address *p){
	if(p == NULL || (*p) == NULL) return;
	
	free(*p);
	(*p) = NULL;
}

int getIndex (address p){
	return p->Antri;
}

char* getName (address p){
	return p->Name;
}

address getNext (address p){
	return p->next;
}

void setIndex (address *p, int newNilai){
	(*p)->Antri = newNilai;
}

void setName (address *p, char* newNilai){
	(*p)->Name = (char *)malloc(sizeof(char)*50);
	if ((*p)->Name != NULL) {
		free((*p)->Name);
	}
	
	(*p)->Name = strdup(newNilai);
}

void setNext (address *p, address newNilai){
	(*p)->next = newNilai;
}
