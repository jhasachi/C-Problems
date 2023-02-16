/*
 * Sachin Kumar Jha
 * BestSeller
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCT 100
#define MAX_NAME_LENGTH 100

typedef struct Object {
    char name[MAX_NAME_LENGTH];
    int sold;
} Object;

void addProducts(Object products[], int *objectCount, char name[]){

    for(int i = 0; i < *objectCount; i++){
        if(strcmp(products[i].name, name) == 0){
            products[i].sold++;
            return;
        }
    }
    strcpy(products[*objectCount].name, name);
    products[*objectCount].sold = 1;
    (*objectCount)++;
}

int compareProducts(const void *a, const void *b) {
    Object *ObjectA = (Object *)a;
    Object *ObjectB = (Object *)b;
    return ObjectB->sold - ObjectA->sold;
}

void printBestSellingProducts(Object products[], int objectCount, int value){
    qsort(products, objectCount, sizeof(Object), compareProducts);

    int totalSold = 0, sameSold, nextDiff = 0;
    for (int i = 0; i < value && i < objectCount; i++) {
        if (i == nextDiff) {
            sameSold = 0;
            while (i != value && products[i].sold == products[i + ++sameSold].sold);
            nextDiff = i + sameSold;
        }
        if (sameSold == 1) {
            printf("%d. %s, %dx\n",(i+1), products[i].name, products[i].sold);
        }
        else {
            printf("%d.-%d. %s, %dx\n", nextDiff - sameSold + 1, nextDiff, products[i].name, products[i].sold);
        }
        totalSold += products[i].sold;
    }
    printf("Top sellers: sold %d items\n",totalSold);

}


int main() {
    Object products[MAX_PRODUCT];
    int objectCount = 0;
    int value;

    printf("Top N:\n");
    scanf("%d",&value);

    printf("Requests:\n");
    char name[MAX_NAME_LENGTH];
    char operators;

    while (scanf("%c", &operators) != EOF) {
        if(operators == '+'){
            scanf("%s",name);
            addProducts(products, &objectCount, name);
        }
        else if (operators == '#'){
            printBestSellingProducts(products, objectCount,value);
        }
        else if (operators == '?'){
            int totalSold = 0;
            for (int i = 0; i < value; i++){
                totalSold += products[i].sold;
            }
            printf("Top sellers: sold %d items\n",totalSold);
        }
    }

    return 0;
}
