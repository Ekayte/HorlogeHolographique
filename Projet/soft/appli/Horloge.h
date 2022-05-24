/*
 * Horloge.h
 *
 *  Created on: 20 mai 2019
 *      Author: terriema
 */
#include "stm32f1_rtc.h"
#include "config.h"

#ifndef HORLOGE_H_
#define HORLOGE_H_

running_e Horloge_main(bool_e ask_for_finish);
uint8_t lettertoindex(uint8_t l);
void simuLed();
void initialisation();
void colorLed();

#endif /* HORLOGE_H_ */
