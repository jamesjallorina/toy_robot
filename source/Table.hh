#ifndef TABLE_HH
#define TABLE_HH

#include "Robot.hh"
#include <vector>
#include <cstdint>

// currently supports only 1 robot as stated in the requirements
constexpr uint8_t unique_robot_index = 0;

// default values for x and y table dimensions
constexpr int default_x_dim = 5;
constexpr int default_y_dim = 5;
constexpr size_t default_robot_size = 1;

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

    int get_x_dim() const { return m_dim_x; }
    int get_y_dim() const { return m_dim_y; }
    size_t get_robot_size() const { return robots.size(); }
    Coordinates get_robot_coordinate(const uint8_t robot_id = unique_robot_index) const
    {
        return robots[robot_id].get_state();
    }

private:
    int m_dim_x = default_x_dim;
    int m_dim_y = default_y_dim;
    std::vector<Robot> robots{default_robot_size};
};

#endif  // TABLE_HH
