#pragma once

#include <vector>

#include <SFML/System/Time.hpp>

#include "Map.hpp"
#include "Objects.hpp"

using std::vector;

class World {
public:
    friend Object;

    World();

    void Update(sf::Time timeElapsed);

    void FillingWorld();
	template<typename T, typename... TArgs>
	Object *CreateObject(Tile *, TArgs&&... Args) const;
    Creature *CreateNewPlayerCreature() const;

    Object *GetObject(uint id);

private:
    uptr<Map> map;

    Creature *testMob;
    Tile *testMob_lastPosition;
    int test_dx;
    int test_dy;
    int mobsVelocity;

    std::vector<uptr<Object>> objects;
    std::vector<uint> free_ids;

    // Available only for Object()
    uint addObject(Object *);
};

template<typename T, typename... TArgs>
Object *World::CreateObject(Tile *tile, TArgs&&... Args) const {
	auto *obj = new T(std::forward<TArgs>(Args)...);

	if (tile)
		tile->PlaceTo(obj);

	obj->AfterCreation();
	return obj;
}

