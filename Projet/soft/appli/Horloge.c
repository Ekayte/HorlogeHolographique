/*
 * Horloge.c
 *
 *  Created on: 20 mai 2019
 *      Author: terriema
 */
#include "stm32f1_rtc.h"
#include "config.h"
#include "Horloge.h"
#include "stm32f1xx_hal.h"
#include "macro_types.h"
#include "stm32f1_gpio.h"


#define COLOR_BLUE	0x0000FF
#define COLOR_RED	0x00FF00
#define COLOR_GREEN	0xFF0000
#define COLOR_BLACK 0x000000
#define capteur_Hall							GPIOA,GPIO_PIN_4

static volatile uint32_t t = 0;

static void process_ms(void){
	t++;
}

void onArrivePasAvecProcess_ms(void)
{
	Systick_add_callback_function(&process_ms);

}

static char message[50]; //nombre de caractères que l'on peut afficher au maximum

static uint16_t matrice[256]; //nombre de positions verticales

uint8_t alphabet[24][5]=//alphabet[36][5]
{
{
0b00011111,
0b00010001,
0b00011111, //A
0b00010001,
0b00010001,
},

{
0b00011111,
0b00010001,
0b00011110, //B
0b00010001,
0b00011111,
},
{
0b00011111,
0b00010000,
0b00010000, //C
0b00010000,
0b00011111,
},
{
0b00011110,
0b00010001,
0b00010001, //D
0b00010001,
0b00011110,
},
{
0b00011111,
0b00010000,
0b00011100, //E
0b00010000,
0b00011111,
},
{
0b00011111,
0b00010000,
0b00011100, //F
0b00010000,
0b00010000,
},
{
0b00011111,
0b00010000,
0b00010011, //G
0b00010001,
0b00011111,
},
{
0b00010001,
0b00010001,
0b00011111, //H
0b00010001,
0b00010001,
},
{
0b00000100,
0b00000100,
0b00000100, //I
0b00000100,
0b00000100,
},
{
0b00011111,
0b00000001,
0b00000001, //J MAIS JE SAIS PAS COMMENT LE FAIRE
0b00000001,
0b00011110,
},
{
0b00010001,
0b00010010,
0b00011100, //K
0b00010010,
0b00010001,
},
{
0b00010000,
0b00010000,
0b00010000, //L
0b00010000,
0b00011111,
},
{
0b00010001,
0b00011011,
0b00010101, //M
0b00010001,
0b00010001,
},
{
0b00010001,
0b00011001,
0b00010101, //N
0b00010011,
0b00010001,
},
{
0b00011111,
0b00010001,
0b00010001, //O
0b00010001,
0b00011111,
},
{
0b00011110,
0b00010001,
0b00011110, //P
0b00010000,
0b00010000,
},
{
0b00011111,
0b00010001,
0b00010101, //Q
0b00010011,
0b00011111,
},
{
0b00011110,
0b00010001,
0b00011110, //R
0b00010010,
0b00010001,
},
{
0b00011111,
0b00010000,
0b00011111, //S
0b00000001,
0b00011111,
},
{
0b00011111,
0b00000100,
0b00000100, //T
0b00000100,
0b00000100,
},
{
0b00010001,
0b00010001,
0b00010001, //U
0b00010001,
0b00011111,
},
{
0b00010001,
0b00010001,
0b00010001, //V
0b00001010,
0b00000100,
},
{
0b00010001,
0b00010001,
0b00010001, //W
0b00010101,
0b00011011,
},
{
0b00010001,
0b00001010,
0b00000100, //X
0b00001010,
0b00010001,
},
{
0b00010001,
0b00001010,
0b00000100, //Y
0b00000100,
0b00000100,
},
{
0b00011111,
0b00000010,
0b00000100, //Z
0b00001000,
0b00011111,
},


};

uint8_t lettertoindex(uint8_t l){ //renvoie un index en fonction de la lettre entrée ??
	if(l >= 'a' && l<= 'z')
		return l-'a';
	if(l>= 'A' && l<='Z')
		return l-'A';
	if (l>= '0' && l<= '9')
		return l-'0'+26;
	return 0;
}

void simuLed(){  // simulation sur le terminal
	for (uint8_t j=0;j<16;j++){
		for(uint16_t i=0; i<256; i++){
			if((matrice[i]>>(15-j))&1)
				printf("X");
			else
				printf(" ");
		}
	printf("\n");


	}
}

void affichage_colonne(){ //même chose
	for(uint16_t i=0; i<256; i++){
		for(uint16_t j=0; j<16; j++){
			if((matrice[i]>>(15-j))&1)
				printf("X");
			else
				printf(" ");
		}
	printf("\n");
	HAL_Delay(1000);
	}

}

void affichage_Led(uint16_t i){ //affiche le bandeau de led en fonction de la position entrée en paramètre
	uint32_t ruban[16];

	int test = 0;
	for(uint16_t j=0; j<16; j++){
		if((matrice[i]>>(15-j))&1){
			ruban[j] = COLOR_RED;
			test= 1;
		}
		else
			ruban[j] = COLOR_BLACK;
	}
	LED_MATRIX_display(ruban, 16);
	if (test == 1)
		HAL_Delay(5



		);

}

void initialisation(){ // on intialise les led 1 par 1 a 0
	for(int k=0;k<256;k++)
		matrice[k]=0;
}





running_e Horloge_main(bool_e ask_for_finish)
{

	sprintf(message, "ABC");


	int compteurIndiceMatrice = 0;

		if (HAL_GPIO_ReadPin(capteur_Hall) == 0)

			while(compteurIndiceMatrice <= 255)
			{
				int l, i, j;
				uint16_t index;
				for (l=0; message[l]; l++) //compte les lettres
				{
					index = lettertoindex(message[l]); //transforme les lettres en index
					for(i=0; i<5; i++) //compte les positions verticales dans une lettre
					{
						matrice[i+6*l] = 0; //on met un espace entre les lettres
						for(j=0; j<5; j++)
						{
							matrice[i+6*l] |= ((uint16_t)(alphabet[index][j]>>(4-i))&1)<<(5+j);
						}

						affichage_Led(compteurIndiceMatrice); //on affiche une position verticale
						compteurIndiceMatrice++;


					}
					matrice[5+6*l] = 0;
				}
			 }


		}


	}






