/*
 * Sachin Kumar Jha
 * Sequence Sum
 * Homework 04
*/

#include <stdio.h>
#include <stdlib.h>

int * readInput ( int * dataNr )
{
    int * data = (int *) malloc(sizeof(int) * 2000);
    int index = 0;

    while (scanf("%d", &data[index]) == 1){
        index++;
    }
    if (!feof ( stdin )){
        free ( data );
        return NULL;
    }
    if(index >= 2000){
        printf("Invalid input.\n");
        exit (1);
    }

    (*dataNr) = index;
    return data;
}

int find_pair(int sum[], int size){
    int value;
    int count = 0;

    for(int i = 0; i < size-1; ++i){
        value = sum[i];
        for(int j = i+1; j < size; ++j){
            if(value == sum[j]){
                count++;
            }
        }
    }
    return count;
}

void array_sum(int arr[], int size, int sum[]){
    int index = -1;
    int value;

    for (int i = 0; i < size-1; i++) {
        value =  arr[i];
        for (int j = i+1; j < size; j++) {
            value +=  arr[j];
            sum[++index] = value;
        }
    }
}

int main() {

    int pairs;
    int size_arr = 0;
    int size_sequence;

    printf("Input sequence:\n");
    int* my_arr = readInput (&size_sequence);

    if (my_arr == NULL) {
        printf ( "Invalid input.\n" );
        return 1;
    }

    if (size_sequence >= 1) {
        for (int i = 0; i < size_sequence; ++i) {
            size_arr += i;
        }
        int * sum_arr;
        sum_arr = (int*) calloc(size_arr,sizeof(int));

        array_sum(my_arr, size_sequence, sum_arr);
        pairs = find_pair(sum_arr, size_arr);

        printf("Total pairs: %d\n", pairs);
        free (sum_arr);
    }

    else{
        printf("Invalid input.\n");
    }
    free (my_arr);

    return 0;
}
