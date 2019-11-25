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
\fn void future(struct cell taulukko[KOKO][KOKO], int koko)
\brief Laskee taulukon solujen tilan seuraavalla kierroksella
\param Input:  olentotaulukko, taulukon koko, sääntötaulukko, käyttäjän valitsema alkutilanne
\param Output: taulukon tila*/
/*********************************************************************/
void future(struct cell taulukko[KOKO][KOKO], struct rules ehdot[2], int koko)
{
	int x, y, minx, miny, maxx, maxy, naapuri, vihollinen, populaatio;
	
	/**1. Silmukka selvittää taulukon tulevan tilan tarkistamalla erikseen asuttujen ja asumattomien solujen tilat*/
	for(x = 0; x < koko; x++)
	{
		for(y = 0; y < koko; y++)
		{
			naapuri = 0;
			vihollinen = 0;
			populaatio = 0;
			minx = x - 1;
			miny = y - 1;
			maxx = x + 1;
			maxy = y + 1;
			/*ehtolausekkeilla huomioidaan taulukon rajat*/
			if(minx < 0) minx = koko - 1;
			if(miny < 0) miny = koko - 1;
			if(maxx >= koko) maxx = 0;
			if(maxy >= koko) maxy = 0;
			
			/*tarkistaa yksitellen asutun solun naapurit*/
			if(taulukko[x][y].current != 0)
			{
				if(taulukko[minx][miny].current == taulukko[x][y].current)
				{
					if(taulukko[x][y].current == 1) naapuri += ehdot[0].voima;
					if(taulukko[x][y].current == 2) naapuri += ehdot[1].voima;
					populaatio++;
				}
				if(taulukko[minx][y].current == taulukko[x][y].current)
				{
					if(taulukko[x][y].current == 1) naapuri += ehdot[0].voima;
					if(taulukko[x][y].current == 2) naapuri += ehdot[1].voima;
					populaatio++;
				}
				if(taulukko[minx][maxy].current == taulukko[x][y].current)
				{
					if(taulukko[x][y].current == 1) naapuri += ehdot[0].voima;
					if(taulukko[x][y].current == 2) naapuri += ehdot[1].voima;
					populaatio++;
				}
				if(taulukko[x][miny].current == taulukko[x][y].current)
				{
					if(taulukko[x][y].current == 1) naapuri += ehdot[0].voima;
					if(taulukko[x][y].current == 2) naapuri += ehdot[1].voima;
					populaatio++;
				}
				if(taulukko[x][maxy].current == taulukko[x][y].current)
				{
					if(taulukko[x][y].current == 1) naapuri += ehdot[0].voima;
					if(taulukko[x][y].current == 2) naapuri += ehdot[1].voima;
					populaatio++;
				}
				if(taulukko[maxx][miny].current == taulukko[x][y].current)
				{
					if(taulukko[x][y].current == 1) naapuri += ehdot[0].voima;
					if(taulukko[x][y].current == 2) naapuri += ehdot[1].voima;
					populaatio++;
				}
				if(taulukko[maxx][y].current == taulukko[x][y].current)
				{
					if(taulukko[x][y].current == 1) naapuri += ehdot[0].voima;
					if(taulukko[x][y].current == 2) naapuri += ehdot[1].voima;
					populaatio++;
				}
				if(taulukko[maxx][maxy].current == taulukko[x][y].current)
				{
					if(taulukko[x][y].current == 1) naapuri += ehdot[0].voima;
					if(taulukko[x][y].current == 2) naapuri += ehdot[1].voima;
					populaatio++;
				}
				
				//vihollisten voiman lasku
				if(taulukko[minx][miny].current != taulukko[x][y].current && taulukko[minx][miny].current != 0)
				{
					if(taulukko[x][y].current == 1) vihollinen += ehdot[1].voima;
					if(taulukko[x][y].current == 2) vihollinen += ehdot[0].voima;
					populaatio++;
				}
				if(taulukko[minx][y].current != taulukko[x][y].current && taulukko[minx][y].current != 0)
				{
					if(taulukko[x][y].current == 1) vihollinen += ehdot[1].voima;
					if(taulukko[x][y].current == 2) vihollinen += ehdot[0].voima;
					populaatio++;
				}
				if(taulukko[minx][maxy].current != taulukko[x][y].current && taulukko[minx][maxy].current != 0)
				{
					if(taulukko[x][y].current == 1) vihollinen += ehdot[1].voima;
					if(taulukko[x][y].current == 2) vihollinen += ehdot[0].voima;
					populaatio++;
				}
				if(taulukko[x][miny].current != taulukko[x][y].current && taulukko[x][miny].current != 0)
				{
					if(taulukko[x][y].current == 1) vihollinen += ehdot[1].voima;
					if(taulukko[x][y].current == 2) vihollinen += ehdot[0].voima;
					populaatio++;
				}
				if(taulukko[x][maxy].current != taulukko[x][y].current && taulukko[x][maxy].current != 0)
				{
					if(taulukko[x][y].current == 1) vihollinen += ehdot[1].voima;
					if(taulukko[x][y].current == 2) vihollinen += ehdot[0].voima;
					populaatio++;
				}
				if(taulukko[maxx][miny].current != taulukko[x][y].current && taulukko[maxx][miny].current != 0)
				{
					if(taulukko[x][y].current == 1) vihollinen += ehdot[1].voima;
					if(taulukko[x][y].current == 2) vihollinen += ehdot[0].voima;
					populaatio++;
				}
				if(taulukko[maxx][y].current != taulukko[x][y].current && taulukko[maxx][y].current != 0)
				{
					if(taulukko[x][y].current == 1) vihollinen += ehdot[1].voima;
					if(taulukko[x][y].current == 2) vihollinen += ehdot[0].voima;
					populaatio++;
				}
				if(taulukko[maxx][maxy].current != taulukko[x][y].current && taulukko[maxx][maxy].current != 0)
				{
					if(taulukko[x][y].current == 1) vihollinen += ehdot[1].voima;
					if(taulukko[x][y].current == 2) vihollinen += ehdot[0].voima;
					populaatio++;
				}
				if(naapuri + 1 < vihollinen) populaatio = 0;
			}
			/*tarkistaa yksitellen asumattomien solujen tilan*/
			else
			{
				if(taulukko[minx][miny].current == 1) naapuri++;
				if(taulukko[minx][y].current == 1) naapuri++;
				if(taulukko[minx][maxy].current == 1) naapuri++;
				if(taulukko[x][miny].current == 1) naapuri++;
				if(taulukko[x][maxy].current == 1) naapuri++;
				if(taulukko[maxx][miny].current == 1) naapuri++;
				if(taulukko[maxx][y].current == 1) naapuri++;
				if(taulukko[maxx][maxy].current == 1) naapuri++;
				
				if(taulukko[minx][miny].current == 2) vihollinen++;
				if(taulukko[minx][y].current == 2) vihollinen++;
				if(taulukko[minx][maxy].current == 2) vihollinen++;
				if(taulukko[x][miny].current == 2) vihollinen++;
				if(taulukko[x][maxy].current == 2) vihollinen++;
				if(taulukko[maxx][miny].current == 2) vihollinen++;
				if(taulukko[maxx][y].current == 2) vihollinen++;
				if(taulukko[maxx][maxy].current == 2) vihollinen++;
			}
			
			/*asuttujen solujen tila*/
			if(taulukko[x][y].current == 1 && populaatio >= ehdot[0].ali && populaatio <= ehdot[0].yli) taulukko[x][y].future = taulukko[x][y].current;
			else if(taulukko[x][y].current == 2 && populaatio >= ehdot[1].ali && populaatio <= ehdot[1].yli) taulukko[x][y].future = taulukko[x][y].current;
			/*asumattomien solujen tila*/
			else if(taulukko[x][y].current == 0 && naapuri == ehdot[0].kasvu && vihollinen == ehdot[1].kasvu) taulukko[x][y].future = (rand() % 2) + 1;
			else if(taulukko[x][y].current == 0 && naapuri == ehdot[0].kasvu) taulukko[x][y].future = 1;
			else if(taulukko[x][y].current == 0 && vihollinen == ehdot[1].kasvu) taulukko[x][y].future = 2;
			else taulukko[x][y].future = 0;
		}
	}
	
	/**2. silmukka päivittää 1. silmukassa selvitetyn tulevan tilan nykytilaksi*/
	for(x = 0; x < koko; x++)
	{
		for(y = 0; y < koko; y++)
		{
			taulukko[x][y].current = taulukko[x][y].future;
		}
	}
}