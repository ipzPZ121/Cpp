#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <conio.h>
#include <string>

using namespace std;

bool equalWords(const char *word1, const char *word2);
char ** encodeWords(char **words, unsigned int size);
unsigned int getFileSizeByChar(const char *fileName);
unsigned int countToken(const char *text, char ch);
char ** getEncodesFromKey(const char *fileName);
char ** stringToken(const char *text, char ch);
unsigned int countConsonants(const char *word);
char ** getWordsFromKey(const char *fileName);
unsigned int countLines(const char *fileName);
char * getSecFileName(const char *fileName);
char * getKeyFileName(const char *fileName);
unsigned int countSymbols(const char *word);
char * stringCopy(const char *src, char *dest);
unsigned int countWords(const char *text);
unsigned int countGaps(const char *text);
char * readFile(const char *fileName);
int encodeFile(const char *fileName);
char * encodeWord(const char *word);
char ** getWords(const char *text);
char ** getGaps(const char *text);
bool isPunctuation(char ch);
bool isNumber(char ch);
bool isLetter(char ch);
bool isVowel(char ch);
char * normaliseString(const char *text);
int decodeFile(const char *fileSec, const char *fileOut);

int main(int argc, char **argv) {
	char *appName = argv[0];

	if(argc == 1) {
		cout
				<< "You must input one argument of programm as filename with its extension, like filename.ext"
				<< endl;
		return EXIT_FAILURE;
	}
	if(argc > 1) {
		cout << argv[1] << endl;
	}

	cout << endl;

	encodeFile(argv[1]);

	char **enc = getEncodesFromKey(argv[1]);
	char **wrd = getWordsFromKey(argv[1]);
	int countL = countLines(getKeyFileName(argv[1])) - 1;
	for(int i = 0; i < countL; i++) {
		cout << enc[i] << " - " << wrd[i] << endl;
	}

	decodeFile(getSecFileName(argv[1]), "out.txt");

	cout << endl;
	cout << endl;
	system("pause");

	return EXIT_SUCCESS;
}

int decodeFile(const char *fileSec, const char *fileOut) {
	const char *txt = ".txt";
	int count;
	for(count = 0; fileSec[count] != '.'; count++) {
	}
	int fileNameSize = count + countSymbols(txt);
	char *fileName = new char[fileNameSize];
	for(int i = 0; i < count; i++) {
		fileName[i] = fileSec[i];
	}
	for(int i = 0; i < countSymbols(txt); i++) {
		fileName[i + count] = txt[i];
	}
	fileName[fileNameSize] = '\0';

	char *fileNameKey = getKeyFileName(fileName);

	char *text = readFile(fileSec);
	int size = countSymbols(text);
	char *buf = new char[size * 10];
	for(int i = 0; i < size * 10; i++) {
		buf[i] = '\0';
	}

	char **srcEnc = getEncodesFromKey(fileName);
	char **srcWrd = getWordsFromKey(fileName);
	int countL = countLines(getKeyFileName(fileName)) - 1;
	char **gaps = getGaps(text);
	char **encWrd = getWords(text);
	int encWrdCount = countWords(text);

	int e = 0;
	int s = 0;
	for(int i = 0; i < encWrdCount; i++) {
		for(int j = e; j < countL; j++) {
			if(equalWords(encWrd[i], srcEnc[j])) {
				for(int k = 0; srcWrd[j][k] != '\0'; k++, s++) {
					buf[s] = srcWrd[j][k];
				}
				for(int k = 0; gaps[i][k] != '\0'; k++, s++) {
					buf[s] = gaps[i][k];
				}
				e++;
				break;
			}
		}
	}

	FILE *fOut = NULL;
	fOut = fopen(fileOut, "w");
	fputs(buf, fOut);
	fclose(fOut);

	return 0;
}

char * normaliseString(const char *text) {
	char *tmp = NULL;
	tmp = stringCopy(text, tmp);

	for(int i = 0; tmp[i] != '\0'; i++) {
		if(tmp[i] == '\n') tmp[i] = '\0';
	}

	return tmp;
}

