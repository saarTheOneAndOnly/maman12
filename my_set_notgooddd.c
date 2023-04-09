void get_set(int **copy, int *sizeOfCopy, int **ptr, int *size){
    int input;
    int i=0;
    int j=0;
    int exist = 0;
    /*int flag;*/
    /**ptr = (int*)realloc(*ptr, sizeof(int));
    if (*ptr == NULL){
        printf("allocation failure\n");
        exit(1);
    } */

    /*init first input to the first pointer*/
    /*flag = scanf("%d", &input);*/

    while (*size <= *sizeOfCopy){
        /* we will use this while loop to check if an integer already exists in ptr array*/
        for (i = 0; i < *size; i++){
            if ((*ptr)[i] == *(copy)[j]){
                exist = 1;
                break;
            }
        }

        if (exist == 0){
                *ptr = (int*)realloc(*ptr, sizeof(int)*(*size + ENLARGE_SIZE));
                if (*ptr == NULL){
                    printf("RE-allocation failure\n");
                    exit(1);
                }
                (*ptr)[*size] = *(copy)[j];
                (*size)++;
            }
            else exist = 0;
        j++;

    }
}

void print_set(int *ptr, int size) {
    int i;    
    for (i = 0; i < size; i++) {
        printf("element number %d IS %d\n", (i+1), ptr[i]);   
    }
    printf("-----END OF ARRAY-----\n");
}