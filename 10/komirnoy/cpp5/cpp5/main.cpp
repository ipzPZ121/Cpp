#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

char * getStrOfNum(double fnum, int numOfDig);

int main(int argv, char *argc[]) {
	char *str = getStrOfNum(-524333.853466452, 45);
	for(int i = 0; str[i] != '\0'; i++) {
		cout << str[i];
	}

	cout << endl;
	cout << getchar();

	return EXIT_SUCCESS;
}

char * getStrOfNum(double fnum, int numOfDig) {
	int count = 0;
	int base = 0;
	int dig = 0;
	const unsigned int SIZEBUFF = 1024;
	int *number = NULL;
	char *cNumber = NULL;
	int cTmp[SIZEBUFF];
	for(int i = 0; i < SIZEBUFF; i++) {
		cTmp[i] = 100;
	}
	unsigned int SIZE = 0;
	int t = 0;

	for(int i = 0; i < 2; i++) {
		if(count > 0) {
			if(numOfDig == -1) {
				if(fnum > 0) SIZE = (base);
				else SIZE = (base + 1);
			} else if(numOfDig == 0) {
				if(fnum > 0) SIZE = (base + dig + 1);
				else SIZE = (base + dig + 2);
			} else if(numOfDig > 0) {
				if(fnum > 0) SIZE = (base + numOfDig + 1);
				else SIZE = (base + numOfDig + 2);
			}
			number = new int[SIZE];
			for(int k = 0; k < SIZE; k++) {
				number[k] = 48;
			}
			if(fnum < 0) number[0] = 45;
		}

		double ftemp = fnum > 0 ? fnum : fnum * -1;

		while((static_cast<int>(ftemp) % 10) > 0) {
			int temp = static_cast<int>(ftemp) % 10;
			if(number != NULL) {
				cTmp[t] = temp + 48;
				t++;
			}
			ftemp /= 10;
			count++;
			base++;
		}

		if(number != NULL) {
			for(int k = SIZEBUFF - 1, j = fnum > 0 ? 0 : 1; k >= 0; k--) {
				if(cTmp[k] == 100) continue;
				number[j] = cTmp[k];
				j++;
			}
			if(numOfDig == -1) {
				cNumber = new char[SIZE];
				for(int a = 0; a < SIZE; a++) {
					cNumber[a] = static_cast<char>(number[a]);
				}
				cNumber[SIZE] = '\0';
				return cNumber;
			}
			if(fnum > 0) number[t] = 44;
			else if(fnum < 0) number[t + 1] = 44;
			for(int k = 0; k < SIZEBUFF; k++) {
				cTmp[k] = 100;
			}
			t = 0;
		}

		ftemp = fnum > 0 ? fnum : fnum * -1;
		while((static_cast<int>(ftemp) % 10) > 0) {
			ftemp = (ftemp - static_cast<int>(ftemp)) * 10;
			int temp = (static_cast<int>(ftemp) % 10);
			if(number != NULL) {
				if(t >= SIZEBUFF - 1) {
					break;
				}
				cTmp[t] = temp + 48;
				t++;
			}
			count++;
			dig++;
		}

		if(number != NULL) {
			int temp = 0;
			for(int k = 0; k < SIZE; k++) {
				if(number[k] == 44) {
					temp = k;
					break;
				}
			}
			for(int k = temp + 1; k < SIZE; k++) {
				if(cTmp[k - temp - 1] == 100) continue;
				if(numOfDig > 0) {
					if(k >= SIZEBUFF) continue;
				}
				number[k] = cTmp[k - temp - 1];
			}
			cNumber = new char[SIZE];
			for(int a = 0; a < SIZE; a++) {
				cNumber[a] = static_cast<char>(number[a]);
			}
			cNumber[SIZE] = '\0';
		}
	}

	return cNumber;
}
