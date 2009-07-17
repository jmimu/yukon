/*
 *      Y_Level.cpp
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


#include "Y_Level.h"


Y_Level::Y_Level()
  : Level(),level_time(0),sky_color_r(255),sky_color_g(255),sky_color_b(255),sky_color_a(0),
  moon_image(),moon_sprite()
{
  std::cout<<"Create Y_Level\n";
  load_level();
  moon_image.LoadFromFile("data/moon.png");
  moon_sprite.SetImage(moon_image);
}


Y_Level::~Y_Level()
{
  
}

bool Y_Level::load_level()
{
  //background
  bg.push_back(Ground_Plane(0,0));
  //foreground
  fg.push_back(Ground_Plane(0,0,false));
  //objects
  

  Particle_Src<Particle> *fire1_smoke =new Particle_Src<Particle>(Particle::SMOKE,100,180,objs,0,0 ,0,0,10,1,-0.5,0.1,0.2,0.1);
  objs.push_back(fire1_smoke);
  //Particle_Src<Particle> *fire1 =new Particle_Src<Particle>(Particle::FIRE,100,150,objs,0,0,0,1, 10,1,-1,0.1, 0.1,0.1);
  //objs.push_back(fire1);

  Particle_Src<Particle> *fire2_smoke =new Particle_Src<Particle>(Particle::SMOKE,-100,180,objs,0,0 ,0,1,10,1,-0.5,0.1,0.2,0.1);
  objs.push_back(fire2_smoke);
  //Particle_Src<Particle> *fire2 =new Particle_Src<Particle>(Particle::FIRE,-100,150,objs,0,0,0,1, 10,1,-1,0.1, 0.1,0.1);
  //objs.push_back(fire2);

  Particle_Src<Particle> *snow1 =new Particle_Src<Particle>(Particle::SNOW,-500,-500,objs,0,0,0,1, 30,1,0.8,0.2, 0.5,0.5);
  objs.push_back(snow1);


  return true;
}

void Y_Level::draw_fg(sf::RenderWindow & App)
{
	level_time+=0.001;
	
  sky_color_a=127*(cos(2*3.1516*level_time+3.1416)+1);
  sky_color_r=127*(cos(2*3.1516*level_time       )+1);
  sky_color_g=0;
  sky_color_b=63*(cos(4*3.1516*level_time+3.1416)+1);

  
  fg[0].get_sprite()->SetColor(sf::Color(sky_color_r,sky_color_g,sky_color_b,sky_color_a));
  
  Level::draw_fg(App);
  
  moon_sprite.SetPosition(sin(2*3.1516*level_time*0.233)*400,cos(2*3.1516*level_time*0.233)*50-50);
  App.Draw(moon_sprite);
  //std::cout<<level_time<<std::endl;
}

