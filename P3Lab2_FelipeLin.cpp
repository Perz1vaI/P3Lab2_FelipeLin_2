#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
using namespace std;
void Ejercicio3_Recurisva(int, double);
int main()
{
    int menu;
    cout << "1. Ejercicio 1 \n2. Ejercicio 2\n3. Ejercicio 3\n4. Salida" << endl;
    cin >> menu;
    while (menu != 4)
    {
        switch (menu)
        {
        case 1:
        {

            break;
        }
        case 2:
        {

            int n;
            cout << "Ingrese el tamaño de la matriz: ";
            cin >> n;
            int matriz[n][n];

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matriz[i][j] = rand() % 89 + 10;
                }
            }

            for (int i = 0; i < n; i++)
            {
                cout << "[";
                for (int j = 0; j < n; j++)
                {
                    cout << setw(3) << matriz[i][j] << " ";
                }
                cout << "]" << endl;
            }

            double mediana = 0, suma = 0, sumatoria_desviacion = 0, desviacion = 0;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    suma = suma + matriz[i][j];
                }
            }
            mediana = suma / n;
            cout << suma << "= suma\n";
            cout << "Mediana = " << mediana << endl;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    sumatoria_desviacion += pow(matriz[i][j] - mediana, 2);
                }
            }

            desviacion = sqrt(sumatoria_desviacion / n);

            cout << "Sumatoria de la desvicaion estandar= " << sumatoria_desviacion << endl;
            cout << "Desviacion estandar= " << desviacion << endl;

            double matriz_estandarizada[n][n];

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matriz_estandarizada[i][j] = (matriz[i][j] - mediana) / desviacion;
                }
            }

            for (int i = 0; i < n; i++)
            {
                cout << "[";
                for (int j = 0; j < n; j++)
                {
                    cout << setw(10) << matriz_estandarizada[i][j] << " ";
                }
                cout << "]" << endl;
            }

            break;
        }
        case 3:
        {
            int n;
            cout << "Ingrese el limite: ";
            cin >> n;

            Ejercicio3_Recurisva(n, 0);

            break;
        }

        default:
            cout << "No existe esa opcion!" << endl;
            break;
        }

        cout << "1. Ejercicio 1 \n2. Ejercicio 2\n3. Ejercicio 3\n4. Salida" << endl;
        cin >> menu;
    }
}

void Ejercicio3_Recurisva(int n, double suma)
{
    double pi, sumatoria = 0, suma2;

    if (n == 0)
    {
        suma += pow(-1, n) / ((2 * n) + 1);
        pi = 4 * suma;
        cout << "La aproximacion es = " << pi << endl;
    }
    else
    {
        suma2 = suma2 + pow(-1, n) / ((2 * n) + 1);
        Ejercicio3_Recurisva(n - 1, suma + suma2);
    }
}
