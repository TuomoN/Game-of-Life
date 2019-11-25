/***************************************************************************
 *   Copyright (C) $YEAR$ by $AUTHOR$   *
 *   $EMAIL$   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************
*
* 1.  NAME
*     $Source$ 
* 2.  DESCRIPTION
*
* 6.  VERSIONS
*       Original:
*         $Date$ / $Author$
*
*       Version history:
*       $Log$
*
**********************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include "life.h"

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES                                                *
*--------------------------------------------------------------------*/
/* Control flags */

/* Global constants */

/* Global variables */

/* Global structures */

/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

/*********************************************************************
*    FUNCTIONS                                                     *
**********************************************************************/

/*********************************************************************/
/**
\fn int ask_integer_number(int min, int max)
\brief Lukee käyttäjän antaman luvun
\param Input: Luvun raja-arvot, syötetty luku
\param Output: Syötetty luku*/
/*********************************************************************/
int ask_integer_number(int min, int max)
{
	int value, err;
	printf("Anna luku välillä %d ja %d: ", min, max);
	char trash[40], entteri[40];
	
	//lue syötetty arvo fgets-funktiolla ja sijoitetaan muuttujaan sscanf:llä
	fgets(entteri, sizeof(entteri), stdin);
	err = sscanf(entteri, "%d%s", &value, trash);
	/*err on näppäinpuskurista oikein syötettyjen muuttujien määrä, väärät/liiat merkit sijoitetaan trash-muuttujaan
	jos syöttö alkaa kirjaimella, err = 0, koska sscanf pysähtyy ensimmäiselle muuttujalle virheelliseen syöttöön ja jos syötössä on kirjaimia, err = 2, koska sscanf lukee luvun jälkeen olevat merkit*/

	while(value < min || value > max || err != 1) //jos arvo on virheellinen tai sscanf on lukenut liian vähän tai liikaa muuttujia, toistetaan kysymys ja luetaan uusi arvo
	{
		printf("Virhe annetussa arvossa!\n");
		printf("Anna luku välillä %d ja %d: ", min, max);
		fgets(entteri, sizeof(entteri), stdin);
		err = sscanf(entteri, "%d%s", &value, trash);
	}
	return value;//palauttaa muuttujan arvon
}

/*********************************************************************/
/**
\fn void start(struct cell taulukko[KOKO][KOKO], int koko)
\brief Alkutilanteen valintafunktio, satunnainen alustus tai tallennettu tilanne
\param Input: olentotaulukko, taulukon koko, sääntötaulukko, käyttäjän valitsema alkutilanne
\param Output: syöttää halutun alkutilanteen taulukkoon*/
/*********************************************************************/
void start(struct cell taulukko[KOKO][KOKO], struct rules ehdot[2], int koko)
{
	int alku, maara, ehto, i, j, k;
	FILE *initfile, *rules;
	
	printf("Haluatko asuttaa alueen satunnaisesti (0) vai ladata tallennetun alkutilanteen (1)?\n");
	alku = ask_integer_number(0, 1);
	
	switch (alku)/**Eri vaihtoehtoja voi myöhemmin lisätä switch-vaihtoon, esimerkiksi useampia tallennettuja tilanteita*/
	{
		case 0:
		srand(time(NULL));/*Satunnaisuuden alustus*/
		printf("Kuinka paljon olentoja haluat alkutilanteeseen?\n");
		maara = ask_integer_number(0, KOKO * KOKO);
		i = 0;
		while(i < maara)/*Arvotaan kunnes olentoja on haluttu määrä*/
		{
			j = rand() % KOKO;
			k = rand() % KOKO;
			alku = (rand() % 2) + 1;
			if(taulukko[j][k].current == 0)/*Tarkistaa onko arvottu solu asuttu*/
			{
				taulukko[j][k].current = alku;
				i++;
			}
		}
		break;
		
		case 1:
		/*Lataa tilanteen tiedostosta ja lukee joka solulle tallennetun arvon, sulkee lopuksi tiedoston*/
		initfile = fopen("initfile.txt", "r");
		for(i = 0; i < KOKO; i++)
		{
			for(j = 0; j < KOKO; j++)
			{
				fscanf(initfile, "%d", &taulukko[j][i].current);
			}
		}
		fclose(initfile);
		break;
	}
	
	printf("Haluatko käyttää oletussääntöjä (0; populaatio 2-3, kasvu 3, voima 1)\nvai ladata olentotyypeille eri säännöt (1; vihreällä populaatio 1-5, kasvu 3, voima 2, punaisella populaatio 2-4, kasvaa 3, voima 5)?\n");
	ehto = ask_integer_number(0, 1);
	switch (ehto)
	{
		case 0:
		for(i = 0; i < 2; i++)
		{
			ehdot[i].ali = 2;
			ehdot[i].yli = 3;
			ehdot[i].kasvu = 3;
			ehdot[i].voima = 1;
			
		}
		break;
		
		case 1:
		rules = fopen("rules.txt", "r");
		for(i = 0; i < 2; i++)
		{
			fscanf(rules, "%d", &ehdot[i].ali);
			fscanf(rules, "%d", &ehdot[i].yli);
			fscanf(rules, "%d", &ehdot[i].kasvu);
			fscanf(rules, "%d", &ehdot[i].voima);
		}
		fclose(rules);
		break;
	}
}