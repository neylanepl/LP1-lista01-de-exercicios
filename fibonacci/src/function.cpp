#include "function.h"

std::vector<unsigned int> fib_below_n( unsigned int n )
{
    std::vector<unsigned int> v; // Declaração de um vetor dinâmico
    int contador = 2;

    if (n < 2){ // Condicional para verificar se n é um número inválido(menor que 2)
        return std::vector<unsigned int>{v}; // Retorna o vetor v vazio
    }
    else{
        v.push_back(1); // Adiciona um elemento no vetor v
        v.push_back(1); // Adiciona um novo elemento no final do vetor v
        if (n==2){ // Condicional para verificar se n é igual a 2, onde temos um caso especial(os dois primeiros termos iguais a 1)
            return std::vector<unsigned int>{v}; // Retorna o vetor v com seus elemnetos 
        }
        else{
            do{
                v.push_back(v[contador-2] + v[contador-1]); /* Adiciona um novo elemento no final do vetor v, 
                                                                em que o elemento é a soma dos dois termos imediatamente anteriores */
                contador+=1; // Realiza a contagem de quantos números foram adicionados no vetor
            }while((v.at(contador-2) + v.at(contador-1)) < n); /* Laço em que a condição de parada é se soma dos dois
                                                                termos imediatamente anteriores a n for maior que n */

            // TODO: Isto é apenas um STUB. Troque o retorno pelo que você julgar correto.
            return std::vector<unsigned int>{v}; // Retorna o vetor v com seus elemnetos
        }
    }
}
