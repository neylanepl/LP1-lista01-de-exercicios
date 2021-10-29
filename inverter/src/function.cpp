#include "function.h"

#include <iterator>
using std::iter_swap;

/*! 
 * Reverse de order of elements inside the array.
 * @param arr Reference to the array with the values.
 */
template <size_t SIZE>
void reverse( std::array< std::string, SIZE > & arr )
{
    std::size_t tamanho = arr.size (); // Obtém a quantidade de elementos em arr

    if(tamanho == 0){ //Condicional para verificar se o vetor arr é vazio
        return;
    }
    else{
        std::string auxiliar;

        for (int i=0; i<(tamanho/2); ++i){ // Loop que se repete até metade do tamanho de arr
            auxiliar = arr[i]; // Atribui um elemento, que está entre o inicío e o meio de arr, à auxiliar
            arr[i] = arr[(tamanho-1)-i]; // Move um elemento, que está entre o meio e o final de arr, para o inicio de arr
            arr[(tamanho-1)-i] = auxiliar; // Move um elemento, que está entre o inicío e o meio de arr, para o final de arr
        }
    }
}
