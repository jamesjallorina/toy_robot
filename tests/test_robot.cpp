#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../source/Robot.hh"

// Anything with a valid parameters is accepted by the Robot place api
// It doesn't detect out of bounds x and y coordinates
// The Table class handles that for us

/// @brief test report api
TEST_CASE("test report", "[Robot]")
{
    Coordinates coordinate = {1, 2, Face::North};
    Robot robot;
    robot.place(coordinate);
    // we move 1 step above y coordinate, should be 1, 3, North
    robot.move();
    // we rotate right, should be 1, 3, East
    robot.rotate(Rotate::Right);
    {
        // report only does standard output based on current coordinate
        // but it returns the current state, so we can still verify
        const auto current_coordinates = robot.report();
        CHECK(current_coordinates.x_pos == 1);
        CHECK(current_coordinates.y_pos == 3);
        CHECK(current_coordinates.f_pos == Face::East);
    }
}

/// @brief  test get_state api
TEST_CASE("test get_state", "[Robot]")
{
    Coordinates coordinate = {2, 3, Face::South};
    Robot robot;
    robot.place(coordinate);
    // we move 2 steps below y coordinate, should be 2, 1, South
    robot.move();
    robot.move();
    // we rotate left, should be 2, 1, East
    robot.rotate(Rotate::Left);
    {
        // get the current state
        const auto current_coordinates = robot.get_state();
        CHECK(current_coordinates.x_pos == 2);
        CHECK(current_coordinates.y_pos == 1);
        CHECK(current_coordinates.f_pos == Face::East);
    }
}

/// @brief test save_state api
TEST_CASE("test save_state", "[Robot]")
{
    Coordinates coordinate = {3, 4, Face::North};
    Robot robot;
    robot.place(coordinate);
    // we rotate left, should be 3, 4, West
    robot.rotate(Rotate::Left);
    // we move 2 steps left x coordinate, should be 1, 4, West
    robot.move();
    robot.move();
    {
        // save the current state
        const auto current_coordinates = robot.save_state();
        CHECK(current_coordinates.x_pos == 1);
        CHECK(current_coordinates.y_pos == 4);
        CHECK(current_coordinates.f_pos == Face::West);
    }
}

/// @brief test reset_state api
TEST_CASE("test reset_state", "[Robot]")
{
    Coordinates coordinate = {4, 0, Face::North};
    Robot robot;
    robot.place(coordinate);
    // we move 3 steps above y coordinate, should be 4, 3, North 
    robot.move();
    robot.move();
    robot.move();
    // we rotate right, should be 4, 3, East
    robot.rotate(Rotate::Right);
    {
        // test reset_state, should be 4, 3, North
        const auto current_coordinates = robot.reset_state();
        CHECK(current_coordinates.x_pos == 4);
        CHECK(current_coordinates.y_pos == 3);
        CHECK(current_coordinates.f_pos == Face::North);
    }
}

/// @brief simple random movement
TEST_CASE("simple random movement","[Robot]")
{
    Coordinates coordinate = {0,0, Face::East};   
    Robot robot;
    robot.place(coordinate);
    {
        const auto current_coordinates = robot.get_state();
        CHECK(current_coordinates.x_pos == 0);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::East);
    }

    robot.move();
    robot.move();
    {
        const auto current_coordinates = robot.get_state();
        CHECK(current_coordinates.x_pos == 2);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::East);
    }

    robot.rotate(Rotate::Left);
    {
        const auto current_coordinates = robot.get_state();
        CHECK(current_coordinates.x_pos == 2);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::North);
    }
}

