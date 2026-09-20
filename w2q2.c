#include<stdio.h>
int main(){
    int n, m;
    printf("enter the size of array : \n");
    printf("number of rows : ");
    scanf("%d",&n);
    printf("number of columns : ");
    scanf("%d",&m);
    int arr[n][m];
    printf("enter the binary numbers in array : \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int i = 0, j = m-1, ind = -1;
    while(i<n){
        if(arr[i][j] == 1){
            ind = i+1;
            j--;
        }
        else if(arr[i][j] == 0){
            i++;
        }    
        if(j<0){
            j=0;
            i++;
        }
    }
    printf("maximum 1's in array is in %d row\n", ind);
    return 0;
}