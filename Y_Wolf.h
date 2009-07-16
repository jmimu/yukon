/*
 *      Y_Wolf.h
 *      
 *      Copyright 2009 Roa <roa@ordi-ana>
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


#ifndef Y_WOLF_H
#define Y_WOLF_H
#include <SFML/Audio.hpp>

#include "engine/Actor.h"

#include <list>

#include "Y_Perso.h"
#include "Y_Fire.h"

class Y_Wolf: public Actor
{
	public:
		Y_Wolf(int size_x,int size_y,Y_Perso * _perso,Y_Fire * _fire1,Y_Fire * _fire2);
		virtual ~Y_Wolf();
		bool update();//return true if object is to be deleted
		void draw_infos(sf::RenderWindow & App,int x2,int y2);
		float stress;
		static std::list <Y_Wolf*> wolves;
		Y_Perso * perso;
		Y_Fire * fire1;
		Y_Fire * fire2;
	protected:
		static Animation *anim_wolf;
		int number;
		
		static sf::SoundBuffer w_yell_buffer;
		static sf::Sound w_yell_sound;
		static sf::SoundBuffer w_stress_buffer;
		static sf::Sound w_stress_sound;
};

#endif /* Y_WOLF_H */ 
