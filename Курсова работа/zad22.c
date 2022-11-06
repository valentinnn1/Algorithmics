#include <stdio.h>
#include<stdlib.h>

int main(){
    int n, br, dolni, gorni, count=0;
    printf("n=");
    scanf("%d", &n);

    int arr[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("[%d][%d]:", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    br=n+(n-2);

    for (int k=0; k<br/2; k++){
        dolni=0;
        gorni=0;
        for(int i=0, j=k; i<=k, j>=0; i++, j--){
            if(arr[i][j]!=0){
                gorni=1;
            }
            if(arr[(br/2)-i][(br/2)-j]!=0){
                dolni=1;
            }
        }
        if(dolni==0){
            count++;
        }
        if(gorni==0){
            count++;
        }
        printf("\n");
    }

    printf("broq na diagonalite s nulevi elementi, usporedni na vtorichniq e: %d", count);

    return 0;
}
