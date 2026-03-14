#include <stdio.h>
#include <string.h>

#define MAX 100

// Struktur data barang
struct Barang {
    char nama[50];
    char kategori[50];
    int stok;
};

// Fungsi menghitung total stok berdasarkan kategori
int hitungTotal(struct Barang data[], int n, char kategoriCari[]) {
    int total = 0;

    for(int i = 0; i < n; i++) {
        if(strcmp(data[i].kategori, kategoriCari) == 0) {
            total += data[i].stok;
        }
    }

    return total;
}

int main() {

    struct Barang gudang[MAX];
    int N;
    char kategoriCari[50];

    printf("Masukkan jumlah data barang: ");
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {

        printf("\nData barang ke-%d\n", i+1);

        printf("Nama barang : ");
        scanf(" %[^\n]", gudang[i].nama);

        printf("Kategori (Sembako / Sekolah): ");
        scanf(" %[^\n]", gudang[i].kategori);

        printf("Jumlah stok : ");
        scanf("%d", &gudang[i].stok);
    }

    printf("\nMasukkan kategori yang ingin dihitung: ");
    scanf(" %[^\n]", kategoriCari);

    int total = hitungTotal(gudang, N, kategoriCari);

    printf("\nTotal stok kategori %s = %d PCS\n", kategoriCari, total);

    return 0;
}