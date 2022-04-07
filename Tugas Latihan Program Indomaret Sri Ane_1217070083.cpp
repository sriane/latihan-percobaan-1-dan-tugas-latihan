#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct barang{
	char nb[30];
	int kb;
	int hb;
	int jb;
};

struct Elemen{
	barang brg;
	Elemen *next;
};

struct List{
	Elemen *first;
	Elemen *last;
};

void addFirst(char nb[], int kb, int hb,int jb, List *L);
void addAfter(Elemen *prev, char nb[], int kb,int hb,int jb, List *L);
void addLast(char nb[], int kb,int hb,int jb, List *L);

void deleteFirst(List *L);
void deleteAfter(Elemen *prev, List *L);
void deleteLast(List *L);

void showData(List *L);

Elemen *searchData(char kb[], List *L);
barang inputbarang();
char *searchbrg();

int count(List L);

int main(){
	char option;
	
	List L;
	L.first = NULL;
	
	barang data;
	Elemen *prev;
	
	int menu = 0;
	int pos = 0;
	
	do{
		system("cls");
		printf("============================================\n");
		printf("<   SELAMAT DATANG DI DATABASE INDOMARET   >\n");
		printf("============================================\n");
		printf("Banyak data saat ini :\n");
		printf("\n\nMENU : \n");
		printf("1. Tambah Data \n");
		printf("2. Hapus Data \n");
		printf("3. Carikan Data\n");
		printf("4. Tampilkan Data\n");
		printf("5. Exit\n");
		
		printf("Pilih Menu : ");
		scanf("%d", &menu);

		switch(menu){
			case 1:
				data = inputbarang();
				addFirst(data.nb, data.kb, data.jb,data.hb,&L);
				break;
				
			case 2:
				deleteFirst(&L);
				break;
				
			case 3:
					prev = searchData(searchbrg(), &L);
				if(prev != NULL){
					data = inputbarang();
					addAfter(prev, data.nb, data.kb, data.jb,data.hb, &L);
				}
				break;
				
			case 4:
				showData(&L);
				break;
				
				
			case 5:
				printf("\nkeluar dari program\n");
				break;
				
		
				
			default:
				printf("Invalid Input!!");
				break;	
		}
		printf("\n");
		
	   getch();
	
	}while(menu!=8);
	
	return 0;
}

void addFirst(char nb[], int kb,int hb,int jb, List *L){
	Elemen *baru = new Elemen;
	
	strcpy(baru->brg.nb, nb);
	baru->brg.kb = kb;
	baru->brg.jb = jb;
	baru->brg.hb = hb;
	
	if(L->first == NULL){
		L->first = baru;
		baru->next = NULL;
		L->last = baru;
	}else{
		baru->next = L->first;
		L->first = baru;
	}
	
	
	baru = NULL;
	printf("\nBerhasil ditambahkan!\n");
}

void addAfter(Elemen *prev, char nb[], int kb,int hb,int jb, List *L){
	Elemen *baru = (Elemen*) malloc (sizeof(Elemen));
	
	strcpy(baru->brg.nb, nb);
	baru->brg.kb = kb;
	baru->brg.jb = jb;
	baru->brg.hb = hb;
	
	baru->next = prev->next;
	prev->next = baru;
	
	if(baru->next == NULL){
		L->last = baru;
	}
	
	baru = NULL;
	printf("\nBerhasil ditambahkan!\n");
}

void addLast(char nb[], int kb,int hb,int jb, List *L){
	Elemen *baru = (Elemen*) malloc (sizeof(Elemen));
	
	strcpy(baru->brg.nb, nb);
	baru->brg.kb = kb;
	baru->brg.jb = jb;
	baru->brg.hb = hb;
	
	if(L->first == NULL){
		L->first = baru;
		L->last = baru;
		baru->next = NULL;
	}else{
		L->last->next = baru;
		L->last = baru;
		baru->next = NULL;
	}
	
	baru = NULL;
	printf("\nBerhasil ditambahkan!\n");
}

void deleteFirst(List *L){
	Elemen *data = L->first;
	if(data == NULL){
		printf("List kosong\n");
	}
	else{
	L->first = data->next;

	free(data);
	
	printf("\nBerhasil dihapus!\n");
}
}

void deleteAfter(Elemen *prev, List *L){
	Elemen *data = prev->next;
	prev->next = data->next;
	
	if(prev->next == NULL){
		L->last = prev;
	}
	
	free(data);
	
	printf("\nBerhasil dihapus!\n");
}

void deleteLast(List *L){
	Elemen *data = NULL;
	Elemen *prev = NULL;
	Elemen *pNow = L->first;
	
	while(pNow != NULL){
		prev = data;
		data = pNow;
		pNow = pNow->next;
	}
	
	if(prev == NULL){
		printf("Data kosong\n");
		L->first = NULL;
		L->last = NULL;
	}else{
		prev->next = NULL;
		L->last = prev;	
		printf("\nBerhasil dihapus!\n");
	}
	
	free(data);
	
}

void showData(List *L){
	Elemen *pnow = L->first;
	if(pnow == NULL){
		printf("\nAnda belum menambahkan data!\n");
	}else{
		printf("\nLIST DATA");
		int no = 0;
		while(pnow != NULL){
			no++;
	    	printf("\n\nBarang ke-%d", no);
	    	printf("\nNama Barang    : %s", pnow->brg.nb);
	    	printf("\nKode Barang    : %d", pnow->brg.kb);
	    	printf("\nHarga Barang   : %d", pnow->brg.jb);
	    	printf("\nJumlah Barang  : %d", pnow->brg.hb);
			pnow = pnow->next;
		}
	}
}

Elemen *searchData(char nb[], List *L){
	int no = 0;
	Elemen *pnow = L->first;
	Elemen *result = NULL;
	if(pnow == NULL){
		printf("\nAnda belum menambahkan data!\n");
	}else{
		while(pnow != NULL){
			no++;
			if(strcmp(pnow->brg.nb,nb) == 0){
				result = pnow;
				pnow = NULL;
			}else{
				pnow = pnow->next;
			}
		}
	}
	
	if(result == NULL){
		printf("Data tidak ditemukan!");
	}else{
		printf("Data ditemukan pada posisi ke-%d!",no);
	}
	
	return result;
}

barang inputbarang(){
	barang data;
	
	printf("\nNama Barang : ");
	scanf("%s",&data.nb);
	
	printf("Kode Barang   : ");
	scanf("%d",&data.kb);
	
	printf("Jumlah Barang : ");
	scanf("%d",&data.jb);
	
	printf("Harga Barang  : ");
	scanf("%d",&data.hb);
	
	
	return data;
}

char *searchbrg(){
	barang data;
	printf("\nCari Barang (Nama Barang) : ");
	scanf("%s",&data.nb);
	return data.nb;
}
