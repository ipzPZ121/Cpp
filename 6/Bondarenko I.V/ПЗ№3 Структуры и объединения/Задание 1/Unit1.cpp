//---------------------------------------------------------------------------
#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#pragma hdrstop


//---------------------------------------------------------------------------

#pragma argsused

struct DataR
{
        string Famil;
        int Kbooks;
        string Pbooks;

};
const int N=3;
int main(int argc, char* argv[])
{
        DataR Readers[N];
        int i,max,m;
        Readers[0].Famil = "Sidorov";
        Readers[0].Kbooks = 1;
        Readers[0].Pbooks = "Azbuka";

        Readers[1].Famil = "Ivanov";
        Readers[1].Kbooks = 3;
        Readers[1].Pbooks = "Onegin, Dante, Bukvar";

        Readers[2].Famil = "Petrov";
        Readers[2].Kbooks = 2;
        Readers[2].Pbooks = "C++, C#";

        cout << "Spisok knig Ivanova: ";
        for (i=0; i<N; i++)
        {
                if (Readers[i].Famil=="Ivanov")
                {
                        cout << Readers[i].Pbooks;
                }
        }

        cout << "\nBolshe knig vzial ";
        m=0;
        max = Readers[m].Kbooks ;
        for(i=1;i<N;i++)
        {
              if(max<Readers[i].Kbooks)
              {
               max = Readers[i].Kbooks ;
               m=i;

              }
        }
        cout << Readers[m].Famil << ".";
        getch();
        return 0;
}
//---------------------------------------------------------------------------
 