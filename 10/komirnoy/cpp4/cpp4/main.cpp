#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
    unsigned int arraySize = 0;

    cout << "Input array size: ";
    cin >> arraySize;
    cout << endl;

    int middleIndex = (arraySize / 2 ) + (arraySize % 2);
    int mIdxI = 0, mIdxJ = 0, count = 1;
    mIdxI = mIdxJ = middleIndex - 1;

    int **arr = new int*[arraySize];

    for(int i = 0; i < arraySize; i++) {
        arr[i] = new int[arraySize];
        for(int j = 0; j < arraySize; j++) {
            arr[i][j] = 0;
        }
    }

    for(int k = 0; k < arraySize;) {
        if(k == 0) {
            arr[mIdxI][mIdxJ] = count;
            k++;
        }
        for(int i = 0; i < k; i++) arr[mIdxI++][mIdxJ] = count++;
        for(int i = 0; i < k; i++) arr[mIdxI][mIdxJ++] = count++;
        if(k == (arraySize - 1)) break;
        k++;
        for(int i = 0; i < k; i++) arr[mIdxI--][mIdxJ] = count++;
        for(int i = 0; i < k; i++) arr[mIdxI][mIdxJ--] = count++;
        k++;
    }
    for(int k = 0; k < arraySize; k++) {
        if(arraySize > 1) {
            if(arraySize % 2 == 0) arr[mIdxI--][mIdxJ] = count++;
            else arr[mIdxI++][mIdxJ] = count++;
        }
    }


    for(int i = 0; i < arraySize; i++) {
        for(int j = 0; j < arraySize; j++) {
            cout << setw(4) << setiosflags(ios::right) << arr[i][j];
        }
        cout << endl;
        cout << endl;
    }

    cout << endl;
    cin.ignore();
    cout << getchar();

    return EXIT_SUCCESS;
}