void allocateMatrix(int ***matrix, int row, int col) {
    int i;
    if ((*matrix = (int **)malloc(row * sizeof(int *))) == NULL) {
        perror("There has been an error");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < row; ++i) {
        if ((*matrix[i] = (int *)malloc(col * sizeof(int))) == NULL) {
            perror("There has been an error");
            exit(EXIT_FAILURE);
        }
    }
}


You need to change

if((*matrix[i] = (int*)malloc(col * sizeof(int))) == NULL)
to

if(((*matrix)[i] = (int*)malloc(col * sizeof(int))) == NULL)

//  ^       ^
Prior to utilizing the array subscript, it is necessary to dereference  matrix  .  *matrix[i]  is identical in meaning to  *(matrix[i])  .
Solution 2:
The issue lies with the precedence of operators. Within the context given, this is the concern.
if ((*matrix[i] = (int*)malloc( ... ))