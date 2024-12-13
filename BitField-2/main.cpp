#include "Matrix.h"
#include "Vector.h"

 int main() {
	
 	TVector<int> a(4), b(4);
 		cout << " input a(4) " << endl;
 		cin >> a;
 		b[0] = 1;
 		b[1] = 1;
 		b[2] = 1;
 		cout << "a - > " << a << endl;
 		cout << "b - > " << b << endl;
 		cout << "a + b - > " << a + b << endl;
 		cout << "a - b - > " << a - b << endl;
		cout << "a * b - > " << a * b << endl;
		cout << "a * 5 - > " << a * 5 << endl;
		cout << "a == b - > " << (a == b) << endl;
		cout << "a != b - > " << (a != b) << endl;
		cout << "a = b - > " << (a = b) << endl;
	    cout << "a + 2 - > " << a + 2 << endl;
		cout << "a - 5 - > " << a - 5 << endl;
		cout << "a.GetStartIndex()- > " << a.GetStartIndex() << endl;
		cout << "a.GetSize()- > " << a.GetSize() << endl;



        cout<<"---------------------MATRIX---------------------";


    TMatrix<int> e(5), f(5), c(3);
   size_t i, j;
 
        for (i = 0; i < 5; i++)
        for (j = i; j < 5; j++)
        {
            e[i][j] = i * 10 + j;
            f[i][j] = (i * 10 + j) * 100;
        }
    cout << "input matrix c(3) - >" << endl;
    cin >> c;
    cout << "Matrix e = " << endl << e << endl;
    cout << "Matrix f = " << endl << f << endl;
    cout << "Matrix c = " << endl << c << endl;
    cout << "e + f = " << endl << e + f << endl;
    cout << "e - f = " << endl << e - f << endl;
    cout << "e * f = " << endl << e * f << endl;
    cout << "e == f = " << (e == f) << endl;
    cout << "e != f = " << (e != f) << endl;
    c = e;
    cout << "c = e - >" << endl << c << endl;
    

 	return 0;
 }