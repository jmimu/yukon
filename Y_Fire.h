/*
 *      Y_Fire.h
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


#ifndef Y_FIRE_H
#define Y_FIRE_H

#include "engine/Anim_Sprite.h"

class Y_Fire: public Anim_Sprite
{
	public:
		Y_Fire(int _pos_x);
		virtual ~Y_Fire();

		float get_intensity(){return intensity;};
		int get_intensity_increase(){return intensity_increase;};
		bool add_money();
		void draw_infos(sf::RenderWindow & App,int x2,int y2);
		void update();
		float get_pos_x(){return pos_x;};
	protected:
		float pos_x;
		float intensity;
		int intensity_increase;
};

#endif /* Y_FIRE_H */ 
