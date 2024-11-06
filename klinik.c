#include <stdio.h>
#include <string.h>
#include <conio.h>

int jmlPasien = 0;

int noAntrian() {
	int base = 500;
	int *atr = &jmlPasien;
	int etc = *atr * 11;
	return base + etc;
}

void registrasi() {
	if (jmlPasien >= 200) {
        printf("Jumlah pasien sudah maksimal!\n");
        return;
    }
    
    char nama[100], alamat[200], jkelamin;
    int umur, nrp;
    
    system("cls");
    printf("Masukkan nama pasien : ");
    fgets(nama, sizeof(nama), stdin);
    nama[strcspn(nama, "\n")] = 0;
    
    int benar = 0;
    printf("Masukkan jenis kelamin pasien : ");
    scanf("%c\n", &jkelamin);
    if (jkelamin == 'l' || jkelamin == 'p') {
    	benar = 1;
	}
	else {
		printf("Jenis kelamin tidak valid!");
		benar = 0;
		getch();
	}
	
	printf("Masukkan alamat pasien : ");
	fgets(alamat, sizeof(alamat), stdin);
    alamat[strcspn(alamat, "\n")] = 0;
    
    printf("Masukkan umur pasien : ");
    scanf("%d\n", &umur);
    getchar();
    
    nrp = noAntrian();
	printf("Nomor antrian Anda adalah %d", nrp);
    
	FILE *file = fopen("infopasien.txt", "a");
    if (file != NULL) {  
    	fprintf(file, "Nama : %s\n", nama);
    	fprintf(file, "Jenis Kelamin : %c\n", jkelamin);
    	fprintf(file, "Alamat : %s\n", alamat);
    	fprintf(file, "Umur : %d\n", umur);
    	fprintf(file, "NRP : %d\n", nrp);
    	fclose(file);
    	printf("Data disimpan!");
    }
    else {
    	printf("Tidak dapat membuka file untuk menyimpan data.\n");
	}
	
	jmlPasien++;
    getch();
}

void srcPasien() {
	system("cls");
	
	FILE *file = fopen("infopasien.txt", "r");
	
	int antri, src = 0;
	int nrp = noAntrian();
	char nama[100];
	
	printf("Masukkan nomor antrian : ");
	scanf("%d", &antri);
	
	int i = 0;
	while (i < jmlPasien) {
		if (nrp == antri) {
			printf("Nomor %d terdaftar atas nama %s.\n", nrp, fprintf(file, "Nama : %s\n", nama));
			src = 1;
			getch();
			break;
		}
		i++;
	}
	if (!src) {
		printf("Nomor antrian %d tidak terdaftar.\n", antri);
		getch();
	}
	
	fclose(file);
}

void showPasien() {
	system("cls");
	
	FILE *file = fopen("infopasien.txt", "w");
    if (jmlPasien == 0) {
        printf("Belum ada data pasien.\n");
        return;
    }

    char line[2000];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    printf("=======================================\n");

    fclose(file);
}

int main() {
	int ch;
	
	FILE *file = fopen("pasiendukun.txt", "r");
	
	do {
		system("cls");
		printf("1. Daftar sebagai pasien baru.\n");
		printf("2. Cari pasien.\n");
		printf("3. Tampilkan seluruh data\n");
		printf("Pilih opsi : ");
		scanf("%d\n", &ch);
		getchar();
		
		switch (ch) {
			case 1:
				registrasi();
			case 2:
				srcPasien();
			case 3:
				showPasien();
			case 4:
				break;
			default:
				printf("Pilihan tidak valid!");
				getch();
		}
	} while (ch != 4);
	
	return 0;
}
