#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../source/Table.hh"
#include "../source/Robot.hh"

/// @brief test table api
TEST_CASE("test table api", "[Table]")
{
    {
        Table table;
        CHECK(table.get_robot_size() == 1);
        CHECK(table.get_x_dim() == 5);
        CHECK(table.get_y_dim() == 5);
    }

    {
        // prepare table
        Table table(8, 8, 1);
        // prepare initial coordinate
        Coordinates coordinate{3, 4, Face::North};
        // create robot object
        Robot robot;
        // pass the initial coordinate to robot object
        robot.place(coordinate);
        // we move 4 steps above
        robot.move();
        robot.move();
        robot.move();
        robot.move();
        CHECK(table.fall_detection(robot) == true);
    }

    {
        Table table;
        UserInput place_command = {Command::Place, {2,3, Face::East}, Rotate::unknown};

        /// There's no need to pass robot index id since there's only 1 unique robot id by default
        CHECK(table.process_command(place_command) == false);
        auto curr_robot_coordinate = table.get_robot_coordinate();
        CHECK(curr_robot_coordinate.x_pos == 2);
        CHECK(curr_robot_coordinate.y_pos == 3);
        CHECK(curr_robot_coordinate.f_pos == Face::East);

        UserInput report_command = {Command::Report, {}, {}};

        CHECK(table.process_command(report_command) == true);
        curr_robot_coordinate = table.get_robot_coordinate();
        CHECK(curr_robot_coordinate.x_pos == 2);
        CHECK(curr_robot_coordinate.y_pos == 3);
        CHECK(curr_robot_coordinate.f_pos == Face::East);
    }
}