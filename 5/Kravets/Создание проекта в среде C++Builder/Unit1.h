//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "sButton.hpp"
#include "sEdit.hpp"
#include "sLabel.hpp"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TsLabel *sLabel1;
        TsLabel *sLabel2;
        TsLabel *sLabel3;
        TsLabel *sLabel4;
        TsEdit *sEdit1;
        TsEdit *sEdit2;
        TsButton *sButton1;
        TsButton *sButton2;
        void __fastcall sButton1Click(TObject *Sender);
        void __fastcall sButton2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
