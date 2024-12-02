/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int rows = matrixSize;
    int cols = *matrixColSize;

    // Set the return size
    *returnSize = cols;

    // Allocate memory for returnColumnSizes
    *returnColumnSizes = (int*)malloc(cols * sizeof(int));

    // Allocate memory for the transposed matrix
    int** transposed = (int**)malloc(cols * sizeof(int*));
    for (int i = 0; i < cols; i++) {
        transposed[i] = (int*)malloc(rows * sizeof(int));
        (*returnColumnSizes)[i] = rows; // Each row of the transposed matrix will have `rows` elements
    }

    // Transpose the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}
