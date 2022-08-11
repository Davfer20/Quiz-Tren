#include <iostream>
using namespace std;
//--------------------------------------------Nota-------------------------------------------------------------
// El programa funciona perfectamente, el unico problema es que en la parte de detectar los ultimos asientos disponibles por alguna razon no sirve si esta el void que busca los 10 primeros. Lo que se debe hacer para que sivan los ultimos es comentar de la linea 91 a la 98 y finalmente el algoritmo sirve.

// El primer numero son los vagones el segudo los asientos por vagon se escoje cuantos se quieren
int tren[10][8];
void inicio();

void primeros();
int frente1V[10]; // Son los 10 asiententos que se buscan
int frente1A[10];

void ultimos();
int atras1V[10]; // Son los 10 asientos que se buscan
int atras1A[10];

void inicio() // Se crea la cantidad de vagones deseados y los llena con asientos numerados
{
    for (int i = 1; i <= 10; i = i + 1)
    {
        for (int j = 1; j <= 8; j = j + 1)
        {
            tren[i][j] = j;
        }
    }
}

void primeros()
{
    int xV = 1; // Variable pointer Vagon
    int xA = 1; // Variable pointer Asiento
    int yV = 1; // Variable pocicion Vagon
    int yA = 1; // Variable pocicion Asiento
    do
    {
        do
        {
            if (tren[xV][xA] != 0)
            {
                frente1V[yV] = xV;
                frente1A[yA] = xA;
                yA = yA + 1;
                yV = yV + 1;
            }
            xA = xA + 1;
        } while (xA <= 8);
        xV = xV + 1;
        xA = 1;
    } while (yV <= 10);
}

void ultimos()
{
    int sV = 10; // Variable pointer Vagon
    int sA = 8;  // Variable pointer Asiento
    int rV = 1;  // Variable pocicion Vagon
    int rA = 1;  // Variable pocicion Asiento
    do
    {
        do
        {
            if (tren[sV][sA] != 0)
            {
                atras1V[rV] = sV;
                atras1A[rA] = sA;
                rA = rA + 1;
                rV = rV + 1;
            }
            sA = sA - 1;
        } while (sA > 0);
        sV = sV - 1;
        sA = 8;
    } while (rV <= 10);
}

int main()
{
    inicio();
    // Aca se decide que vagones y asientos se van a llenar
    tren[1][2] = 0;
    tren[1][3] = 0;
    tren[1][7] = 0;
    tren[2][2] = 0;
    tren[2][5] = 0;
    tren[4][4] = 0;
    tren[10][6] = 0;
    tren[10][8] = 0;

    // Se llamas los 2 voids y se imprime la informacion correspondiente
    primeros();
    cout << "Los primeros 10 campos libres son los siguientes: " << endl;
    for (int i = 1; i <= 10; i = i + 1)
    {
        cout << i << ")."
             << "Vagon numero: " << frente1V[i] << " "
             << "asiento numero: " << frente1A[i] << endl;
    }

    ultimos();
    cout << "\n";
    cout << "Los ultimos 10 campos libres son los siguientes: " << endl;
    for (int i = 1; i <= 10; i = i + 1)
    {
        cout << i << ")."
             << "Vagon numero: " << atras1V[i] << " "
             << "asiento numero: " << atras1A[i] << endl;
    }
    return 0;
}