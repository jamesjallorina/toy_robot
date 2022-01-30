#include "Table.hh"
#include "GameLoop.hh"

#include <iostream>
#include <vector>
#include <memory>
// command line parsing
#include <unistd.h>
#include <getopt.h>



int main(int argc, char **argv)
{
    int opt = 0;
    int table_w = 5;
    int table_h = 5;
    int num_robots = 1;

    while(true){
        opt = getopt(argc, argv, "w:h:n:");
        if(opt == -1){
            break;
        }
        switch(opt){
            case 'w':
                table_w = atoi(optarg);
                break;
            case 'h':   
                table_h = atoi(optarg);
                break;
            case 'n':
                // num_robots = atoi(optarg); // #uncomment to support multiple robots
                // based on requirements only 1 robot is stated
                // but the code can be extended to support multiple robots
                num_robots = 1;
                break;
            default:
                std::cout << "invalid arguments" << std::endl;
                exit(EXIT_FAILURE);
        }
    }

    std::cout << "table_w: " << table_w << std::endl;
    std::cout << "table_h: " << table_h << std::endl;
    std::cout << "num_robots: " << num_robots << std::endl;

    auto table = std::make_unique<Table>(table_w, table_h, num_robots);
    auto game_loop = std::make_unique<GameLoop>(std::move(table));
    game_loop->start();

    return 0;
}
