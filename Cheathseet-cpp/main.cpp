#include <iostream>
#include <funciones.h>

/*
                                    ________________________________________
                                   | Misterios de iostream y namespace std |

The same situation can arise in your C++ applications. For example, you might be writing some code that has a function
called xyz() and there is another library available which is also having same function xyz().
Now the compiler has no way of knowing which version of xyz() function you are referring to within your code.

A namespace is designed to overcome this difficulty and is used as additional information to differentiate similar functions,
classes, variables etc. with the same name available in different libraries.
Using namespace, you can define the context in which names are defined. In essence, a namespace defines a scope.

src: https://www.tutorialspoint.com/What-does-using-namespace-std-mean-in-Cplusplus

*/

using namespace std;

int main()  {
    int i = 0;

    //Construye el objeto.
    const funciones f;

    char input [10];

    for (i; i < 10; i++)    {
        cout << "Índice: " << i << endl;
    }

    cout << endl << "Ingresá algo: ";
    cin >> input;
    cout << endl << input << endl;
/*
    cout << endl << "Var x: " << *pX << " y var y: " << *pY << endl;
    pSwap (pX, pY);
    cout << endl << "Var x: " << *pX << " y var y: " << *pY << endl;

    rSwap (f.x, f.y);
    cout << endl << "Var x: " << x << " y var y: " << y << endl;
*/
    //El printf de C; el endl sería el /n.
    cout << endl << "Goodbye world!" << endl;

    return 0;
}
