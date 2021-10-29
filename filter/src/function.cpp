/*! 
 * Remove negative and zero values from an array, preserving the
 * relative order of the original values that will remain in the
 * resulting array.
 * We do not alter the origimal memory associated withe the input
 * array. Rather, we just rearrange the values inside the array
 * and return a pointer to the new 'logical' end of the array,
 * after the processes of eliminating the required elements is
 * finished.
 *
 * @param first Pointer to the beginning of the range we want to filter.
 * @param last Pointer just past the last valid value of the range we want to filter.
 * @return a pointer to the new 'logical' end of the array.
 */
int * filter( int * first, int * last )
{
    int *ponteiro = first, auxiliar, quantidade_filtrados=0, total_numeros=0;

    while(&ponteiro[total_numeros] < last){ // Laço que se repete enquanto o endereço de memória de uma posição de ponteiro for menor que o endereço de last
        if (ponteiro[total_numeros] > 0){ // Condicional que verifica se o número não é negativo ou nulo
            auxiliar = ponteiro[total_numeros]; // Atribui um elemento de ponteiro, que não é negativo nem nulo, a auxiliar
            ponteiro[total_numeros] = ponteiro[quantidade_filtrados]; // Coloca um elemento inválido em um posição que não faz parte dos números filtrados
            ponteiro[quantidade_filtrados] = auxiliar; // Rearranja o vetor, colocando um número válido em um posição do vetor filtrado
            quantidade_filtrados+=1; // Realiza a contagem dos números que foram filtrados, ou seja, que não são negativos ou nulos
        }
        total_numeros+=1; // Realiza a contagem de todos os números que estão no vetor antes de filtrado
    }

    return &ponteiro[quantidade_filtrados]; //Retorna o endereço de memória logo após o último valor válido dentro do vetor filtrado
}
