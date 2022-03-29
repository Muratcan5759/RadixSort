#include<stdio.h>
#include<stdlib.h>


int getMax(int dizi[], int n) {

    int mx = dizi[0];
    int i;
    for (i = 1; i < n; i++)
        if (dizi[i] > mx)
            mx = dizi[i];
    return mx;
}

void countingSort(int dizi[], int n, int exp) {

    int output[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(dizi[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(dizi[i] / exp) % 10] - 1] = dizi[i];
        count[(dizi[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        dizi[i] = output[i];
}


void radixsort(int dizi[], int n) {
    int m = getMax(dizi, n);

    int exp;
    for (exp = 1; m / exp > 0; exp *= 10)
        countingSort(dizi, n, exp);
}


void DosyayaYazdir(float dizi[], int n) {

    int i;
    FILE *dosya = fopen("Sonuc.txt", "w");
    for (i = 0; i < n; i++)
    {
        fprintf(dosya,"%f \n",dizi[i]);
    }
    fclose(dosya);
}


int main() {

    float dizi[100000];
    int i=0;
    FILE *dosya = fopen("100000likliste 4.txt","r");

    while(!feof(dosya)){

        fscanf(dosya,"%f",&dizi[i]);
        i=i+1;

    }
    fclose(dosya);

    int n = sizeof(dizi) / sizeof(dizi[0]);
    radixsort(dizi, n);
    DosyayaYazdir(dizi, n);


    printf("Islem Tamamlandi Sonuc.txt Dosyasina Yazdirildi");
    return 0;
}
