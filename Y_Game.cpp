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
	: Game("Yukon",_FPS),player(0,0),spr_fire1(80),spr_fire2(-80),night_number(0),nbr_bills_init(90),nbr_total_nights(5),nbr_wolves_add(4)
{
	std::cout<<"Create Y_Game\n";	
	load_level();
	level->get_objs().push_back(&player);
	
	  sf::Image next_image;
	  next_image.LoadFromFile("data/title.png");
	  sf::Sprite next_sprite;
	  next_sprite.SetImage(next_image);
	  App.Draw(next_sprite);
	  
	  bool running1=true;
	  bool running2=true;
	  sf::Event Event;
	  sf::String txt_begin;
	  txt_begin.SetSize(25.f);
	  txt_begin.SetColor(sf::Color(100,100, 200));
	  txt_begin.SetPosition(240,290);
	  txt_begin.SetText("* Left - Right : move\n* Down : stop\n* Up : yell\n* Space : add money");
	  float wait=0;
	  while (running2)
	  {
		App.Clear();
	    if (running1) App.Draw(next_sprite); else wait+=0.1;
		App.Draw(txt_begin);
		App.Display();
		while (App.GetEvent(Event))
		{
		  if ((Event.Type==sf::Event::Closed)||((Event.Type==sf::Event::KeyPressed)&&(Event.Key.Code==sf::Key::Escape)))
			running2=false;
		  if ((!running1)&&(wait>2)&&((App.GetInput().IsKeyDown(sf::Key::Space))||(App.GetInput().IsKeyDown(sf::Key::Return)))) running2=false;
		  if ((running1)&&((App.GetInput().IsKeyDown(sf::Key::Space))||(App.GetInput().IsKeyDown(sf::Key::Return))))
		  {
			  running1=false;
	  		  txt_begin.SetText("After you hold up a bank in Dawson,\nyou run through the deep, wild and\nsnowy White Agony Valley of Yukon.\n\nWhen night falls, you have to light\na fire to keep wolves away.\nBut there is few wood, and you have\nto sacrifice your stolen money!\n\nLiberty is 5 walking days away...\n\nGood luck!");
			  txt_begin.SetSize(30.f);
	  		  txt_begin.SetColor(sf::Color(150,150, 200));
	  		  txt_begin.SetPosition(50,10);
		  }
		  
	    }
	  }

	  fade_out(50);
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

  sf::String txt_bills;
  txt_bills.SetSize(30.f);
  txt_bills.SetColor(sf::Color(10, 250, 10));
  txt_bills.SetText("Bills: ");
  txt_bills.SetPosition(150,20);

  night_number=0;

  		
  player.nbr_bills=nbr_bills_init;

	  sf::Image next_image;
	  next_image.LoadFromFile("data/walk.png");
	  sf::Sprite next_sprite;
	  next_sprite.SetImage(next_image);
	  App.Draw(next_sprite);
	  sf::String txt_end;
	  txt_end.SetColor(sf::Color(100, 100, 200));
	  txt_end.SetSize(30.f);
	  txt_end.SetPosition(200,10);
	  txt_end.SetText("This is the first night...\n");
	  App.Draw(txt_end);
	  App.Display();
	  fade_out(150);

  bool quit_game=false;
  bool is_lost=false;
  while (!quit_game)
  {
		//add wolves every night
		if (is_lost)
		{
			for (unsigned int i=0;i<wolves.size();i++)
			{
				level->get_objs().remove(wolves[i]);
				delete wolves[i];
			}
			wolves.resize(0);
		}
		
		for (int i=0;i<nbr_wolves_add;i++)
		{
			wolves.push_back(new Y_Wolf(0,0,&player,&spr_fire1,&spr_fire2));
			level->get_objs().push_back(wolves.back());
		}

		for (unsigned int i=0;i<wolves.size()/2;i++)
		{
			wolves[i]->x=-(rand() % 1000 + 500);
			wolves[i]->y=180;
		}	
		for (unsigned int i=wolves.size()/2;i<wolves.size();i++)
		{
			wolves[i]->x=(rand() % 1000 + 500);
			wolves[i]->y=180;
		}
				
		sf::SoundBuffer far_buffer;
		far_buffer.LoadFromFile("data/sound/far2.ogg");
		sf::Sound far_sound;
		far_sound.SetBuffer(far_buffer);	
		far_sound.Play();	
			
	  player.x=0;
	  player.y=180;
	  player.re_init();
	  spr_fire1.init();
	  spr_fire2.init();
	  ((Y_Level*)level)->level_time=0;
	
	  float t=0;
	  int t_int=0;
	  bool running=true;
	  is_lost=false;
	  
	  night_number++;
	  
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
			  if ((fabs(player.x-spr_fire1.get_pos_x())<2)&&(player.target_x==spr_fire1.get_pos_x())) res=player.throw_money(spr_fire1);
			  if ((fabs(player.x-spr_fire2.get_pos_x())<2)&&(player.target_x==spr_fire2.get_pos_x())) res=player.throw_money(spr_fire2);
			  if (res) 
			  {
				  Particle_Src<Particle> *money =new Particle_Src<Particle>(Particle::BILL,player.x,player.y,level->get_objs(),0,0 ,10,0,0,0,0,0,1,0);
					level->get_objs().push_back(money);
				}
			};

		  for (unsigned int i=0;i<wolves.size();i++)
			if (fabs(wolves[i]->x)<90)
			{
				is_lost=true;
				running=false;
			}
		  if (((Y_Level*)level)->level_time>1)
		  {
				is_lost=false;
				running=false;			  
		  }
		  
		  std::ostringstream oss;//output stream
		  oss<<"Night number  "<<night_number<<"    "<<player.str_infos();
		  txt_bills.SetText(oss.str());
		   
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
		  App.Draw(txt_bills);
		  App.Display();
			
		}//end loop
		
	if (is_lost) quit_game=lost();
	else if (night_number==nbr_total_nights) quit_game=finished(); else quit_game=won();
	
		
  }//quit_game
  return true;
}

