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
        const auto current_coordinates = r.report();
        CHECK(current_coordinates.x_pos == 0);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::East);
    }

    r.move();
    r.move();
    {
        const auto current_coordinates = r.report();
        CHECK(current_coordinates.x_pos == 2);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::East);
    }

    r.rotate(Rotate::Left);
    {
        const auto current_coordinates = r.report();
        CHECK(current_coordinates.x_pos == 2);
        CHECK(current_coordinates.y_pos == 0);
        CHECK(current_coordinates.f_pos == Face::North);
    }
}

/// @brief Robot moves from North -> East -> South -> West
TEST_CASE("square movement", "[Robot]")
{
    Coordinates c = {0, 0, Face::East};
    Robot r;
}

/// @brief Robot moves from East -> North -> West -> South
TEST_CASE("rever square movement", "[Robot]")
{

}
