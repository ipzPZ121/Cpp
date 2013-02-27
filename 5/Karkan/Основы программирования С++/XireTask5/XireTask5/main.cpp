//
//  main.cpp
//  XireTask5
//
//  Created by Evgeniy Karkan on 12/17/12.
//  Copyright (c) 2012 Sigma Ukraine. All rights reserved.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const int size = 5;

int main(int argc, const char * argv[])
{
    
    int a[size][size] = {{1,1,1,1,1},
                         {1,0,0,0,1},
                         {1,0,0,0,1},
                         {1,0,0,0,1},
                         {1,0,0,0,1}}; // 13

    int SUM = 0;
    for (int coll = 0; coll < size; coll++) {
        SUM += a[0][coll];
    }
    for (int row = 1; row < size; row++) {
        SUM += a[row][0] + a[row][size-1];
    }
    
    cout << "RESULT: " << SUM << endl;
    
    return 0;
}

