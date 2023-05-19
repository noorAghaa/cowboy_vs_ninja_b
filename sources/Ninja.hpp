#pragma once
#include "Character.hpp"

class Ninja: public Character
{
    int speed;

    public:
    Ninja(string name, Point loc, int hpoint, int s): Character(name,loc,hpoint)
    {
        speed =s;
    }

    void move(Character* enemy)
    {
        // double d_p1_p2 = this->distance(enemy);
        // double a = this->getLocation().getX() + (speed / d_p1_p2) * (enemy->getLocation().getX() - this->getLocation().getX());
        // double b = this->getLocation().getY() + (speed / d_p1_p2) * (enemy->getLocation().getY() - this->getLocation().getY());
        Point p= Point::moveTowards(this->getLocation(),enemy->getLocation(), speed);
        this->setLocation(p);
    }

    void fire(Character* enemy)
    {
        this->slash(enemy);
    }

    virtual void slash(Character* enemy)
    {
        if(enemy == this)
        {
            throw std::runtime_error("No Self harm");
        }

        if(!enemy->isAlive() )
        {
            throw std::runtime_error("Can't shoot dead enemy");
        }

        if(!this->isAlive())
        {
            throw std::runtime_error("Dead can't shoot");
        }

        if(this->isAlive() && this->distance(enemy) <= 1)
        {
            enemy->hit(40);
        }
        else
        {
            this->move(enemy);
        }
    }

    string print()
    {
        return "N " + Character::print();
    }
};