#include "AFD.cpp"

int main(void) {
    AFD *inicio;
    inicio = new AFD();
    inicio->leerArchivo();
    inicio->ingresarLenguaje();
    return 0;
}

