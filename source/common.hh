#ifndef COMMON_HH
#define COMMON_HH

#include <string>

enum class Face
{
    North,
    South,
    East,
    West,
};

enum class Rotate
{
    Left,
    Right,
    unknown
};

struct Coordinates
{
    int x_pos = 0;
    int y_pos = 0;
    Face f_pos = Face::North;
};

enum class Command
{
    Place,
    Move,
    Rotate,
    Report,
    unknown
};

struct UserInput
{
    Command command = Command::unknown;
    Coordinates new_coordinate;
    Rotate rotate = Rotate::unknown;
};


extern Face string_to_face(std::string const &face);
extern std::string face_to_string(const Face face);
extern void command_info(UserInput const &ui);

#endif  // COMMON_HH
