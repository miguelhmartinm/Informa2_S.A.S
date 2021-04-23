#include <iostream>

using namespace std;

//const int MAXROW = 8;
//const int MAXCOLUMN = 8;

#define MAXROW (unsigned char)8
#define MAXCOLUMN (unsigned char)8

const int SER = 2;
const int RCLK = 4;
const int SRCLK = 5 ;

unsigned int digitalSignal[3] = {0, 1, 0};
unsigned int puertos[3] = {SER, RCLK, SRCLK};

//int byteI[] = { 0x7E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7E }; //I
int charA[][8] = {{0,1,1,1,1,1,1,0}, {1,1,1,1,1,1,1,1}, {1,1,0,0,0,0,1,1}, {1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1},  {1,1,0,0,0,0,1,1}, {1,1,0,0,0,0,1,1}, {1,1,0,0,0,0,1,1}};

// **************** FUNCTIONS PROTOTYPE ***************

int verificacion(int [][MAXCOLUMN]);
int imagen(int [][MAXCOLUMN]);
void dataSER(int );
void signalSRCLK();
void signalRCLK();


// *****************************************************



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

     Inicialización de los puertos digitales
    for(unsigned int i = 0 ; i < 3 ; i++ ){
        pinMode( puertos[i] , OUTPUT );
        digitalWrite( puertos[i] , 0 );
    }


    int matrizLeds[MAXROW][MAXCOLUMN];
    //int (*ptrMatrizLeds)[8][8];

    //ptrMatrizLeds = &matrizLeds;

    verificacion(matrizLeds);



    return 0;
}


// *****************************************************
// **************** FUNCTIONS DEFINITION ***************
// *****************************************************

int verificacion(int matriz[][8]){

    // Rellenado de toda la matríz con valores igual a 1
    for(int row = 0; row < MAXROW ; row++){
        for(int column = 0; column < MAXCOLUMN ; column++){
            matriz[row][column] = 1;
            //cout << " " << matriz[row][column];
            dataSER(matriz[row][column]);
            signalSRCLK();
            signalRCLK();
        }
        //cout << endl;
    }


    //dataSER(matriz[]);


    return 0;
}

//******************************************************************
int imagen(int charA[][8], int matriz[][8]){
    /*for(int row = 0; row < MAXROW ; row++){
      dataSER(charA[row]);
      signalSRCLK();
      signalRCLK();
    } */

    for(int row = 0; row < MAXROW ; row++){
      for(int column = 0; column < MAXCOLUMN ; column++){
        matriz[row][column] = charA[row][column];
        //cout << " " << matriz[row][column];
        dataSER(matriz[row][column]);
        signalSRCLK();
        signalRCLK();
      }
      //cout << endl;
    }

}


//******************************************************************
void dataSER(int bit){

    // Señal de dato SERIAL
    //digitalWrite( SER, bit);
}

//******************************************************************
void signalSRCLK(){

    // Reloj del registro de ENTRADA
    for(int bit=0; bit < 3; bit++){
//        digitalWrite( SRCLK, digitalSignal[bit]);
    }

}

//******************************************************************
void signalRCLK(){

    // Reloj del registro de SALIDA
    for(int bit=0; bit < 3; bit++){
//        digitalWrite( RCLK, digitalSignal[bit]);
    }
}


