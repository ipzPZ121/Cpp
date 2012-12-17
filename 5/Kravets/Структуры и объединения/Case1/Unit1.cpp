#include <stdlib.h> //здесь ф-ии случайных чисел
#include <string.h> //здесь ф-ии работы со строками
#include <conio.h>  //здесь getch();
#include <iostream> // здесь все что std::
#include <time.h>   // тип time
using namespace std;

const int AMOUNT_OF_STUDENTS =10; // не больше 99 можно указывать
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
    char s[100] = {'S','t','u','d','e','n','t',' '}; // можно и другую гыдоту




student students[AMOUNT_OF_STUDENTS];
srand(time(NULL)); //функция рандомизации по времени - без нее при каждом новом
                   //запуске программы случайные элементы будут неслучайны))))
                   
cout << "Please print Names of " << AMOUNT_OF_STUDENTS << " " 
     << s2.c_str() << "s" << endl;

    for(int i=0; i<AMOUNT_OF_STUDENTS; i++) {
            cout << i+1 << ". ";
            cin >> s2; // вводим имена поочереди, я чтоб не париться поставил i = 5
            
    // функция strcpy принимает аргументы: массив(в который) и указатель копируемого
            char *s1_ptr = &s[0];                            // указатель на массив
            const char* s2_ptr = s2.c_str(); // функция получения из строки(типа) указателя на строку(массив)
            const char* aP = &a[0];                  // еще один указатель на массив
          
          
          strcpy(students[i].lastName,s1_ptr);       // копирование слова "студент"
          
          a[0] = ' ';  //пишем пробел в строку... можно было так же записать его в
                       //виде а[0] = 0x20; или a[0] = 32; - все тот же ASCII
          a[1] = 0;    // конец строки
          strcat(students[i].lastName,aP);           // и вставляем пробел в строку 
          
          int x = i+1;                //представим номер студента в качестве строки
          if(x > 9){              //если номер занимает два знака (но только до 100)
               a[0] = (i/10)+48;         // ASCII коды цифр начинаются с 48
               a[1] = (i%10)+48;         // поэтому добавляем смещение 48
               a[2] = 0;
          }
          else {                         // иначе..
               a[0] = i+48;
               a[1] = 0;
               a[2] = 0;
          } 
          strcat(students[i].lastName,aP); //конкатенация студента с номером п\п
          //
          a[0] = ' ';  //пишем пробел в строку..
          a[1] = 0;    // конец строки
          strcat(students[i].lastName,aP);           // и вставляем пробел в строку 
          strcat(students[i].lastName,s2_ptr);// конкатенация(добавляем имя студента)
          students[i].number = i;                // собсно порядковый номер студента
          students[i].result = rand()%100+1;     // оценка стд
    }
cout << endl << "BEFORE BUBBLE SORT:" << endl << endl;         
      //вывод начального массива структур
    for(int i = 0; i < AMOUNT_OF_STUDENTS; i++){
            cout << students[i].lastName << endl << "mark: " 
            <<  students[i].result << endl << endl;
    }
        
buble_sort: //если нужна замена, то меняем по очереди все элементы students[i]
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
// выведем сортированный массив..
for(int i = 0; i < AMOUNT_OF_STUDENTS; i++){
        cout << students[i].lastName << endl << "mark: " 
        <<  students[i].result << endl << endl;
        }                      
      
      getch();
}
}

