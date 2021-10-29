/*!
 * @brief This code implements the "Soma Vizinhos" programming problem
 * @author selan
 * @data June, 6th 2021
 */
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main( void )
{
    int m, n, soma=0; // Declaração e inicialização de variáveis
    
    while(std::cin >> m >> n){ // Ler um número indeterminado de valores
        if ((n >= -10000 && n <= 1000) && (m >= -10000 && m <= 1000)){ // Condicional para verificar se os valores digitados estão no intervalo especificado
            if (n > 0){ // Condicional que verifica se n é um número positivo
                for(int i=m; i<m+n; ++i){ // Loop que repete de m até m+n incrementando em 1
                    soma += i; // Realiza a soma dos n primeiros inteiros consecutivos à partir de m
                }
            }
            else if (n < 0){ // Condicional que verifica se n é um número negativo
                for(int j=m; j>m+n; --j){ // Loop que repete de m até m+n decrementando em 1
                    soma += j; // Realiza a soma dos n primeiros inteiros antecedentes à partir de m
                }   
            }
            else if (n==0){
                soma = m; // Caso n seja 0, a soma será igual a m
            }
            std::cout << soma << '\n';
            soma=0; // Zera a variável soma para utilizar ela na soma dos próximos números
        }
    } 

    return 0;
}
