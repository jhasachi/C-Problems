/**
 * Sachin Kumar Jha
 * Homework 05
 * Airplane
 */

/*---------------------------------------------------------------------------*/

#define EPSILON 10e-10

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * Find the smallest distance.
 * Find number of pair having same distance as smallest distance.
 * Find the flight pair detail having the smallest distance.
 *
 * The implementation uses dynamic memory allocation. The program, is
 * divided into reasonably short functions.
 */

/*---------------------------------------------------------------------------*/

/**
 * Struct content used for storing the different type of data.
 *
 * @param fName used for storing the flight name details.
 * @param xAxis used for storing the flight x co-ordinates.
 * @param yAxis used for storing the flight y co-ordinates.
**/

typedef struct content {
    char fName[200];
    double xAxis;
    double yAxis;
} content;
/*---------------------------------------------------------------------------*/

/**
 * Function reads input values into a dynamically allocated struct array.
 * Read Input function use for reading the data and stores input in array.
 *
 * The implementation uses dynamic memory allocation malloc() and realloc()
 * standard library function.
 *
 * new array size increased by 100 elements / * 1.5
 *
 * Use realloc to increase the size of the array. This function either
 * just increases the memory blocks (if possible), or creates a new (bigger) array
 * and copies the content. Return value is the pointer to the extended/newly allocated
 * array.
 *
 * @param dataLen number of elements read.
 * @return pointer to the dynamically allocated array.
 */

content *readInput(int *dataLen) {
    int arrLen = 0;
    int arrMax = 100;
    content *dataArr;

    dataArr = (content *) malloc(arrMax * sizeof(*dataArr));
    while (scanf("%lf,%lf: %199s", &dataArr[arrLen].xAxis, &dataArr[arrLen].yAxis, dataArr[arrLen].fName) == 3) {
        if (arrLen + 1 == arrMax) {
            if (arrMax < 1000) {
                arrMax += 100;
            } else {
                arrMax += arrMax / 2;
            }
            dataArr = (content *) realloc(dataArr, arrMax * sizeof(*dataArr));
        }
        arrLen++;
    }
    if (!feof(stdin)) {
        free(dataArr);
        return NULL;
    }
    *dataLen = arrLen;
    return dataArr;
}
/*---------------------------------------------------------------------------*/

/**
 * Stores distance function used for storing distance between two flight co-ordinates.
 *
 * This distance is calculated for each flight using the co-ordinates stored
 * in the data array.
 *
 * After calculating the distance, stores distance in distance array.
 *
 * @param dataArr[] used for taking stored co-ordinates Inputs of the flights.
 * @param dataLen number of element in the data array.
 * @param disArr[] used to stores all distance of two flight.
 * @return void
 */

void storeDistance(content dataArr[], int dataLen, double disArr[]) {
    int order = 0;
    double distance = 0;

    for (int i = 0; i < (dataLen - 1); i++) {
        for (int j = i; j + 1 < dataLen; j++) {
            distance = sqrt(((dataArr[i].xAxis - dataArr[j + 1].xAxis) * (dataArr[i].xAxis - dataArr[j + 1].xAxis))
                            + ((dataArr[i].yAxis - dataArr[j + 1].yAxis) * (dataArr[i].yAxis - dataArr[j + 1].yAxis)));
            disArr[order++] = distance;
        }
    }
}
/*---------------------------------------------------------------------------*/

/**
 * Find Minimum distance and no. of pair function used for finding smallest distance and how many flight having same
 * smallest distance.
 *
 * Compare Data used for comparing all possible distance and find the smallest one.
 *
 * After finding smallest distance, compare with other possible distance to find how many having same smallest distance.
 *
 * @param disArr[] used for taking stored distance of the flights.
 * @param disLen number of element in the distance array.
 * @return compare data used for returning the smallest distance.
 */

double find_MinDistance_And_NumOfPairs(double disArr[], int disLen) {
    double compareData = 0;
    int pairs = 0;
    int i = 0;

    compareData = disArr[i];
    for (int j = 0; j < disLen - 1; ++j) {
        if (compareData > disArr[j + 1]) {
            compareData = disArr[j + 1];
        }
    }
    printf("Minimum airplane distance: %lf\n", compareData);

    for (int k = 0; k < disLen; k++) {
        if (disArr[k] - compareData <= EPSILON * disArr[k] * compareData) {
            pairs++;
        }
    }
    printf("Pairs found: %d\n", pairs);
    return compareData;
}
/*---------------------------------------------------------------------------*/

/**
 * Find flight pair function used for finding all possible flight name having same smallest distance.
 *
 * Data store the smallest distance flight.
 * Data used for comparing with the other possible distance and find the smallest distance pair of flight.
 *
 * @param disArr[] used for taking stored distance of the flights.
 * @param dataLen number of element in the data array.
 * @param data stores the smallest distance.
 * @return void
 */

void find_FlightPair(content dataArr[], int dataLen, double data) {
    double distance = 0;

    for (int i = 0; i < (dataLen - 1); i++) {
        for (int j = i; j + 1 < dataLen; j++) {
            distance = sqrt(((dataArr[i].xAxis - dataArr[j + 1].xAxis) * (dataArr[i].xAxis - dataArr[j + 1].xAxis))
                            + ((dataArr[i].yAxis - dataArr[j + 1].yAxis) * (dataArr[i].yAxis - dataArr[j + 1].yAxis)));
            if (distance - data <= EPSILON * distance * data) {
                printf("%.199s - %.199s\n", dataArr[i].fName, dataArr[j + 1].fName);
            }
        }
    }
}
/*---------------------------------------------------------------------------*/

/**
 * dataArr - dynamically allocated array.
 * dataLen - number of elements in the dataArr.
 * disLen - number of elements in the disArr.
 *
 * the dataArr is empty at the beginning
 * used calloc for assigning the number of element in disArr
 *
 */

int main() {
    int dataLen = 0;
    content *dataArr;
    int disLen = 0;

    printf("Plane coordinates:\n");
    dataArr = readInput(&dataLen);

    if (dataArr == NULL) {
        free(dataArr);
        printf("Invalid input.\n");
        return 1;
    }
    if (dataLen >= 2) {
        double *disArr;
        double shortDistance;

        for (int i = 0; i < dataLen; ++i) {
            disLen += i;
        }
        disArr = (double *) calloc(disLen, sizeof(double));

        storeDistance(dataArr, dataLen, disArr);
        shortDistance = find_MinDistance_And_NumOfPairs(disArr, disLen);
        find_FlightPair(dataArr, dataLen, shortDistance);

        free(disArr);
        free(dataArr);
    } else {
        free(dataArr);
        printf("Invalid input.\n");
        return 1;
    }
    return 0;
}
/*---------------------------------------------------------------------------*/


