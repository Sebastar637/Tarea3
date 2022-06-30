#include <iostream>
#include <string>

#define CO_PRIME 127;

using namespace std;

struct Palabra
{
    string termino;
    string significado;
    int consultas;
};

class CacheDiccionario
{
private:
    int total, conocidos, desconocidos, accesses;
    int hits, misses, cleanups, inserciones;

    void cleanup()
    {
        return;
    }

    int hashFunction(string termino)
    {
        int suma = 0;
        for(unsigned int i = 0; i < termino.length(); i++)
        {
            suma += termino[i];
        }
        return suma %= 128;
    }

public:
    CacheDiccionario()
    {
        Palabra hashTable[128];
    }

    bool query(string termino, string& significado)
    {
        return true;
    }

    void insert(string termino, string significado)
    {   




        inserciones++;
        if(inserciones == 128)
        {
            cleanup();
            inserciones = 64;
        }
        return;
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
    return 0;
}




