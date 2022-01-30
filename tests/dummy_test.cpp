#include "../source/Robot.hh"
#include <iostream>
#include <cassert>
#include <string>

std::ostream & operator<<(std::ostream &os, const Face f)
{
    std::string to_str = "";
    switch(f){
        case Face::North:
            to_str = "North";
            break;
        case Face::South:
            to_str = "South";
            break;
        case Face::West:
            to_str = "West";
            break;
        case Face::East:
            to_str = "East";
            break;
        default:
            break;
    }
    os << to_str;
    return os;
}

int main()
{
    Coordinates c = {0,0, Face::East};
    std::cout << "Coordinates initialized to: " << c.x_pos << ", " 
        << c.y_pos << ", " 
        << c.f_pos << std::endl;    
    Robot r;
    r.report();
    r.place(c);
    r.report();
    assert(r.report().x_pos == 0);
    assert(r.report().y_pos == 0);
    assert(r.report().f_pos == Face::East);

    r.move();
    r.report();
    r.move();
    r.report();
    assert(r.report().x_pos == 2);
    r.rotate(Rotate::Left);
    r.report();
    assert(r.report().f_pos == Face::North);
}