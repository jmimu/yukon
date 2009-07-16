/*
 *      Y_Fire.cpp
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


#include "Y_Fire.h"


Y_Fire::Y_Fire(int _pos_x)
	: Anim_Sprite(),pos_x(_pos_x),intensity(100),intensity_increase(0)
{
	
}


Y_Fire::~Y_Fire()
{
	
}

bool Y_Fire::add_money()
{
	intensity+=30;
	intensity_increase=20;
	return true;
}

void Y_Fire::draw_infos(sf::RenderWindow & App,int x2,int y2)
{
	App.Draw(sf::Shape::Rectangle(x2-40, y2+0, x2-39, y2+0-intensity/2, sf::Color::Color(0,200,200,255) ));
}

void Y_Fire::update()//return true if object is deleted
{
	SetScale(1,intensity/100.0);
	if (intensity_increase>0) intensity_increase--;
	//intensity-=0.5;
	intensity/=1.003;
	if (intensity<1) intensity=1;
}
