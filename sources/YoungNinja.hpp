#include "Ninja.hpp"


class YoungNinja: public Ninja
{
    public:
    YoungNinja(string n, Point loc, int hits=100, int speed=14):Ninja(n,loc,hits,speed){}
};
