#include "GameLoop.hh"
#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
#include <cctype>

constexpr uint8_t command_index = 0;
constexpr uint8_t x_pos_index = 1;
constexpr uint8_t y_pos_index = 2;
constexpr uint8_t f_pos_index = 3;

static void serialize_place(UserInput & user_input,
        std::vector<std::string> const &param)
{
    if(param[command_index] == "PLACE"){
        user_input.command = Command::Place;
        user_input.new_coordinate.x_pos = std::stoi(param[x_pos_index]);
        user_input.new_coordinate.y_pos = std::stoi(param[y_pos_index]);
        user_input.new_coordinate.f_pos = string_to_face(param[f_pos_index]);
#if defined(DEBUG_ENABLE)
        command_info(user_input);
#endif
    }
    return;
}

static void serialize_move(UserInput & user_input,
        std::vector<std::string> const &param)
{
    if(param[command_index] == "MOVE"){
        user_input.command = Command::Move;
    }
    return;
}

static void serialize_rotate(UserInput & user_input,
        std::vector<std::string> const &param)
{
    if(param[command_index] == "LEFT"){
            user_input.command = Command::Rotate;
            user_input.rotate = Rotate::Left;
    }else if(param[command_index] == "RIGHT"){
            user_input.command = Command::Rotate;
            user_input.rotate = Rotate::Right;
    }
    return;
}

static void serialize_report(UserInput & user_input,
        std::vector<std::string> const &param)
{
    if(param[command_index] == "REPORT"){
        user_input.command = Command::Report;
    }
    return;
}

static UserInput serialize(std::vector<std::string> const &param)
{
    UserInput user_input;
    serialize_place(user_input, param);
    serialize_move(user_input, param);
    serialize_rotate(user_input, param);
    serialize_report(user_input, param);
    return user_input;
};

static UserInput parse_command(std::string const &input)
{
    std::vector<std::string> param;
    const std::regex wsc(R"([\s|,]+)");
    std::copy( std::sregex_token_iterator(input.begin(), input.end(), wsc, -1),
        std::sregex_token_iterator(), std::back_inserter(param));

#if defined(DEBUG_ENABLE)
    for(const auto &val : param){
        std::cout << "string value: " << val << std::endl;
        std::cout << "string length: " << val.size() << std::endl;
    }
#endif
    return serialize(param);
}

UserInput GameLoop::input()
{
    std::string input = "";
    /// get user from standard input command
    std::getline(std::cin, input);
    std::cout << "command_str: " << input << std::endl;
    return parse_command(input);
}

int GameLoop::start()
{
    while(true)
    {
        // proccess input
        auto end_of_command = false;
        auto user_input = input();

        if(user_input.command == Command::Place){
            m_table->process_command(user_input);
            while(!end_of_command)
            {
                auto user_input = input();
                m_table->process_command(user_input);
                end_of_command = (user_input.command == Command::Report) ? true : false;
            }   // while(!end_of_command)
        }else{
            std::cout << "first command should be PLACE" << std::endl;
        }
    }   // while(true)
    return 0;
}