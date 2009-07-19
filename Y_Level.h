/*
 *      Y_Level.h
 *      
 *      Copyright 2009 jmimu
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


#ifndef Y_Level_H
#define Y_Level_H

#include <iostream>
#include "engine/Level.h"

class Y_Level: public Level
{
	public:
		Y_Level();
		virtual ~Y_Level();
		bool load_level();
		void draw_fg(sf::RenderWindow & App);

		float level_time;

	protected:
		float sky_color_r;
		float sky_color_g;
		float sky_color_b;
		float sky_color_a;
		
		sf::Image moon_image;
		sf::Sprite moon_sprite;
};

#endif /* Y_Level_H */ 
