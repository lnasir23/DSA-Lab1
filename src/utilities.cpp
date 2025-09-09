#include "C:\Users\FutureX\DSA-Lab1\include\utilities.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int findIndices(int arr[], int N, int key, int indices[]) {
    int count = 0;
    for (int i = 0; i < N; i++) {

        if (arr[i] == key){
            indices[count++] = i;
        }
    }

    return count;
}

void printArray(int arr[], int size){
    if (size == 0){
        cout << "{}";
        return;
    }

    cout << "{";
    for (int i = 0; i< size; i++) cout << arr[i] << " ";
    cout << "}";

}


//test cases

//if the key appears more than once
void testMultipleOccurences() {
    int arr[] = {3, 7, 5, 7, 1, 7};
    int indices[10];
    int count = findIndices(arr, 6, 7, indices);

    cout << "Test for the Multiple Occurrence (Key = 7) ";
    printArray(indices, count);
    cout << endl;


}

//if the key is not present
void testKeyNotPresent(){
    int arr[] = {2, 5, 7, 9, 6};
    int indices[10];
    int count = findIndices(arr, 5, 10, indices);

    cout << "Key absent (Key = 10): ";
    printArray(indices, count);
    cout << endl;
}

//if empty array is provided
void testEmptyArray(){
    int arr[] = {};
    int indices[10];
    int count = findIndices(arr, 0, 5, indices);
    cout << "Test Empty Array (Key=5): ";
    cout << endl;
}


void test_task3() {
    testMultipleOccurences();
    testKeyNotPresent();
    testEmptyArray();
}


//task 4

//func to find first occurence of string in a text or if not found , -1
int naiveSearch(const string& text, const string& pattern){

    int N = text.size();
    int m = pattern.size();


    if (m == 0) return 0; //empty pattern

    for(int i = 0; i <=N - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j== m) return i; //match found

    }

    return -1;
}

// beginning pattern
void testBeginningPattern(){
    string t1 = "hello lama";
    string t2 = "hello";

    int result = naiveSearch(t1, t2);
    cout << "Test for the beginning pattern in text: " << result << endl;


}


//ending pattern
void testEndingPattern(){
    string t1 = "hello lama";
    string t2 = "lama";

    int result = naiveSearch(t1, t2);
    cout << "Test for the ending pattern in text: " << result << endl;

}

//pattern absent
void testAbsentPattern(){
    string t1 = "hello lama";
    string t2 = "nice";

    int result = naiveSearch(t1, t2);
    cout << "Test for the pattern absent in text: " << result << endl;

}

//empty pattern
void testEmptyPattern(){
    string t1 = "hello lama";
    string t2 = "";

    int result = naiveSearch(t1, t2);
    cout << "Test for the empty pattern: " << result << endl;

}

//test application
void test_task4() {
    testBeginningPattern();
    testEndingPattern();
    testAbsentPattern();
    testEmptyPattern();

}


//task 5

//function for generating Pascal triangles upto rows n
void genPascal(int N , int triangle[100][100]){
    for (int i = 0; i < N; i++){
        triangle[i][0] = triangle[i][i] = 1;
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i-1][j -1] + triangle[i - 1][j];
        }
    }
}

//function for printing a row
void printRow(int row[], int size) {
    cout << "{ ";
    for (int i = 0; i < size; i++) cout << row[i] << " ";
    cout << "}";


}

//testing Pascal's triangle
//for given rows n
void testPascal(int N) {
    int triangle[100][100] = {0};
    genPascal(N, triangle);

    cout << "Pascal's Triangle for n: " << N << endl;

    if (N == 0) {
        cout << "{}" << endl;
        return;
    }

    for (int i = 0; i < N; i++){
        printRow(triangle[i], i + 1);
        cout << endl;
    }


    //special case check in case of row 5
    if (N >= 5) {
        cout << "Row 5 Verification: ";
        printRow(triangle[4], 5);
        
    }

    cout << endl;
}

void test_task5(){
    //checking for n= 0, 1, 5
    testPascal(0);
    testPascal(1);
    testPascal(5);
}


//task 6
//function for finding mode of array, -1 if empty
int findMode(int arr[], int N) {
    if (N == 0) return -1;

    int maxNo = 0, mode = arr[0];

    for(int i = 0; i < N; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (arr[j] == arr[i]){
                count++;
            }
        }

        if (count > maxNo) {
            maxNo = count;
            mode = arr[i];
        }
    }

    return mode;
}

//where a mode is present within the array
void testUniqueMode(){
    int arr[] = {1, 3, 3, 6, 9};
    int result = findMode(arr, 5);
    cout <<  "Unique mode: " << result << endl;
}

//more than one mode exists, case 2
void testMultipleModes(){
    int arr[] = {1, 3, 3, 9, 9};
    int result = findMode(arr, 5);
    cout <<  "Multiple modes case: " << result << endl;
}

void testEmptyArray2(){
    int arr[] = {};
    int result = findMode(arr, 0);
    cout <<  "Empty array leads to: " << result << endl;


}

//testing application
void test_task6(){
    testUniqueMode();
    testMultipleModes();
    testEmptyArray();
}


