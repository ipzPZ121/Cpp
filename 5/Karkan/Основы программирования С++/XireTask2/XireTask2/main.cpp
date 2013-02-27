//
//  main.cpp
//  XireTask2
//
//  Created by Evgeniy Karkan on 12/17/12.
//  Copyright (c) 2012 Sigma Ukraine. All rights reserved.
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const int numbers = 10;


int main(int argc, const char * argv[])
{
    
    int array[numbers];
    
    for (int i=0; i<numbers; i++)
    {
        cout << "VVEDITE CHISLO" ;
        cin >> array[i];
    }

    
    for (int i=1; i<numbers; i++) {
        array[i] = array[i]/array[0];
    }
    
    for (int i=0; i<numbers; i++)
    {
        cout << array[i] << endl;
        
    }
    
    return 0;
}

