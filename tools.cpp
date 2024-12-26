#include "tools.h"
#include "Earnings.h"


// Name: void welcome()
// Desc: This function displays the welcome message
// Input: None
// Output: None
// Return: None
void welcome() {
  cout << "Welcome to the Magnificent 7 Earnings Tracker!" << endl;
  cout << "\nThis program displays the revenue and earnings per share "
    << "(EPS) of each company in the Magnificent 7." << endl;
  cout << "\nYou may add quarterly earnings for a specific company, remove a " 
    << "specific company from the list, view a specific company's earnings, " 
    << " and view the company with the highest revenue in the Magnificent 7." << endl;
}

// Name: void displaymenu()
// Desc: This function displays the menu
// Input: None
// Output: None
// Return: None
void displaymenu() {
  cout << "\n(A)DD" << endl;
  cout << "(R)EMOVE" << endl;
  cout << "(P)RINT" << endl;
  cout << "(F)IND" << endl;
  cout << "(M)AX" << endl;
  cout << "(Q)UIT" << endl;
}

// Name: void readOption(char *option)
// Desc: This function reads in the user's option
// Input: char *option
// Output: None
// Return: None
void readOption(char *option) {
  cout << "\nPlease enter an option from above: ";
  cin >> option;
  cin.ignore(100, '\n');
}

// Name: void readDouble(double &num)
// Desc: This function reads in doubles, specifically for the addData function
//       when the user enters the revenue and eps for a company
// Input: double num
// Output: None
// Return: None
void readDouble(double &num) {
  cin >> num;
  while (cin.fail() || num < 0) {
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Invalid number! Please try again." << endl;
    cout << "Enter a valid number: ";
    cin >> num;
  }
  cin.ignore(100, '\n'); // Clearing line after user entered the double
}

// Name: void readInt(int &temp)
// Desc: This function reads in integers from the user such as the index 
//       when removing a company from the list
// Input: double num
// Output: None
// Return: None
void readInt(int &temp) {
  cin >> temp;
  while (cin.fail() || temp < 0) {
    cout << "Invalid number! Please try again." << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cin >> temp;
  }
  cin.ignore(100, '\n'); // use if needed to clear line after user entered the double
}

// Name: bool validateIndex(int index, int count)
// Desc: This function validates the index via checking if the index is less 
//       than or equal to the count
// Input: None
// Output: None
// Return: bool true or false
bool validateIndex(int index, int count) {
  if (index <= count) {
    return true;
  }
  else {
    return false;
  }
}

// Name: void validateTicker(char ticker [], Earnings list [], int count)
// Desc: This function validates the ticker via checking if the ticker exists 
//       within the list
// Input: char ticker []
// Output: None
// Return: None
void validateTicker(char ticker[], Earnings list[], int count) {
  bool flag = false;
  while (flag == false) {
    cout << "Enter a valid ticker: ";
    cin.getline(ticker, MAX);
    for (int i = 0; i < count; i++) {
      if (strcmp(list[i].ticker, ticker) == 0) {
        cout << "Ticker found!" << endl;
        flag = true;
      }
    }
    if (flag == false) {
      cout << "Ticker not found! Please try again." << endl;
    }
  }
}


// Name: void validateQuarter(char quarter [])
// Desc: This function validates the quarter
// Input: char quarter []
// Output: None
// Return: None
void validateQuarter(char quarter []) {
  bool check = false;
  while (check == false) {
    cout << "Enter the quarter: ";
    cin >> quarter;
    if (toupper(quarter[0]) != 'Q' || quarter[1] != '1' && quarter[1] != '2' && 
      quarter[1] != '3' && quarter[1] != '4') {
      cout << "Invalid quarter! Please try again." << endl;
    }
    else {
      check = true;
    }
  } 
}


// Name: void exeOption(char *option, Earnings list[], int &count)
// Desc: This function executes the option the user enters 
// Input: None
// Output: None
// Return: None
void exeOption(char *option, Earnings list[], int &count) {

  int index = 0;
  
  switch(toupper(option[0])) {
    case 'A':
      addData(list, count);
      break;
    case 'P':
      printData(list,count);
      break;
    case 'R':
      printData(list,count);
      cout << "\nEnter the index (ranking) of the company to remove: "; 
      readInt(index);
      if (validateIndex(index,count)) {
        removeData(list, count, index);
        cout << "\nHere is the updated list below: " << endl;
        printData(list, count);
      }
      else {
        cout << "Invalid index! Please try again." << endl;
      }
    break;
    case 'F':
      findTicker(list, count);
      break;
    case 'M':
      findMax(list, count);
      break;
    case 'Q':
      cout << "\nThank you for using the Magnificent 7 earnings tracker!" << endl;
      break;
    default:
      cout << "Invalid option! Please try again." << endl;
  }
}



