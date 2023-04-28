#include <bits/stdc++.h>
#include <windows.h>

#include "../includes/conv.hpp"
#include "../includes/logo.hpp"

using namespace std;
 
int main() {
  logo();
  Sleep(1300);
  conv c;
  int choice;
  double input;
  string result;
  bool running = true;
  cout << " -----------------------------------------\n";
  cout << "|  Welcome to the number conversion tool  |\n";
  cout << " -----------------------------------------\n";
  while (running) {
    cout << "\nPlease choose an option:\n";
    cout << "--------------------------\n";
    cout << "1. Decimal to binary\n";
    cout << "2. Binary to decimal\n";
    cout << "3. Decimal to hexadecimal\n";
    cout << "4. Hexadecimal to decimal\n";
    cout << "5. Decimal to octal\n";
    cout << "6. Octal to decimal\n";
    cout << "7. to Exit\n";
    cout << "--------------------------\n";
    cout << "Your choice: ";
    cin >> choice;
    switch (choice) {
      case 1:
        cout << "Enter decimal number: ", cin >> input;
        cout << input << " (decimal) = " << c.dec_to_bin(input) << " (binary)" << '\n';
        Sleep(500);
        break;

      case 2:
        cout << "Enter binary number: ", cin >> result;
        cout << result << " (binary) = " << c.binToDec(result) << " (decimal)" << '\n';
        Sleep(500);
        break;

      case 3:
        cout << "Enter decimal number: ", cin >> input;
        cout << input << " (decimal) = " << c.decToHex(input) << " (hexadecimal)" << '\n';
        Sleep(500);
        break;

      case 4:
        cout << "Enter hexadecimal number: ", cin >> result;
        cout << result << " (hexadecimal) = " << c.hexToDec(result) << " (decimal)" << '\n';
        Sleep(500);
        break;

      case 5:
        cout << "Enter decimal number: ", cin >> input;
        cout << input << " (decimal) = " << c.dec_to_oct(input) << " (octal)" << '\n';
        Sleep(500);
        break;

      case 6:
        cout << "Enter octal number: ", cin >> result;
        cout << result << " (octal) = " << c.octToDec(result) << " (decimal)" << '\n';
        Sleep(500);
        break;

      case 7:
        cout << "\nthanks for using our tool. Goodbye!\n";
        running = false;
        break;

      default:
        cout << "Invalid choice. Please enter a number between 1 and 7." << '\n';
        continue;
    }

    if (running) {
      char flag;
      cout << "\nDo you want to continue using the tool? (y/n): ", cin >> flag;
      Sleep(500);
      if (tolower(flag) == 'n') cout << "\nthanks for using our tool. Goodbye!\n", running = false;
    }
  }
}
