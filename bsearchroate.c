#include <stdio.h>

void rotatebyone(int arr[], int n)
{
    int temp = arr[0];
    int i;
    for (i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[i] = temp;
}
int min(int arr[], int n)
{
    int i, min1 = arr[0], index;
    for (i = 1; i < n; i++)
    {
        if (min1 > arr[i])
        {
            min1 = arr[i];
            index = i;
        }
    }
    return index;
}

void rotate(int arr[], int n, int d)
{
    for (int i = 0; i < d; i++)
        rotatebyone(arr, n);
}

int binarysearch(int arr[], int l, int h, int key)
{
    int mid;
    if (l <= h)
    {
        mid = l + h / 2;
        if (key == arr[mid])
            return mid;

        else if (key < arr[mid])
            return binarysearch(arr, l, mid - 1, key);

        else
            return binarysearch(arr, mid + 1, h, key);
    }
}
void bsearchrotate(int arr[], int key, int n)
{

    int index;
    int x, y;
    index = min(arr,n);
    x = binarysearch(arr, 0, index - 1, key);
    y = binarysearch(arr, index, n - 1, key);
    printf("%d",x);
    printf("%d",y);
    // if (x < 0 && y < 0)
    //     printf("np elements found");
    // if (x > 0)
    //     printf("%d", x);

    // if (y > 0)
    //     printf("%d", y);
}



void print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    int arr[] = {4, 5, 6, 7, 1, 2, 3};
    n = sizeof(arr) / sizeof(arr[0]);
    // rotate(arr,n,3);
    // print(arr,n);
    bsearchrotate(arr, 6, n);

    return 0;
}