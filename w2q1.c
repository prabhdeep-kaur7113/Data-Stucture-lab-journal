#include <stdio.h>
int main()
{
    int n, key, m, flag = 0;
    printf("enter the size of array :\n");
    printf("row : ");
    scanf("%d", &n);
    printf("coloumn : ");
    scanf("%d", &m);
    int arr[n][m];
    printf("enter the elements of array : \n");
    for (int i = 0; i < n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("enter the key element to search : ");
    scanf("%d", &key);
    int i = 0, j = n - 1;
    while (i <= n - 1 && j >= 0)
    {
        if (arr[i][j] == key)
        {
            flag = 1;
            printf("element found at index arr[%d][%d]", i, j);
            break;
        }
        if (key < arr[i][j])
            j--;
        else
            i++;
    }
    if (!flag)
    {
        printf("element not present in the array \n");
    }
    return 0;
}