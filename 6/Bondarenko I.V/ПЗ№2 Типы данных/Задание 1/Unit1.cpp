//---------------------------------------------------------------------------
#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        int a[10] = {10,34,-2,5,-10,9,-5,2,-34,4};
        int i,j,p;
        cout << "Array: \n";
        for (i=0;i<10;i++)
        {
              cout << a[i] << "\t";
        }
        for(i=0;i<10;i++)
        {
                for(j=i+1;j<10;j++)
                {
                    if (a[i]== -a[j])
                    {
                        p=a[i];
                        a[i] = a[j];
                        a[j] = p;
                    }
                }
        }
        cout << "\n\nResult: \n";
        for(i=0;i<10;i++)
        {
                cout << a[i] << "\t";
        }
        getch();
        return 0;
}
//---------------------------------------------------------------------------
 