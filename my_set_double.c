#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ENLARGE_SIZE 1
void get_set(double *copy, int sizeOfCopy, int **ptr, int *size);
void print_set(int *ptr, int size);

int main() {
    int sizeOfCopy = 0;
    double *inputCopy = NULL;
    double input;
    int flag;
    int i=0;

    int size = 0;
    int *result = NULL;

    printf("please enter numbers as input\n");
    flag = scanf("%lf", &input);
    
    while (flag!=EOF){
        inputCopy = (double*)realloc(inputCopy, sizeof(double)*(sizeOfCopy+ENLARGE_SIZE));
        if (inputCopy == NULL){
            printf("allocation failure\n");
            exit(1);
        }
        inputCopy[i] = input;
        sizeOfCopy++;
        i++;
        flag = scanf("%lf", &input);
    }
    printf("the numbers that were given as input are:\n");
    for(i=0;i<sizeOfCopy;i++){
        printf("%f,  " ,inputCopy[i]);
    }
    printf("\n");

    get_set(inputCopy, sizeOfCopy, &result, &size);
    print_set(result, size);
    free(result);
    free(inputCopy);
    printf("-----END OF MAIN-----\n");
    return 0;
}

void get_set(double *copy, int sizeOfCopy, int **ptr, int *size){
    int i=0;
    int j=0;
    int exist = 0;

    *ptr = (int*)realloc(*ptr, sizeof(int));
    if (*ptr == NULL){
        printf("allocation failure\n");
        exit(1);
    } 
    
    /*init first input to the first pointer*/
 
    while(j<sizeOfCopy){
        /* we will use this while loop to check if an integer already exists in ptr array*/
        for (i = 0; i < *size; i++)
            if ((*ptr)[i] == copy[j]){
                exist = 1;
                break;
            }
        

        if (exist == 0){
                *ptr = (int*)realloc(*ptr, sizeof(int)*(*size + ENLARGE_SIZE));
                if (*ptr == NULL){
                    printf("RE-allocation failure\n");
                    exit(1);
                }
                (*ptr)[*size] = copy[j];
                (*size)++;
            }
            else exist = 0;
        j++;

    }
}

void print_set(int *ptr, int size) {
    int i; 
    printf("this is the order of the set:\n"); 
    for (i = 0; i < size; i++) {
        printf("element number %d IS %d\n", (i+1), ptr[i]);   
    }
    printf("-----END OF ARRAY-----\n");
}
