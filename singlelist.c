/*======================================
    Nama	: Farrel Zikri Suryahadi
    NPM		: 23081010213
    Tugas	: Linked List
======================================*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *nxt;
};
typedef struct node node;

void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir(node **head);
void delData(node **head);
void delAwal(node **head);
void delTengah(node **head);
void delAkhir(node **head);
void tampilData(node *head);
int countData(node *head);
int sumData(node *head);
node *srcData(node *head, int num);

int main()
{
    node *head = NULL;
    char ch;
    int num;

    do
    {
        system("cls");
        printf("Masukkan pilihan anda :\n");
        printf("1. Tambahkan data di awal\n");
        printf("2. Tambahkan data di tengah list\n");
        printf("3. Tambahkan data di akhir\n");
        printf("4. Hapus data\n");
        printf("5. Tampilkan semua data\n");
        printf("6. Cari data\n");
        printf("7. Tampilkan jumlah data\n");
        printf("8. Tampilkan hasil penjumlahan semua data\n");
        printf("Masukkan pilihan anda (Tekan 'x' untuk keluar) : ");
        fflush(stdin);
        scanf("%c", &ch);

        switch (ch)
        {
        case '1':
            tambahAwal(&head);
            break;
        case '2':
            tambahData(&head);
            break;
        case '3':
            tambahAkhir(&head);
            break;
        case '4':
            delData(&head);
            getch();
            break;
        case '5':
            tampilData(head);
            getch();
            break;
        case '6':
        	system("cls");
            printf("Masukkan data yang dicari : ");
            scanf("%d", &num);
            node *hasil = srcData(head, num);
        	tampilData(head);
            if (hasil != NULL)
            {
                printf("Data %d ditemukan\n", hasil->data);
            }
            else
            {
                printf("Data %d tidak ditemukan\n", num);
            }
            getch();
            break;
        case '7':
            printf("\nJumlah data dalam linked list : %d\n", countData(head));
            getch();
            break;
        case '8':
            printf("\nHasil penjumlahan semua data : %d\n", sumData(head));
            getch();
            break;
        }

    } while (ch != 'x');

    return 0;
}

//=====================================================
void tambahAwal(node **head)
{
    int num;
    node *pNew;

    system("cls");
    printf("Masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &num);

    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL)
    {
        pNew->data = num;
        pNew->nxt = *head;
        *head = pNew;
    }
    else
    {
        printf("Alokasi memori gagal");
        getch();
    }
}
//=================================================
void tambahData(node **head)
{
    int pos, num;
    node *pNew, *pCur;

    system("cls");
    tampilData(*head);
    printf("\nPosisi penyisipan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nBilangan : ");
    fflush(stdin);
    scanf("%d", &num);

    pCur = *head;
    while (pCur != NULL && pCur->data != pos)
    {
        pCur = pCur->nxt;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pCur == NULL)
    {
        printf("\nNode tidak ditemukan\n");
        getch();
    }
    else if (pNew == NULL)
    {
        printf("\nAlokasi memori gagal\n");
        getch();
    }
    else
    {
        pNew->data = num;
        pNew->nxt = pCur->nxt;
        pCur->nxt = pNew;
    }
}
//==================================
void tambahAkhir(node **head)
{
    int num;
    node *pNew, *pCur;

    system("cls");
    printf("Masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &num);

    pNew = (node *)malloc(sizeof(node));

    if (pNew == NULL)
    {
        printf("Alokasi memori gagal");
        getch();
        return;
    }

    pNew->data = num;
    pNew->nxt = NULL;

    if (*head == NULL)
    {
        *head = pNew;
    }
    else
    {
        pCur = *head;
        while (pCur->nxt != NULL)
        {
            pCur = pCur->nxt;
        }
        pCur->nxt = pNew;
    }
}
//=====================================
void delData(node **head)
{
    int ch;

    system("cls");
    tampilData(*head);
    printf("\nPilih opsi hapus :\n");
    printf("1. Hapus data di awal\n");
    printf("2. Hapus data di tengah\n");
    printf("3. Hapus data di akhir\n");
    printf("Masukkan pilihan : ");
    fflush(stdin);
    scanf("%d", &ch);

    if (ch == 1) {
    	delAwal(head);
    	return;
	}
	else if (ch == 2) {
		delTengah(head);
		return;
	}
	else if (ch == 3) {
		delAkhir(head);
		return;
	}
	else {
		printf("Input salah!");
		return;
	}
}
//====================================================
void delAwal(node **head)
{
    if (*head == NULL)
    {
        printf("List kosong\n");
        return;
    }
    node *temp = *head;
    *head = (*head)->nxt;
    free(temp);
    printf("Node di awal berhasil dihapus.\n");
}
//===================================================
void delTengah(node **head)
{
    if (*head == NULL)
    {
        printf("List kosong\n");
        return;
    }

    tampilData(*head);

    int data;
    printf("\nMasukkan nilai data yang ingin dihapus : ");
    fflush(stdin);
    scanf("%d", &data);

    node *pCur = *head, *pPrev = NULL;

    while (pCur != NULL && pCur->data != data)
    {
        pPrev = pCur;
        pCur = pCur->nxt;
    }

    if (pCur == NULL)
    {
        printf("Data %d tidak ditemukan\n", data);
        return;
    }

    if (pPrev == NULL)
    {
        *head = pCur->nxt;
    }
    else
    {
        pPrev->nxt = pCur->nxt;
    }
    free(pCur);
    printf("Node dengan data %d berhasil dihapus.\n", data);
}
//=================================================
void delAkhir(node **head)
{
    if (*head == NULL)
    {
        printf("List kosong\n");
        return;
    }

    node *pCur = *head, *pPrev = NULL;

    if (pCur->nxt == NULL)
    {
        free(pCur);
        *head = NULL;
        printf("Node di akhir berhasil dihapus.\n");
        return;
    }

    while (pCur->nxt != NULL)
    {
        pPrev = pCur;
        pCur = pCur->nxt;
    }

    pPrev->nxt = NULL;
    free(pCur);
    printf("Node di akhir berhasil dihapus.\n");
}
//===================================================
node *srcData(node *head, int num)
{
    node *pCur = head;
    while (pCur != NULL)
    {
        if (pCur->data == num)
        {
            return pCur;
        }
        pCur = pCur->nxt;
    }
    return NULL;
}
//==================================================
void tampilData(node *head)
{
    node *pWalker = head;

    system("cls");
    printf("Data dalam linked list :\n");
    if (pWalker == NULL)
    {
        printf("Linked list kosong\n");
    }
    else
    {
        while (pWalker != NULL)
        {
            printf("%d -> ", pWalker->data);
            pWalker = pWalker->nxt;
        }
        printf("NULL\n");
    }
}
//============================================================
int countData(node *head)
{
	system("cls");
    tampilData(head);
    int cnt = 0;
    node *pWalker = head;

    while (pWalker != NULL)
    {
        cnt++;
        pWalker = pWalker->nxt;
    }

    return cnt;
}

//================================================s
int sumData(node *head)
{
	system("cls");
    tampilData(head);
    int sum = 0;
    node *pWalker = head;

    while (pWalker != NULL)
    {
        sum += pWalker->data;
        pWalker = pWalker->nxt;
    }

    return sum;
}
