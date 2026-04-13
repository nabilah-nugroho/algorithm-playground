#include <stdio.h>

#define serem 10
int m, n;
int hantu[serem];
int angka[100];

void tuker(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int tungs(int angka[], int low, int high) {
    int pivot = angka[high]; 
    int i = (low - 1); 

    for (int j = low; j < high; j++) {
        // asc
        if (angka[j] < pivot) {
            i++;
            tuker(&angka[i], &angka[j]);
        }
    }
    tuker(&angka[i + 1], &angka[high]);
    return (i + 1);
}

void quickSort(int angka[], int low, int high) {
    if (low < high) {
        int pi = tungs(angka, low, high);

        quickSort(angka, low, pi - 1);  // bagian kiri pivot
        quickSort(angka, pi + 1, high); // bagian kanan pivot
    }
}

void cetakQS(int angka[], int n){
    printf("\nhasil sorting quick sort (asc): \n");
    for(int i = 0; i < n; i++){
        printf("%d ", angka[i]);
    }
    printf("\n");
}

int hantuIni(int x){
    for(int i=0; i<m; i++){
        if(x==hantu[i])return 1;
    }
    return 0;
}

void bubbleSort(int angka[], int size, int hantu[]){
    int temp, i, j;
    for(i=0; i<size-1; i++){
        for(j=0; j<size-1-i; j++){
            if(angka[j]<angka[j+1]){
                tuker(&angka[j], &angka[j+1]);    
            }
        }
    }
    printf("hasil sorting bubble (desc+hantu): \n");
    for(int i = 0; i < n; i++){
        if(hantuIni(angka[i])){
            printf("  ");
        }
        else{
            printf("%d ", angka[i]);
        }
    }
}

void input() {
    printf("masukkan total angka hantu yang ada (m): "); scanf("%d", &m);
    printf("masukkan total angka keseluruhan (n): "); scanf("%d", &n);
    printf("\n");

    if (m < 10 && m > 0 && n <= 100 && n > 0 && m < n){
        for(int i = 0; i < m; i++){
            printf("angka hantu ke-%d: ", i+1); scanf("%d", &hantu[i]);
        }
        for(int i = 0; i < n; i++){
            printf("angka ke-%d: ", i+1); scanf("%d", &angka[i]);
        }
        quickSort(angka, 0, n-1);
        cetakQS(angka, n);
        bubbleSort(angka, n, hantu);
        }
    else {
        printf("tidak valid, silakan coba kembali");
    }
}

void inputHantu(){
}

int main() {
    input();
    return 0;
}   