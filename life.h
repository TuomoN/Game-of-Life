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
#include <curses.h>
#include <time.h>
#include <stdlib.h>

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES                                                *
*--------------------------------------------------------------------*/
/* Control flags */
#define DEBUG

/* Global constants */
#define KOKO 40 /**< Alueen sivujen pituus*/

/* Global variables */

/* Global structures */
/** \struct cell
* \brief Solujen nykytilan ja tulevan tilan säilytys
*/
struct cell
{
	int current; /**< Solun nykytila, 0 = asumaton, 1 tai 2 = asuttu*/
	int future; /**< Solun tuleva tila, estää tilanteen muuttumisen tarkistuksen aikana*/
};

struct rules
{
	int ali; /**< Olentotyypin populaation alaraja*/
	int yli; /**< Olentotyypin populaation yläraja*/
	int kasvu; /**< Olentotyypin populaation kasvuraja*/
	int voima; /**< Olentotyypin voima kilpailijoita vastaan*/
};

/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
int ask_integer_number(int min, int max);
void start(struct cell taulukko[KOKO][KOKO], struct rules ehdot[2], int koko);
void future(struct cell taulukko[KOKO][KOKO], struct rules ehdot[2], int koko);
void draw(struct cell taulukko[KOKO][KOKO], int koko);

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

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