//task 7
//fucntion for adding together matrices
void addM(int A[n][n], int B[n][n], int C[n][n], int size) {
    for (int i = 0; i < size; i ++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
}

//function for the substraction of two matrices
void subtractM(int A[n][n], int B[n][n], int C[n][n], int size) {
    for (int i = 0; i < size; i ++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] - B[i][j];
}

//normal/naive matrices' multiplication
void naiveMultiplication(int A[n][n], int B[n][n], int C[n][n], int size) {
    for (int i = 0; i < size; i ++)
        for (int j = 0; j < size; j++){
            C[i][j] = 0;
            for (int k = 0; k < size; k++)
                C[i][j] += A[i][k] * B[k][j];


        }
    
    }

//function for using Strassen Algorithm to calculate matrices' multiplication
void strassen(int A[n][n], int B[n][n], int C[n][n], int size) {

    //base case scenario
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
}

    int newSize = size / 2;
    int A11[n][n], A12[n][n], A21[n][n], A22[n][n];
    int B11[n][n], B12[n][n], B21[n][n], B22[n][n];
    int C11[n][n], C12[n][n], C21[n][n], C22[n][n];
    int M1[n][n], M2[n][n], M3[n][n], M4[n][n], M5[n][n], M6[n][n], M7[n][n];
    int temp1[n][n], temp2[n][n];


    //initiallizing submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j <newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];


            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }



    //M1 = (A11+ A22) x (B11+ B22)
    addM(A11, A22, temp1, newSize);
    addM(B11, B22, temp2, newSize);

    strassen(temp1, temp2, M1, newSize);


    //M2 = (A21+ A22) x B11
    addM(A21, A22, temp1, newSize);

    strassen(temp1, B11, M2, newSize);


    //M3 = A11 x (B12 - B22)
    subtractM(B12, B22, temp2, newSize);

    strassen(A11, temp2, M3, newSize);


    //M4 = A22 x (B21 - B11)
    subtractM(B21, B11, temp2, newSize);

    strassen(A22, temp2, M4, newSize);


    //M5 = (A11 + A12) x B22
    addM(A11, A12, temp1, newSize);

    strassen(temp1, B22, M5, newSize);


    //M6 = (A21 -A11) x (B11 + B12)
    subtractM(A21, A11, temp1, newSize);
    addM(B11, B12, temp2, newSize);

    strassen(temp1, temp2, M6, newSize);


    //M7 = (A12- A22) x (B21+ B22)
    subtractM(A12, A22, temp1, newSize);
    addM(B21, B22, temp2, newSize);

    strassen(temp1, temp2, M7, newSize);


    //C11 = M1 + M4 - M5 + M7
    addM(M1, M4, temp1, newSize);
    subtractM(temp1, M5, temp2, newSize);
    addM(temp2, M7, C11, newSize);


    //C12 = M3 + M5
    addM(M3, M5, C12, newSize);


    //C21 = M2 + M4
    addM(M2, M4, C21, newSize);


    //C22 = M1 - M2 + M3 + M6
    subtractM(M1, M2, temp1, newSize);
    addM(temp1, M3, temp2, newSize);
    addM(temp2, M6, C22, newSize);


    //combinging submatrices into result c
    for (int i = 0; i < newSize; i++){
        for(int j = 0; j < newSize; j++){
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];

        }
    
    }
}


//fucntion for matrix printing
void printM(int M[n][n], int size) {
    for (int i = 0; i < size; i++) {
        cout << "{ ";
        for (int j = 0; j < size; j ++) {
            cout << M[i][j] << " ";
        }
        cout << "}" << endl;
    }

}



//test cases
//2x2 matrices
void test2x2M(){
    int A[n][n] = {{1, 2}, {3, 4}};
    int B[n][n] = {{5, 6}, {7, 8}};
    int C1[n][n], C2[n][n];

    naiveMultiplication(A, B, C1, 2);
    strassen(A, B, C2, 2);

    cout << "2x2 multiplication (naive): " << endl;
    printM(C1, 2);
    cout << "2x2 multiplication (Strassen): " << endl;
    printM(C2, 2);

    cout << endl;

}

//4x4 matrices
void test4x4M() {
    int A[n][n] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {1, 2, 3, 4}, {5, 6, 7, 8}};
    int B[n][n] = {{5, 6, 7, 8}, {7, 8, 5, 1}, {5, 6, 7, 8}, {7, 8, 5, 1}};
    int C1[n][n], C2[n][n];

    naiveMultiplication(A, B, C1, 4);
    strassen(A, B, C2, 4);

    cout << "4x4 multiplication (naive): " << endl;
    printM(C1, 4);
    cout << "4x4 multiplication (Strassen): " << endl;
    printM(C2, 4);

    cout << endl;

}


//random test case
void testRandomM(int size) {
int A[n][n], B[n][n], C1[n][n], C2[n][n];
srand(42);

for (int i = 0;i < size; i++){
    for (int j = 0; j < size; j ++){
        A[i][j] = rand() % 10;
        B[i][j] = rand() % 10;
    }
}

    naiveMultiplication(A, B, C1, size);
    strassen(A, B, C2, size);

    cout << size <<"x" << size << " multiplication (naive): " << endl;
    printM(C1, size);
    cout << size <<"x" << size << " multiplication (Strassen): " << endl;
    printM(C2, size);

    cout << endl;

}


//testing application
void test_task7() {
    test2x2M();
    test4x4M();
    testRandomM(2);
    


}