/*
 *      Game.cpp
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


#include "Game.h"



Game::Game(std::string window_name,float _FPS)
  : FPS(_FPS),App(sf::VideoMode(640, 400, 32), window_name.c_str())
{
 	std::cout<<"Create Game\n";
	App.SetFramerateLimit(FPS);
    srand ( time(NULL) );
}


Game::~Game()
{
	Particle::delete_anims();
}

bool Game::load_level()
{
	level=new Level();
	return true;
}



bool Game::get_input()
{
	/*bool button=App.GetInput().IsJoystickButtonDown(0, 1);

    if (attacking>=0)
    {
    	if ((App.GetInput().GetJoystickAxis(0, sf::Joy::AxisX)!=0)||(App.GetInput().GetJoystickAxis(0, sf::Joy::AxisY)!=0))
    	{
    		vx=(int)(App.GetInput().GetJoystickAxis(0, sf::Joy::AxisX)/20.0);
			vy=(int)(App.GetInput().GetJoystickAxis(0, sf::Joy::AxisY)/20.0);
    	}else{
        	if (!(App.GetInput().IsKeyDown(sf::Key::Left))&&(!(App.GetInput().IsKeyDown(sf::Key::Left)))) vx=0;
        	if (!(App.GetInput().IsKeyDown(sf::Key::Up))&&(!(App.GetInput().IsKeyDown(sf::Key::Down)))) vy=0;
        	if (App.GetInput().IsKeyDown(sf::Key::Left))
        		vx=-5;
        	if (App.GetInput().IsKeyDown(sf::Key::Right))
        		vx=5;
        	if (App.GetInput().IsKeyDown(sf::Key::Up))
        		vy=-5;
        	if (App.GetInput().IsKeyDown(sf::Key::Down))
        		vy=5;
        	if (App.GetInput().IsKeyDown(sf::Key::Space))
        		button=true;
        	else button=App.GetInput().IsJoystickButtonDown(0, 1);
        }
    }*/
	return false;
}
