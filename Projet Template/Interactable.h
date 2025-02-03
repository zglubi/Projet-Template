#ifndef INTERACTABLE_H
#define INTERACTABLE_H

#include <memory>  // N�cessaire pour std::shared_ptr

class Player;  // D�claration avanc�e

class Interactable
{
public:
    virtual void interact(std::shared_ptr<Player>& player) = 0;
};

#endif // INTERACTABLE_H