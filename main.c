#include <stdio.h>

#define MAX 100

/* ====== Deklarasi Fungsi ====== */
void inputData(int a[], int *n);
void tampilData(int a[], int n);
int total(int a[], int n);
float rata(int a[], int n);
int maksimum(int a[], int n);
int minimum(int a[], int n);
void maxMinKedua(int a[], int n);
void frekuensi(int a[], int n);
void cariData(int a[], int n);
void hapusData(int a[], int *n);

/* ====== Program Utama ====== */
int main() {
    int data[MAX], n = 0, pilih;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Input Data\n");
        printf("2. Tampil Data\n");
        printf("3. Total & Rata-rata\n");
        printf("4. Maksimum & Minimum\n");
        printf("5. Maks & Min Kedua\n");
        printf("6. Frekuensi Bilangan\n");
        printf("7. Cari Data\n");
        printf("8. Hapus Data\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1: inputData(data, &n); break;
            case 2: tampilData(data, n); break;
            case 3:
                printf("Total = %d\n", total(data, n));
                printf("Rata-rata = %.2f\n", rata(data, n));
                break;
            case 4:
                printf("Maksimum = %d\n", maksimum(data, n));
                printf("Minimum = %d\n", minimum(data, n));
                break;
            case 5: maxMinKedua(data, n); break;
            case 6: frekuensi(data, n); break;
            case 7: cariData(data, n); break;
            case 8: hapusData(data, &n); break;
            case 0: printf("Keluar...\n"); break;
            default: printf("Menu tidak valid!\n");
        }
    } while (pilih != 0);

    return 0;
}

/* ====== Implementasi Fungsi ====== */

void inputData(int a[], int *n) {
    int i;
    printf("Jumlah data: ");
    scanf("%d", n);
    for (i = 0; i < *n; i++) {
        printf("Data ke-%d: ", i + 1);
        scanf("%d", &a[i]);
    }
}

void tampilData(int a[], int n) {
    int i;
    printf("Data: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int total(int a[], int n) {
    int i, t = 0;
    for (i = 0; i < n; i++)
        t += a[i];
    return t;
}

float rata(int a[], int n) {
    return (float) total(a, n) / n;
}

int maksimum(int a[], int n) {
    int i, max = a[0];
    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

int minimum(int a[], int n) {
    int i, min = a[0];
    for (i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

void maxMinKedua(int a[], int n) {
    int i, max1, max2, min1, min2;

    max1 = max2 = a[0];
    min1 = min2 = a[0];

    for (i = 1; i < n; i++) {
        if (a[i] > max1) {
            max2 = max1;
            max1 = a[i];
        } else if (a[i] > max2 && a[i] != max1)
            max2 = a[i];

        if (a[i] < min1) {
            min2 = min1;
            min1 = a[i];
        } else if (a[i] < min2 && a[i] != min1)
            min2 = a[i];
    }

    printf("Maksimum kedua = %d\n", max2);
    printf("Minimum kedua = %d\n", min2);
}

void frekuensi(int a[], int n) {
    int cari, i, count = 0;
    printf("Masukkan bilangan: ");
    scanf("%d", &cari);

    for (i = 0; i < n; i++)
        if (a[i] == cari)
            count++;

    printf("Frekuensi %d = %d kali\n", cari, count);
}

void cariData(int a[], int n) {
    int cari, i, ketemu = 0;
    printf("Cari data: ");
    scanf("%d", &cari);

    for (i = 0; i < n; i++) {
        if (a[i] == cari) {
            printf("Data ditemukan di indeks %d\n", i);
            ketemu = 1;
        }
    }

    if (!ketemu)
        printf("Data tidak ditemukan\n");
}

void hapusData(int a[], int *n) {
    int hapus, i, j;
    printf("Data yang dihapus: ");
    scanf("%d", &hapus);

    for (i = 0; i < *n; i++) {
        if (a[i] == hapus) {
            for (j = i; j < *n - 1; j++)
                a[j] = a[j + 1];
            (*n)--;
            printf("Data berhasil dihapus\n");
            return;
        }
    }
    printf("Data tidak ditemukan\n");
}