bool equalWords(const char *word1, const char *word2) {
	if(word1 == NULL && word2 != NULL) {
		return false;
	} else if(word2 == NULL && word1 != NULL) {
		return false;
	} else if(word1 != NULL && word2 != NULL) {
		if(countSymbols(word1) != countSymbols(word2)) return false;

		for(int i = 0; i < countSymbols(word1); i++) {
			if(word1[i] != word2[i]) return false;
		}
	}

	return true;
}

char ** encodeWords(char **words, unsigned int size) {
	char **encode = NULL;
	if(words == NULL) {
		cout << endl;
		cout << "Function encodeWords(const char **words, unsigned int size)"
				<< endl;
		cout << "I can\'t read words list" << endl;
		cout << endl;
	} else {
		encode = new char*[size];
		for(int i = 0; i < size; i++) {
			char *tmp = encodeWord(words[i]);
			unsigned int count = countSymbols(tmp);

			encode[i] = new char[count + 1];
			for(int j = 0; tmp[j] != '\0'; j++)
				encode[i][j] = tmp[j];
			encode[i][count] = '\0';
		}
	}

	return encode;
}

unsigned int getFileSizeByChar(const char *fileName) {
	unsigned int SIZE = 0;
	FILE *file = NULL;
	file = fopen(fileName, "rt");
	if(file == NULL) {
		cout << endl;
		cout << "Function getFileSizeByChar(const char *fileName)" << endl;
		cout << "I can\'t open a file: " << fileName << endl;
		cout << endl;
	} else {
		fseek(file, 0, SEEK_END);
		SIZE = ftell(file);

		fclose(file);
		file = NULL;
		delete file;
	}

	return SIZE;
}

unsigned int countToken(const char *text, char ch) {
	unsigned int COUNT = 0;

	if(text == NULL) {
		cout << endl;
		cout << "Function countToken(const char *text, char ch)" << endl;
		cout
				<< "It is a empty text. There aren\'t any words or symbols. Argument text."
				<< endl;
		cout << endl;
	} else {
		unsigned int c = countSymbols(text);
		for(int i = 0; i < c;) {
			int t;
			for(t = 0; text[i] != ch; i++, t++) {
				if(text[i] == '\0') break;
			}

			i++;

			COUNT++;

			if(text[i] == '\0') break;
		}
	}

	return COUNT;
}

char ** getEncodesFromKey(const char *fileName) {
	char **encodes = NULL;

	if(fileName == NULL) {
		cout << endl;
		cout << "Function getEncodesFromKey(const char *fileName)" << endl;
		cout << "File name is empty" << endl;
		cout << endl;
	} else {
		char *fileKey = getKeyFileName(fileName);
		unsigned int SIZE = countLines(fileKey) - 1;
		encodes = new char*[SIZE];

		FILE *fileK = NULL;
		fileK = fopen(fileKey, "rt");
		if(fileK == NULL) {
			cout << endl;
			cout << "Function getEncodesFromKey(const char *fileName)" << endl;
			cout << "I can\'t open a file: " << fileKey << endl;
			cout << endl;
		} else {
			for(int i = 0; !feof(fileK); i++) {
				char buf[1024] = { 0 };
				fgets(buf, sizeof(buf) / sizeof(char), fileK);

				if(buf[0] == '\0') {
					break;
				}

				char **token = stringToken(normaliseString(buf), '-');

				encodes[i] = NULL;
				encodes[i] = stringCopy(token[0], encodes[i]);
			}

			fclose(fileK);
		}

		fileK = NULL;
		delete fileK;
	}

	return encodes;
}

