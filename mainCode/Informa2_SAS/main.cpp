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

int (*matrizLeds)[MAXCOLUMN] = new int[8][8];


int patron[MAXROW][MAXCOLUMN];


//int charA[]={65,126,255,195,255,255,195,195,195}; //A
//int charI[]={73,255,255,24,24,24,24,255,255}; //I
//int charE[]={69,255, 255, 192, 254, 254, 192, 255, 255}; //E
//int charJ[]={74,3, 3, 3, 3, 3, 195, 255, 126}; // J


int characters[][9] = { {65,126,255,195,255,255,195,195,195},        // A
                        {73,255,255,24,24,24,24,255,255},            // I
                        {69,255, 255, 192, 254, 254, 192, 255, 255}, // E
                        {74,3, 3, 3, 3, 3, 195, 255, 126}            // J
                      };

// **************** FUNCTIONS PROTOTYPE ***************

int verificacion(int [][MAXCOLUMN]);
int imagen(int [][MAXCOLUMN],int [][MAXCOLUMN]);


//int decimalToBinary(int [], int (*p)[MAXCOLUMN]);
int decimalToBinary(int []);

void dataSER(int );
void signalSRCLK();
void signalRCLK();


// *****************************************************



int main()
{   //int b[] = {8,41};
    //int arreglo[][3] = {{*b},{7,54},{35,15}};
    //int patron[MAXROW][MAXCOLUMN];
    //int (*ptrPatron)[MAXCOLUMN] = patron;

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

//     Inicialización de los puertos digitales
//    for(unsigned int i = 0 ; i < 3 ; i++ ){
//        pinMode( puertos[i] , OUTPUT );
//        digitalWrite( puertos[i] , 0 );
//    }
    char caracter;

    cout << "Caracter: ";
    cin >> caracter;

    //cout << "Aquí: " << **(arreglo+1) << endl;

    //cout << "Aquí" << *(*(characters+1)+3) ;
    cout << "Decimal: " << **(characters+2) ;

    for( int i = 0; i < 4 ; i++ ){
//        if( int(caracter) == **(characters + i) ){
//            decimalToBinary( *(characters+i), ptrPatron );
//        }
        if( caracter == **(characters+i) ){
            //Rif( caracter == characters[i][0] ){
            //out << "Valor: "<< characters[i][0];
            //cout << "Bit: "<< characters[i+1][0];
            //cout << "Bit: "<< charA[i+1];
            cout << characters[i];
            //decimalToBinary( characters[i], ptrPatron );

            // Envía como parámetro el arreglo que esté en la posición actual
            decimalToBinary( characters[i]);
        }
    }
/*
    for( int i = 0; i < 1 ; i++ ){
        if( int(caracter) == **(characters + i) ){
            //decimalToBinary( *(characters+i), ptrPatron );
            //decimalToBinary( *(characters+i));
            //decimalToBinary( characters[i][0] );
        }
//        if( caracter == charA[0] ){
//            //cout << "Valor: "<< characters[i][0];
//            //cout << "Bit: "<< characters[i+1][0];
//            //cout << "Decimal: "<< charA[i+1];
//            //cout << characters[i];
//            //decimalToBinary( characters[i], ptrPatron );
//            decimalToBinary( charA);
//        }
    }*/


    //int matrizLeds[MAXROW][MAXCOLUMN];
    //int (*ptrMatrizLeds)[8][8];

    //ptrMatrizLeds = &matrizLeds;

//    verificacion(matrizLeds);
//    imagen(ptrPatron, matrizLeds);
    imagen(patron, matrizLeds);

    return 0;
}


// *****************************************************
// **************** FUNCTIONS DEFINITION ***************
// *****************************************************

//int patron[MAXROW][MAXCOLUMN];
//int charA[]={65,126,255,195,255,255,195,195,195};


int eraser(int matriz[][8]){

    // Rellenado de toda la matríz con valores igual a 1
    for(int row = 0; row < MAXROW ; row++){
        for(int column = 0; column < MAXCOLUMN ; column++){
            matriz[row][column] = 0;
            cout << " " << matriz[row][column];
            //dataSER(matriz[row][column]);
            signalSRCLK();
            signalRCLK();
        }
        //cout << endl;
    }

    //dataSER(matriz[]);


    return 0;
}


//int decimalToBinary( int arrayPatron[], int (*patron)[8] ){
int decimalToBinary( int arrayPatron[] ){

    int bit, decimal=0;


    //cout << "\nChar in function: " << arrayPatron[0];
    //cout << "\nDecimal in Function: " << arrayPatron[1];
    for(int j = 0; j < 8; j++){
        bool biteDivide = true;
        int k=8;
        //for(int k = 7; k >= 0; k--){
            //division =  arrayPatron[j+1] / 2;
            decimal =  arrayPatron[j+1];
            //cout << "\nDecimal in Function: " << decimal;
            //bit = arrayPatron[j+1] % 2;
            //bit = decimal % 2;
            while(biteDivide){
                k--;
                //division =  *(arrayPatron + (j+1) ) / 2;
                bit = decimal % 2;

                //division =  arrayPatron[j+1] / 2;
                //division =  arrayPatron[m] / 2;
                //cout << "-*" << division;
                //cout << "-*" << bit;
                //bit = *(arrayPatron + (j+1) ) % 2;
                //bit = arrayPatron[j+1] % 2;

                //*(*(patron+j)+k) = bit;
                patron[j][k] = bit;
                //cout << "-" << bit;
                //m++;

                if( decimal / 2 == 0 ){
                    biteDivide = false;
                }

                decimal = decimal / 2;
            }
            //cout << "K: " << k << endl;
            for(int m=k-1; m > 0 ; m-- ){
                patron[j][m] = 0;
                // *(*(patron+j)+k) = 0;
            }
            //cout << "-" << bit;
        //} //END for k
        cout << endl;
    }

    return 0;
}


int verificacion(int matriz[][8]){

    // Rellenado de toda la matríz con valores igual a 1
    for(int row = 0; row < MAXROW ; row++){
        for(int column = 0; column < MAXCOLUMN ; column++){
            matriz[row][column] = 1;
            cout << " " << matriz[row][column];
            //dataSER(matriz[row][column]);
            signalSRCLK();
            signalRCLK();
        }
        //cout << endl;
    }

    //dataSER(matriz[]);


    return 0;
}

//******************************************************************
int imagen(int patron[][8], int matriz[][8]){
    /*for(int row = 0; row < MAXROW ; row++){
      dataSER(charA[row]);
      signalSRCLK();
      signalRCLK();
    } */

    for(int row = 0; row < MAXROW ; row++){
      for(int column = 0; column < MAXCOLUMN ; column++){
        matriz[row][column] = patron[row][column];
        cout << " " << matriz[row][column];
        dataSER(matriz[row][column]);
        signalSRCLK();
        signalRCLK();
      }
      cout << endl;
    }
    return 0;
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


