/*
 * maquina.c
 *
 *  Created on: 27 abr 2026
 *      Author: tomyl
 */



#include <stdint.h>
#include "main.h"
#include "maquina.h"
#include "stm32f1xx_it.h"

uint8_t producto[4] = {1, 2, 3, 4};
uint8_t cantidad = sizeof(producto) / sizeof(producto[0]);
uint8_t indice = 1;
volatile uint8_t flag_start = 0;

void rotacion_productos(){
	if (indice < cantidad){
		indice++;
	} else { indice = 1; }
}

void habilitar_mecanismo(){
	 flag_start = 1;
}


/* Process evento and execute actions */
Estado_maquina MAQ_procesar_evento(Estado_maquina actual, Evento_maquina evento) {
    Estado_maquina siguiente = actual;
    switch (actual) {
        case ESTADO_SELECCION:
            if (evento == EVENTO_BOTON_SELEC) {
                siguiente = ESTADO_EXPENDIENDO;
                break;
            }
            if (evento == EVENTO_BOTON_ROTAR) {
                rotacion_productos();
                siguiente = ESTADO_SELECCION;
                break;
            }
            break;
        case ESTADO_EXPENDIENDO:
            if (evento == EVENTO_FIN_EXP) {
                siguiente = ESTADO_SELECCION;
                break;
            }
            break;
        default: break;
    }

    if (siguiente != actual) {
        switch (siguiente) {
            case ESTADO_EXPENDIENDO:
                habilitar_mecanismo();
                break;
            default: break;
        }
    }
    return siguiente;
}

/* Initialize FSM */
Estado_maquina iniciar_maquina(void) {
    Estado_maquina inicial = ESTADO_SELECCION;
    return inicial;
}/*
 * maquina.c
 *
 *  Created on: 27 abr 2026
 *      Author: tomyl
 */


