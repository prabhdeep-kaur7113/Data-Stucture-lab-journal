#include<stdio.h>
int main(){
    int n;
    printf("enter array size : ");
    scanf("%d",&n);
    int arr[n], k, m=0, brr[n];
    printf("enter array elements :\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the no of times u want to roate the array : ");
    scanf("%d",&k);
    while(k >= n){
        k -= n;
    }
    for(int i=0; i<n; i++)
    {
        if(k < n){
            brr[i] = arr[k];
            k++;
        }
        else{
            brr[i] = arr[m];
            m++;
        }
    }
    printf("rotated array is \n");
    for(int i=0; i<n; i++)
    {
        arr[i] = brr[i];
        printf("%d\t",arr[i]);
    }
    return 0;
}