#include "room.h"

using namespace std;

std::map <unsigned int, dirt*> population::put_all_dirts_map()
{
	map <unsigned int, dirt*> res;
	res.clear();
	res[0] = &spark;
	return res;
}
std::map <unsigned int, drop*> population::put_all_drops_map()
{
	map <unsigned int, drop*> res;
	res.clear();

	for (auto it_drop = map_waterfears.begin(); it_drop != map_waterfears.end(); it_drop++)
		res[it_drop->first] = &(it_drop->second);
	return res;
}

void room::determ_checkpoint()
{
	unsigned int res = current_checkpoint_id;
	std::pair <std::pair<float, float>, std::pair<float, float>> rect1;
	std::pair <std::pair<float, float>, std::pair<float, float>> rect2;
	for (auto checkpt_it = room_map.get_map_checkpoints().begin(); checkpt_it != room_map.get_map_checkpoints().end(); checkpt_it++)
	{
		rect1 = { {room_population.spark.get_x(),room_population.spark.get_y()}, {room_population.spark.get_x() + room_population.spark.get_width(), room_population.spark.get_y() + room_population.spark.get_height()} };
		rect2 = { {checkpt_it->second.get_x(),checkpt_it->second.get_y()}, {checkpt_it->second.get_x() + checkpt_it->second.get_width(), checkpt_it->second.get_y() + checkpt_it->second.get_height()} };
		if (does_rectangles_intersects(rect1, rect2))
				if (checkpt_it->first > res)
					res = checkpt_it->first;
	}
	current_checkpoint_id = res;
}

bool room::restart()
{
	if (!room_population.spark.init("entities/spark.tsv", room_map.get_map_checkpoints()[current_checkpoint_id].get_x() + room_map.get_map_checkpoints()[current_checkpoint_id].get_width() / 2.0, room_map.get_map_checkpoints()[current_checkpoint_id].get_y() + room_map.get_map_checkpoints()[current_checkpoint_id].get_height() / 2.0, 0))
		return false;
	return true;
}
bool room::start(sf::RenderWindow& window, string NAME, unsigned int ID_CHCKPT)
{
	room_population.map_waterfears.clear();

	name = NAME;
	if (!room_map.load_from_file("levels/" + name + ".tmx"))
		return false;
	current_checkpoint_id = ID_CHCKPT;
	if (!room_population.spark.init("entities/spark.tsv", room_map.get_map_checkpoints()[ID_CHCKPT].get_x() + room_map.get_map_checkpoints()[ID_CHCKPT].get_width() / 2.0, room_map.get_map_checkpoints()[ID_CHCKPT].get_y() + room_map.get_map_checkpoints()[ID_CHCKPT].get_height() / 2.0, 0))
		return false;
	for (auto it_born = room_map.get_map_born().begin(); it_born != room_map.get_map_born().end(); it_born++)
	{
		bool ok = false;
		if (it_born->second.first == "waterfear")
		{
			ok = true;
			if (!room_population.map_waterfears[it_born->first].init("entities/waterfear.tsv", it_born->second.second.first, it_born->second.second.second, it_born->first))
				return false;
		}
		if (!ok)
			return false;
	}
	if (!room_drawer.init(window, room_map))
		return false;
	current_checkpoint_id = ID_CHCKPT;
	level_mode = level_mode_enum::play;
	return true;
}
bool room::start_from_beginning(sf::RenderWindow& window, string NAME)
{
	name = NAME;
	if (!room_map.load_from_file("levels/" + name + ".tmx"))
		return false;
	if (!room_population.spark.init("entities/spark.tsv", room_map.get_map_checkpoints()[room_map.get_player_start_id()].get_x() + room_map.get_map_checkpoints()[room_map.get_player_start_id()].get_width() / 2.0, room_map.get_map_checkpoints()[room_map.get_player_start_id()].get_y() + room_map.get_map_checkpoints()[room_map.get_player_start_id()].get_height() / 2.0, 0))
		return false;
	for (auto it_born = room_map.get_map_born().begin(); it_born != room_map.get_map_born().end(); it_born++)
	{
		bool ok = false;
		if (it_born->second.first == "waterfear")
		{
			ok = true;
			if (!room_population.map_waterfears[it_born->first].init("entities/waterfear.tsv", it_born->second.second.first, it_born->second.second.second, it_born->first))
				return false;
		}
		if (!ok)
			return false;
	}
	if (!room_drawer.init(window, room_map))
		return false;
	current_checkpoint_id = room_map.get_player_start_id();
	level_mode = level_mode_enum::play;
	return true;
}
void room::play()
{
	level_mode = level_mode_enum::play;
}
void room::pause()
{
	level_mode = level_mode_enum::pause;
}
level_mode_enum room::get_level_mode()
{
	return level_mode;
}
bool room::update(float time)
{
	if (level_mode == level_mode_enum::play)
	{
		if (room_population.spark.is_alive())
		{
			determ_checkpoint();
			if (!room_interactor.interact(room_map, room_population.put_all_dirts_map(), room_population.put_all_drops_map(), time))
				return false;
			brain.drive(room_map, room_population);
			if (!room_interactor.interact(room_map, room_population.put_all_dirts_map(), room_population.put_all_drops_map(), time))
				return false;
			if (!room_population.spark.update(time))
				return false;
			for (auto it_waterfear = room_population.map_waterfears.begin(); it_waterfear != room_population.map_waterfears.end(); it_waterfear++)
				if (!it_waterfear->second.update(time))
					return false;
			if (!room_drawer.show(room_map, room_population, level_mode_enum::play))
				return false;
		}
		else
		{
			restart();
		}
	}
	else
	{
		if (!room_drawer.show(room_map, room_population, level_mode_enum::pause))
			return false;
	}
	return true;
}