#include <stdio.h>
int main() {
    int arr[10];
    int n, i, j, temp;
    printf("enter the number of elements : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("enter the elements : ");
        scanf("%d",&arr[i]);
    }
    
   

    for(i=0;i<n;i++)
    {
        for(j = 0; j < n; j++)
        {
            if(arr[i] < arr[j])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
            else
            {
                continue;
            }
        }
    }
    
     for(i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

}
