#include <stdlib.h> //����� �-�� ��������� �����
#include <string.h> //����� �-�� ������ �� ��������
#include <conio.h>  //����� getch();
#include <iostream> // ����� ��� ��� std::
#include <time.h>   // ��� time
using namespace std;

const int AMOUNT_OF_STUDENTS =10; // �� ������ 99 ����� ���������
const int SCORES = 10; 

 struct student{
                char lastName[100];
                int number;
                int result;
        };

int main(){
while(1){
    char a[3];
    char b = '"';
    string s2;
    int tempi;
    char temp[100];
    char s[100] = {'S','t','u','d','e','n','t',' '}; // ����� � ������ ������




student students[AMOUNT_OF_STUDENTS];
srand(time(NULL)); //������� ������������ �� ������� - ��� ��� ��� ������ �����
                   //������� ��������� ��������� �������� ����� ����������))))
                   
cout << "Please print Names of " << AMOUNT_OF_STUDENTS << " " 
     << s2.c_str() << "s" << endl;

    for(int i=0; i<AMOUNT_OF_STUDENTS; i++) {
            cout << i+1 << ". ";
            cin >> s2; // ������ ����� ���������, � ���� �� �������� �������� i = 5
            
    // ������� strcpy ��������� ���������: ������(� �������) � ��������� �����������
            char *s1_ptr = &s[0];                            // ��������� �� ������
            const char* s2_ptr = s2.c_str(); // ������� ��������� �� ������(����) ��������� �� ������(������)
            const char* aP = &a[0];                  // ��� ���� ��������� �� ������
          
          
          strcpy(students[i].lastName,s1_ptr);       // ����������� ����� "�������"
          
          a[0] = ' ';  //����� ������ � ������... ����� ���� ��� �� �������� ��� �
                       //���� �[0] = 0x20; ��� a[0] = 32; - ��� ��� �� ASCII
          a[1] = 0;    // ����� ������
          strcat(students[i].lastName,aP);           // � ��������� ������ � ������ 
          
          int x = i+1;                //���������� ����� �������� � �������� ������
          if(x > 9){              //���� ����� �������� ��� ����� (�� ������ �� 100)
               a[0] = (i/10)+48;         // ASCII ���� ���� ���������� � 48
               a[1] = (i%10)+48;         // ������� ��������� �������� 48
               a[2] = 0;
          }
          else {                         // �����..
               a[0] = i+48;
               a[1] = 0;
               a[2] = 0;
          } 
          strcat(students[i].lastName,aP); //������������ �������� � ������� �\�
          //
          a[0] = ' ';  //����� ������ � ������..
          a[1] = 0;    // ����� ������
          strcat(students[i].lastName,aP);           // � ��������� ������ � ������ 
          strcat(students[i].lastName,s2_ptr);// ������������(��������� ��� ��������)
          students[i].number = i;                // ������ ���������� ����� ��������
          students[i].result = rand()%100+1;     // ������ ���
    }
cout << endl << "BEFORE BUBBLE SORT:" << endl << endl;         
      //����� ���������� ������� ��������
    for(int i = 0; i < AMOUNT_OF_STUDENTS; i++){
            cout << students[i].lastName << endl << "mark: " 
            <<  students[i].result << endl << endl;
    }
        
buble_sort: //���� ����� ������, �� ������ �� ������� ��� �������� students[i]
           for(int pass = AMOUNT_OF_STUDENTS - 1; pass > 0 ; pass --){
                   for(int i = 0; i < pass; i++){
                           if(students[i].result > students[i+1].result){
                               

                               const char* t_p = &temp[0];
                               const char* res_p = &students[i].lastName[0];
                               const char* res_p1 = &students[i+1].lastName[0];
                               
                               strcpy(temp,res_p1);
                               strcpy(students[i+1].lastName,res_p);
                               strcpy(students[i].lastName,t_p);
           //========================================================
                               tempi = students[i+1].result;
                               students[i+1].result = students[i].result;
                               students[i].result = tempi;
           //========================================================
                               tempi = students[i+1].number;
                               students[i+1].number = students[i].number;
                               students[i].number = tempi;
                               }
                     }
           }

cout << endl << "AFTER BUBBLE SORT:" << endl << endl;
// ������� ������������� ������..
for(int i = 0; i < AMOUNT_OF_STUDENTS; i++){
        cout << students[i].lastName << endl << "mark: " 
        <<  students[i].result << endl << endl;
        }                      
      
      getch();
}
}

