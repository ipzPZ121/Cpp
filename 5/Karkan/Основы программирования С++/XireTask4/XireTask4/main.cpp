//
//  main.cpp
//  XireTask4
//
//  Created by Evgeniy Karkan on 12/17/12.
//  Copyright (c) 2012 Sigma Ukraine. All rights reserved.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Student {
    char name[255];
    float math;
    float english;
    float russian;
};

const int MAX = 3;

float average(struct Student *aStudent) {
    
    return ((aStudent->english + aStudent->math + aStudent->russian) / 3);
    
}

int main(int argc, const char * argv[])
{

    Student students[MAX];
    
    for (int i = 0; i < MAX; i++) {
        
        cout << "Enter student's name: ";
        cin >> students[i].name;
        cout << "Enter student's math grade: ";
        cin >> students[i].math;
        cout << "Enter student's english grade: ";
        cin >> students[i].english;
        cout << "Enter student's russian grade: ";
        cin >> students[i].russian;
        
    }
    
    Student *sortedStudents[MAX];
    for (int i = 0; i < MAX; i++) {
        sortedStudents[i] = &students[i];
    }
    
    // BEHOLD
    // АЛГОРИТМ ШЕЛЛА
    
    bool fl;
    
    do {
        
        fl = true;
        for (int i = 0; i < MAX-1; i++) {
            
            if (average(sortedStudents[i]) < average(sortedStudents[i+1])) {
                
                Student *buf = sortedStudents[i];
                sortedStudents[i] = sortedStudents[i+1];
                sortedStudents[i+1] = buf;
                fl = false;
                
            }
            
        }
        
    } while (!fl);
    
    for (int i = 0; i < MAX; i++) {
        cout << "STUDENT: " << sortedStudents[i]->name << endl;
    }
    
    return 0;
}

