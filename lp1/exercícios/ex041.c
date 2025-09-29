#include <stdio.h>

int main() {
    int arr[] = {5, 15, 25, 35, 45};
    int *ptr1 = arr;
    int *ptr2 = &arr[4];

    printf("%d\n", *ptr2 - *ptr1);
    printf("%d\n", ptr2 - ptr1);

    return 0;

}