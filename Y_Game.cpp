/*
 *      Y_Game.cpp
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


#include "Y_Game.h"

using namespace std;

Y_Game::Y_Game(float _FPS)
	: Game("R",_FPS),player(0,0),spr_fire1(80),spr_fire2(-80)
{
	std::cout<<"Create Y_Game\n";	
	load_level();
	level->get_objs().push_back(&player);
	for (unsigned int i=0;i<5;i++)
	{
		wolves.push_back(new Y_Wolf(0,0,&player,&spr_fire1,&spr_fire2));
		wolves[i]->x=-(rand() % 500 + 200);
		wolves[i]->y=180;
		level->get_objs().push_back(wolves[i]);
	}
	for (unsigned int i=5;i<10;i++)
	{
		wolves.push_back(new Y_Wolf(0,0,&player,&spr_fire1,&spr_fire2));
		wolves[i]->x=(rand() % 500 + 200);
		wolves[i]->y=180;
		level->get_objs().push_back(wolves[i]);
	}
}


Y_Game::~Y_Game()
{
	for (unsigned int i=0;i<wolves.size();i++)
		delete wolves[i];
}

bool Y_Game::load_level()
{
	std::cout<<"load_level\n";	
	level = new Y_Level();
	return true;
}

bool Y_Game::run()
{
  cout<<"Start running game\n";

  Animation *anim_fire=new Animation();
  anim_fire->load_animation("data/divers/fire.png",27,64);
  spr_fire1.add_anim(anim_fire);
  spr_fire1.x=100;
  spr_fire1.y=180;
  spr_fire2.add_anim(anim_fire);
  spr_fire2.x=-100;
  spr_fire2.y=180;
	
  player.x=0;
  player.y=180;
	
  float t=0;
  int t_int=0;
  bool running=true;
  while (running)
    {

      //std::cout<<"frame"<<std::endl;
	  
      sf::Event Event;
      while (App.GetEvent(Event))
        {
	  if ((Event.Type==sf::Event::Closed)||((Event.Type==sf::Event::KeyPressed)&&(Event.Key.Code==sf::Key::Escape)))
	    return EXIT_SUCCESS;
        }
      get_input();
        
      //std::cout<<"look at "<<see_x<<" "<<see_y<<std::endl;        
      if (App.GetInput().IsKeyDown(sf::Key::Right)) {player.target_x=spr_fire1.get_pos_x();}
      if (App.GetInput().IsKeyDown(sf::Key::Left)) {player.target_x=spr_fire2.get_pos_x();}
	  if (App.GetInput().IsKeyDown(sf::Key::Down)) {player.target_x=player.x;player.speed_x=0;player.set_position(Y_Perso::STAND,0);}
	  if (App.GetInput().IsKeyDown(sf::Key::Up)) {player.yell();};
	  if (App.GetInput().IsKeyDown(sf::Key::Space))
	  {
		  bool res=false;
		  if ((fabs(player.x-spr_fire1.get_pos_x())<1)&&(player.target_x==spr_fire1.get_pos_x())) res=player.throw_money(spr_fire1);
		  if ((fabs(player.x-spr_fire2.get_pos_x())<1)&&(player.target_x==spr_fire2.get_pos_x())) res=player.throw_money(spr_fire2);
		  if (res) 
		  {
			  Particle_Src<Particle> *money =new Particle_Src<Particle>(Particle::BILL,player.x,player.y,level->get_objs(),0,0 ,1,0,0,0,0,0,0.2,0.1);
				level->get_objs().push_back(money);
			}
		};

       
      t+=0.2;
      t_int++;
      if (t>=100000000.) t=0;
      level->update();
        
      level->draw(App,t);
        
 
      spr_fire1.update();
      spr_fire1.set_anim_image(t);
      level->get_cam()->draw_spr(App,spr_fire1);
      spr_fire2.update();
      spr_fire2.set_anim_image(t);
      level->get_cam()->draw_spr(App,spr_fire2);


      level->draw_fg(App);

      App.Display();
        
    }
  return true;
}
