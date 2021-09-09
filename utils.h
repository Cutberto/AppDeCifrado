#pragma once
#include <iostream>
#include <algorithm> 
#include <vector>
#include <string>
#include <math.h>
#include <cmath>

using namespace std;

void divideTheString(string str, int n) {
    int str_length = str.size();
    if (str_length % n != 0) {
        cout << "Can't divide string into equal parts" << endl;
        return;
    }
    int part_size = str_length / n;
    for (int i = 0; i < str_length; i++) {
        if (i != 0 && i % part_size == 0) {
            cout << endl;
        }
        cout << str[i];
    }
    cout << endl;
}



/*
funcion cifrarBloque
recibe un substring del texto a encriptar y devuelve el texto ya encriptado

recibe: string bloque: texto a cifrar
devuelve: string : valor cifrado

*/
string cifrarBloque(string bloque, int nBloque) {
    //raiz del tama�o de str a cifrar
    int matrixLen = ceil(sqrt(bloque.length()));
    //char matrix[matrixLen][matrixLen];
    vector<vector<char> > matrix(100000);
    for (int i = 0; i < matrixLen; i++)
        matrix[i].resize(100000);

    int pos = 0;
    //cout << "matriz declarada \n Iniciando ciclo de llenado de matriz \n";
    for (int i = 0; i < matrixLen; i++) {
        for (int j = 0; j < matrixLen; j++) {
            //ciclo para llenar la matriz con el string 

            //revisar si todavia no se acab� el string
            if (pos < bloque.length()) {
                matrix[i][j] = bloque[pos]; //:'( :c
                pos++;
            }
            else {
                matrix[i][j] = '$';
            }
        }
    }
    // cout << "matriz llenada. Iniciando cambio de filas x columnas \n \n";
    //  cout << "imprimiendo matriz original \n";
     /*  for (int i = 0; i < matrixLen;i++){
         for (int j= 0; j < matrixLen;j++){
           cout << matrix[i][j] << " ";
         }
         cout << endl;
       }*/
       //cambiar filas por columnas
    char temp = ' ';
    for (int i = 1;i < matrixLen;i++) {
        for (int j = 0;j < i;j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;

        }

    }
    //  cout << "imprimiendo matriz intercambiada \n";
   /*   for (int i = 0; i < matrixLen;i++){
        for (int j= 0; j < matrixLen;j++){
          cout << matrix[i][j] << " ";
        }
        cout << endl;
      }
  */
  //  cout << "filas y columnas intercambiadas \n iniciando creaci�n de matriz secreta\n";
    //matriz clave secreta
    //char claveSecreta[matrixLen][matrixLen];
    vector<vector<char> > claveSecreta(100000);
    for (int i = 0; i < matrixLen; i++)
        claveSecreta[i].resize(100000);
    for (int i = 0; i < matrixLen;i++) {
        for (int j = 0; j < matrixLen; j++) {
            claveSecreta[i][j] = i + j + 80; // asigna el valor char ASCII = i+j 
         //   cout << claveSecreta[i][j];
        }
        //  cout << endl;
    }

    //  cout << "matriz secreta creada \n iniciando operacion xor con desplazamiento de bits\n";
      //aplicar una operacion xor 
    for (int i = 0; i < matrixLen; i++) {
        for (int j = 0; j < matrixLen; j++) {
            //operacion XOR del caracter de la matriz con el de claveSecreta
            matrix[i][j] = matrix[i][j] ^ claveSecreta[i][j];

            //aplicar un desplazamiento de dos bits a la  izquierda
            matrix[i][j] = matrix[i][j] + (nBloque);
        }
    }
    //cout << "iniciando cambio de filas x columnas otra vez \n";
    //cambiar filas por columnas otra vez
    temp = ' ';
    for (int i = 1;i < matrixLen;i++)
        for (int j = 0;j < i;j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    //cout << "cambio de filas x col terminado\n inicinado XOR \n";
    //volver a aplicar XOR
    for (int i = 0; i < matrixLen; i++) {
        for (int j = 0; j < matrixLen; j++) {
            //operacion XOR del caracter de la matriz con el de claveSecreta
            matrix[i][j] = matrix[i][j] ^ claveSecreta[i][j];
        }
    }

    //cout << "cifrado completado. inicinado vaciado a string\n \n";
    string valorCifrado = "";
    for (int i = 0; i < matrixLen; i++) {
        for (int j = 0; j < matrixLen; j++) {
            valorCifrado.push_back(matrix[i][j]);
        }
    }


    return valorCifrado;
}


string descifrarBloque(string bloque, int nBloque) {
    //raiz del tama�o de str a cifrar
    int matrixLen = (int)sqrt(bloque.length());
    //char matrix[matrixLen][matrixLen];
    vector<vector<char> > matrix(100000);
    for (int i = 0; i < matrixLen; i++)
        matrix[i].resize(100000);
    int pos = 0;
    // cout << "matriz declarada \n Iniciando ciclo de llenado de matriz \n";
    for (int i = 0; i < matrixLen; i++) {
        for (int j = 0; j < matrixLen; j++) {
            //ciclo para llenar la matriz con el string 

            //revisar si todavia no se acab� el string
            if (pos < bloque.length()) {
                matrix[i][j] = bloque[pos]; //:'( :c
                pos++;
            }
            else {
                matrix[i][j] = '$';
            }
        }
    }
    // cout << "matriz llenada. \n";
    //  cout << "imprimiendo matriz original \n";
    //   for (int i = 0; i < matrixLen;i++){
   //      for (int j= 0; j < matrixLen;j++){
   //        cout << matrix[i][j] << " "; 
   //      }
   ////      cout << endl;
     //  }
    ///    cout << " iniciando creaci�n de matriz secreta\n";
     //matriz clave secreta
    vector<vector<char> > claveSecreta(100000);
    for (int i = 0; i < matrixLen; i++)
        claveSecreta[i].resize(100000);
    // char claveSecreta[matrixLen][matrixLen];
    for (int i = 0; i < matrixLen;i++) {
        for (int j = 0; j < matrixLen; j++) {
            claveSecreta[i][j] = i + j + 80; // asigna el valor char ASCII = i+j 
           // cout << claveSecreta[i][j];
        }
        //  cout << endl;
    }

    //    cout << "inicinado XOR \n";
    //aplicar XOR
    for (int i = 0; i < matrixLen; i++) {
        for (int j = 0; j < matrixLen; j++) {
            //operacion XOR del caracter de la matriz con el de claveSecreta
            matrix[i][j] = matrix[i][j] ^ claveSecreta[i][j];
        }
    }
    // cout << "XOR terminado, cambiando filas x columans \n";
     //cambiar filas por columnas
    char temp = ' ';
    for (int i = 1;i < matrixLen;i++) {
        for (int j = 0;j < i;j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;

        }

    }
    /*  cout << "imprimiendo matriz intercambiada \n";
      for (int i = 0; i < matrixLen;i++){
        for (int j= 0; j < matrixLen;j++){
          cout << matrix[i][j] << " ";
        }
        cout << endl;
      }
   */

   //cout << "intercambio terminado \n iniciando desplazamiento de bits en sentido opuesto y despues XOR\n";
   //aplicar una operacion xor 
    for (int i = 0; i < matrixLen; i++) {
        for (int j = 0; j < matrixLen; j++) {

            //aplicar un desplazamiento de dos bits a la derecha
            matrix[i][j] = matrix[i][j] - (nBloque);
            //operacion XOR del caracter de la matriz con el de claveSecreta
            matrix[i][j] = matrix[i][j] ^ claveSecreta[i][j];


        }
    }
    //cout << "iniciando cambio de filas x columnas otra vez \n";
    //cambiar filas por columnas otra vez
    temp = ' ';
    for (int i = 1;i < matrixLen;i++)
        for (int j = 0;j < i;j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }




    //cout << "cifrado completado. inicinado vaciado a string\n \n";
    string valorCifrado = "";
    for (int i = 0; i < matrixLen; i++) {
        for (int j = 0; j < matrixLen; j++) {
            if (matrix[i][j] != '$')
                valorCifrado.push_back(matrix[i][j]);
            else break;

        }
    }


    return valorCifrado;
}




string cifradoPrincipal(string mensaje) {

    int longitudMensaje = mensaje.length();
    int half = longitudMensaje / 2;
    //arreglo de bloques a encriptar
    string bloques[2] = { mensaje.substr(0,half),
    mensaje.substr(half, longitudMensaje),
    };



    string bloque0Cifrado = cifrarBloque(bloques[0], 1);
    string bloque1Cifrado = cifrarBloque(bloques[1], 2);

    string mensajeCifrado = bloque0Cifrado.append(bloque1Cifrado);
    return mensajeCifrado;
}

string descifradoPrincipal(string mensaje) {

    int longitudMensaje = mensaje.length();
    int half = longitudMensaje / 2;
    //arreglo de bloques a encriptar
    string bloques[2] = { mensaje.substr(0,half),
    mensaje.substr(half, longitudMensaje),
    };



    string bloque0Cifrado = bloques[0];
    string bloque1Cifrado = bloques[1];
    string bloque0desCifrado = descifrarBloque(bloque0Cifrado, 1);
    string bloque1desCifrado = descifrarBloque(bloque1Cifrado, 2);
    string mensajedesCifrado = bloque0desCifrado.append(bloque1desCifrado);
    return mensajedesCifrado;
}
