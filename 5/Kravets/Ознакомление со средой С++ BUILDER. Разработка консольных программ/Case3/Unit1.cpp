#include <iostream.h>
#include <conio.h>
             
void main() {
double rez=0, x;
for (int i=0; i<6;i++){
cout<<"\n Please enter a number #: "<< (i+1) << "\n";
cin>>x;
if(x>4 && x<=7) {
        rez+=x;
}
cout<<"\n The sum is: "<<rez;
}
getch();
}
