#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 2147483647;

int main(){
    int n;
    printf("enter array size : ");
    scanf("%d",&n);
    int arr[n], a, b;
    printf("enter array elements :\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter searching numbers : \n");
    printf("enter a = ");
    scanf("%d", &a);
    printf("enter b = ");
    scanf("%d", &b);

    int brr1[n], brr2[n];
    for(int i=0; i<n; i++)
    {
        brr1[i] = -1;
        brr2[i] = -1;
    }
    int x=0, y=0, min = INT_MAX;
    for(int i=0; i<n; i++)
    {
        if(arr[i] == a){
            brr1[x] = i;
            x++;
        }
        if(arr[i] == b){
            brr2[y] = i;
            y++;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(brr1[i] >= 0){
            for(int j=0; j<n; j++)
            {
                if(brr2[j] >=0){
                    if(min > abs(brr1[i] - brr2[j]))
                    {
                        min = abs(brr1[i] - brr2[j]);
                    }
                }
            }
        }
    }
        printf("min ==== %d\n\n",min);
        return 0;
}