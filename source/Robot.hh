#ifndef ROBOT_HH
#define ROBOT_HH

#include "common.hh"

class Robot
{
public:
    /// Default constructor
    Robot() = default;
    ~Robot() = default;

    /// PLACE command
    Coordinates place(Coordinates const & place);

    /// MOVE command
    Coordinates move();

    /// LEFT or RIGHT command
    Coordinates rotate(const Rotate rotate);

    /// REPORT command
    Coordinates report() const;

    /// get current state
    Coordinates get_state() const
    {
        return m_curr_state;
    }

    // save current state to prev state
    Coordinates save_state()
    {
        m_prev_state = m_curr_state;
        return m_prev_state;
    }

    // reset from previous state
    Coordinates reset_state()
    {
        m_curr_state = m_prev_state;
        return m_curr_state;
    }

private:
    Coordinates m_curr_state;
    Coordinates m_prev_state;
};

#endif  // ROBOT_HH
