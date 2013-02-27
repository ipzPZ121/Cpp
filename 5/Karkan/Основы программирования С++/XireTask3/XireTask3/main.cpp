//
//  main.cpp
//  XireTask3
//
//  Created by Evgeniy Karkan on 12/17/12.
//  Copyright (c) 2012 Sigma Ukraine. All rights reserved.
//

//Поменять местами в двумерном массиве противоположные элементы (например 5.7 и -5.7), с учетов перестановки элемента только один раз.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const int size = 7;

int main(int argc, const char * argv[])
{

    int   MATRIX[size][size] = {{0, 123, 0, 3, 3, 0, 0},
                                {1, -5, 0, 4, 0, 8, 0},
                                {4, 0, -6, 0, 7, 0, 0},
                                {0, 0, 23, 32, 0, 0, 0},
                                {0, 13, 0, 0, -9, 0, 9},
                                {0, 0, 8, 0, 0, -11, 11},
                                {0, 0, 0, 0, 3, 0, 0}};
    
    for (int row = 0; row < size; row++) {
        int SUM = 0;
        int MAX = 0;
        if (MATRIX[row][row] < 0) {
            for (int coll = 0; coll < size; coll++) {
                SUM += MATRIX[row][coll];
                MAX = (MATRIX[row][coll] > MAX) ? (MATRIX[row][coll]) : (MAX);
            }
            cout << "SUM FOR " << row << "th ROW: " << SUM << " MAX: " << MAX << endl;
        }
    }
    
    return 0;
}

