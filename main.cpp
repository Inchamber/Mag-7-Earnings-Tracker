#include <iostream>
#include "tools.h"
#include "Earnings.h"
using namespace std;

int main() {

  // Variables
  Earnings list[MAX];
  int count = 0;
  char option[MAX];
  ofstream outFile;

  // Function calls
  welcome();
  
  if(!loadData(list, count)) {
    cout << "File did not open." << endl;
    return 0;
  }
  // Looping until user decides to quit via required inputs
  do {
    displaymenu();
    readOption(option);
    exeOption(option, list, count);
  } while(strcmp(option, "Q") != 0 && strcmp(option, "q") != 0 
      && strcmp(option, "QUIT") != 0 && strcmp(option, "quit") != 0);
  printData(outFile, list, count);
  return 0;
}
