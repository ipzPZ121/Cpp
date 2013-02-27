//
//  main.cpp
//  XireTask1
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

    int numbers[max];
    
    cout<< "VVEDITE \n";
    cin >> numbers[0];
    
    cout<< "VVEDITE \n";
    cin >> numbers[1];
    
    cout<< "VVEDITE \n";
    cin >> numbers[2];
    
    cout<< "VVEDITE \n";
    cin >> numbers[3];
    
    cout<< "VVEDITE \n";
    cin >> numbers[4];
    
    cout<< "VVEDITE \n";
    cin >> numbers[5];
    
    int sum =0;
    
    if ((numbers[0]>4) && (numbers[0]<=7)) {
        sum = sum +numbers[0];
    }

    if ((numbers[1]>4) && (numbers[1]<=7)) {
        sum = sum +numbers[1];
    }

    if ((numbers[2]>4) && (numbers[2]<=7)) {
        sum = sum +numbers[2];
    }

    if ((numbers[3]>4) && (numbers[3]<=7)) {
        sum = sum +numbers[3];
    }

    if ((numbers[4]>4) && (numbers[4]<=7)) {
        sum = sum +numbers[4];
    }

    if ((numbers[5]>4) && (numbers[5]<=7)) {
        sum = sum +numbers[5];
    }


    cout << "SUM IS =" <<sum ;
   
    return 0;
}

