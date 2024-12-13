#include "TFormula.h"

int main(){
    cout<<"input polinom"<<endl;
    string polinom;
    cin>>polinom;
    TFormula<int> a(polinom);
    a.FormulaChecker();
    cout<<endl<<a.FormulaConverter();
    return 0;
}