char ** stringToken(const char *text, char ch) {
	char **token = NULL;

	if(text == NULL) {
		cout << endl;
		cout << "Function stringToken(const char *text, char ch)" << endl;
		cout
				<< "It is a empty text. There aren\'t any words or symbols. Argument text."
				<< endl;
		cout << endl;
	} else {
		unsigned int SIZE = countToken(text, ch);
		token = new char*[SIZE];

		unsigned int c = countSymbols(text);
		for(int i = 0, s = 0; i < c; s++) {
			int t;
			char buf[1024] = { 0 };
			for(t = 0; text[i] != ch; i++, t++) {
				if(text[i] == '\0') break;
				buf[t] = text[i];
			}
			i++;

			token[s] = NULL;
			token[s] = stringCopy(buf, token[s]);

			if(text[i] == '\0') break;
		}
	}

	return token;
}

unsigned int countConsonants(const char *word) {
	unsigned int SIZE = 0;
	if(word == NULL) {
		cout << endl;
		cout << "Function countConsonant(const char *word)" << endl;
		cout << "I can\'t read word" << endl;
		cout << endl;
	} else {
		for(int i = 0; word[i] != '\0'; i++) {
			if(!isVowel(word[i])) SIZE++;
		}
	}

	return SIZE;
}

char ** getWordsFromKey(const char *fileName) {
	char **words = NULL;

	if(fileName == NULL) {
		cout << endl;
		cout << "Function getEncodesFromKey(const char *fileName)" << endl;
		cout << "File name is empty" << endl;
		cout << endl;
	} else {
		char *fileKey = getKeyFileName(fileName);
		unsigned int SIZE = countLines(fileKey) - 1;
		words = new char*[SIZE];

		FILE *fileK = NULL;
		fileK = fopen(fileKey, "rt");
		if(fileK == NULL) {
			cout << endl;
			cout << "Function getEncodesFromKey(const char *fileName)" << endl;
			cout << "I can\'t open a file: " << fileKey << endl;
			cout << endl;
		} else {
			for(int i = 0; !feof(fileK); i++) {
				char buf[1024] = { 0 };
				fgets(buf, sizeof(buf) / sizeof(char), fileK);

				if(buf[0] == '\0') {
					break;
				}

				char **token = stringToken(normaliseString(buf), '-');

				words[i] = NULL;
				words[i] = stringCopy(token[1], words[i]);
			}

			fclose(fileK);
		}

		fileK = NULL;
		delete fileK;
	}

	return words;
}

unsigned int countLines(const char *fileName) {
	unsigned int COUNT = 0;

	if(fileName == NULL) {
		cout << endl;
		cout << "Function getSecFileName(const char *fileName)" << endl;
		cout << "File name is empty" << endl;
		cout << endl;
	} else {
		FILE *file = NULL;
		file = fopen(fileName, "rt");

		char buf[1024] = { 0 };

		for(; !feof(file); COUNT++) {
			fgets(buf, 1022, file);
		}

		fclose(file);
		file = NULL;
		delete file;
	}

	return COUNT;
}

char * getSecFileName(const char *fileName) {
	char *fileSec = NULL;

	if(fileName == NULL) {
		cout << endl;
		cout << "Function getSecFileName(const char *fileName)" << endl;
		cout << "File name is empty" << endl;
		cout << endl;
	} else {
		unsigned int count = countSymbols(fileName);
		fileSec = new char[count + 1];
		const char *fileSecExt = ".sec";

		int c = 0;
		for(int i = 0; fileName[i] != '.'; i++, c++) {
			fileSec[i] = fileName[i];
		}
		for(int i = 0; fileSecExt[i] != '\0'; i++) {
			fileSec[i + c] = fileSecExt[i];
		}
		fileSec[count] = '\0';

		fileSecExt = NULL;
		delete fileSecExt;
	}

	return fileSec;
}

char * getKeyFileName(const char *fileName) {
	char *fileKey = NULL;

	if(fileName == NULL) {
		cout << endl;
		cout << "Function getKeyFileName(const char *fileName)" << endl;
		cout << "File name is empty" << endl;
		cout << endl;
	} else {
		unsigned int count = countSymbols(fileName);
		fileKey = new char[count + 1];
		const char *fileKeyExt = ".key";

		int c = 0;
		for(int i = 0; fileName[i] != '.'; i++, c++) {
			fileKey[i] = fileName[i];
		}
		for(int i = 0; fileKeyExt[i] != '\0'; i++) {
			fileKey[i + c] = fileKeyExt[i];
		}
		fileKey[count] = '\0';

		fileKeyExt = NULL;
		delete fileKeyExt;
	}

	return fileKey;
}

