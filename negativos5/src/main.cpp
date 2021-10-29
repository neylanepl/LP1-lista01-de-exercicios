#include <iostream>
using std::cin;
using std::cout;

const int SIZE = 5; // input size.

int main(void)
{
    int numero, contador=0; // Declaração e inicialização de variáveis
    
    for(int i=0; i<SIZE; i++){ // Loop que repete 5 vezes
        std::cin >> std::ws >> numero;
        if (numero < 0){ // Condicional para verificar se o número digitado é negativo
            contador++;
        }
    }

    std::cout << contador << '\n';

    return 0;
}
