/*
 *      Y_sPerso.h
 *      
 *      Copyright 2009 jmmuller <jmmuller@jmmuller-laptop>
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


#ifndef Y_PERSO_H
#define Y_PERSO_H
#include <SFML/Audio.hpp>

#include "engine/Actor.h"

#include "Y_Fire.h"

class Y_Perso: public Actor
{
	public:
		enum Pos_Y_Perso
		{
			STAND,
			RUN,
			THROW,
			YELL
		};
		
	public:
		Y_Perso(int size_x,int size_y);
		virtual ~Y_Perso();
		bool update();//return true if object is to be deleted
		bool is_at_target(){return fabs((target_x-x))<1;};
		bool yell();
		bool throw_money(Y_Fire & fire);
		void draw_infos(sf::RenderWindow & App,int x2,int y2);
		int get_yelling(){return yelling;};
		int nbr_bills;
	protected:
		float energy;//defines player's speed
		int yelling;//time still yelling
		int throwing;//time still throwing
		sf::SoundBuffer yell_buffer;
		sf::Sound yell_sound;
};

#endif /* Y_PERSO_H */ 
