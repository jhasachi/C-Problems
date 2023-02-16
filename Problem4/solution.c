/*
 * Sachin Kumar Jha
 * Homework 02
 * 2D Plane
 * BIE-PA1
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 10e-10

double check_distance(double a1, double a2, double b1, double b2, double c1, double c2){

    long double distance1, distance2, distance3;
    long double x_difference1, y_difference1, x_difference2, y_difference2, x_difference3, y_difference3;

    x_difference1 = fabs(a1 - b1) * fabs(a1 - b1);
    y_difference1 = fabs(a2 - b2) * fabs(a2- b2);

    x_difference2 = fabs(b1 - c1) * fabs(b1 - c1);
    y_difference2 = fabs(b2 - c2) * fabs(b2- c2);

    x_difference3 = fabs(a1 - c1) * fabs(a1 - c1);
    y_difference3 = fabs(a2 - c2) * fabs(a2- c2);

    distance1 = sqrt(x_difference1 + y_difference1);
    distance2 = sqrt(x_difference2 + y_difference2);
    distance3 = sqrt(x_difference3 + y_difference3);

    if((fabs(distance3 - distance2 - distance1) <= fabs(distance3)*(EPSILON)) ||
       (fabs(distance2 - distance1 - distance3) <= fabs(distance2)*(EPSILON)) ||
       (fabs(distance1 - distance2 - distance3) <= fabs(distance1)*(EPSILON)))
    {
        if((distance1 > distance2) && (distance1 > distance3)){
                printf("There exists a line connecting all three points.\n");
                printf("Point C is in the middle.\n");
                return 0;
        }
        if((distance2 > distance3) && (distance2 > distance1)){
                printf("There exists a line connecting all three points.\n");
                printf("Point A is in the middle.\n");
                return 0;
        }
        if((distance3 > distance2) && (distance3 > distance1)){
                printf("There exists a line connecting all three points.\n");
                printf("Point B is in the middle.\n");
                return 0;
        }
    }
    else{
        printf("No line connects all points.\n");
        exit(0);
    }

    return 0;
}

int main() {
    double a1, a2, b1, b2, c1, c2;

    printf("Point A:\n");
    if(scanf("%lf %lf",&a1, &a2) != 2){
        printf("Invalid input.\n");
        return 0;
    }

    printf("Point B:\n");
    if(scanf("%lf %lf",&b1, &b2) != 2){
        printf("Invalid input.\n");
        return 0;
    }

    printf("Point C:\n");
    if(scanf("%lf %lf",&c1, &c2) != 2){
        printf("Invalid input.\n");
        return 0;
    }

    if((a1==c1 && a2==c2) || (a1 == b1 && a2 == b2) || (b1 == c1 && b2 == c2)){
        printf("Some points are identical.\n");
        return 0;
    }

    check_distance(a1, a2, b1, b2, c1, c2);

    return 0;
}

