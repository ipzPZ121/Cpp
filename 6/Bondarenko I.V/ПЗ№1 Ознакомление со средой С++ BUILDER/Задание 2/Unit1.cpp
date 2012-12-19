#include <stdio.h>
#include <conio.h>

void main()
{
        printf("Enter 7 random digits:\n");
        double d;
        int i=0;
        int n=0;
        ScLab:
        scanf("%lf", &d);
        i++;
        if (d<7. && d!=5.) n++;
        if (i<7) goto ScLab;

        printf("Numbers are not equal to 5 and less than 7: \t%d\n",n);
        getch();
}
