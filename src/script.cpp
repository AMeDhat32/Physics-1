#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//medhat
// Convert decimal to binary
string dec_to_bin(ll dec) {
	string bin = "";
	while (dec) bin = to_string(dec % 2) + bin, dec /= 2;
	return bin;
}

// Convert binary to decimal
ll bin_to_dec(string bin) {
	ll dec = 0, base = 1;
	for (ll i = bin.size() - 1; i >= 0; i--) if (bin[i] == '1') dec += base, base *= 2;
	return dec;
}

// Convert decimal to hexadecimal
string dec_to_hex(ll dec) {
	string hex = "";
	while (dec) {
		int rem = dec % 16;
		hex = (rem < 10) ? to_string(rem) + hex : char ('A' + rem - 10) + hex;
		dec /= 16;
	}
	return hex;
}

// Convert hexadecimal to decimal
ll hex_to_dec(string hex) {
	ll dec = 0, base = 1;
	for (ll i = hex.size() - 1; i >= 0; i--)
		dec += (hex[i] >= '0' && hex[i] <= '9') ? (hex[i] - '0') * base : (hex[i] - 'A' + 10) * base, base *= 16;
	return dec;
}

// Convert octal to decimal
int oct_to_dec(string oct) {
	ll dec = 0, base = 1;
	for (int i = oct.length() - 1; i >= 0; i--) dec += (oct[i] - '0') * base, base *= 8;
	return dec;
}

// Convert decimal to octal
string dec_to_oct(ll dec) {
	string oct = "";
	while (dec) oct = to_string(dec % 8) + oct, dec /= 8;
	return oct;
}

int main() {
}