unsigned int countSymbols(const char *word) {
	unsigned int COUNT = 0;
	if(word == NULL) {
		cout << endl;
		cout << "Function countSymbols(const char *word)" << endl;
		cout << "I can\'t read word" << endl;
		cout << endl;
	} else {
		for(int i = 0; word[i] != '\0'/* || word[i] != '\n'*/; i++)
			COUNT++;
	}

	return COUNT;
}

char * stringCopy(const char *src, char *dest) {
	int result;
	unsigned int SIZE = 0;

	if(src == NULL) {
		cout << endl;
		cout << "Function stringCopy(const char *src, char *dest)" << endl;
		cout
				<< "It is a empty text. There aren\'t any words or symbols. Argument src."
				<< endl;
		cout << endl;

		result = -1;

		return NULL;
	}

	if(dest == NULL) {
		SIZE = countSymbols(src);
		if(SIZE == 0) {
			dest = new char[1];
			dest[0] = '\0';
		}
		dest = new char[SIZE + 1];
	} else SIZE = countSymbols(dest);

	for(int i = 0; i < SIZE; i++)
		dest[i] = src[i];
	dest[SIZE] = '\0';

	result = 0;

	return dest;
}

unsigned int countWords(const char *text) {
	unsigned int COUNT = 0;
	if(text == NULL) {
		cout << endl;
		cout << "Function countWords(const char *text)" << endl;
		cout << "It is a empty text. There aren\'t any words or symbols."
				<< endl;
		cout << endl;
	} else {
		int c = countSymbols(text);
		for(int i = 0; i < c;) {
			int t;
			for(t = 0; isLetter(text[i]); i++, t++) {
			}
			i++;

			if(t > 0) COUNT++;
		}
	}

	return COUNT;
}

unsigned int countGaps(const char *text) {
	unsigned int COUNT = 0;
	if(text == NULL) {
		cout << endl;
		cout << "Function countGaps(const char *text)" << endl;
		cout << "It is a empty text. There aren\'t any words or symbols."
				<< endl;
		cout << endl;
	} else {
		int c = countSymbols(text);
		for(int i = 0; i < c;) {
			int t;
			for(t = 0; !isLetter(text[i]); i++, t++) {
			}
			i++;

			if(t > 0) COUNT++;
		}
	}

	return COUNT;
}

char * readFile(const char *fileName) {
	unsigned int SIZE = getFileSizeByChar(fileName);
	char *text = NULL;
	FILE *file = NULL;
	if((file = fopen(fileName, "rt")) == NULL) {
		cout << endl;
		cout << "Function readFile(const char *fileName)" << endl;
		cout << "I can\'t open a file: " << fileName << endl;
		cout << endl;
	} else {
		text = new char[SIZE + 1];
		for(int i = 0; i < SIZE; i++) {
			text[i] = static_cast<char>(48);
		}

		fread(text, SIZE, sizeof(char), file);
		text[SIZE] = '\0';

		fclose(file);
		file = NULL;
		delete file;
	}

	return text;
}

