#pragma once
#include <iostream>
#include <string>

#include "Point.hpp"

using namespace std;


class Character
{
    Point location;
    int hit_points;
    string name;
    bool captain;
    bool assigned;

    public:

    Character(string n, Point l, int hpoint)
    {
        location = l;
        hit_points = hpoint;
        name = n;
        captain=false;
        assigned = false;
    }

    void setLocation(Point p)
    {
        location = p;
    }
    Point getLocation()
    {
        return location;
    }

    void makeCaptain(){captain = true;}
    bool isCaptain(){return captain;}

    string getName()
    {
        return name;
    }

    bool isAlive()
    {
        return hit_points > 0;
    }

    bool isAssigned(){return assigned;}
    void assignTeam(){assigned=true;}

    double distance(Character* c)
    {
        Point p1 = c->getLocation();
        
        return location.distance(p1);
    }

    void hit(int h)
    {
        if(h <0)
        {
            throw std::invalid_argument("can't be negative");
        }
        
        if(hit_points - h >= 0 )
        {
            hit_points -= h;
        }
        else    
        {
            hit_points=0;
        }
    }

    int getHits(){return hit_points;}

    virtual void fire(Character* c)=0;

    virtual string print()
    {
        string str="";
        if(hit_points > 0) // if the character is alive
        {
            str=  name + " " + to_string(hit_points) +  location.print();
        
        }
        else
        {
            str=  "(" + name + ")";
        }
        return str;

    }

    virtual ~Character()
    {
        
    }
};



