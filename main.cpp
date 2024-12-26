/***
# Author: Gagandeep Bhatia
# Assignment: CS 161B Final Project
# Date: March 17, 2024
# Description: This program is a menu driven program for the Mag 7's earnings. 
               You can print the mag 7 earnings, add a company, remove a 
               company, see who the highest revenue company is, 
               find a company by entering their ticker and quit the program.
# Input: char *option, char ticker [], char quarter [], double revenue, 
         double eps, int index, 
# Output: list[i].ticker, list[i].revenue, list[i].eps, revenue, eps, big, max
          temp
# Sources: Each companies earnings data is from their investor relations tab:
          1.https://www.microsoft.com/en-us/investor/earnings/fy-2024-q2/press-release-webcast
          2.https://www.apple.com/newsroom/pdfs/fy2024-q1/FY24_Q1_Consolidated_Financial_Statements.pdf
          3. https://investor.nvidia.com/news/press-release-details/2024/NVIDIA-Announces-Financial-Results-for-Fourth-Quarter-and-Fiscal-2024/
          4. https://ir.aboutamazon.com/news-release/news-release-details/2024/Amazon.com-Announces-Fourth-Quarter-Results/default.aspx
          5. https://abc.xyz/assets/95/eb/9cef90184e09bac553796896c633/2023q4-alphabet-earnings-release.pdf
          6. https://s21.q4cdn.com/399680738/files/doc_financials/2023/q4/Meta-12-31-2023-Exhibit-99-1-FINAL.pdf
          7. https://digitalassets.tesla.com/tesla-contents/image/upload/IR/TSLA-Q4-2023-Update.pdf
          
***/



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