int encodeFile(const char *fileName) {
	int result;

	if(fileName == NULL) {
		cout << endl;
		cout << "Function encodeFile(const char *fileName)" << endl;
		cout << "File name is empty" << endl;
		cout << endl;

		result = -1;
	}

	char *text = readFile(fileName);
	unsigned int countW = countWords(text);
	unsigned int countG = countGaps(text);
	char **words = getWords(text);
	char **gaps = getGaps(text);
	char **encodes = encodeWords(words, countW);

	char *fileSec = getSecFileName(fileName);
	char *fileKey = getKeyFileName(fileName);

	FILE *fileO = NULL;
	FILE *fileK = NULL;

	int minCount = countG > countW ? countW : countG;
	fileO = fopen(fileSec, "wt");
	if(fileO == NULL) {
		cout << endl;
		cout << "Function encodeFile(const char *fileName)" << endl;
		cout << "I can\'t open a file to write: " << fileSec << endl;
		cout << endl;

		result = -1;
	}
	for(int i = 0; i < minCount - 1; i++) {
		fwrite(encodes[i], countSymbols(encodes[i]), 1, fileO);
		fwrite(gaps[i], countSymbols(gaps[i]), 1, fileO);
	}
	fwrite(
			encodes[minCount - 1], countSymbols(encodes[minCount - 1]), 1,
			fileO);
	fwrite(gaps[minCount - 1], countSymbols(gaps[minCount - 1]) - 1, 1, fileO);
	fclose(fileO);

	if((fileK = fopen(fileKey, "wt")) == NULL) {
		cout << endl;
		cout << "Function encodeFile(const char *fileName)" << endl;
		cout << "I can\'t open a file to write: " << fileKey << endl;
		cout << endl;

		result = -1;
	} else {
		fclose(fileK);
	}

	FILE *fchk = NULL;
	for(int i = 0; i < countW; i++) {
		if((fchk = fopen(fileKey, "rt")) == NULL) {
			fileK = fopen(fileKey, "wt");
		}

		int countSymbolsW = countSymbols(words[i]);
		int countSymbolsE = countSymbols(encodes[i]);
		char sep = '-';

		int sizeKey = countSymbolsW + countSymbolsE
				+ (sizeof(sep) / sizeof(char));
		char *key = new char[sizeKey + 1];
		int cK = 0;
		for(int j = 0; encodes[i][j] != '\0'; j++, cK++) {
			key[j] = encodes[i][j];
		}
		key[cK] = sep;
		for(int j = 0; words[i][j] != '\0'; j++) {
			key[j + cK + 1] = words[i][j];
		}
		key[sizeKey] = '\0';

		bool equal = false;
		if(fchk != NULL) {
			while(!feof(fchk)) {
				char buf[1024] = { 0 };

				fgets(buf, sizeof(buf) / sizeof(char), fchk);

//				int a = 0;
//				for(int j = 0; buf[j] != '\n'; j++, a++) {
//				}
//				char *b = new char[a + 1];
//				for(int j = 0; j < a; j++) {
//					b[j] = buf[j];
//				}
//				b[a] = '\0';

				char *b = NULL;
				b = normaliseString(stringCopy(buf, b));

				equal = equalWords(b, key);
				if(equal) {
					b = NULL;
					delete b;
					break;
				}
			}
			fclose(fchk);
		}

		if(!equal) {
			fileK = fopen(fileKey, "at");
			if(fileK == NULL) {
				cout << endl;
				cout << "Function encodeFile(const char *fileName)" << endl;
				cout << "I can\'t open a file to write: " << fileKey << endl;
				cout << endl;

				result = -1;
			}

			fseek(fileK, 0, SEEK_END);

			fwrite(key, countSymbols(key), 1, fileK);
			fwrite("\n", 1, 1, fileK);

			fclose(fileK);
		}
		result = 0;
	}

	fileO = NULL;
	fileK = NULL;
	fchk = NULL;
	delete fileO;
	delete fileK;
	delete fchk;

	fileSec = NULL;
	delete fileSec;

	fileKey = NULL;
	delete fileKey;

	for(int i = 0; i < countW; i++) {
		words[i] = NULL;
		delete words[i];

		encodes[i] = NULL;
		delete encodes[i];
	}
	words = NULL;
	delete words;

	encodes = NULL;
	delete encodes;

	for(int i = 0; i < countG; i++) {
		gaps[i] = NULL;
		delete gaps[i];
	}
	gaps = NULL;
	delete gaps;

	return result;
}

