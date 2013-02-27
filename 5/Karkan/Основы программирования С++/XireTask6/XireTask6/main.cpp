//
//  main.cpp
//  XireTask6
//
//  Created by Evgeniy Karkan on 12/17/12.
//  Copyright (c) 2012 Sigma Ukraine. All rights reserved.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;



int main(int argc, const char * argv[])
{
    int size;
    cout << "Enter array size: ";
    cin >> size;
    
    if (size < 0) {
        cout << "(fuckyou!)";
        exit(0);
    }
    
    int a;
    cout << "Enter 'a': ";
    cin >> a;
    
    int array[size];
    int count = 0;
    for (int i = 0; i < size; i++) {
        
        cout << "Enter " << i << "th element: ";
        cin >> array[i];
        count = (array[i] == a)? (count+1) : (count);
        
    }
    
    cout << "Number of elements in array == " << a << " is: " << count << endl;
    
    return 0;
}

