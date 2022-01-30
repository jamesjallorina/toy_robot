#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../source/Robot.hh"

/// @brief simple random movement
TEST_CASE("simple random movement","[Robot]")
{
    Coordinates c = {0,0, Face::East};   
    Robot r;
    r.place(c);
    {
        const auto current_coordinates = r.get_state();
        CHECK(current_coordinates.x_pos == 0);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::East);
    }

    r.move();
    r.move();
    {
        const auto current_coordinates = r.get_state();
        CHECK(current_coordinates.x_pos == 2);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::East);
    }

    r.rotate(Rotate::Left);
    {
        const auto current_coordinates = r.get_state();
        CHECK(current_coordinates.x_pos == 2);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::North);
    }
}

/// @brief Robot moves from North -> East -> South -> West
TEST_CASE("square movement", "[Robot]")
{
    Coordinates c = {0, 0, Face::North};
    Robot r;
    // move 4 steps to north, coordinate should 0, 4, North
    r.place(c);
    r.move();
    r.move();
    r.move();
    r.move();
    {
        const auto current_coordinates = r.get_state();
        CHECK(current_coordinates.x_pos == 0);
        CHECK(current_coordinates.y_pos == 4);
        CHECK(current_coordinates.f_pos == Face::North);
    }
    // rotate right, cooridinate should be 0, 4, East
    r.rotate(Rotate::Right);
    {
        const auto current_coordinates = r.get_state();
        CHECK(current_coordinates.x_pos == 0);
        CHECK(current_coordinates.y_pos == 4);
        CHECK(current_coordinates.f_pos == Face::East);
    }
    // move 4 steps to east, cooridate should be 4, 4, East
    r.move();
    r.move();
    r.move();
    r.move();
    {
        const auto current_coordinates = r.get_state();
        CHECK(current_coordinates.x_pos == 4);
        CHECK(current_coordinates.y_pos == 4);
        CHECK(current_coordinates.f_pos == Face::East);
    }
    // rotate right, coordinate should be 4, 4, South
    r.rotate(Rotate::Right);
    {
        const auto current_coordinates = r.get_state();
        CHECK(current_coordinates.x_pos == 4);
        CHECK(current_coordinates.y_pos == 4);
        CHECK(current_coordinates.f_pos == Face::South);
    }
    // move 4 steps south, coordinate should be 4, 0, South
    r.move();
    r.move();
    r.move();
    r.move();
    {
        const auto current_coordinates = r.get_state();
        CHECK(current_coordinates.x_pos == 4);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::South);
    }
    // rotate right, coordinate should be 4, 0, West
    r.rotate(Rotate::Right);
    {
        const auto current_coordinates = r.get_state();
        CHECK(current_coordinates.x_pos == 4);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::West);
    }
    // move 4 steps West, coordinate should be 0, 0, West
    r.move();
    r.move();
    r.move();
    r.move();
    {
        const auto current_coordinates = r.get_state();
        CHECK(current_coordinates.x_pos == 0);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::West);
    }
    // rotate right, coordinate should be 0, 0, North
    r.rotate(Rotate::Right);
    {
        const auto current_coordinates = r.get_state();
        CHECK(current_coordinates.x_pos == 0);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::North);
    }
}

/// @brief Robot moves from East -> North -> West -> South
TEST_CASE("reverse square movement", "[Robot]")
{
    Coordinates c = {0, 0, Face::East};
    Robot r;
    // move 4 steps to north, coordinate should 4, 0, East
    r.place(c);
    r.move();
    r.move();
    r.move();
    r.move();
    {
        const auto current_coordinates = r.get_state();
        CHECK(current_coordinates.x_pos == 4);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::East);
    }
    // rotate left, cooridinate should be 4, 0, North
    r.rotate(Rotate::Left);
    {
        const auto current_coordinates = r.get_state();
        CHECK(current_coordinates.x_pos == 4);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::North);
    }
    // move 4 steps to north, cooridate should be 4, 4, North
    r.move();
    r.move();
    r.move();
    r.move();
    {
        const auto current_coordinates = r.get_state();
        CHECK(current_coordinates.x_pos == 4);
        CHECK(current_coordinates.y_pos == 4);
        CHECK(current_coordinates.f_pos == Face::North);
    }
    // rotate left, coordinate should be 4, 4, East
    r.rotate(Rotate::Left);
    {
        const auto current_coordinates = r.get_state();
        CHECK(current_coordinates.x_pos == 4);
        CHECK(current_coordinates.y_pos == 4);
        CHECK(current_coordinates.f_pos == Face::West);
    }
    // move 4 steps East, coordinate should be 0, 4, East
    r.move();
    r.move();
    r.move();
    r.move();
    {
        const auto current_coordinates = r.get_state();
        CHECK(current_coordinates.x_pos == 0);
        CHECK(current_coordinates.y_pos == 4);
        CHECK(current_coordinates.f_pos == Face::West);
    }
    // rotate left, coordinate should be 4, 0, South
    r.rotate(Rotate::Left);
    {
        const auto current_coordinates = r.get_state();
        CHECK(current_coordinates.x_pos == 0);
        CHECK(current_coordinates.y_pos == 4);
        CHECK(current_coordinates.f_pos == Face::South);
    }
    // move 4 steps South, coordinate should be 0, 0, South
    r.move();
    r.move();
    r.move();
    r.move();
    {
        const auto current_coordinates = r.get_state();
        CHECK(current_coordinates.x_pos == 0);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::South);
    }
    // get back to original face position
    // rotate Left, coordinate should be 0, 0, East
    r.rotate(Rotate::Left);
    {
        const auto current_coordinates = r.get_state();
        CHECK(current_coordinates.x_pos == 0);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::East);
    }
    // rotate Left, coordinate should be 0, 0, North
    r.rotate(Rotate::Left);
    {
        const auto current_coordinates = r.get_state();
        CHECK(current_coordinates.x_pos == 0);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::North);
    }
}
