#include <fstream>
#include <iostream>
#include <malloc.h>
#include <math.h>
#include <iomanip>
#include <cstdio>
using namespace std;
#define N 201

void printMatrix(double a[][N], int row);
void generateIdentityMatrix(double a[][N], int row);
bool GuassInverse(double a[][N], double b[][N], int row);
void multiplyMatrix(double a[][N], double b[][N], double c[][N], int row);
double errorDetect(double a[][N], double b[][N], int row);

int main(){
    int row;
    cin >> row;  

    int num_ele;
    num_ele = row*row; 
    double *buffer;  // define head of array 
    buffer = (double *)calloc(num_ele, sizeof(double));// allocate space 
    double *p; 
    p = buffer;
    int i, j; 
    for(i = 0; i < num_ele; i++){
        cin >> *p++;
    }

    /********** stored into matrix ******/
    double A[N][N], B[N][N], C[N][N];
    p = buffer; // go back to head of array
    for(i = 0; i < row; i++)
        for(j = 0; j < row; j++)
            A[i][j] = *p++; 

    /********* find the inverse and variefy *********/
    if(GuassInverse(A,B,row)){ 
    	multiplyMatrix(A,B,C,row);
    	cout << "error is " <<  errorDetect(A, B, row) << endl;
        cout << "Inverse of matrix A is: " << endl;
        printMatrix(B, row);
    	cout << "multiply A and B: " << endl;
    	printMatrix(C, row);
    }
    else
        cout << "The matrix has no inverse matrix." << endl;

    free(buffer);
    return 0;
}

void printMatrix(double a[][N], int row){
    int i, j; 
    for(i = 0; i < row; i++){
        for(j = 0; j < row; j++)
            printf("%10.5lf ",a[i][j]);
        printf("\n");
    }
}
void generateIdentityMatrix(double a[][N], int row){
    int i, j;
    for(i = 0; i < row; i++)
        for(j = 0; j < row; j++)
            a[i][j] = (i == j)? 1: 0; 
}

bool GuassInverse(double a[][N], double b[][N], int row){
    /******** initialize B as an identity matrix ******/
    int i, j, k;
    generateIdentityMatrix(b, row);

    double max, temp;
    double t[N][N];                
    /********** store a into t temporarily ******/
    for (i = 0; i < row; i++){  
        for (j = 0; j < row; j++)
            t[i][j] = a[i][j];
    }

    for (i = 0; i < row; i++){
        /******** find the main element *******/
        max = t[i][i];
        k = i;
        for (j = i+1; j < row; j++)
        {
            if (fabs(t[j][i]) > fabs(max))
            {
                max = t[j][i];
                k = j;
            }
        }
        if (k != i) // if the main element is not in ith row, exchange
        {
            for (j = 0; j < row; j++)
            {
                temp = t[i][j];
                t[i][j] = t[k][j];
                t[k][j] = temp;
                /****** matrix b exchange accordingly ****/
                temp = b[i][j];
                b[i][j] = b[k][j];
                b[k][j] = temp; 
            }
        }
        /******** if main element is 0, a doesn't have inverse matrix ****/
        if (t[i][i] == 0){
            return false;
        }
        /**** eliminate any other element except ith row in ith column *****/
        temp = t[i][i];
        for (j = 0; j < row; j++){
            t[i][j] = t[i][j] / temp;        //set 1 on main diagonal
            b[i][j] = b[i][j] / temp;        //transform accordingly
        }
        for (j = 0; j < row; j++){        // Line 0 to Line row
            if (j != i){                // if not Line i
                temp = t[j][i];
                for (k = 0; k < row; k++){  
                    t[j][k] = t[j][k] - t[i][k]*temp;
                    b[j][k] = b[j][k] - b[i][k]*temp;
                }
            }
        }
    }
    return true;
}

void multiplyMatrix(double a[][N], double b[][N], double c[][N], int row){
    int i,j,k;
    for(i = 0; i < row; i++)
        for(j = 0; j < row; j++)
            for(k = 0; k < row; k++)
                c[i][j] += a[i][k]*b[k][j];
}

double errorDetect(double a[][N], double b[][N], int row){
    double I[N][N];
    double c[N][N];  
    generateIdentityMatrix(I, row);
    multiplyMatrix(a, b, c, row);
    int i,j;
    /****** subtraction *******/
    double error_matrix[N][N];
    for(i = 0; i < row; i++)
        for(j = 0; j < row; j++)
            error_matrix[i][j] = c[i][j] - I[i][j];
    /***** find the max error ******/
    double err = 0;
    for(i = 0; i < row; i++)
        for(j = 0; j < row; j++)
           err = (fabs(error_matrix[i][j]) > err) ? error_matrix[i][j] : err; 
    return err;
}
