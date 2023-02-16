/*
 * Sachin Kumar Jha
 * Unique visitors
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

typedef struct Raw {
    int raw;
    char checkId;
} Raw;

typedef struct Object {
    int value;
    int occurs;
} Object;

void addNumber(Raw rawArr[], int *rawLen, Object dataArr[], int *dataLen, int data){

    rawArr[*rawLen].raw = data;
    rawArr[*rawLen].checkId = 0;
    (*rawLen)++;

    for(int i = 0; i < *dataLen; i++){
        if(dataArr[i].value == data){
            dataArr[i].occurs++;
            printf("visit #%d\n",dataArr[i].occurs);
            return;
        }
    }
    dataArr[*dataLen].value = data;
    dataArr[*dataLen].occurs = 1;
    (*dataLen)++;

    printf("> first visit\n");
}

int main(){
    Object dataArr[MAX_LENGTH];
    Raw rawArr[MAX_LENGTH];
    int dataLen = 0;
    int rawLen = 0;

    printf("Requests:\n");
    int end;
    int data;
    int start;
    char operator;
    char curId = 0;

    while (scanf("%c", &operator) != EOF) {
        if (operator == '+') {
            scanf("%d", &data);
            addNumber(rawArr, &rawLen, dataArr, &dataLen, data);
        }
        else if(operator == '?') {
            scanf("%d %d", &start, &end);
            int all = end - start + 1;
            int unique = all;
            curId++;

            for(int i = start; i <= end; i++){
                if (rawArr[i].checkId == curId) {
                    continue;
                }
                for(int j = i + 1; j <= end; j++){
                    if(rawArr[i].raw == rawArr[j].raw){
                        unique--;
                        rawArr[j].checkId = curId;
                    }
                }
            }
            printf("> %d / %d\n", unique, all);
        }
    }

    return 0;
}
