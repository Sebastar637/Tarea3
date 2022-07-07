#include <iostream>
#include <string>

#define CO_PRIME 127

using namespace std;

struct Palabra
{
    string termino = "";
    string significado = "";
    int consultas = 0;
};

class CacheDiccionario
{
private:
    int total, conocidos, desconocidos, accesses;
    int hits, misses, cleanups, inserciones;
    Palabra hashTable[128];

    void cleanup()
    {
        return;
    }
    int asciistring(string termino)
    {
      int suma = 0;
      for(unsigned int i = 0; i < termino.length(); i++)
      {
          suma += termino[i];
      }
      return suma;
    }


    int hashFunction(string termino)
    {
      int key = asciistring(termino)%128;
        return key;
    }

    int hashFunction2(string termino)
    {
      int key = CO_PRIME - (asciistring(termino) %CO_PRIME);
      return key;
    }

public:
    CacheDiccionario()
    {

    }
    void ayuda(){
      for(unsigned int i = 0; i < 127; i++){
        cout << hashTable[i].termino << hashTable[i].consultas << endl;
      }
    }
    bool query(string termino, string& significado)
    {
      bool flag = true;
      for (int i = 0; flag == true; i++)
      {
        int key = (hashFunction(termino) + (i * hashFunction2(termino)))%128;
        if (hashTable[key].termino == termino)
        {
          cout << hashTable[key].significado << endl;
          hashTable[key].consultas++;
          return true;
        }
        else if (hashTable[key].termino == "")
        {
          misses++;
          flag = false;
        }
      }
      return false;
    }
    void insert(string termino, string significado)
    {

        Palabra insercion;
        insercion.termino = termino;
        insercion.significado = significado;
        if(inserciones == 128)
        {
            cleanup();
            inserciones = 64;
        }
        int key;
        bool flag = true;
        for (int i = 0; flag == true; i++)
        {
          key = (hashFunction(termino) + (i * hashFunction2(termino)))%128;
          if (hashTable[key].termino == "" || hashTable[key].termino == termino)
          {
            flag = false;
            hashTable[key] = insercion;
            inserciones++;
          }
        }
    }

    void querystats(int& total, int& conocidos, int& desconocidos)
    {
        return;
    }

    void perfstats(int& accesses, int& hits, int& misses, int& cleanups)
    {
        return;
    }
};

int main(){
    std::cout << "Hello, World!" << std::endl;
    CacheDiccionario a;
    string b = "asd";
    int choice;
    cout << "Presiona 1 para introducir una definición ,2 para consultar y 3 para salir."<< endl;
    while(cin >> choice){
      if (choice == 1){
        string termino;
        string def;
        cout << "Introduzca el término" << endl;
        cin >> termino;
        cout << "Introduzca la definición" << endl;
        cin >> def;
        a.insert(termino, def);
      }
      else if (choice == 2){
        string termino;
        cout << "Introduzca el término" << endl;
        cin >> termino;
        a.query(termino, b);
      }
      else if (choice == 3){
        break;
      }
      cout << "Presiona 1 para introducir una definición ,2 para consultar y 3 para salir."<< endl;
    }
    return 0;
}
