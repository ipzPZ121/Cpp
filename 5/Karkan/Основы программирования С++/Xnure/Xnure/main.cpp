//
//  main.cpp
//  Xnure
//
//  Created by Evgeniy Karkan on 12/17/12.
//  Copyright (c) 2012 Sigma Ukraine. All rights reserved.
//

#include <iostream>
using std::cin;
using std::cout;
const int max=6;

int main(int argc, const char * argv[])
{

    int numbers [max];
    
    for (int i=0; i<max; i++)
    {
        cout << "VVEDITE CHISLO" ;
        cin >> numbers[i];
    }
        int sum =0;
    
    for (int i=0; i<max; i++) {
        if ((numbers[i]>4) && (numbers[i]<=7)) {
            sum = sum +numbers[i];
        }
    }
    cout << "SUM IS =" <<sum ;
    
  
    return 0;
}

