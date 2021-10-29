/*!
 * @brIEf Implementação do Ponto em Retângulo V2.
 * @author selan
 * @data June, 6th 2021
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <algorithm>
using std::min;
using std::max;

#include "function.h"

//=== Funções

int verifica_retangulo_invalido(Ponto R1, Ponto R2)
{
    if ((R1.x == R2.x) && (R1.y == R2.y)){ /* Um retângulo é considerado válido se e somente se pelo menos uma das 
                                            quatro coordenadas dos vértices que o define for diferente */
        return 1;
    } 
    else if ((R1.x < -1000) || (R1.x > 1000)
        || (R1.y < -1000) || (R1.y > 1000)
        || (R2.x < -1000) || (R2.x > 1000)
        || (R2.y < -1000) || (R2.y > 1000)){ // Verifica se as coordenadas dos pontos estão em um intervalo inválido
        return 1;
    }
    else{ // Se o retângulo for válido
        return 0;
    }
}

void imprime_localizacao_ponto(location_t p)
{
    if (p == INSIDE){ // Verifica se o ponto está dentro do retângulo
        std::cout << "inside" << '\n';
    }
    else if (p == OUTSIDE){ // Verifica se o ponto está fora do retângulo
        std::cout << "outside" << '\n';
    }
    else if (p == BORDER){ // // Verifica se o ponto está na borda do retângulo
        std::cout << "border" << '\n';
    }
}

int main(void)
{
    int x1, y1, x2, y2, x3, y3;

    while (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){ // Ler um número indeterminado de valores

        Ponto R1, R2, P, IE, SD; // Declaração de variáveis do tipo Ponto
        R1.x = x1, R1.y = y1, R2.x = x2, R2.y = y2, P.x = x3, P.y = y3; // Acessa os campos de uma struct e atribui um valor

        if(verifica_retangulo_invalido(R1,R2)){ // Verifica se o retângulo é valido
            std::cout << "invalid"; // Enviar para a saı́da padrão a mensagem “invalid”
        }else{
            if(R1.x == R2.x){ // Condicional que verifica se os vértices têm a mesma coordenada x
                if(R1.y > R2.y){ // Condicional que verifica se R1 é o vértice do canto superior
                    SD = R1;  // Atribui as coordenadas do canto superior a SD
                    IE = R2; // Atribui as coordenadas do canto inferior a IE
                }else{ // R1 é o vértice do canto inferior
                    SD = R2; // Atribui as coordenadas do canto superior a SD
                    IE = R1; // Atribui as coordenadas do canto inferior a IE
                }
            }
            else if(R1.x < R2.x){ // Condicional que verifica se R1 é o vértice do canto esquerdo
                if(R1.y > R2.y){ // Condicional que verifica se R1 é o vértice do canto superior
                    SD = {R2.x,R1.y}; // Realiza ajustes necessários para ter as coordenadas do canto superior direito
                    IE = {R1.x,R2.y}; // Realiza ajustes necessários para ter as coordenadas do canto inferior esquerdo
                }else{ // R1 é o vértice do canto inferior
                    SD = R2; // Atribui as coordenadas do canto superior direito a SD
                    IE = R1; // Atribui as coordenadas do canto inferior esquerdo a IE
                }
            }
            else if(R1.x > R2.x){ // Condicional que verifica se R1 é o vértice do canto direito
                if(R1.y > R2.y){ // Condicional que verifica se R1 é o vértice do canto superior
                    SD = R1; // Atribui as coordenadas do canto superior direito a SD
                    IE = R2; // Atribui as coordenadas do canto inferior esquerdo a IE
                }else{ // R1 é o vértice do canto inferior
                    SD = {R1.x,R2.y}; // Realiza ajustes necessários para ter as coordenadas do canto superior direito
                    IE = {R2.x,R1.y}; // Realiza ajustes necessários para ter as coordenadas do canto inferior esquerdo
                    
                }
            }

            location_t localizacao_P = pt_in_rect(IE, SD, P); /* Chama a função pt_in_rect que retorna 
                                                                onde está o ponto P em relação ao retângulo */

            imprime_localizacao_ponto(localizacao_P); /* Chama a função que envia para a saı́da padrão 
                                                        onde está o ponto em relação ao retângulo */
        }  
    }
    return 0;
}