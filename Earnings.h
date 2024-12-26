
#ifndef EARNINGS_H
#define EARNINGS_H
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;

// Integer constant 
const int MAX = 101;


// Data Struct
struct Earnings 
{
  char ticker[MAX];
  double revenue;
  double eps;
};

// Function prototypes
bool loadData(Earnings list[], int &count);
void printData(const Earnings list[], int count);
void addData(Earnings list[], int &count);
void removeData(Earnings list[], int &count, int index);
void findMax(const Earnings list[], int count);
void findTicker(const Earnings list[], int count);
void printData(ofstream &outFile, const Earnings list[], int count);

#endif