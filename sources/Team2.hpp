#pragma once
#include <iostream>
#include "Character.hpp"
#include "Team.hpp"

using namespace std;

class Team2 : public Team
{

    public:
    Team2(Character* l):Team(l){    }


    int stillAlive()
    {
        return Team::stillAlive();
    }

    void add(Character* c)
    {
        Team::add(c);
    }

    void attack(Team* t)
    {
        Team::attack(t);
    }

    ~Team2()
    {
    }

};