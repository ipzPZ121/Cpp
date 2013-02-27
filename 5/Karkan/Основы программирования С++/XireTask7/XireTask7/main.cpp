//
//  main.cpp
//  XireTask7
//
//  Created by Evgeniy Karkan on 12/17/12.
//  Copyright (c) 2012 Sigma Ukraine. All rights reserved.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int lengthOfTheLastWord(const char *string) {

    int lastWordLength = 0;
    
    for (long i = strlen(string)-1; i >= 0; i--) {
        if (string[i] == ' ') break;
        lastWordLength++;
    }
    
    return lastWordLength;
    
}

int main(int argc, const char * argv[])
{

    cout << lengthOfTheLastWord("abc abc aaabbbbb");
    return 0;
}

