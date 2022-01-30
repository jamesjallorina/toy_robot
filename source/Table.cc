#include "Table.hh"
#include <iostream>

bool Table::fall_detection(Robot &curr_robot)
{
    const int leftmost_x_dim = 0;
    const int rightmost_x_dim = m_dim_x -1;
    const int downmost_y_dim = 0;
    const int upmost_y_dim = m_dim_y - 1;

    auto is_detected = false;
    const auto curr_state = curr_robot.get_state();
    if(curr_state.x_pos > rightmost_x_dim || curr_state.x_pos < leftmost_x_dim){
        curr_robot.reset_state();
        is_detected = true;
        std::cout << "fall detected in x_coordinate reset to previous state" << std::endl;
    }
    if(curr_state.y_pos > upmost_y_dim || curr_state.y_pos < downmost_y_dim){
        curr_robot.reset_state();
        is_detected = true;
        std::cout << "fall detected in y_coordinate reset to previous state" << std::endl;
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
