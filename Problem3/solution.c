/*
 * Sachin Kumar Jha
 * Parking
 * BIE-PA1
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 11

typedef struct parking {
    int value;
    char rz[MAX_LENGTH];
}Parking;

void freePark(Parking ** array,  int x){
    for(int i = 0; i < x; i++){
        free(array[i]);
    }
    free(array);
}

int main(){

    int x,y;

    printf("Size:\n");

    if(scanf(" %d %d", &x, &y) != 2 || x < 0 || y < 0){
        printf("Invalid input.\n");
        return 1;
    }

    Parking ** carData = (Parking **) malloc(x * sizeof(Parking *));

    for(int i = 0; i < x; i++){
        carData[i] = (Parking *) malloc( y * sizeof(Parking));
    }

    printf("Requirements :\n");

    int xPos, yPos, err;
    char operator;
    char buffer[MAX_LENGTH];

    while((err = scanf(" %c",&operator)) == 1){

        if(operator != '+' && operator != '-' ){
            printf("Invalid input.\n");
            freePark(carData, x);
            return 1;
        }
        if(operator == '+'){
            if(scanf(" %d %d %10s",&xPos, &yPos, buffer) != 3 || xPos >= x || yPos >= y){
                printf("Invalid input.\n");
                freePark(carData, x);
                return 1;
            }
            if(carData[xPos][yPos].value == 1){
                printf("Occupied by %s.\n",carData[xPos][yPos].rz);
            }
            else{
                strcpy(carData[xPos][yPos].rz, buffer);
                carData[xPos][yPos].value = 1;
                printf("Ok.\n");
            }
        }
        if(operator == '-'){
            int found = 0;
            if(scanf(" %s",buffer) != 1){
                printf("Invalid input.\n");
                freePark(carData,x);
                return 1;
            }
            for(int i = 0; i < x; i++){
                if(found == 1){
                    break;
                }
                for(int j = 0; j < y; j++){
                    if(strcmp(carData[i][j].rz, buffer) == 0){
                        carData[i][j].value = 0;
                        strcpy(carData[i][j].rz, "");
                        found = 1;
                        break;
                    }
                }
            }
            if(found == 1){
                printf("Ok.\n");
            }
            else{
                printf("Not Found.\n");
            }
        }
    }
    if(err != EOF){
        printf("Invalid input.\n");
        freePark(carData, x);
        return 0;
    }
    return 0;
}
