#include <stdio.h>
#include <conio.h>

void main()
{
        printf("Enter 7 random digits:\n");
        double d;
        int i,n=0;
        for(i=0;i<7;i++){
        scanf("%lf", &d);
        if (d<7. && d!=5.) n++;
        }

        printf("Numbers are not equal to 5 and less than 7: \t%d\n",n);
        getch();
}