char * encodeWord(const char *word) {
	unsigned int SIZE = 0;
	char *encode = NULL;

	if(word == NULL) {
		cout << endl;
		cout << "Function encodeWord(const char *word)" << endl;
		cout << "I can\'t read word" << endl;
		cout << endl;
	} else {
		unsigned int COUNT = countSymbols(word);
		if(COUNT == 1) {
			encode = new char[COUNT + 1];
			for(int i = 0; word[i] != '\0'; i++)
				encode[i] = word[i];
			encode[COUNT] = '\0';

		} else {
			SIZE = countConsonants(word);

			encode = new char[SIZE + 1];
			int enc = 0;
			for(int i = 0; word[i] != '\0'; i++) {
				if(!isVowel(word[i])) {
					encode[enc] = word[i];
					enc++;
				}
			}
			encode[SIZE] = '\0';
		}
	}

	return encode;
}

char ** getWords(const char *text) {
	char **words = NULL;
	if(text == NULL) {
		cout << endl;
		cout << "Function getWords(const char *text)" << endl;
		cout << "I can\'t read text because it\'s empty." << endl;
		cout << endl;
	} else {
		unsigned int SIZE = countWords(text);
		words = new char*[SIZE];

		int s = 0;
		int c = countSymbols(text);
		for(int i = 0; i < c;) {
			char buf[1024];
			for(int a = 0; a < sizeof(buf) / sizeof(char); a++)
				buf[a] = static_cast<char>(48);

			int t;
			for(t = 0; isLetter(text[i]); i++, t++)
				buf[t] = text[i];
			i++;

			if(t > 0) {
				words[s] = new char[t + 1];
				for(int j = 0; j < t; j++)
					words[s][j] = buf[j];
				words[s][t] = '\0';
				s++;
			}
		}
	}

	return words;
}

char ** getGaps(const char *text) {
	char **gaps = NULL;
	if(text == NULL) {
		cout << endl;
		cout << "Function getGaps(const char *text)" << endl;
		cout << "I can\'t read text because it\'s empty." << endl;
		cout << endl;
	} else {
		unsigned int SIZE = countGaps(text);
		gaps = new char*[SIZE];

		int s = 0;
		int c = countSymbols(text);
		for(int i = 0; i < c;) {
			char buf[1024];
			for(int a = 0; a < sizeof(buf) / sizeof(char); a++)
				buf[a] = static_cast<char>(48);

			int t;
			for(t = 0; !isLetter(text[i]); i++, t++)
				buf[t] = text[i];
			i++;

			if(t > 0) {
				gaps[s] = new char[t + 1];
				for(int j = 0; j < t; j++)
					gaps[s][j] = buf[j];
				gaps[s][t] = '\0';
				s++;
			}
		}
	}

	return gaps;
}

bool isPunctuation(char ch) {
	char punctuations[] = { ' ', '.', ',', ':', '-', '!', '?', ';', '\"', '(',
			')' };

	for(int i = 0; i < sizeof(punctuations) / sizeof(char); i++) {
		if(punctuations[i] == ch) return true;
	}

	return false;
}

bool isNumber(char ch) {
	char numbers[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	for(int i = 0; i < sizeof(numbers) / sizeof(char); i++) {
		if(numbers[i] == ch) return true;
	}

	return false;
}

bool isLetter(char ch) {
	int bigChars[] = { 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138,
			139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151,
			152, 153, 154, 155, 156, 157, 158, 159, 240 };
	int smallChars[] = { 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170,
			171, 172, 173, 174, 175, 224, 225, 226, 227, 228, 229, 230, 231,
			232, 233, 234, 235, 236, 237, 238, 239, 241 };

	for(int i = 0; i < sizeof(bigChars) / sizeof(int); i++) {
		if(static_cast<char>(bigChars[i]) == ch
				|| static_cast<char>(smallChars[i]) == ch) return true;
	}

	return false;
}

bool isVowel(char ch) {
	int bigChars[] = { 128, 133, 240, 136, 142, 147, 155, 157, 158, 159 };
	int smallChars[] = { 160, 165, 241, 168, 174, 227, 235, 237, 238, 239 };

	for(int i = 0; i < sizeof(bigChars) / sizeof(int); i++) {
		if(static_cast<char>(bigChars[i]) == ch
				|| static_cast<char>(smallChars[i]) == ch) return true;
	}

	return false;
}

