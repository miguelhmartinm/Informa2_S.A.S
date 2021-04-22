#include <iostream>

using namespace std;

const int MAXROW = 8;
const int MAXCOLUMN = 8;

const int SER = 2;
const int RCLK = 4;
const int SRCLK = 5 ;


int verificacion(int [][MAXCOLUMN]);

int main()
{
    /*  // Caracter a ASCCI a binario
    char caracter;
    int binaryChar[8]={};
    int i = 0;

    while(1){
        cout << endl;
        cout << "Ingrese caracter: " ;
        cin >> caracter;

        cout << "Caracter " << caracter << " en ASCII: "  << int(caracter) << endl;

        caracter = int(caracter);

        do{
           caracter = caracter / 2;
           binaryChar[i] = caracter % 2;
           i++;

        } while (caracter / 2 > 0);

    for (int j = 0; j < 8; j++)
        cout << binaryChar[j];
    }*/

    int matrizLeds[MAXROW][MAXCOLUMN];
    //int (*ptrMatrizLeds)[8][8];

    //ptrMatrizLeds = &matrizLeds;

    verificacion(matrizLeds);



    return 0;
}

int verificacion(int matriz[][MAXCOLUMN]){

    // Rellenado de toda la matríz con valores igual a 1
    for(int row = 0; row < 8 ; row++){
        for(int column = 0; column < 8 ; column++){
            matriz[row][column] = 1;
            //cout << " " << matriz[row][column];
        }
        //cout << endl;
    }



    return 0;
}

void dataSER(){

    // Señal de dato serial
    digitalWrite( SER, );
}

void signalSRCLK(){

    // Reloj del registro de ENTRADA
    digitalWrite( SRCLK, );

}

void signalRCLK(){

    // Reloj del registro de SALIDA
    digitalWrite( RCLK, );
}