bool Y_Game::lost()
{
	  sf::String txt_end;
	  txt_end.SetSize(20.f);
	  txt_end.SetColor(sf::Color(200, 50, 50));
	  txt_end.SetText("Game lost !\n");
	  float t=0;
	  bool running2=true;
	  sf::Event Event;
	  while (running2)
	  {
		t=t+0.1;
		txt_end.SetSize(50+5*sin(t));
		txt_end.SetPosition(150.f-(0+5*sin(t)), 150.f-(0+1.5*sin(t)));
		level->draw(App,t);
		  level->draw_fg(App);
		App.Draw(txt_end);
		App.Display();
		while (App.GetEvent(Event))
		{
		  if ((Event.Type==sf::Event::Closed)||((Event.Type==sf::Event::KeyPressed)&&(Event.Key.Code==sf::Key::Escape)))
			return true;
		  if ((t>1)&&(App.GetInput().IsKeyDown(sf::Key::Space))) running2=false;
		  if ((t>1)&&(App.GetInput().IsKeyDown(sf::Key::Return))) running2=false;
	    }
	  }
	  night_number=0;
	  player.nbr_bills=nbr_bills_init;
	  fade_out(100);
  
	  
	  sf::Image next_image;
	  next_image.LoadFromFile("data/lost.png");
	  sf::Sprite next_sprite;
	  next_sprite.SetImage(next_image);
	  App.Draw(next_sprite);
	  txt_end.SetColor(sf::Color(100, 100, 200));
	  txt_end.SetSize(40.f);
	  txt_end.SetPosition(220, 330);
	  txt_end.SetText("You have been eatten!\n");
	  App.Draw(txt_end);
	  App.Display();
	  fade_out(100);

	  return false;
}

