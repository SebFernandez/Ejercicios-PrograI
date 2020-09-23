#include <iostream>

using namespace std;

//Llamado mediante punteros de los argumentos
void pSwap (int *pX, int *pY)    {
    int tmp;

    tmp = *pX;
    *pX = *pY;
    *pY = tmp;

    return;
}

//Llamado mediante referencia de los argumentos
void rSwap (int &x, int &y)    {
    int tmp;

    tmp = x;
    x = y;
    y = tmp;

    return;
}

int main()  {
    int i = 0, x = 10, y = 5;

    int *pX = &x, *pY = &y;

    char input [10];

    for (i; i < 10; i++)    {
        cout << "Índice: " << i << endl;
    }

    cout << endl << "Ingresá algo: ";
    cin >> input;
    cout << endl << input << endl;

    cout << endl << "Var x: " << *pX << " y var y: " << *pY << endl;
    pSwap (pX, pY);
    cout << endl << "Var x: " << *pX << " y var y: " << *pY << endl;
    rSwap (x, y);
    cout << endl << "Var x: " << x << " y var y: " << y << endl;

    //El printf de C; el endl sería el /n.
    cout << endl << "Goodbye world!" << endl;

    return 0;
}
