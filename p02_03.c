#include <stdio.h>
#include <string.h>

struct Menu
{
    int id;
    char nama[50];
    int harga;
};

struct Pesanan
{
    char namaPembeli[50];
    int idMenu;
    int jumlah;
    int totalHarga;
    char metodeBayar[20];
    char jamAmbil[10];
};

struct Menu menuList[5] = {
    {1, "Nasi Goreng", 15000},
    {2, "Mie Goreng", 13000},
    {3, "Ayam Geprek", 18000},
    {4, "Es Teh", 5000},
    {5, "Jus Alpukat", 10000}
};

void tampilMenu()
{
    printf("\n===== MENU KAFETARIA IT DEL =====\n");
    for(int i=0;i<5;i++)
    {
        printf("%d. %s - Rp%d\n",menuList[i].id,menuList[i].nama,menuList[i].harga);
    }
}

int cariHarga(int id)
{
    for(int i=0;i<5;i++)
    {
        if(menuList[i].id==id)
        {
            return menuList[i].harga;
        }
    }
    return 0;
}

void pembayaran(struct Pesanan p)
{
    int pilihan;

    printf("\nMetode Pembayaran\n");
    printf("1. QRIS\n");
    printf("2. E-Wallet\n");
    printf("Pilih metode: ");
    scanf("%d",&pilihan);

    if(pilihan==1)
    {
        strcpy(p.metodeBayar,"QRIS");
    }
    else
    {
        strcpy(p.metodeBayar,"E-Wallet");
    }

    printf("\n===== STRUK PEMBELIAN =====\n");
    printf("Nama Pembeli : %s\n",p.namaPembeli);
    printf("ID Menu      : %d\n",p.idMenu);
    printf("Jumlah       : %d\n",p.jumlah);
    printf("Total Harga  : Rp%d\n",p.totalHarga);
    printf("Pembayaran   : %s\n",p.metodeBayar);

    if(strlen(p.jamAmbil)>0)
    {
        printf("Jam Ambil    : %s\n",p.jamAmbil);
    }

    printf("============================\n");
}

void pesanLangsung()
{
    struct Pesanan p;

    printf("\nNama Pembeli: ");
    scanf("%s",p.namaPembeli);

    tampilMenu();

    printf("\nPilih ID Menu: ");
    scanf("%d",&p.idMenu);

    printf("Jumlah: ");
    scanf("%d",&p.jumlah);

    int harga=cariHarga(p.idMenu);

    p.totalHarga=harga*p.jumlah;

    strcpy(p.jamAmbil,"");

    pembayaran(p);
}

void preOrder()
{
    struct Pesanan p;

    printf("\nNama Pembeli: ");
    scanf("%s",p.namaPembeli);

    tampilMenu();

    printf("\nPilih ID Menu: ");
    scanf("%d",&p.idMenu);

    printf("Jumlah: ");
    scanf("%d",&p.jumlah);

    printf("Jam Pengambilan (contoh 12:30): ");
    scanf("%s",p.jamAmbil);

    int harga=cariHarga(p.idMenu);

    p.totalHarga=harga*p.jumlah;

    pembayaran(p);
}

int main()
{
    int pilihan;

    do
    {
        printf("\n===== SISTEM KAFETARIA IT DEL =====\n");
        printf("1. Lihat Menu\n");
        printf("2. Pesan Langsung\n");
        printf("3. Pre Order\n");
        printf("4. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d",&pilihan);

        switch(pilihan)
        {
            case 1:
                tampilMenu();
                break;

            case 2:
                pesanLangsung();
                break;

            case 3:
                preOrder();
                break;

            case 4:
                printf("Terima kasih\n");
                break;

            default:
                printf("Pilihan tidak tersedia\n");
        }

    }while(pilihan!=4);

    return 0;
}