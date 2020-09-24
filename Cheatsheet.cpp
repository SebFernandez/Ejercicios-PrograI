#include <iostream>

using namespace std;

class Box   {
    public:
        int x, y, z;

        //A constructor will have exact same name as the class and it does not have any return type at all, not even void.
        Box (void);
        void sumarTodo (void);
};

//Herencia.
class volumeBox:Box {
    public:
        int volumen;

        volumeBox (void);
        void figura (void);
};

Box::Box (void) {
    cout << "Objeto creado" << endl;

    this->x = 5;
    this->y = 2;
    this->z = 3;
}

void Box::sumarTodo(void)    {
    int rtdo = 0;

    rtdo = this->x + this->y + this->z;

    cout << endl << "Suma de todo: " << rtdo << endl;
}

volumeBox::volumeBox (void) {
    cout << "Constructor de child creado." << endl;

    this->volumen = this->x * this->y * this->z;
}

void volumeBox::figura (void)   {
    if (this->x == this->y && this->x == this->z && this->y == this->z) {
        cout << "Es un cubo." << endl;
    }   else    {
        cout << "Es un rectángulo." << endl;
    }
}

void pSwap (int * pA, int * pB) {
    int tmp = *pA;

    *pA = *pB;
    *pB = tmp;
}

void rSwap (int &a, int &b) {
    int tmp = a;

    a = b;
    b = tmp;
}


int main () {
    //Original.
    Box box1;
    
    //Hereda atributos de Box.
    volumeBox vBox1;

    cout << endl << "Prueba de atributos" << endl << "X: " << box1.x << ", Y: " << box1.y << ", Z: " << box1.z << endl;

    box1.sumarTodo();
    vBox1.figura();

    /* --------------------------------------------------------------------------------------------------------------- */

    int a = 5, b = 10;
    int *pA = &a, *pB = &b;

    cout << endl << "Valores" << endl << "A: " << a << ", B: " << b << endl;

    //Uso de unteros.
    pSwap (pA, pB);
    cout << endl << "--------Función pSwap---------" << endl << "Valores" << endl << "A: " << a << ", B: " << b << endl;

    //Uso de referencias.
    rSwap (a, b);
    cout << endl << "--------Función rSwap---------" << endl << "Valores" << endl << "A: " << a << ", B: " << b << endl;

    cout << endl << "Goodbye world!" << endl;
}