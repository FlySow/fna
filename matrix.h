#ifndef __MATRIX__
#define __MATRIX__

typedef struct s_matrix {
	int rows;
	int lines;
	double** mat;
} matrix;

matrix mcreate(int lines, introws, bool random);

matrix mfree(matrix A);

matrix mprint(matrix A);

matrix madd(matrix a, matrix B);

matrix mmul(matrix A, matrix B);

matrix meval(matrix A, double (*func)(double));

#endif
