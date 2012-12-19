//---------------------------------------------------------------------------
#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        int arr[10];
        int i;
        randomize();
        for(i=0; i<10; i++)
        {
                arr[i] = 100.0*rand()/RAND_MAX-50;
        }
        cout << "Array[10]: \n\n";
        for (i=0; i<10; i++)
        {
                cout << arr[i] << "\t";
        }
        cout << "\n\n\n\nResult: \n\n";
        for (i=0; i<10; i++)
        {
                if (arr[i]>=0) arr[i]++;
                cout << arr[i] << "\t";

        }
        getch();
        return 0;
}
//---------------------------------------------------------------------------
 