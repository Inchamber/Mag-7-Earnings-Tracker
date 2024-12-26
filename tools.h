#include <iostream>
#include "Earnings.h"
#include <cstring>
using namespace std;



// Function Prototypes
void welcome();
void displaymenu();
void readOption(char *option);
void readDouble(double &num);
void readInt(int &temp);
bool validateIndex(int index, int count);
void validateTicker(char ticker[], Earnings list [], int count);;
void validateQuarter(char quarter[]);
void exeOption(char *option, Earnings list[], int &count);