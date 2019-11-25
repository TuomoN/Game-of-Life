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
\fn void draw(struct cell taulukko[KOKO][KOKO], int koko)
\brief Piirtää merkin asutusta sektorista
\param Input: taulukko, taulukon koko
\param Output: piirretty merkki, jos sektori on asuttu*/
/*********************************************************************/
void draw(struct cell taulukko[KOKO][KOKO], int koko)
{
	int x, y, elossa = 0, vihr = 0, pun = 0;
	/*Tyhjentää ruudun*/
	clear();
	/**Merkitsee ncursesille piirrettävät solut ja laskee olentojen määrän*/
	for(x = 0; x < koko; x++)
	{
		for(y = 0; y < koko; y++)
		{
			if(taulukko[x][y].current == 1)
			{	
				mvaddch(y, x, '*' | COLOR_PAIR(1));
				elossa++;
				vihr++;
			}
			if(taulukko[x][y].current == 2)
			{	
				mvaddch(y, x, '*' | COLOR_PAIR(2));
				elossa++;
				pun++;
			}
		}
	}
	mvprintw(koko, 0, "Lopeta painamalla q, jatka painamalla mitä tahansa muuta näppäintä. Olentoja elossa: %d Vihreitä: %d Punaisia: %d", elossa, vihr, pun);
	/*Päivittää ruudun*/
	refresh();
}