/// @brief Robot moves from North -> East -> South -> West
TEST_CASE("square movement", "[Robot]")
{
    Coordinates coordinate = {0, 0, Face::North};
    Robot robot;
    // move 4 steps to north, coordinate should 0, 4, North
    robot.place(coordinate);
    robot.move();
    robot.move();
    robot.move();
    robot.move();
    {
        const auto current_coordinates = robot.get_state();
        CHECK(current_coordinates.x_pos == 0);
        CHECK(current_coordinates.y_pos == 4);
        CHECK(current_coordinates.f_pos == Face::North);
    }
    // rotate right, cooridinate should be 0, 4, East
    robot.rotate(Rotate::Right);
    {
        const auto current_coordinates = robot.get_state();
        CHECK(current_coordinates.x_pos == 0);
        CHECK(current_coordinates.y_pos == 4);
        CHECK(current_coordinates.f_pos == Face::East);
    }
    // move 4 steps to east, cooridate should be 4, 4, East
    robot.move();
    robot.move();
    robot.move();
    robot.move();
    {
        const auto current_coordinates = robot.get_state();
        CHECK(current_coordinates.x_pos == 4);
        CHECK(current_coordinates.y_pos == 4);
        CHECK(current_coordinates.f_pos == Face::East);
    }
    // rotate right, coordinate should be 4, 4, South
    robot.rotate(Rotate::Right);
    {
        const auto current_coordinates = robot.get_state();
        CHECK(current_coordinates.x_pos == 4);
        CHECK(current_coordinates.y_pos == 4);
        CHECK(current_coordinates.f_pos == Face::South);
    }
    // move 4 steps south, coordinate should be 4, 0, South
    robot.move();
    robot.move();
    robot.move();
    robot.move();
    {
        const auto current_coordinates = robot.get_state();
        CHECK(current_coordinates.x_pos == 4);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::South);
    }
    // rotate right, coordinate should be 4, 0, West
    robot.rotate(Rotate::Right);
    {
        const auto current_coordinates = robot.get_state();
        CHECK(current_coordinates.x_pos == 4);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::West);
    }
    // move 4 steps West, coordinate should be 0, 0, West
    robot.move();
    robot.move();
    robot.move();
    robot.move();
    {
        const auto current_coordinates = robot.get_state();
        CHECK(current_coordinates.x_pos == 0);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::West);
    }
    // rotate right, coordinate should be 0, 0, North
    robot.rotate(Rotate::Right);
    {
        const auto current_coordinates = robot.get_state();
        CHECK(current_coordinates.x_pos == 0);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::North);
    }
}

/// @brief Robot moves from East -> North -> West -> South
TEST_CASE("reverse square movement", "[Robot]")
{
    Coordinates coordinate = {0, 0, Face::East};
    Robot robot;
    // move 4 steps to north, coordinate should 4, 0, East
    robot.place(coordinate);
    robot.move();
    robot.move();
    robot.move();
    robot.move();
    {
        const auto current_coordinates = robot.get_state();
        CHECK(current_coordinates.x_pos == 4);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::East);
    }
    // rotate left, cooridinate should be 4, 0, North
    robot.rotate(Rotate::Left);
    {
        const auto current_coordinates = robot.get_state();
        CHECK(current_coordinates.x_pos == 4);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::North);
    }
    // move 4 steps to north, cooridate should be 4, 4, North
    robot.move();
    robot.move();
    robot.move();
    robot.move();
    {
        const auto current_coordinates = robot.get_state();
        CHECK(current_coordinates.x_pos == 4);
        CHECK(current_coordinates.y_pos == 4);
        CHECK(current_coordinates.f_pos == Face::North);
    }
    // rotate left, coordinate should be 4, 4, East
    robot.rotate(Rotate::Left);
    {
        const auto current_coordinates = robot.get_state();
        CHECK(current_coordinates.x_pos == 4);
        CHECK(current_coordinates.y_pos == 4);
        CHECK(current_coordinates.f_pos == Face::West);
    }
    // move 4 steps East, coordinate should be 0, 4, East
    robot.move();
    robot.move();
    robot.move();
    robot.move();
    {
        const auto current_coordinates = robot.get_state();
        CHECK(current_coordinates.x_pos == 0);
        CHECK(current_coordinates.y_pos == 4);
        CHECK(current_coordinates.f_pos == Face::West);
    }
    // rotate left, coordinate should be 4, 0, South
    robot.rotate(Rotate::Left);
    {
        const auto current_coordinates = robot.get_state();
        CHECK(current_coordinates.x_pos == 0);
        CHECK(current_coordinates.y_pos == 4);
        CHECK(current_coordinates.f_pos == Face::South);
    }
    // move 4 steps South, coordinate should be 0, 0, South
    robot.move();
    robot.move();
    robot.move();
    robot.move();
    {
        const auto current_coordinates = robot.get_state();
        CHECK(current_coordinates.x_pos == 0);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::South);
    }
    // get back to original face position
    // rotate Left, coordinate should be 0, 0, East
    robot.rotate(Rotate::Left);
    {
        const auto current_coordinates = robot.get_state();
        CHECK(current_coordinates.x_pos == 0);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::East);
    }
    // rotate Left, coordinate should be 0, 0, North
    robot.rotate(Rotate::Left);
    {
        const auto current_coordinates = robot.get_state();
        CHECK(current_coordinates.x_pos == 0);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::North);
    }
}
