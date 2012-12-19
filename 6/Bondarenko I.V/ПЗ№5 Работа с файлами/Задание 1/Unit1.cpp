#include <stdio.h>
#include <conio.h>


int main()
{
        FILE *FileF,*FileG,*FileH;
        if ((FileF=fopen("f.txt","rt"))==NULL)
        {
                printf("Cannot open input file.\n");
                getch();
                return 1;
        }
        if ((FileG=fopen("g.txt","w"))==NULL)
        {
                printf("Cannot open input file.\n");
                getch();
                return 1;
        }
        if ((FileH=fopen("h.txt","w"))==NULL)
        {
                printf("Cannot open input file.\n");
                getch();
                return 1;
        }
        int Num;
        while (fscanf(FileF,"%i",&Num)!=EOF)
        {
                printf("%i ",Num);
                if (Num % 2==0)
                {
                        fprintf(FileG,"%i ",Num);
                }
                else
                {
                        fprintf(FileH,"%i ",Num);
                }
        }
        getch();
        return 0;
}
