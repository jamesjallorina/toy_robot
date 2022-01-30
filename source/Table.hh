#ifndef TABLE_HH
#define TABLE_HH

#include "Robot.hh"
#include <vector>
#include <cstdint>

// currently supports only 1 robot as stated in the requirements
constexpr uint8_t unique_robot_index = 0;

// The Table class is responsible for the following 
// 1. handle collision detection
// 2. prevent robots from falling
class Table
{
public:
    Table() = default;
    Table(const int width, const int height, const uint8_t no_of_robots) : 
        m_dim_x(width), m_dim_y(height), robots(no_of_robots) {}

    ~Table() = default; 

    // collission detection can be supported in the future
    // current requirements does not state completely if it supports multiple robots
    //bool collision_detection() {}
    bool fall_detection(Robot &curr_robot);
    bool process_command(UserInput const &input, 
            const uint8_t robot_id = unique_robot_index);

private:
    int m_dim_x;
    int m_dim_y;
    std::vector<Robot> robots;
};

#endif  // TABLE_HH
