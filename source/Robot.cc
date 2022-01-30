#include "Robot.hh"

#include <iostream>

/// implementation can be in namespace details
static Face rotate_left(const Face curr_f_pos);
static Face rotate_right(const Face curr_f_pos);

Coordinates Robot::place(Coordinates const & Place)
{
    std::cout << "place command" << std::endl;
    save_state();
    m_curr_state.x_pos += Place.x_pos;
    m_curr_state.y_pos += Place.y_pos;
    m_curr_state.f_pos = Place.f_pos;
    return m_curr_state;
}

Coordinates Robot::move()
{
    std::cout << "move command" << std::endl;
    save_state();
    switch(m_curr_state.f_pos){
        case Face::North:
            m_curr_state.y_pos++;
            break;
        case Face::South:
            m_curr_state.y_pos--;
            break;
        case Face::East:
           m_curr_state.x_pos++;
            break;
        case Face::West:
            m_curr_state.x_pos--;
            break;
        default:
            std::cout << "invalid move" << std::endl;
            break;
    }
    return m_curr_state;
}

Coordinates Robot::rotate(const Rotate rotate)
{
    std::cout << "rotate command" << std::endl;
    save_state();
    const auto curr_f_pos = m_curr_state.f_pos;
    if(rotate == Rotate::Left){
        m_curr_state.f_pos = rotate_left(curr_f_pos);
    }else{  // else Rotate::Right
        m_curr_state.f_pos = rotate_right(curr_f_pos);
    }
    return m_curr_state;
}

Coordinates Robot::report() const
{
    std::cout << "report command" << std::endl;
    std::cout << "Output: " 
        << m_curr_state.x_pos << ", " 
        << m_curr_state.y_pos << ", " 
        << face_to_string(m_curr_state.f_pos) 
        << std::endl;
    return m_curr_state;
}


static Face rotate_left(const Face curr_f_pos)
{
    Face rotate_res;
    switch(curr_f_pos){
        case Face::North:
            rotate_res = Face::West;
            break;
        case Face::South:
            rotate_res = Face::East;
            break;
        case Face::West:
            rotate_res = Face::South;
            break;
        case Face::East:
            rotate_res = Face::North;
            break;
        default:
            std::cout << "invalid rotate_left" << std::endl;
            break;
    }
    return rotate_res;
}

static Face rotate_right(const Face curr_f_pos)
{
    Face rotate_res;
    switch(curr_f_pos){
        case Face::North:
            rotate_res = Face::East;
            break;
        case Face::South:
            rotate_res = Face::West;
            break;
        case Face::West:
            rotate_res = Face::North;
            break;
        case Face::East:
            rotate_res = Face::South;
            break;
        default:
            std::cout << "invalid rotate_right" << std::endl;
            break;
    }
    return rotate_res;
}
