#include "Character.hpp"

class Cowboy : public Character
{
    char type='C';
    int nBullets;

    public:
    Cowboy(string n, Point l):Character(n, l, 110), nBullets(6){}

    int getNBullets()
    {
        return nBullets;
    }

    void fire(Character* enemey)
    {
        if(!hasboolets())
        {
            reload();
        }
        else
        {
            shoot(enemey);
        }
    }

    void shoot(Character* enemey)
    {
        if(enemey == this || !enemey->isAlive() || !this->isAlive())
        {
            throw std::runtime_error("No Self harm");
        }

        if(enemey->isAlive() && nBullets > 0)
        {
            enemey->hit(10);
            nBullets--;
        }
    }

    bool hasboolets()
    {
        return nBullets > 0;
    }

    void reload()
    {
        if(!isAlive())
        {
            throw std::runtime_error("Can't reload dead cowboy");
        }
        nBullets =6;
    }

    string print()
    {
        return "C " + Character::print();
    }

};