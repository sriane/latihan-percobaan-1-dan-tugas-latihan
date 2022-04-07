#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	int a;
}isi;

typedef struct elmt *alamat;

typedef struct elmt  {
	isi paket;
	alamat next;
}elemen;

typedef struct {
	elemen* first;
	elemen*tail;
}list;

void creatList (list *L){
	(*L) .first=NULL;
	(*L) .tail=NULL;
}

int countElemen(list L){
	int jumlah = 0;
	if (L.first !=NULL){
	elemen* now = L.first;
	while (now !=NULL){
	jumlah ++;
	now=now->next;
}
}
return jumlah;
}

void addFirst (list *L, int i){
	elemen *baru = (elemen*)malloc(sizeof(elemen));
	baru->paket.a=i;
	
	if((*L).first ==NULL){
		(*L).first = baru;
		(*L).tail = baru;
		baru->next = NULL;
	}else{
		baru->next=(*L).first;
		(*L).first=baru;
	}
}

void addAfter(list *L, int i, int urutan ){
	if(urutan <=countElemen(*L)){
		elemen *baru = (elemen*)malloc(sizeof(elemen));
		elemen *sebelum = (*L).first;
		int j=1;
		while(j<urutan){
			sebelum=sebelum->next;
			j++;
		}
		
		if (sebelum!= NULL){
			baru->paket.a=i;
			if(sebelum==(*L).tail){
				sebelum->next=baru;
				baru->next=NULL;
				(*L).tail=baru;
			}else{
				baru->next=sebelum->next;
				sebelum->next=baru;
			}
		}
		else{
			addFirst(L,i);
		}
	}
	else{
		printf("elemen tidak ada\n");
	}
}

void addList(list *L, int i){
	if((*L).first==NULL){
		addFirst(L,i);
	}else{
		elemen* baru = (elemen*)malloc(sizeof(elemen));
		
		baru->paket.a=i;
		baru->next=NULL;
		(*L).tail->next=baru;
		(*L).tail=baru;
	}
}

void delFirst(list *L){
	if((*L).first !=NULL){
		if(countElemen(*L)==1){
			elemen *elhapus = (*L).first;
			(*L).first=NULL;
			(*L).tail=NULL;
			free(elhapus);
		}else{
			elemen *elhapus = (*L).first;
			(*L).first = elhapus->next;
			elhapus->next=NULL;
			free(elhapus);
		}
	}
	else{
		printf("List masih kosong\n");
	}
}

void delLast(list *L){
	if((*L).first !=NULL){
		if(countElemen(*L) == 1){
			delFirst(L);
		}else{
			elemen *terakhir = (*L).first;
			elemen *sterakhir = NULL;
			
			while(terakhir->next !=NULL){
				sterakhir =terakhir;
				terakhir = terakhir->next;
			}
			
			terakhir->next=NULL;
			(*L).tail=sterakhir;
			sterakhir->next = NULL;
			free(terakhir);
		}
	}
	else{
		printf("List masih kosong\n");
	}
}

void delAfter(list *L, int urutan){
	if((*L).first!=NULL){
		if(urutan<countElemen(*L)){
			if(countElemen(*L)==1){
				delFirst(L);
			}else{
				int c=1;
				
				elemen *hapus=(*L).first;
				elemen *shapus=NULL;
				
				while(c<=urutan){
					shapus=hapus;
					hapus=hapus->next;
					c++;
				}
				
				shapus->next=hapus->next;
				hapus->next=NULL;
				free(hapus);
			}
		}
		else if(urutan == countElemen(*L)){
			delLast(L);
	}
		else{
			printf("tidak ada urutannya\n");
		}
	}
	else{
		printf("list masih kosong\n");
	}
}


void printElemen(list L){
	if(L.first !=NULL){
		elemen *elmt =L.first;
		while(elmt !=NULL){
			printf("%d\n",elmt->paket.a);
			elmt=elmt->next;
		}
	}
	else{
		printf("List masih kosong\n");
	}
}

main(void){
	
	list L;

	
	
	addFirst(&L,3);
	addFirst(&L,4);
	addFirst(&L,5);
	addFirst(&L,6);
	addAfter(&L,7,2);
	
	printf("List setelah di input\n");
	printElemen(L);
	
	delFirst(&L);
	delAfter(&L,3);
	delLast(&L);
	
	printf("\n\nList setelah beberapa elemen dihapus\n");
	printElemen(L);
	
	


return 0;	
}
