#include <stdio.h>

#define MAX 10
int m, n;
int hantu[MAX];
int angka[100];

void quickSort(){

}

void bubbleSort(int angka[], int size){
    int temp, i, j;
    for(i=0; i<size-1; i++){
        for(j=0; j<size-1-i; j++){
            if(angka[j]<angka[j+1]){
                temp= angka[j]; angka[j]=
                angka[j+1];angka[j+1]= temp;      
            }
        }
    }
    printf("hasil sorting: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", angka[i]);

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
        bubbleSort(angka, n);
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