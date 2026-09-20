#include<stdio.h>

void rotate(int n,int arr[n][n], int start, int end){
    int i=start , j=start+1;
    int temp = arr[start][start], new_temp;
    while(i!=start || j!=start){
        new_temp = arr[i][j];
        arr[i][j] = temp;
        temp = new_temp;
        if( i== start && j<end-1)
            j++;
        else if(j ==start && i>start)
            i--;
        else if(i==end-1 && j>start)  
            j--;
        else if(j==end-1 && i<end-1)
            i++;
    }
    arr[i][j] = temp;
}

int main(){
    int n;
    printf("enter the array size : ");
    scanf("%d",&n);
    int arr[n][n], start=0, end = n;
    printf("enter the elements : \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0; i<n/2; i++){
        rotate(n,arr, start,end);
        start++;
        end--;
    }
    printf("rotated array is  : \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*
OUTPUT : 
enter the array size : 4
enter the elements : 
1 2 3 4 
5 6 7 8
2 4 0 1
9 0 5 2
rotated array is  : 
5 1 2 3 
2 4 6 4 
9 0 7 8 
0 5 2 1 
*/