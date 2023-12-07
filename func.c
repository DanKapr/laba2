#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include <string.h>
void write(sobaka *arr, int n) {
    if (n <= 0)
        return;
    FILE *f = fopen("file.txt", "w");
    if (!f)
        return;
    fprintf(f, "%d\n", n);
    for (int i = 0; i < n; i++)
        fprintf(f, "%s %s %s %d\n", arr[i].name, arr[i].poroda, arr[i].pol, arr[i].age);
    fclose(f);
}
void read(sobaka **arr, int *n) {
    FILE *f = fopen("file.txt", "r");
    if (!f)
        return;
    if (fscanf(f, "%d", n) != 1)
        return;
    if (*n < 0)
        return;
    *arr = (sobaka *) calloc(*n, sizeof(sobaka));
    for (int i = 0; i < *n; i++)
        fscanf(f, "%s %s %s %d", (*arr)[i].name, (*arr)[i].poroda, (*arr)[i].pol, &(*arr)[i].age);
    fclose(f);
}
void create(sobaka **arr, int *n) {
    printf("n=");
    scanf("%d", n);
    if (*n <= 0)
        return;
    *arr = (sobaka *) calloc(*n, sizeof(sobaka));
    for (int i = 0; i < *n; i++) {
        printf("name=");
        scanf("%s", (*arr)[i].name);
        int nameLength = strlen((*arr)[i].name);
        if (nameLength > 40) {
            printf("Ай-я-яй. Так делать не надо. Попробуй ещё раз.\n");
            i--;
            continue;
        }
        printf("poroda=");
        scanf("%s", (*arr)[i].poroda);
        int porodaLength = strlen((*arr)[i].poroda);
        if (porodaLength > 40) {
            printf("Ай-я-яй. Так делать не надо. Попробуй ещё раз.\n");
            i--;
            continue;
        }
        printf("pol=");
        scanf("%s", (*arr)[i].pol);
        int polLength = strlen((*arr)[i].pol);
        if (polLength > 40) {
            printf("Ай-я-яй. Так делать не надо. Попробуй ещё раз.\n");
            i--;
            continue;
        }
        printf("age=");
        scanf("%d", &(*arr)[i].age);
        if ((*arr)[i].age < 0) {
            printf("Ай-я-яй. Так делать не надо. Попробуй ещё раз.\n");
            i--;
            continue;
        }
    }
}
void search(sobaka *arr, int n, char *name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            printf("Собака найдена по индеку: %d\n", i);
            printf("Name: %s, Poroda: %s, Pol: %s, Age: %d\n", arr[i].name, arr[i].poroda, arr[i].pol, arr[i].age);
            return;
        }
    }
    printf("Такой собаки нет.\n", name);
}



























