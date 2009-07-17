/*
 *      Y_Wolf.cpp
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


#include "Y_Wolf.h"

Animation *Y_Wolf::anim_wolf;
std::list <Y_Wolf*> Y_Wolf::wolves;
sf::SoundBuffer Y_Wolf::w_yell_buffer;
sf::Sound Y_Wolf::w_yell_sound;
sf::SoundBuffer Y_Wolf::w_stress_buffer;
sf::Sound Y_Wolf::w_stress_sound;

 
Y_Wolf::Y_Wolf(int size_x,int size_y,Y_Perso * _perso,Y_Fire * _fire1,Y_Fire * _fire2)
	: Actor(size_x,size_y),stress(0),perso(_perso),fire1(_fire1),fire2(_fire2)
{
	if (wolves.empty())
	{
		anim_wolf=new Animation();
		anim_wolf->load_animation("data/wolf2.png",54,45);
		w_yell_buffer.LoadFromFile("data/sound/wolf1.wav");
		w_yell_sound.SetBuffer(w_yell_buffer);
		w_stress_buffer.LoadFromFile("data/sound/wolf3.wav");
		w_stress_sound.SetBuffer(w_stress_buffer);
	}
	add_anim(anim_wolf);
	x=-200;
	y=180;
	mass=0;
	//wolf.SetScale(2.0,2.0);
	wolves.push_back(this);
	number=wolves.size();
}


Y_Wolf::~Y_Wolf()
{
	wolves.remove(this);
	if (wolves.empty()) delete_all_anims();
}


bool Y_Wolf::update()//return true if object is deleted
{
	if (rand()%1000==3) w_yell_sound.Play();
	
	bool ret;
	ret=Phys_Object::update();


	float wolves_close=0;//nbr of wolves close
	
	std::list <Y_Wolf*>::iterator wolf_iterator;
	wolf_iterator = wolves.begin();
    while( wolf_iterator != wolves.end() ) {
		wolves_close+=1/(fabs(x-(*wolf_iterator)->x)+1);
		++wolf_iterator;
    }

	float previous_stress=stress;
	if (x<0)
	{
		stress=(stress*10+						//previous
			//(400-fabs(x))					//position
			+perso->get_yelling()*1000		//yell
			//+10*(fire1->get_intensity()+fire1->get_intensity_increase()*1000)/ sqrtf(fabs(x-fire1->get_pos_x()))
			+10*(fire2->get_intensity()+fire2->get_intensity_increase()*1000)/ sqrtf(fabs(x-fire2->get_pos_x()))
			-10*wolves_close
			+ rand() % 400 - 200
			)/11;
		if (stress<0) stress=0;
		target_x=-stress;
	}else{
		stress=(stress*10+						//previous
			//(400-fabs(x))					//position
			+perso->get_yelling()*1000		//yell
			+10*(fire1->get_intensity()+fire1->get_intensity_increase()*1000)/ sqrtf(fabs(x-fire1->get_pos_x()))
			//+10*(fire2->get_intensity()+fire2->get_intensity_increase()*1000)/ sqrtf(fabs(x-fire2->get_pos_x()))
			-10*wolves_close
			+ rand() % 400 - 200
			)/11;
		if (stress<0) stress=0;
		target_x=+stress;
	}

	if ((target_x-x)>1)
	{
		if (speed_x<0.01)
		{
			speed_x=0;
			set_flipX(false);
		}
		
		speed_x+=5;
		speed_x/=1.3;
	}
	else if ((target_x-x)<-1)
	{
		if (speed_x>-0.01)
		{
			speed_x=0;
			set_flipX(true);
		}
		speed_x+=-5;
		speed_x/=1.3;
	}else
	{
		speed_x=0;
	}
	
	if (previous_stress*2<stress) w_stress_sound.Play();
	
	return ret;
}

void Y_Wolf::draw_infos(sf::RenderWindow & App,int x2,int y2)
{
	//App.Draw(sf::Shape::Rectangle(x2-20, y2-59-number, x2-20+stress/2.5, y2-58-number, sf::Color::Color(255,0,0,255) ));
}


