#include "TStack.h"
#include <map>
template <class T>
class TFormula : public TStack<T>{
private:
TStack<char> operands;
string Formula;
string PostfixForm;
public:
TFormula(string polinom){
    Formula = polinom;
}
void FormulaChecker(){
    int index = 1;
    size_t errors = 0;
for(char c: Formula){
    if(c=='(')
    {
         this->Push(index++);
         //cout<<"(";
    }
    if(c==')')
    {
        //cout<<')';
        if(!(this->IsEmpty())){
            cout<< this->Top()<<' '<<index++<<endl;
            this->Pop();continue;
        }
        cout << 0 <<' '<< index++<<endl;
        errors++;
    }
}
while(!(this->IsEmpty())){
    cout<<this->Top()<<' '<<0<<endl;
    errors++;
    this->Pop();
}
    cout<<errors<<"errors"<<endl;
}
string FormulaConverter(){
     map<char,int> char_to_num;
     char_to_num['('] = 0;
     char_to_num[')'] = 1;
     char_to_num['+'] = 2;
     char_to_num['-'] = 2;
     char_to_num['*'] = 3;
     char_to_num['/'] = 3;
    string postfix = "";
    for(char c : Formula){
         if(char_to_num[c]!=1 && char_to_num[c]!=2 && char_to_num[c]!=0 && char_to_num[c]!=3)    
         {
          postfix+=c; continue;
         }
         if(char_to_num[c]==1){
             while(this->Top()!='('){
             postfix+=this->operands.Top();
             this->operands.Pop();
             }
             this->operands.Pop();
         }
         if(char_to_num[c]>char_to_num[this->operands.Top()])
         {
          this->operands.Push(c); continue;
         }
         if(this->IsEmpty()) {
         this->Push(c); continue;
         }
        if(c == '(') 
        {
            cout<<"123";
         this->operands.Push(c); continue;
        }
     while(char_to_num[this->operands.Top()]>char_to_num[c]){
         postfix+=this->operands.Top();
         this->operands.Pop();
     }
     postfix+=c;
     continue;
     }
     while(!(this->operands.IsEmpty())){
         postfix+=this->operands.Top();
         this->operands.Pop();
     
    }
    return postfix;
}
double FormulaCalculator();
};