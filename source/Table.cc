#include "Table.hh"
#include <iostream>

bool Table::fall_detection(Robot &curr_robot)
{
    constexpr int leftmost_x_dim = 0;
    constexpr int downmost_y_dim = 0;
    auto is_detected = false;
    const auto curr_state = curr_robot.get_state();
    if(curr_state.x_pos > m_dim_x || curr_state.x_pos < leftmost_x_dim){
        curr_robot.reset_state();
        is_detected = true;
        //std::cout << "fall detected in x_coordinate" << std::endl;
    }
    if(curr_state.y_pos > m_dim_y || curr_state.y_pos < downmost_y_dim){
        curr_robot.reset_state();
        is_detected = true;
        //std::cout << "fall detected in y_coordinate" << std::endl;
    }
    return is_detected;
}

bool Table::process_command(UserInput const &input, const uint8_t robot_id)
{
    const auto command = input.command;
    bool end_of_command = false;
    auto & curr_robot = robots[robot_id];
    switch(command)
    {
        case Command::Place:
            curr_robot.place(input.new_coordinate);
            fall_detection(curr_robot);
            break;
        case Command::Move:
            curr_robot.move();
            fall_detection(curr_robot);
            break;
        case Command::Rotate:
            curr_robot.rotate(input.rotate);
            break;
        case Command::Report:
            curr_robot.report();
            end_of_command = true;
            break;
        default:
            std::cout << __PRETTY_FUNCTION__ 
                << " invalid command" << std::endl;
            break;
    }
    return end_of_command;
}
