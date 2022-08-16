#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;



string cifrarContrasena(string p)
{
    char  aux[9],l, aux2;
            for (int i=0;i<strlen(p.c_str());i++) {
                l=p[i];
                aux2=l+3;
                aux[i]=aux2;
            }
    return aux;
}
void cifradoCesar(string origen, string destino, string p )
{
    char l,aux, contra[10]="vhuqdMO<4";
    string contrasena=cifrarContrasena(p);//mando llamar a la funcion cifrar contraseña para obtener la contraseña
    strcpy(contra,contrasena.c_str());//asigno la contraseña a mi char contra
    fstream escribir(destino, ios::out | ios::app);
    if(!escribir.is_open()){
        cout<<"no se pudo abrir el archivo";
    }
    else {
        fstream leer(origen, ios::in);
        if(!leer.is_open()){
            cout<<"No se pudo abrir el archivo"<<endl;
        }
        else {
            cout<<"cifrando..."<<endl;
            for (int i=0;i<strlen(contra);i++) {
               escribir.put(contra[i]);
            }
            while (!leer.eof()) {
                leer.get(l);
                aux=l+3;
                escribir.put(aux);
            }
        }
        leer.close();
    }
    escribir.close();
}

void descifradoCesar(string origen, string destino, string letras)
{
    char contra[10]="sssssssss", aux;
    int i=0, tam, tamcontra;
    char l;
    tam=strlen(contra);
    tamcontra=strlen(letras.c_str());
    if(tamcontra == 9){
    fstream escribir(destino, ios::out | ios::app);
        fstream leer(origen, ios::in);
        if (!leer.is_open()){
            cout<<"no se pudo abrir el archivo"<<endl;
        }
        else {
            while (!leer.eof()) {
                if(i==tam){
                    if(contra==letras){
                        leer.get(l);
                        aux=l-3;
                        escribir.put(aux);
                    }
                    else {
                            cout<<"La contrasena es incorrect"<<endl;
                        break;
                    }
                }
                if (i < 9){
                leer.get(l);
                contra[i]=l;
                i++;
                }
            }
        }
        leer.close();
    escribir.close();
    remove("copiaS.csv");
    rename(destino.c_str(),"copiaS.csv");
    }
    else{
        cout<<"La contrasena es incorrecta"<<endl;
    }
}


int main(int argc, char *argv[])
{
    string condicion=argv[1];
    if(condicion=="cifradoCesar"){
        cifradoCesar(argv[2], argv[3], argv[4]);
    }
    else if(condicion=="descifradoCesar"){
        cout<<argv[4]<<endl;
        string aux=cifrarContrasena(argv[4]);
        cout<<aux<<endl;
        descifradoCesar(argv[2], argv[3],aux);
    }
    return 0;
}
