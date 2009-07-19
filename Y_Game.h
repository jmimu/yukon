/*
 *      Y_Game.h
 *      
 *      Copyright 2009 JMMuller <jmmuller@ts>
 *      
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *      
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *      
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */


#ifndef Y_Game_H
#define Y_Game_H

#include "engine/Game.h"
#include "Y_Level.h"
#include "Y_Perso.h"
#include "Y_Wolf.h"
#include "Y_Fire.h"

class Y_Game: public Game //the actual Game class
{
	public:
		Y_Game(float _FPS=50.);
		virtual ~Y_Game();
		bool load_level();
		bool run();//main loop return error ?
		bool lost();
		bool won();
		bool finished();
		void fade_out(unsigned long duration);
		Y_Perso player;

		Y_Fire spr_fire1;
		Y_Fire spr_fire2;	

		std::vector <Y_Wolf*> wolves;	
		
		int night_number;
		int nbr_bills_init;
		int nbr_total_nights;
		int nbr_wolves_add;//nbr of wolves added every night
	
	private:
		
};

#endif /* Y_Game_H */ 
