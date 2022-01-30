#include "common.hh"
#include <iostream>
#include <string_view>

constexpr char north[] = "NORTH";
constexpr char south[] = "SOUTH";
constexpr char west[] = "WEST";
constexpr char east[] = "EAST";

Face string_to_face(std::string const &face)
{
    Face to_face;
    if(face == "NORTH"){
        to_face = Face::North;
    }else if(face == "SOUTH"){
        to_face = Face::South;
    }else if(face == "WEST"){
        to_face = Face::West;
    }else if(face == "EAST"){
        to_face = Face::East;
    }else{
        std::cout << __PRETTY_FUNCTION__ << " invalid argument" << std::endl;
    }
    return to_face;
}

std::string face_to_string(const Face face)
{
    std::string to_str = "";
    switch(face){
        case Face::North:
            to_str = "NORTH";
            break;
        case Face::South:
            to_str = "SOUTH";
            break;
        case Face::West:
            to_str = "WEST";
            break;
        case Face::East:
            to_str = "EAST";
            break;
        default:
            std::cout << __PRETTY_FUNCTION__ << " invalid face_to_string" << std::endl;
            break;
    }
    return to_str;
}

std::string rotate_to_string(const Rotate r)
{
    std::string to_str = "";
    switch(r)
    {
        case Rotate::Right:
            to_str = "RIGHT";
            break;
        case Rotate::Left:
            to_str = "LEFT";
            break;
        default:
            std::cout << __PRETTY_FUNCTION__ << " invalid rotate_to_string" << std::endl;
    }
    return to_str;
}

std::string command_to_string(const Command c)
{
    std::string to_str = "";
    switch(c)
    {
        case Command::Place:
            to_str = "PLACE";
            break;
        case Command::Move:
            to_str = "MOVE";
            break;
        case Command::Rotate:
            to_str = "ROTATE";
            break;
        case Command::Report:
            to_str = "REPORT";
            break;
        default:
            to_str = "UNKNOWN";
            break;
    }
    return to_str;
}

void command_info(UserInput const &ui)
{
    std::cout << "command info details" << std::endl;
    std::cout << "ui.command: " << command_to_string(ui.command) << std::endl;
    std::cout << "ui.new_coordinate.x_pos: " 
        << ui.new_coordinate.x_pos << std::endl;
    std::cout << "ui.new_coordinate.y_pos: "
        << ui.new_coordinate.y_pos << std::endl;
    std::cout << "ui.new_coordinate.f_pos: " 
        << face_to_string(ui.new_coordinate.f_pos) << std::endl;
    std::cout << "ui.rotate: " 
        << rotate_to_string(ui.rotate) << std::endl;
}