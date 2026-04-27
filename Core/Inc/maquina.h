/*
 * maquina.h
 *
 *  Created on: 27 abr 2026
 *      Author: tomyl
 */

#ifndef INC_MAQUINA_H_
#define INC_MAQUINA_H_


#include <stdint.h>
#include "main.h"

typedef enum {
    ESTADO_SELECCION,
    ESTADO_EXPENDIENDO
} Estado_maquina;

typedef enum {
    EVENTO_BOTON_SELEC,
    EVENTO_FIN_EXP,
    EVENTO_BOTON_ROTAR
} Evento_maquina;

extern uint8_t producto[4];
extern uint8_t indice;
extern volatile uint8_t flag_start;


Estado_maquina iniciar_maquina(void);
Estado_maquina MAQ_procesar_evento(Estado_maquina actual, Evento_maquina evento);


#endif /* INC_MAQUINA_H_ */