bool Y_Game::won()
{
	  sf::String txt_end;
	  txt_end.SetSize(20.f);
	  txt_end.SetColor(sf::Color(50, 250, 50));
	  txt_end.SetText("Night finished !\n");
	  float t=0;
	  bool running2=true;
	  sf::Event Event;
	  while (running2)
	  {
		t=t+0.1;
		txt_end.SetSize(50+5*sin(t));
		txt_end.SetPosition(150.f-(0+5*sin(t)), 150.f-(0+1.5*sin(t)));
		level->draw(App,t);
		App.Draw(txt_end);
		App.Display();
		while (App.GetEvent(Event))
		{
		  if ((Event.Type==sf::Event::Closed)||((Event.Type==sf::Event::KeyPressed)&&(Event.Key.Code==sf::Key::Escape)))
			return true;
		  if ((t>1)&&(App.GetInput().IsKeyDown(sf::Key::Space))) running2=false;
		  if ((t>1)&&(App.GetInput().IsKeyDown(sf::Key::Return))) running2=false;
	    }
	  }
	  fade_out(100);
	  
	  sf::Image next_image;
	  next_image.LoadFromFile("data/walk.png");
	  sf::Sprite next_sprite;
	  next_sprite.SetImage(next_image);
	  App.Draw(next_sprite);
	  txt_end.SetColor(sf::Color(100, 100, 200));
	  txt_end.SetSize(30.f);
	  txt_end.SetPosition(200,10);
	  txt_end.SetText("Journey continues till next night...\n");
	  App.Draw(txt_end);
	  App.Display();
	  fade_out(150);


	  return false;
}

bool Y_Game::finished()
{
	  sf::String txt_end;
	  txt_end.SetSize(20.f);
	  txt_end.SetColor(sf::Color(50, 250, 50));
	  txt_end.SetText("Game finished !\nFinal "+player.str_infos());
	  float t=0;
	  bool running2=true;
	  sf::Event Event;
	  while (running2)
	  {
		t=t+0.1;
		txt_end.SetSize(50+5*sin(t));
		txt_end.SetPosition(150.f-(0+5*sin(t)), 150.f-(0+1.5*sin(t)));
		level->draw(App,t);
		App.Draw(txt_end);
		App.Display();
		while (App.GetEvent(Event))
		{
		  if ((Event.Type==sf::Event::Closed)||((Event.Type==sf::Event::KeyPressed)&&(Event.Key.Code==sf::Key::Escape)))
			return true;
		  if ((t>1)&&(App.GetInput().IsKeyDown(sf::Key::Space))) running2=false;
		  if ((t>1)&&(App.GetInput().IsKeyDown(sf::Key::Return))) running2=false;
	    }
	  }
	  fade_out(100);
	  std::ostringstream oss;//output stream
	  oss<<"With your "<<player.nbr_bills<<" bills left, ";
	  
	  sf::Image next_image;
	  if (player.nbr_bills<5)
	  {
	  	next_image.LoadFromFile("data/ending.png");
		txt_end.SetText(oss.str()+"you can't buy anything...");
	  }
	  else if (player.nbr_bills<=15)
	  {
	  	next_image.LoadFromFile("data/ending1.png");
		txt_end.SetText(oss.str()+"you buy a bad-taste chair...");
	  }
	  else if (player.nbr_bills<=30)
	  {
	  	next_image.LoadFromFile("data/ending2.png");
		txt_end.SetText(oss.str()+"you can buy a hut...");
	  }
	  else
	  {
	  	next_image.LoadFromFile("data/ending3.png");
		txt_end.SetText(oss.str()+"you can buy a castle, bravo!");
	  }

	  sf::Sprite next_sprite;
	  next_sprite.SetImage(next_image);
	  running2=true;
	  txt_end.SetSize(25.f);
	  txt_end.SetPosition(50, 350);
	  while (running2)
	  {
	    App.Draw(next_sprite);
		App.Draw(txt_end);
		App.Display();
		while (App.GetEvent(Event))
		{
		  if ((Event.Type==sf::Event::Closed)||((Event.Type==sf::Event::KeyPressed)&&(Event.Key.Code==sf::Key::Escape)))
			running2=false;
		  if (App.GetInput().IsKeyDown(sf::Key::Space)) running2=false;
		  if (App.GetInput().IsKeyDown(sf::Key::Return)) running2=false;
	    }
	  }

	  fade_out(10);
	  
	  return true;
}

void Y_Game::fade_out(unsigned long duration)
{
	unsigned long t=0;
	while (t<duration)
	{
		App.Draw(sf::Shape::Rectangle(0, 0, 640, 400, sf::Color::Color(0,0,0,2*255.0/duration) ));
		App.Display();
		t++;
	}
}
