#pragma once
#ifndef ET_def
#define ET_def

#include "map.h"
#include "map_content.h"

class mechanical_corrector
{
private:
	const float near_eps = 11;

	float time;
	std::vector <unsigned int> v_actual_static_bodies_id;

	bool old_does_static_body_interfere_body_entity(static_body*, body*);
	bool old_can_go_x(map_class*, entity*);
	bool old_can_go_y(map_class*, entity*);
	bool old_can_go_xy(map_class*, entity*);
	void old_determ_position(map_class*, entity*);
	bool old_handle(map_class*, entity*);

	bool correct_position_and_set_distance(map_class*, entity*);
	void find_static_bodies_in_area(map_class*, float, float);
	void determ_position(map_class*, entity*);
	bool handle(map_class*, entity*);
public:
	bool correct_speed(map_class*, std::map<unsigned int, entity*>, float);
};

class dirt_interactor
{
	std::vector <unsigned int> v_actual_dirt_damages_id;
	std::vector <unsigned int> v_actual_dirt_replenishes_id;
	std::vector <unsigned int> v_actual_dirt_unsticks_id;

	void find_body_circumstances_in_area(map_class*, float, float);
	bool does_circumstance_intersect_dirt(static_circumstance*, dirt*);

	void interact_with_circumstance(dirt_damage*, dirt*);
	void interact_with_circumstance(dirt_replenish*, dirt*);
	void interact_with_circumstance(dirt_unstick*, dirt*);

	void handle(map_class*, dirt*);
public:
	void provide_interaction(map_class*, std::map<unsigned int, dirt*>);
};

class interactor
{
private:
	mechanical_corrector mechanical_part;
	dirt_interactor dirt_interactor_part;
public:
	bool interact(map_class&, std::map <unsigned int, dirt*>, std::map <unsigned int, drop*>, float);
};
/*
class physics_world_class
{
private:
	std::map <unsigned int, body> map_bodies;

	float time;
	std::vector <unsigned int> v_actual_body_walls_id;

	void find_bodies_in_area(float, float);
	bool does_bodies_conflict(body&, body&);
	bool can_go_x(body&);
	bool can_go_y(body&);

	bool correct_position(body&);
	void determ_position(body&);
	void exert_force(body&);
	bool interact_with_bodies(body&);
public:
	bool update(float);

	bool set_speed(unsigned int, float, float);
	bool set_speed(unsigned int, float, float);
	

	void add_new_body(body&);
	void delete_body_with_id(unsigned int);
};*/


#endif