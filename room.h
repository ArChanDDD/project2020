#pragma once
#pragma once
#ifndef Rm_def
#define Rm_def

#include "general_terms_for_level_part.h"
#include "map.h"
#include "map_content.h"
#include "interactor.h"
#include "intellect.h"
#include "drawer.h"

class room
{
private:
	std::string name;
	unsigned int current_checkpoint_id;
	level_mode_enum level_mode;

	map_class room_map;
	population room_population;

	intellect brain;
	interactor room_interactor;
	drawer room_drawer;

	void determ_checkpoint();

	bool restart();
public:
	//bool start(sf::RenderWindow&, std::string, room_portal&);
	bool start(sf::RenderWindow&, std::string, unsigned int);
	bool start_from_beginning(sf::RenderWindow&, std::string);
	void play();
	void pause();

	level_mode_enum get_level_mode();

	bool update(float);
};



#endif