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
/**Pääohjelma valitsee alkutilanteen, alustaa ncurses-ruudun ja hoitaa ohjelman kierron, kunnes käyttäjä katkaisee kierron*/
int main (void)
{
	/*Muuttujien ja taulukon alustus*/
	char jatko;
	struct cell populaatio[KOKO][KOKO] = {{0, 0}};
	struct rules ehdot[2];

	/*Alkutilanteen valinta*/
	start(populaatio, ehdot, KOKO);
	
	/*ncurses alkuasetukset*/
	initscr();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_GREEN);
	init_pair(2, COLOR_RED, COLOR_RED);
	init_pair(3, COLOR_BLACK, COLOR_WHITE);
	bkgd(COLOR_PAIR(3));
	noecho();
	
	/*Kierron jatko ja katkaisu*/
	while(jatko != 'q')
	{
		draw(populaatio, KOKO);
		future(populaatio, ehdot, KOKO);/*päivittää taulukon tilanteen seuraavalle kierrokselle*/
		jatko = getch ();/*odottaa näppäinpainallusta simulaation jatkamiseksi*/
	}
	endwin();/*ncurses lopetus*/
} /* end of main */

/*********************************************************************
*    FUNCTIONS                                                     *
**********************************************************************/

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME:
; DESCRIPTION:
;	Input:
;	Output:
;  Used global variables:
; REMARKS when using this function:
;*********************************************************************/
