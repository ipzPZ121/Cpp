//---------------------------------------------------------------------------
#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{

        int arr[5][5];
        int i, j, sum=0;
        randomize();
        cout << "Random array: \n";
        for (i = 0; i < 5; i++)
        {
                for (j = 0; j < 5; j++)
                {
                       arr[i][j] = 100.0*rand()/RAND_MAX;

                       cout << arr[i][j] << "\t";
                }

                cout << "\n\n";
        }
        cout << "\n\n\n";
        cout << "Summa\n\n|_|\n|_|\n\n";


        for (i = 0; i < 5; i++)
        {
                for (j = 0; j < 5; j++)
                {
                        if (i==2 || i==4 || j==0 || j==4)
                        {
                                sum+=arr[i][j];
                        }

                }

        }
        cout << sum << "\n\n";
        getch();
        return 0;
}
//---------------------------------------------------------------------------
 