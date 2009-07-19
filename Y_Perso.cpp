/*
 *      Y_Perso.cpp
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


#include "Y_Perso.h"


Y_Perso::Y_Perso(int size_x,int size_y)
	: Actor(size_x,size_y),nbr_bills(0),energy(100),yelling(0),throwing(0)
{
	mass=0;
	Animation *anim_stand=new Animation();
	anim_stand->load_animation("data/stand.png",45,45);
	add_anim(anim_stand);
	Animation *anim_run=new Animation();
	anim_run->load_animation("data/run.png",45,45);
	add_anim(anim_run);
	Animation *anim_throw=new Animation();
	anim_throw->load_animation("data/throw.png",45,45);
	add_anim(anim_throw);
	Animation *anim_yell=new Animation();
	anim_yell->load_animation("data/yell.png",45,45);
	add_anim(anim_yell);
	yell_buffer.LoadFromFile("data/sound/leave2.ogg");
	yell_sound.SetBuffer(yell_buffer);
	fire_buffer.LoadFromFile("data/sound/burn2.ogg");
	fire_sound.SetBuffer(fire_buffer);
}


Y_Perso::~Y_Perso()
{
	delete_all_anims();
}

bool Y_Perso::update()//return true if object is deleted
{
	bool ret;
	ret=Phys_Object::update();

	if (throwing>0)
	{
		throwing--;
		if (throwing>0)
		{
			return false;
		}else set_position(Y_Perso::STAND,0);
	}	

	if (yelling>0)
	{
		yelling--;
		if (yelling>0)
		{
			energy-=1;
			return false;
		}else set_position(Y_Perso::STAND,0);
	}

	if ((target_x-x)>1)
	{
		if (speed_x<0.01)
		{
			speed_x=0;
			set_position(Y_Perso::RUN,0);
			set_flipX(true);
		}
		
		speed_x+=3+energy/20;
		speed_x/=1.3;
		energy-=0.05;
	}
	else if ((target_x-x)<-1)
	{
		if (speed_x>-0.01)
		{
			speed_x=0;
			set_position(Y_Perso::RUN,0);
			set_flipX(false);
		}
		speed_x+=-3-energy/20;
		speed_x/=1.3;
		energy-=0.05;
	}else
	{
		energy+=0.2;
		if (energy>100) energy=100;
		if (fabs(speed_x)>0.01) set_position(Y_Perso::STAND,0);
		speed_x=0;
	}
	if (energy<0)
	{
		target_x=x;
		speed_x=0;
		set_position(Y_Perso::STAND,0);
	}
	
	//std::cout<<speed_x<<std::endl;
	//std::cout<<"Energy: "<<energy<<std::endl;
	
	return ret;
}

std::string Y_Perso::str_infos()
{
	std::ostringstream oss;//output stream
	oss<<"Bills:  "<<nbr_bills;
	return oss.str();
}

void Y_Perso::re_init()
{
	energy=100;
	yelling=0;
	throwing=0;
}

bool Y_Perso::yell()
{
	if ((yelling>0)||(energy<80)) return false;
	
	yell_sound.Play();
	yelling=80;
	set_position(Y_Perso::YELL,0);
	if (fabs(target_x-x)>1) target_x=x;
	speed_x=0;
	
	return true;
}

bool Y_Perso::throw_money(Y_Fire & fire)
{
	if ((throwing>0)||(nbr_bills<=0)) return false;
	set_position(Y_Perso::THROW,0);
	throwing=20;
	
	fire.add_money();
	fire_sound.Play();
	nbr_bills--;
	
	return true;
}

void Y_Perso::draw_infos(sf::RenderWindow & App,int x2,int y2)
{
	App.Draw(sf::Shape::Rectangle(x2-21, y2-59, x2+21, y2-58, sf::Color::Color(200,150,100,255) ));
	App.Draw(sf::Shape::Rectangle(x2-20, y2-59, x2-20+energy/2.5, y2-58, sf::Color::Color(200-energy*2,0,energy*2,255) ));
	//std::cout<<nbr_bills<<std::endl;
}
