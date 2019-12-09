#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class AFD{
private:
    int tabla[15][3];
    int aceptacion[15];
    int numeroAceptacion=0;
    int inicio=0;
    
public:
    void leerArchivo(){
        FILE *fp;
        char caracter;
        int  numeroFila=-1, numeroColumna=0;
        fp=fopen("AFD.txt","r");
        if(fp==NULL){
            cout<<"No se pudo abrir el archivo AFD.txt"<<endl;
        }
        else{
            caracter=fgetc(fp);
            while(caracter!=';'){
                if(!(caracter==',')){
                    aceptacion[numeroAceptacion]=caracter-'0';
                    numeroAceptacion++;
                }
                caracter=fgetc(fp);
            }
            caracter=fgetc(fp);
            while(caracter!=EOF){
                if(caracter=='\n'){
                    numeroFila++;
                    numeroColumna=0;
                }
                else if(!(caracter==',' || caracter==';')){
                    tabla[numeroFila][numeroColumna]=caracter-'0';
                    numeroColumna++;
                }
                caracter=fgetc(fp);
            }
            pclose(fp);
            cout<<"El archivo fue cargado correctamente."<<endl;
        }
    }
    
    void verCamino(char valor){
       int columna=valor-'0';
       columna++;
       inicio = tabla[inicio][columna];
    }
    
    void verificarLenguaje(void){
        int i,bandera=0;
        for(i=0;i<numeroAceptacion;i++){
            if(aceptacion[i]==inicio){
                cout<<"Lenguaje valido"<<endl;
                bandera=1;
            }
        }
        if(bandera==0){
            cout<<"Lenguaje no valido"<<endl;
        }
    }
    
    void ingresarLenguaje(void){
        char caracter;
        cout<<"Ingrese el lenguaje de 0 y 1 numero por numero\nCuando termine"
                "ingrese el caracter + para terminar"<<endl;
        cout<<"Ingresar caracter"<<endl;
        cin>>caracter;
        while(!(caracter=='+')){
            verCamino(caracter);
            cout<<"Ingresar caracter"<<endl;
            cin>>caracter;
        }
        verificarLenguaje();
    }
    
};