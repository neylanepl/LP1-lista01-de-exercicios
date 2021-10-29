#include "function.h"

/*! 
 * Finds and returns a pair with the first instance of the smallest element
 * and the last instance of the largest element in an array.
 *
 * @param V This is the array-to-pointer decay representing an array.
 * @param n The array's size.
 *
 * @return A pair of indexes to the first smallest and last largest values.
 */

std::pair<int,int> min_max( int V[], size_t n )
{
    std::pair<int,int> MinMax; //Declaração de um par de valores

    if (n == 0){ // Condicional para verificar se o vetor V é vazio
        MinMax.first = -1; // Atribui -1 ao primeiro elemento do par
        MinMax.second = -1; // Atribui -1 ao sengundo elemento do par
    }
    else{
        int menor_indice=0, maior_indice=0;

        for (int i=1; i<n; ++i){
            if (V[menor_indice] > V[i]){ //Condicional para verificar a primeira ocorrência do menor elemento presente em V
                menor_indice = i; //Armazena o ı́ndice da primeira ocorrência do menor elemento presente em V
            } 
            else if (V[maior_indice] <= V[i]) { //Condicional para verificar a última ocorrência do maior elemento presente em V
                maior_indice = i; //Armazena o índice da última ocorrência do maior elemento presente em V
            }
        }

        MinMax.first = menor_indice; //Adiciona o indíce no primeiro elemento do par
        MinMax.second = maior_indice;  //Adiciona o indíce no segundo elemento do par
    }
    return MinMax; //Retorna um par de valores
}
