#include "function.h"

/*! 
 * Verifica se um ponto está dentro de um retângulo.
 */

location_t pt_in_rect( const Ponto &IE, const Ponto &SD, const Ponto &P )
{   
    //Condicional que verifica se o ponto P está dentro do retângulo definido por dois pontos
    if (((P.x > IE.x) && (P.x < SD.x)) && ((P.y > IE.y) && (P.y < SD.y))){ 
        return INSIDE;        
    }
    //Condicional que verifica se o ponto P está fora do retângulo definido por dois pontos
    else if ((P.x < IE.x) || (P.x > SD.x) || (P.y < IE.y) || (P.y > SD.y)){
        return OUTSIDE;
    }
    //Se o ponto P não está dentro ou fora do retângulo, então o ponto está na borda do retângulo
    else{
        return BORDER;
    }
}
