#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]) {
    srand(time(NULL));

    unsigned int arraySize = 0, separatePoint = 0;
    cout << "Input array size: ";
    cin >> arraySize;

    do {
        cout << "Input separate point (between 1 and " << arraySize - 2 << "): ";
        cin >> separatePoint;
    } while(separatePoint == 0 || separatePoint > arraySize - 2);

    int *arr = new int[arraySize];
    for(int i = 0; i < arraySize; i++) {
        arr[i] = rand() % 100;
    }

    cout << "Original array: " << endl;
    for(int i = 0; i < arraySize; i++) {
        cout << arr[i] << " ";
    }

    int temp = 0;
    int k = separatePoint - 1;

    for(int i = 0; i < arraySize; i++) {
        temp = arr[i];
        while(k < arraySize) {
            arr[i] = arr[k];
            arr[k] = temp;
            k++;
            break;
        }
    }

    cout << endl;

    cout << "Reverse array: " << endl;
    for(int i = 0; i < arraySize; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    cin.ignore();
    cout << getchar();

    return EXIT_SUCCESS;
}