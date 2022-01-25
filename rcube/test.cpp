#include "state.h"
#include <iostream>
#include <cassert>

int main()
{
    State s;
    State solved;

    assert(s==solved);

    s.step(State::UP0);
    assert(s!=solved);
    s.step(State::UP0);
    s.step(State::DOWN0);
    s.step(State::DOWN0);
    assert(s==solved);

    s.step(State::UP1);
    s.step(State::UP1);
    s.step(State::DOWN1);
    s.step(State::DOWN1);

    assert(s==solved);

    s.step(State::UP2);
    s.step(State::UP2);
    s.step(State::DOWN2);
    s.step(State::DOWN2);

    assert(s==solved);

    s.step(State::LEFT1);
    s.step(State::LEFT1);
    s.step(State::LEFT1);
    s.step(State::LEFT1);

    assert(s==solved);

    s.step(State::UP3);
    s.step(State::DOWN3);

    s.step(State::UP4);
    s.step(State::DOWN4);

    s.step(State::UP5);
    s.step(State::DOWN5);

    assert(s==solved);

    s.step(State::LEFT2);
    s.step(State::RIGHT2);

    assert(s==solved);

    s._state[State::YELLOW][2][0] = State::WHITE;
    s._state[State::YELLOW][2][2] = State::GREEN;

    s._state[State::BLUE][0][2] = State::RED;

    s._state[State::WHITE][0][0] = State::YELLOW;
    s._state[State::WHITE][0][1] = State::RED;
    s._state[State::WHITE][0][2] = State::YELLOW;
    s._state[State::WHITE][1][0] = State::ORANGE;
    s._state[State::WHITE][2][0] = State::ORANGE;

    s._state[State::GREEN][0][2] = State::RED;
    s._state[State::GREEN][1][0] = State::ORANGE;
    s._state[State::GREEN][1][2] = State::RED;
    s._state[State::GREEN][2][0] = State::RED;
    s._state[State::GREEN][2][1] = State::WHITE;
    s._state[State::GREEN][2][2] = State::ORANGE;

    s._state[State::RED][0][0] = State::WHITE;
    s._state[State::RED][1][0] = State::GREEN;
    s._state[State::RED][2][0] = State::GREEN;
    s._state[State::RED][2][1] = State::WHITE;
    s._state[State::RED][2][2] = State::ORANGE;

    s._state[State::ORANGE][0][2] = State::BLUE;
    s._state[State::ORANGE][1][2] = State::GREEN;
    s._state[State::ORANGE][2][0] = State::GREEN;
    s._state[State::ORANGE][2][0] = State::WHITE;
    s._state[State::ORANGE][2][1] = State::GREEN;
    s._state[State::ORANGE][2][2] = State::GREEN;

    int colors_count[6] = {0};
    for (int k = 0; k < 6; ++k) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int color = s._state[k][i][j];
                ++colors_count[color];
            }
        }
    }
    for (int k = 0; k < 6; ++k) {
        if (colors_count[k] != 9) {
            std::cout << k <<"="<< colors_count[k] << ": wrong color count" << std::endl;
            return 1;
        }
    }

    auto origin = s;

    s.step(State::UP0);
    s.step(State::DOWN0);
    assert(s == origin);
    s.step(State::LEFT0);
    s.step(State::RIGHT0);
    assert(s == origin);

    s.step(State::UP1);
    s.step(State::DOWN1);
    assert(s == origin);
    s.step(State::LEFT1);
    s.step(State::RIGHT1);
    assert(s == origin);

    s.step(State::UP2);
    s.step(State::DOWN2);
    assert(s == origin);
    s.step(State::LEFT2);
    s.step(State::RIGHT2);
    assert(s == origin);

    s.step(State::UP3);
    s.step(State::DOWN3);
    assert(s == origin);

    s.step(State::UP4);
    s.step(State::DOWN4);
    assert(s == origin);

    s.step(State::UP5);
    s.step(State::DOWN5);
    assert(s == origin);


    s.step(State::UP0);
    s.step(State::UP0);
    s.step(State::UP0);
    s.step(State::UP0);
    assert(s == origin);

    s.step(State::DOWN0);
    s.step(State::DOWN0);
    s.step(State::DOWN0);
    s.step(State::DOWN0);
    assert(s == origin);

    s.step(State::LEFT0);
    s.step(State::LEFT0);
    s.step(State::LEFT0);
    s.step(State::LEFT0);
    assert(s == origin);

    s.step(State::RIGHT0);
    s.step(State::RIGHT0);
    s.step(State::RIGHT0);
    s.step(State::RIGHT0);
    assert(s == origin);

    s.step(State::UP1);
    s.step(State::UP1);
    s.step(State::UP1);
    s.step(State::UP1);
    assert(s == origin);

    s.step(State::DOWN1);
    s.step(State::DOWN1);
    s.step(State::DOWN1);
    s.step(State::DOWN1);
    assert(s == origin);

    s.step(State::LEFT1);
    s.step(State::LEFT1);
    s.step(State::LEFT1);
    s.step(State::LEFT1);
    assert(s == origin);

    s.step(State::RIGHT1);
    s.step(State::RIGHT1);
    s.step(State::RIGHT1);
    s.step(State::RIGHT1);
    assert(s == origin);



    s.step(State::UP2);
    s.step(State::UP2);
    s.step(State::UP2);
    s.step(State::UP2);
    assert(s == origin);

    s.step(State::DOWN2);
    s.step(State::DOWN2);
    s.step(State::DOWN2);
    s.step(State::DOWN2);
    assert(s == origin);

    s.step(State::LEFT2);
    s.step(State::LEFT2);
    s.step(State::LEFT2);
    s.step(State::LEFT2);
    assert(s == origin);

    s.step(State::RIGHT2);
    s.step(State::RIGHT2);
    s.step(State::RIGHT2);
    s.step(State::RIGHT2);
    assert(s == origin);


    s.step(State::UP3);
    s.step(State::UP3);
    s.step(State::UP3);
    s.step(State::UP3);
    assert(s == origin);

    s.step(State::DOWN3);
    s.step(State::DOWN3);
    s.step(State::DOWN3);
    s.step(State::DOWN3);
    assert(s == origin);

    s.step(State::UP4);
    s.step(State::UP4);
    s.step(State::UP4);
    s.step(State::UP4);
    assert(s == origin);

    s.step(State::DOWN4);
    s.step(State::DOWN4);
    s.step(State::DOWN4);
    s.step(State::DOWN4);

    s.step(State::UP5);
    s.step(State::UP5);
    s.step(State::UP5);
    s.step(State::UP5);
    assert(s == origin);

    s.step(State::DOWN5);
    s.step(State::DOWN5);
    s.step(State::DOWN5);
    s.step(State::DOWN5);
    assert(s == origin);



    s.step(State::UP0);
    s.step(State::UP0);
    s.step(State::UP0);
    origin.step(State::DOWN0);
    assert(s == origin);

    s.step(State::UP0);
    origin.step(State::UP0);
    assert(s == origin);


    s.step(State::DOWN0);
    s.step(State::DOWN0);
    s.step(State::DOWN0);
    origin.step(State::UP0);
    assert(s == origin);

    s.step(State::DOWN0);
    origin.step(State::DOWN0);
    assert(s == origin);


    s.step(State::UP1);
    s.step(State::UP1);
    s.step(State::UP1);
    origin.step(State::DOWN1);
    assert(s == origin);

    s.step(State::UP1);
    origin.step(State::UP1);
    assert(s == origin);


    s.step(State::DOWN1);
    s.step(State::DOWN1);
    s.step(State::DOWN1);
    origin.step(State::UP1);
    assert(s == origin);

    s.step(State::DOWN1);
    origin.step(State::DOWN1);
    assert(s == origin);


    s.step(State::UP2);
    s.step(State::UP2);
    s.step(State::UP2);
    origin.step(State::DOWN2);
    assert(s == origin);

    s.step(State::UP2);
    origin.step(State::UP2);
    assert(s == origin);


    s.step(State::DOWN2);
    s.step(State::DOWN2);
    s.step(State::DOWN2);
    origin.step(State::UP2);
    assert(s == origin);

    s.step(State::DOWN2);
    origin.step(State::DOWN2);
    assert(s == origin);


    s.step(State::UP3);
    s.step(State::UP3);
    s.step(State::UP3);
    origin.step(State::DOWN3);
    assert(s == origin);

    s.step(State::UP3);
    origin.step(State::UP3);
    assert(s == origin);


    s.step(State::DOWN3);
    s.step(State::DOWN3);
    s.step(State::DOWN3);
    origin.step(State::UP3);
    assert(s == origin);

    s.step(State::DOWN3);
    origin.step(State::DOWN3);
    assert(s == origin);

    s.step(State::UP4);
    s.step(State::UP4);
    s.step(State::UP4);
    origin.step(State::DOWN4);
    assert(s == origin);

    s.step(State::UP4);
    origin.step(State::UP4);
    assert(s == origin);


    s.step(State::DOWN4);
    s.step(State::DOWN4);
    s.step(State::DOWN4);
    origin.step(State::UP4);
    assert(s == origin);

    s.step(State::DOWN4);
    origin.step(State::DOWN4);
    assert(s == origin);

    s.step(State::UP5);
    s.step(State::UP5);
    s.step(State::UP5);
    origin.step(State::DOWN5);
    assert(s == origin);

    s.step(State::UP5);
    origin.step(State::UP5);
    assert(s == origin);


    s.step(State::DOWN5);
    s.step(State::DOWN5);
    s.step(State::DOWN5);
    origin.step(State::UP5);
    assert(s == origin);

    s.step(State::DOWN5);
    origin.step(State::DOWN5);
    assert(s == origin);



    s.step(State::LEFT0);
    s.step(State::LEFT0);
    s.step(State::LEFT0);
    origin.step(State::RIGHT0);
    assert(s == origin);

    s.step(State::LEFT0);
    origin.step(State::LEFT0);
    assert(s == origin);

    s.step(State::RIGHT0);
    s.step(State::RIGHT0);
    s.step(State::RIGHT0);
    origin.step(State::LEFT0);
    assert(s == origin);

    s.step(State::RIGHT0);
    origin.step(State::RIGHT0);
    assert(s == origin);


    s.step(State::LEFT1);
    s.step(State::LEFT1);
    s.step(State::LEFT1);
    origin.step(State::RIGHT1);
    assert(s == origin);

    s.step(State::LEFT1);
    origin.step(State::LEFT1);
    assert(s == origin);

    s.step(State::RIGHT1);
    s.step(State::RIGHT1);
    s.step(State::RIGHT1);
    origin.step(State::LEFT1);
    assert(s == origin);

    s.step(State::RIGHT1);
    origin.step(State::RIGHT1);
    assert(s == origin);

    s.step(State::LEFT2);
    s.step(State::LEFT2);
    s.step(State::LEFT2);
    origin.step(State::RIGHT2);
    assert(s == origin);

    s.step(State::LEFT2);
    origin.step(State::LEFT2);
    assert(s == origin);


    s.step(State::RIGHT2);
    s.step(State::RIGHT2);
    s.step(State::RIGHT2);
    origin.step(State::LEFT2);
    assert(s == origin);

    s.step(State::RIGHT2);
    origin.step(State::RIGHT2);
    assert(s == origin);

    return 0;
}
