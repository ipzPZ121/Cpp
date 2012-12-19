//---------------------------------------------------------------------------
#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

const int N = 10;
int main(int argc, char* argv[])
{
        int arr[N];
        int i;
        //Заполняем случайно массив
        randomize();
        for(i=0;i<N;i++)
        {
                arr[i] = 100.0*rand()/RAND_MAX-50;
        }
        cout << "Array: \n";
        for(i=0;i<N;i++)
        {

            printf("%d\t",arr[i]);

        }
        cout << "\n\nResult:\n";
        for(i=0;i<N;i++)
        {

            if (arr[i]>=0)
            {
                arr[i]=arr[i]+1;
            }

        }
        for(i=0;i<N;i++)
        {

            cout << arr[i] << "\t";

        }
        getch();

        return 0;
}
//---------------------------------------------------------------------------
