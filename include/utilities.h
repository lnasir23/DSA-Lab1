#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>
#include <string>
#include <iostream>
#include <string>

#define n 4

// ---------- Task 3 ----------
int findIndices(int arr[], int N, int key, int indices[]);
void printArray(int arr[], int size);
void testMultipleOccurences();
void testKeyNotPresent();
void testEmptyArray();
void test_task3();

// ---------- Task 4 ----------
int naiveSearch(const std::string& text, const std::string& pattern);
void testBeginningPattern();
void testEndingPattern();
void testAbsentPattern();
void testEmptyPattern();
void test_task4();

// ---------- Task 5 ----------
void genPascal(int N , int triangle[100][100]);
void printRow(int row[], int size);
void testPascal(int N);
void test_task5();

// ---------- Task 6 ----------
int findMode(int arr[], int N);
void testUniqueMode();
void testMultipleModes();
void testEmptyArray2();
void test_task6();

// ---------- Task 7 ----------
void addM(int A[n][n], int B[n][n], int C[n][n], int size);
void subtractM(int A[n][n], int B[n][n], int C[n][n], int size);
void naiveMultiplication(int A[n][n], int B[n][n], int C[n][n], int size);
void strassen(int A[n][n], int B[n][n], int C[n][n], int size);
void printM(int M[n][n], int size);
void test2x2M();
void test4x4M();
void testRandomM(int size);
void test_task7();

#endif // UTILITIES_H
