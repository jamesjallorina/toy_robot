#ifndef GAMELOOP_HH
#define GAMELOOP_HH

#include "Table.hh"
#include "common.hh"

#include <memory>

class GameLoop
{
public:
    explicit GameLoop(std::unique_ptr<Table> table) : 
        m_table(std::move(table)) {}

    ~GameLoop() = default;

    UserInput input();

    int start();

private:
    // only 1 table is allowed ofcourse
    std::unique_ptr<Table> m_table;
};

#endif  // GAMELOOP_HH
