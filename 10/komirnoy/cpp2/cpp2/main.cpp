#include <iostream>
#include <iomanip>
#include <cstdlib>

struct Date {
    unsigned int day:5,
    month:4,
    year:7;
};

struct Pupil {
    char *lastName;
    char *firstName;
    float middleEval;
    Date date;
};

int main(int argc, char *argv[]) {
    int numPupils = 0, charBuffSize = 50;

    std::cout << "Input number of pupils: ";
    std::cin >> numPupils;
    std::cout << std::endl;

    Pupil *pupils = new Pupil[numPupils];

    std::cout << "Input information by each pupil" << std::endl;
    for(int i = 0; i < numPupils; i++) {
        std::cin.ignore();
        //==========
        unsigned int day = 0, month = 0, year = 0;
        std::cout << "----------" << std::endl;
        std::cout << "About " << i + 1 << " pupil: " << std::endl;
        pupils[i].lastName = new char[charBuffSize];
        for(int j = 0; j < charBuffSize; j++) {
            pupils[i].lastName[j] = ' ';
        }
         std::cout << "Last name (no more 49 symbols): ";
        std::cin.getline(pupils[i].lastName, charBuffSize);
        pupils[i].firstName = new char[charBuffSize];
        for(int j = 0; j < charBuffSize; j++) {
            pupils[i].firstName[j] = ' ';
        }
        std::cout << "First name (no more 49 symbols): ";
        std::cin.getline(pupils[i].firstName, charBuffSize);
        //==========
        do {
            std::cout << "Day (from 1 to 31 max): ";
            std::cin >> day;
        } while(day == 0 || day > 31);
        do {
            std::cout << "Month (from 1 to 12 ): ";
            std::cin >> month;
        } while(month == 0 || month > 12);
        do {
            std::cout << "Year (from 1 to 99): ";
            std::cin >> year;
        } while(year == 0 || year > 99);
        pupils[i].date.day = day;
        pupils[i].date.month = month;
        pupils[i].date.year = year;
        //==========
        std::cout << "Middle evaluation: ";
        std::cin >> pupils[i].middleEval;
    }

    std::cout << "==========" << std::endl;
    std::cout << "==========" << std::endl;
    std::cout << "Chart number of pupils by each month" << std::endl;
    std::cout << std::endl;
    char *monthes[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Des"};
    char **dataChart = new char*[12];
    int numByMonth[12] = {0};
    int maxNum = 0;
    for(int i = 0; i < numPupils; i++) {
        ++numByMonth[pupils[i].date.month - 1];
    }
    maxNum = numByMonth[0];
    for(int i = 1; i < 12; i++) {
        if(numByMonth[i] > maxNum) maxNum = numByMonth[i];
    }
    for(int i = 0; i < 12; i++) {
        std::cout <<std::setw(4) << std::setiosflags(std::ios::right) << monthes[i];
        dataChart[i] = new char[numByMonth[i]];
        std::cout << std::setw(maxNum) << std::setiosflags(std::ios::right);
        for(int j = 0; j < numByMonth[i]; j++) {
            dataChart[i][j] = '*';
            std::cout << dataChart[i][j];
        }
        for(int j = 0; j < maxNum - numByMonth[i]; j++) {
            dataChart[i][j] = ' ';
            std::cout << dataChart[i][j];
        }
        std::cout << std::setw(4) << std::setiosflags(std::ios::right) << numByMonth[i] << std::endl;
    }

    std::cin.ignore();
    std::cout << std::getchar();

    return EXIT_SUCCESS;
}