#include <stdio.h>
#include <string.h>

// Struktur data kota
struct Kota {
    char kode[5];
    char nama[20];
    int ongkir;
    char keterangan[20];
};

// Fungsi mencari kota berdasarkan kode
int cariKota(struct Kota dataKota[], int jumlah, char kode[]) {
    for(int i = 0; i < jumlah; i++) {
        if(strcmp(dataKota[i].kode, kode) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {

    // Array data kota
    struct Kota dataKota[4] = {
        {"MDN","MEDAN",8000,"DALAM_PULAU"},
        {"BLG","BALIGE",5000,"DALAM_PULAU"},
        {"JKT","JAKARTA",12000,"LUAR_PULAU"},
        {"SBY","SURABAYA",13000,"LUAR_PULAU"}
    };

    char kodeButet[5];
    char kodeUcok[5];

    int beratButet;
    int beratUcok;

    printf("Masukkan kode kota Butet : ");
    scanf("%s", kodeButet);

    if(strcmp(kodeButet,"END")==0){
        return 0;
    }

    printf("Masukkan berat paket Butet (kg) : ");
    scanf("%d", &beratButet);

    printf("Masukkan kode kota Ucok : ");
    scanf("%s", kodeUcok);

    if(strcmp(kodeUcok,"END")==0){
        return 0;
    }

    printf("Masukkan berat paket Ucok (kg) : ");
    scanf("%d", &beratUcok);

    int indexButet = cariKota(dataKota,4,kodeButet);
    int indexUcok = cariKota(dataKota,4,kodeUcok);

    int totalBerat = beratButet + beratUcok;

    int ongkirButet = beratButet * dataKota[indexButet].ongkir;
    int ongkirUcok = beratUcok * dataKota[indexUcok].ongkir;

    int totalOngkir = ongkirButet + ongkirUcok;

    float diskon = 0;

    if(totalBerat > 10){
        diskon = totalOngkir * 0.10;
    }

    totalOngkir = totalOngkir - diskon;

    printf("\n===== STRUK PEMBAYARAN DEL-EXPRESS =====\n");

    printf("Kota tujuan Butet : %s\n", dataKota[indexButet].nama);
    printf("Berat paket Butet : %d kg\n", beratButet);

    printf("Kota tujuan Ucok  : %s\n", dataKota[indexUcok].nama);
    printf("Berat paket Ucok  : %d kg\n", beratUcok);

    printf("Total berat       : %d kg\n", totalBerat);
    printf("Total ongkos kirim: Rp %d\n", totalOngkir);

    if(totalBerat > 10){
        printf("Promo             : Diskon 10%%\n");
    }

    if(strcmp(dataKota[indexButet].keterangan,"LUAR_PULAU")==0 ||
       strcmp(dataKota[indexUcok].keterangan,"LUAR_PULAU")==0){
        printf("Promo tambahan    : Asuransi Gratis\n");
    }

    printf("========================================\n");

    return 0;
}