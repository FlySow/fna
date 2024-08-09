#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include <matrix.h>


matrix mcreate(int lines, int rows, bool random) {
	assert(lines >= 1 && rows >= 1);
	double** mat = malloc(sizeof(double*)*rows);
	for(int i = 0; i < rows; i++) {
		mat[i] = malloc(sizeof(double)*lines);
		for(int j = 0; j < lines; j++) {
			if(random) mat[i][j] = 2*((double) rand())/RAND_MAX-1;
			else mat[i][j] = 0;
		}
	}
	return (matrix) {rows: rows, lines: lines, mat: mat};
}


matrix mfree(matrix A) {
	for(int i = 0; i < A.rows; i++)
		free(A.mat[i]);
	free(A.mat);
}


void mprint(matrix A) {
	for(int i = 0; i < A.lines; i++) {
		printf("|");
		for(int j = 0; j < A.rows-1; j++) {
			if(A.mat[j][i] < 0) printf("%lf ", A.mat[j][i]);
			else printf(" %lf ", A.mat[j][i]);
		}
		if(A.mat[A.rows-1][i] < 0) printf("%lf|\n", A.mat[A.rows-1][i]);
		else printf(" %lf|\n", A.mat[A.rows-1][i]);
	}
}


matrix madd(matrix A, matrix B) {
	assert(A.mat != NULL && A.mat[0] != NULL && A.rows == B.rows && A.lines == B.lines);
	
	double** mat = malloc(sizeof(double*)*A.rows);
	for(int i = 0; i < A.rows; i++) {
		mat[i] = malloc(sizeof(double)*A.lines);
		for(int j = 0; j < A.lines; j++)
			mat[i][j] = A.mat[i][j] + B.mat[i][j];
	}
	return (matrix) {rows: A.rows, lines: A.lines, mat: mat};
}


matrix mmul(matrix A, matrix B) {
	assert(A.mat != NULL && A.mat[0] != NULL && A.rows == B.lines);
	
	double** mat = malloc(sizeof(double*)*B.rows);
	for(int i = 0; i < B.rows; i++) {
		mat[i] = malloc(sizeof(double)*A.lines);
		for(int j = 0; j < A.lines; j++) {
			for(int k = 0; k < A.rows; k++)
				mat[i][j]+= A.mat[i][k]*B.mat[k][j];
		}
	}
	return (matrix) {rows: B.rows, lines: A.lines, mat: mat};
}


matrix meval(matrix A, double (*func)(double)) {
	assert(func != NULL);

	double** mat = malloc(sizeof(double*)*A.rows);
	for(int i = 0; i < A.rows; i++) {
		mat[i] = malloc(sizeof(double)*A.lines);
		for(int j = 0; j < A.lines; j++)
			mat[i][j] = func(A.mat[i][j]);
	}
	return (matrix) {rows: A.rows, lines: A.lines, mat: mat};
}

