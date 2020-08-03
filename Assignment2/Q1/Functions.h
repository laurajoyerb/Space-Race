#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <ios>

const int ENTRIES = 10;

void initialize();

void runcode();

bool checkCode(char input);

double findNyanCatValue(double myNum);

int factorial(int num);

int fibonacci(int fib);

double findSqrtValue(double rad);

double naturalLog(double arg);

int findNextOddValue(int start);

void writeDataToFile(const char* file);

void readDataFromFile(const char* file);

#endif
