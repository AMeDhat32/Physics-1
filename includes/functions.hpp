#ifndef FUNCTIONS
#define FUNCTIONS

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class nsc {
 public:
  // convert decimal numbers with fractional parts into binary
  string decToBin(string dec) {
    double decimal = stod(dec);
    string bin = "";
    int integral = int(decimal);
    double fractional = decimal - integral;

    while (integral != 0) {
      bin = to_string(integral % 2) + bin;
      integral = integral / 2;
    }

    bin += ".";

    int counter = 0;
    while (fractional != 0 && counter < 10) {
      fractional = fractional * 2;
      int bit = int(fractional);
      bin += to_string(bit);
      fractional -= bit;
      counter++;
    }

    if (bin[bin.size() - 1] == '.')
      bin = bin.substr(0, bin.size() - 1);
    return bin;
  }

  // convert binary numbers with a fractional part into decimal
  string binToDec(string bin) {
    double dec = 0, base = 1;

    int dec_point = bin.find('.');
    if (dec_point == string::npos)
      dec_point = bin.size();

    for (int i = dec_point - 1; i >= 0; i--) {
      dec = dec + (bin[i] - '0') * base;
      base = base * 2;
    }

    base = 2;
    for (int i = dec_point + 1; i < bin.size(); i++) {
      dec = dec + (bin[i] - '0') / base;
      base *= 2;
    }
    if (dec == int(dec))
      return to_string(int(dec));
    return to_string(dec);
  }

  // convert a decimal number with a fraction to hexadecimal
  string decToHex(string dec) {
    double decimal = stod(dec);
    string hex = "";
    ll integral = ll(decimal);
    double fractional = decimal - integral;

    while (integral) {
      int rem = integral % 16;
      if (rem < 10)
        hex = to_string(rem) + hex;
      else
        hex = char('A' + rem - 10) + hex;
      integral = integral / 16;
    }

    if (fractional == 0)
      return hex;

    hex += '.';
    for (int i = 0; i < 10; i++) {
      fractional *= 16;
      int rem = int(fractional);
      fractional -= rem;
      if (rem < 10)
        hex = hex + to_string(rem);
      else
        hex = hex + string(1, 'A' + rem - 10);
    }

    return hex;
  }

  string hexToDec(string hex) {
    double dec = 0, base = 1;

    ll dec_point = hex.find('.');
    if (dec_point == string::npos)
      dec_point = hex.size();

    for (int i = dec_point - 1; i >= 0; i--) {
      if (hex[i] >= '0' && hex[i] <= '9')
        dec = dec + (hex[i] - '0') * base;
      else
        dec = dec + (hex[i] - 'A' + 10) * base;
      base *= 16;
    }

    base = 16;
    for (int i = dec_point + 1; i < hex.size(); i++) {
      dec += (hex[i] >= '0' && hex[i] <= '9') ? (hex[i] - '0') / base : (hex[i] - 'A' + 10) / base;
      base *= 16;
    }

    return to_string(dec);
  }

  // Convert decimal to octal
  string decToOct(string dec) {
    double decimal = stod(dec);
    string oct = "";
    int integral = int(decimal);
    double fractional = decimal - integral;

    while (integral) {
      oct = to_string(integral % 8) + oct;
      integral /= 8;
    }

    oct += ".";

    int counter = 0;
    while (fractional != 0 && counter < 10) {
      fractional *= 8;
      int bit = int(fractional);
      oct += to_string(bit);
      fractional -= bit;
      counter++;
    }

    if (oct[oct.size() - 1] == '.')
      oct = oct.substr(0, oct.size() - 1);
    return oct;
  }

  // Convert octal to decimal
  string octToDec(string oct) {
    double dec = 0, base = 1;

    int dec_point = oct.find('.');
    if (dec_point == string::npos)
      dec_point = oct.size();

    for (int i = dec_point - 1; i >= 0; i--) {
      dec += (oct[i] - '0') * base;
      base *= 8;
    }

    base = 8;
    for (int i = dec_point + 1; i < oct.size(); i++) {
      dec += (oct[i] - '0') / base;
      base *= 8;
    }

    return to_string(dec);
  }

  // Convert octal to hexadecimal
  string octToHex(string oct) {
    string dec = octToDec(oct);
    return decToHex(dec);
  }

  // Convert hexadecimal to octal
  string hexToOct(string hex) {
    string dec = hexToDec(hex);
    return decToOct(dec);
  }

  // Convert hexadecimal to binary
  string hexToBin(string hex) {
    string dec = hexToDec(hex);
    return decToBin(dec);
  }

  // Convert binary to octal
  string binToOct(string bin) {
    string dec = binToDec(bin);
    return decToOct(dec);
  }

  // Convert binary to hexadecimal
  string binToHex(string bin) {
    string dec = binToDec(bin);
    return decToHex(dec);
  }

  // Convert octal to binary
  string octToBin(string oct) {
    string dec = octToDec(oct);
    return decToBin(dec);
  }
};

class gates {
 public:
  // AND gate
  bool _and(bool a, bool b) { return a and b; }

  // OR gate
  bool _or(bool a, bool b) { return a or b; }

  // NOT gate
  bool _not(bool a) { return !a; }

  // XOR gate
  bool _xor(bool a, bool b) { return a != b; }

  // NAND gate
  bool _nand(bool a, bool b) { return !_and(a, b); }

  // NOR gate
  bool _nor(bool a, bool b) { return !_or(a, b); }

  // XNOR gate
  bool _xnor(bool a, bool b) { return !_xor(a, b); }

  // Implication gate
  bool _imp(bool a, bool b) { return !a or b; }
};

#endif  // FUNCTIONS