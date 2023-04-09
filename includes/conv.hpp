#ifndef CONV
#define CONV

#include <string>
using namespace std;

typedef long long ll;

class conv {
 public:

	//convert decimal numbers with fractional parts into binary
	string dec_to_bin(double dec) {
		string bin = "";
		int integral = int(dec); // get the integral part
		double fractional = dec - integral; // get the fractional part

		// convert the integral part to binary
		while (integral) {
			bin = to_string(integral % 2) + bin;
			integral /= 2;
		}

		bin += ".";

		// convert the fractional part to binary
		int counter = 0;
		while (fractional != 0 and counter < 10) {
			fractional *= 2;
			int bit = int(fractional);
			bin += to_string(bit);
			fractional -= bit;
			counter++;
		}
		if (bin[bin.size() - 1] == '.') bin = bin.substr(0, bin.size() - 1);
		return bin;
	}


	// convert binary numbers with a fractional part into decimal
	double binToDec(string bin) {
		double dec = 0, base = 1;

		// find decimal point
		int dec_point = bin.find('.');
		if (dec_point == string::npos) dec_point = bin.size();

		// integer part
		for (int i = dec_point - 1; i >= 0; i--) {
			dec += (bin[i] - '0') * base;
			base *= 2;
		}

		// fractional part
		base = 2;
		for (int i = dec_point + 1; i < bin.size(); i++) {
			dec += (bin[i] - '0') / base;
			base *= 2;
		}

		return dec;
	}


	// convert a decimal number with a fraction to hexadecimal
	string decToHex(double dec) {
		string hex = "";
		ll integral = ll(dec);
		double fractional = dec - integral;
		// convert integer part to hexadecimal
		while (integral) {
			int rem = integral % 16;
			hex = (rem < 10) ? to_string(rem) + hex : char('A' + rem - 10) + hex;
			integral /= 16;
		}
		// check if dec is an integer
		if (fractional == 0) return hex;
		// add decimal point
		hex += '.';
		// convert fractional part to hexadecimal
		for (int i = 0; i < 10; i++) {
			fractional *= 16;
			int digit = int(fractional);
			fractional -= digit;
			hex += (digit < 10) ? to_string(digit) : string(1, 'A' + digit - 10);
		}
		return hex;
	}


	double hexToDec(string hex) {
		double dec = 0, base = 1;

		// find decimal point
		ll dec_point = hex.find('.');
		if (dec_point == string::npos) dec_point = hex.size();

		// integer part
		for (int i = dec_point - 1; i >= 0; i--) {
			dec += (hex[i] >= '0' and hex[i] <= '9') ? (hex[i] - '0') * base : (hex[i] - 'A' + 10) * base;
			base *= 16;
		}

		// fractional part
		base = 16;
		for (int i = dec_point + 1; i < hex.size(); i++) {
			dec += (hex[i] >= '0' and hex[i] <= '9') ? (hex[i] - '0') / base : (hex[i] - 'A' + 10) / base;
			base *= 16;
		}
		return dec;
	}


	// Convert decimal to octal
	string dec_to_oct(double dec) {
		string oct = "";
		int integral = int(dec); // get the integral part
		double fractional = dec - integral; // get the fractional part

		// convert the integral part to binary
		while (integral) {
			oct = to_string(integral % 8) + oct;
			integral /= 8;
		}

		oct += ".";

		// convert the fractional part to binary
		int counter = 0;
		while (fractional != 0 and counter < 10) {
			fractional *= 8;
			int bit = int(fractional);
			oct += to_string(bit);
			fractional -= bit;
			counter++;
		}
		if (oct[oct.size() - 1] == '.') oct = oct.substr(0, oct.size() - 1);
		return oct;
	}


	// Convert octal to decimal
	double octToDec(string oct) {
		double dec = 0, base = 1;

		// find decimal point
		int dec_point = oct.find('.');
		if (dec_point == string::npos) dec_point = oct.size();

		// convert integer part to decimal
		for (int i = dec_point - 1; i >= 0; i--) {
			dec += (oct[i] - '0') * base;
			base *= 8;
		}

		// convert fractional part to decimal
		base = 8;
		for (int i = dec_point + 1; i < oct.size(); i++) {
			dec += (oct[i] - '0') / base;
			base *= 8;
		}
		return dec;
	}
};

#endif // CONV