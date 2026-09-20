#include<stdio.h>
int main(){
    int n, k=0;
    printf("enter array size : ");
    scanf("%d",&n);
    int arr[n],a,b;
    printf("enter array elements :\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=0; i<n; i++)
    {
        k = k^arr[i];
    }
    printf("element occuring odd times is : %d\n",k);
    return 0;
}

// OUTPUT : 
// enter array elements :
// 1 2 1 2 3
// element occuring odd times is : 3