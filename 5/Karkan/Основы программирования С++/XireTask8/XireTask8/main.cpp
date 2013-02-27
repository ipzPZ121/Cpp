//
//  main.cpp
//  XireTask8
//
//  Created by Evgeniy Karkan on 12/17/12.
//  Copyright (c) 2012 Sigma Ukraine. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;

int main(int argc, const char * argv[])
{

    ifstream file("/Users/user/Documents/XireTask8/XireTask8/file1.txt");
    
    char *lastSymbol = new char[1];
    char *lastLastSymbol = new char[1];
    
    if (file.is_open())
    while (!file.eof()) {
        
        *lastLastSymbol = *lastSymbol;
        file.read(lastSymbol, 1);
        
    }
    
    if ((*lastLastSymbol >= '0')&&(*lastLastSymbol <= '9')) {
        if ((*lastSymbol >= '0')&&(*lastSymbol <= '9')) {
            if (((*lastSymbol - '0') % 2) == 0) {
                cout << "Last number is even!";
            } else {
                cout << "Last number is odd!";
            }
        }
    }
    
    file.close();
    return 0;
}

