#include <stdio.h>

#define serem 10
int m, n;
int hantu[serem];
int angka[100];

void quickSort(int angka[], int size){
    int temp, i, j;
 //???????masi salah?????????

    printf("\n");
    printf("hasil soring quick asc: \n");
    for(int i=0; i<n; i++){
        printf("%d ", angka[i]);
    }
}

int hantuIni(int target[serem]){
    for(int i=0; i<m; i++){
        if(target[i]==hantu[i])return 1;
    }
    return 0;
}

int bubbleSort(int angka[], int size, int hantu[]){
    int temp, i, j;
    for(i=0; i<size-1; i++){
        for(j=0; j<size-1-i; j++){
            if(angka[j]<angka[j+1]){
                temp= angka[j]; angka[j]=
                angka[j+1];angka[j+1]= temp;      
            }
        }
    }
    printf("hasil sorting bubble desc: \n");
    for(int i = 0; i < n; i++){
        if(i == hantuIni(hantu[i])){
            printf("  ");
        }
        else{
            printf("%d ", angka[i]);
        }
    }
}

void input() {
    printf("masukkan angka m dan n: ");
    scanf("%d %d", &m, &n);

    if (m < 10 && m > 0 && n <= 100 && n > 0 && m < n){
        for(int i = 0; i < m; i++){
            printf("angka hantu ke-%d: ", i+1); scanf("%d", &hantu[i]);
        }
        for(int i = 0; i < n; i++){
            printf("angka ke-%d: ", i+1); scanf("%d", &angka[i]);
        }
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