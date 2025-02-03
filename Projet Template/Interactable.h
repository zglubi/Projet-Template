#ifndef INTERACTABLE_H
#define INTERACTABLE_H

#include <memory>  // Nécessaire pour std::shared_ptr

class Player;  // Déclaration avancée

class Interactable
{
public:
    virtual void interact(std::shared_ptr<Player>& player) = 0;
};

#endif // INTERACTABLE_H