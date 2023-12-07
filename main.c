#include <stdio.h>
#include <stdlib.h>
#include "func.h"
int main() {
    sobaka *arr = NULL;
    int n = 0;
    int stop = 0;
    while (stop != 1) {
        int key;
        printf("1-create, 2-read, 3-printf, 4-search\n");
        scanf("%d", &key);
        switch (key) {
            case 1:
                create(&arr, &n);
                if (arr)
                    write(arr, n);
                break;
            case 2:
                read(&arr, &n);
                if (!arr)
                    printf("read error\n");
                else
                    printf("loaded %d\n", n);
                break;
            case 3:
                for (int i = 0; i < n; i++)
                    printf("%s %d\n", arr[i].name, arr[i].age);
                break;
            case 4:
                char searchName[50];
                printf("Введите имя собаки, которкую нужно найти: ");
                scanf("%s", searchName);
                search(arr, n, searchName);
                break;
            default:
                stop = 1;
                break;
        }
    }
    if (arr)
        free(arr);
    return 0;
}

