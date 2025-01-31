#ifndef INTERACTABLE_H
#define INTERACTABLE_H
#include "Player.h"

class Interactable
{
public:
	virtual void interact(shared_ptr<Player>& player) = 0;
};

#endif // INTERACTABLE_H