#include "Earnings.h"
#include "tools.h"



// Name: bool loadData(Earnings list [], int &count)
// Desc: This function reads data from the file, 
//       and populates the array and doubles
// Input: list[count].ticker, list[count].revenue, list[count].eps
// Output: None
// Return: bool true or false
bool loadData(Earnings list [], int &count) {
  ifstream inFile;
  inFile.open("earnings.txt");
  if(!inFile.is_open()) {
    cout << "File did not open! Program ending." << endl;
    return false;
  }
    inFile.ignore(200, '\n');
    inFile.getline(list[count].ticker, MAX, ';');
    while(!inFile.eof()) {
      inFile >> list[count].revenue;
      inFile.ignore(5, ';');
      inFile >> list[count].eps;
      inFile.ignore(5, '\n');
      count++;
      inFile.getline(list[count].ticker, MAX, ';');
    }
    inFile.close();
    return true;
}


// Name: void printData(const Earnings list [], int count)
// Desc: This function outpus the data from the array and doubles
// Input: None
// Output: i + 1, list[count].ticker, revenue, eps
//         (I couldn't figure out another way to format the output like this)
// Return: None
void printData(const Earnings list [], int count) {
  char revenue[MAX];
  char eps[MAX];
  cout << left;
  cout << "\n" << endl;
  cout << setw(3) << "#" << setw(15) << "Ticker" << setw(14) << "Revenue" 
  << setw(8) << "EPS" << endl;
  cout << "-------------------------------------" << endl;
  for (int i = 0; i < count; i++) {
    cout << setw(3) << left << i + 1; // #
    cout << setw(15) << left << list[i].ticker; // Ticker
    
    snprintf(revenue, 50, "$%.2fB", list[i].revenue); // Concatenating revenue
    snprintf(eps, 50, "$%.2f", list[i].eps); // Concatenating eps
    
    cout << setw(14) << left << revenue; // Outputting revenue
    cout << setw(8) << left << eps << endl; // Outputting eps
  }
}


// Name: void findTicker(const Earnings list [], int count)
// Desc: This function validates ticker by checking if it exists within list 
// Input: char company
// Output: list[i].ticker, list[i].revenue, list[i].eps
// Return: None
void findTicker(const Earnings list[], int count) {
  char company [MAX];
  bool valid = false;
  do {
    cout << "Enter the company's ticker: ";
    cin.getline(company, MAX);
    for (int i = 0; i < count; i++) {
      if(strcmp(list[i].ticker, company) == 0) {
        cout << "\nTicker: " << list[i].ticker << endl;
        cout << "Revenue: $" << list[i].revenue << "B" << endl;
        cout << "EPS: $" << list[i].eps << endl;
        valid = true;
      }
    }
    if (valid == false) {
      cout << "Ticker not found! Please enter a valid ticker." << endl;
    }
  } while(valid == false);
}


// Name: void addData(Earnings list [], int &count)
// Desc: This function adds data to the list, call other functions to do it
// Input: None
// Output: None
// Return: None
void addData(Earnings list[], int &count) {
  char quarter [MAX];
  validateTicker(list[count].ticker, list, count);
  validateQuarter(quarter);
  cout << "Enter the company's revenue in billions: ";
  readDouble(list[count].revenue);
  cout << "Enter the company's EPS: ";
  readDouble(list[count].eps);
  count++;
}


// Name: void removeData(Earnings list [], int &count, int index)
// Desc: This function removes the company at the index the user entered  
//       from the list
// Input: None
// Output: None
// Return: None
void removeData(Earnings list [], int &count, int index) {
  for(int i = index-1; i < count; i++) { 
    list[i] = list[i + 1];
  }
  count--;
} 

// Name: void findMax(const Earnings list [], int count)
// Desc: This function finds the company with the highest revenue
// Input: None
// Output: char big [MAX], double max, double temp
// Return: None
void findMax(const Earnings list[], int count) {
  double max = 0;
  double temp = 0;
  char big [MAX];
  for (int i = 0; i < count; i++) {
    if (list[i].revenue > max) {
      max = list[i].revenue;
      temp = list[i].eps;
      strcpy(big, list[i].ticker);
    }
  }
  cout << "\nThe company with the highest revenue is " << big << " with a " <<
    "revenue of $" << max << "B and an EPS of $" << temp << "." << endl 
    << "\n";
}

// Name: void printData(ofstream &outFile, const Earnings list [], int count)
// Desc: This function adds data to the file that was added by the user  
// Input: None
// Output: list[i].ticker, list[i].revenue, list[i].eps
// Return: None
void printData(ofstream &outFile, const Earnings list[], int count) {
  outFile.open("Output.txt");
  if (!outFile) {
    cout << "File did not open! Terminating the program" << endl;
    return;
  }
  for (int i = 0; i < count; i++) {
    outFile << list[i].ticker << ";" << list[i].revenue << ";" << 
    list[i].eps << endl;
  }
  outFile.close();
}