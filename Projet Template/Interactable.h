#ifndef INTERACTABLE_H
#define INTERACTABLE_H

#include <memory>  // Nécessaire pour shared_ptr

class Player;  // Déclaration avancée

class Interactable
{
public:
    virtual void interact(shared_ptr<Player>& player) = 0;
};

#endif // INTERACTABLE_H