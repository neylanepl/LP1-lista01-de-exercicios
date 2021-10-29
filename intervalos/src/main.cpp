/*!
 * @brief This code implements the Intervalos programming problem
 * @author selan
 * @data June, 6th 2021
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <iomanip>
using std::setprecision;

// Se desejar, crie funções aqui, antes do main().

int main(void)
{
    int numeros, quantidade_numeros=0; // Declaração e inicialização de variáveis
    float conta[5] = {0,0,0,0,0}; // Declaração e inicialização de um vetor

    while( cin >> std::ws >> numeros ){ // Ler um número indeterminado de valores
        if (numeros < 0){ // Condicional para verificar se o número digitado está fora dos intervalos
            conta[4]+=1; // Realiza a contagem dos números que estão fora dos intervalos
        } 
        else if (numeros >= 0 && numeros < 25){
            conta[0]+=1; // Realiza a contagem dos números que estão no intervalo [0,25)
        }
        else if (numeros >= 25 && numeros < 50){
            conta[1]+=1; // Realiza a contagem dos números que estão no intervalo [25,50)
        }
        else if (numeros >= 50 && numeros < 75){
            conta[2]+=1; // Realiza a contagem dos números que estão no intervalo [50,75)
        } 
        else if (numeros >= 75 && numeros < 100){
            conta[3]+=1; // Realiza a contagem dos números que estão no intervalo [75,100)
        } 
        else{ // Condicional para verificar se o número digitado está fora dos intervalos
            conta[4]+=1; // Realiza a contagem dos números que estão fora dos intervalos
        }              
        quantidade_numeros+=1; // Realiza a contagem de quantos números foram digitados
    }

    for (int i=0; i<5; ++i){
        std::cout << std::setprecision(4) << (conta[i]*100)/quantidade_numeros << '\n'; /*Imprimi, com quatro casas de precisão, a porcentagem
                                                                    de números para cada um dos quatro intervalos e de números fora dos intervalos*/
    } 
    return 0;
}
