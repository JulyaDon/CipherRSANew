#include <conio.h>
#include <iostream>
#include <math.h>
#include <cstring> 

using namespace std;

int pow1(int b, int e, int mod)
{
	int result = 1;
	for (int _e = 1;_e <= e;_e++)
	{
		result = (result*b) % mod;
	}
	return result;
}

int main() {
	int p, q, e, n, f, d, length = 0;
	unsigned char* sentence = new unsigned char[201];
	//unsigned char* ciphered = new unsigned char[201];


	cout << "Enter first simple number:" << endl;
	cin >> p;
	cout << "Enter second simple number:" << endl;
	cin >> q;
	cout << "Enter the sentence you want to cipher:" << endl;
	cin >> sentence;

	length = strlen((char*)sentence);
	unsigned char* ciphered = new unsigned char[length + 1];
	ciphered[length] = '\0';

	n = p * q;
	f = (p - 1)*(q - 1);

	for (e = 3; e < n; e++) {
		if (f%e == 0) {
			continue;
		}
		
		for (int i = 2; i < e; i++) {
			if (e%i == 0) {
				if (f%i == 0) {
					break;
				}
			}
		}
		break;
	}
	for (d = 1;  (d * e) % f != 1; d++) {

	}
	for (int i = 0; i < length; i++) {
		ciphered[i] = pow1((sentence[i] - 96), e, n);
	}
	cout <<"Ciphered sentence: "<< ciphered << endl;
	for (int i = 0; i < length; i++) {
		sentence[i] = pow1(ciphered[i], d, n) + 96;
	}
	cout << "Deciphered sentence: " << sentence << endl;
	_getch();
	return 0;
}