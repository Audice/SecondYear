#include "Matrix.h"


int main() {
    TMatrix<int> a(5), b(5), c(3);
    TVector<int> v(3),res(3);
    int i, j;
 
        for (i = 0; i < 5; i++)
        for (j = i; j < 5; j++)
        {
            a[i][j] = i * 10 + j;
            b[i][j] = (i * 10 + j) * 100;
        }
    cout << "input matrix c(3) - >" << endl;
    cin >> c;
    cout << "input vector v(3) - >" << endl;
    cin >> v;
    res = c*v;
    cout << "Vector res = " << endl << res << endl;
    cout << "Matrix a = " << endl << a << endl;
    cout << "Matrix b = " << endl << b << endl;
    cout << "Matrix c = " << endl << c << endl;
    cout << "a + b = " << endl << a + b << endl;
    cout << "a - b = " << endl << a - b << endl;
    cout << "a * b = " << endl << a * b << endl;
    cout << "a == b = " << (a == b) << endl;
    cout << "a != b = " << (a != b) << endl;
    c = a;
    cout << "c = a - >" << endl << c << endl;
    return 0;
}