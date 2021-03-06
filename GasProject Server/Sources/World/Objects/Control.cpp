#include "Control.hpp"

#include <IGame.h>
#include <World/World.hpp>
#include <World/Map.hpp>
#include <World/Objects/Creature.hpp>

#include <Shared/Math.hpp>

#include "Object.hpp"

Control::Control(float speed) : 
	speed(speed), 
    player(nullptr), 
    clickedObjectID(0)
{

}

void Control::Update(sf::Time timeElapsed) {
    ////
    //// Movement
    ////
	uf::vec2i order = moveOrder;
	int zOrder = moveZOrder;
    moveOrder = {};
    moveZOrder = 0;

	if (auto *creature = dynamic_cast<Creature *>(owner)) {
		creature->Move(order);
		creature->MoveZ(zOrder);
	}

    ////
    //// Click
    ////
    if (clickedObjectID) {
        Object *clickedObject = GGame->GetWorld()->GetObject(clickedObjectID);

        if (auto *creature = dynamic_cast<Creature *>(owner))
            creature->TryInteractWith(clickedObject);

        clickedObjectID = 0;
    }
}

void Control::MoveCommand(uf::vec2i order) {
	moveOrder = order;
}

void Control::MoveZCommand(bool order) {
	moveZOrder = order?1:-1;
}

void Control::ClickObjectCommand(uint id) {
    clickedObjectID = id;
}

void Control::SetOwner(Object *owner) {
    Component::SetOwner(owner);
    if (this->owner) {
        this->owner->SetMoveSpeed(speed);
    }
}

float Control::GetSpeed() const { return speed; }
Player *Control::GetPlayer() const { return player; }