#include <iostream.h>
#include <conio.h>

void main() {

double values[6];
double rez=0;

printf("\n\tPlease enter six numbers separated by spaces\n");

scanf("%lf %lf %lf %lf %lf %lf",&values[0],&values[1],&values[2],&values[3],&values[4],&values[5]);

if(values[0]>4 && values[0]<=7){
        rez+=values[0];
}
if(values[1]>4 && values[1]<=7){
        rez+=values[1];
}
if(values[2]>4 && values[2]<=7){
        rez+=values[2];
}
if(values[3]>4 && values[3]<=7){
        rez+=values[3];
}
if(values[4]>4 && values[4]<=7){
        rez+=values[4];
}
if(values[5]>4 && values[5]<=7){
        rez+=values[5];
}
printf("%s %lf","\n The sum is: ",rez);
getch();
}
