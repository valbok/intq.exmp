#pragma once

#include <cstring>
#include <iostream>

class State {

public:
    State()
    {
        memset(_state, 0, sizeof(_state));
        for (int k = 0; k < 6; ++k) {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    _state[k][i][j] = static_cast<unsigned char>(k);
                }
            }
        }

    }


    enum Step {
        UP0 = 0,
        DOWN0,

        LEFT0,
        RIGHT0,


        UP1,
        DOWN1,

        LEFT1,
        RIGHT1,

        UP2,
        DOWN2,

        LEFT2,
        RIGHT2,

        UP3,
        DOWN3,

        UP4,
        DOWN4,

        UP5,
        DOWN5,

        END

    };

    constexpr static const int YELLOW = 0;
    constexpr static const int BLUE = 1;
    constexpr static const int WHITE = 2;
    constexpr static const int GREEN = 3;
    constexpr static const int RED = 4;
    constexpr static const int ORANGE = 5;

    void up(int i)
    {
        unsigned char tmp[3] = {0};
        tmp[0] = _state[YELLOW][0][i];
        tmp[1] = _state[YELLOW][1][i];
        tmp[2] = _state[YELLOW][2][i];

        _state[YELLOW][0][i] = _state[GREEN][0][i]; //0 - 5  0+i
        _state[YELLOW][1][i] = _state[GREEN][1][i];
        _state[YELLOW][2][i] = _state[GREEN][2][i];

        _state[GREEN][0][i] = _state[WHITE][0][i]; //3 - 1
        _state[GREEN][1][i] = _state[WHITE][1][i];
        _state[GREEN][2][i] = _state[WHITE][2][i];

        _state[WHITE][0][i] = _state[BLUE][0][i]; //2 - 4
        _state[WHITE][1][i] = _state[BLUE][1][i];
        _state[WHITE][2][i] = _state[BLUE][2][i];

        _state[BLUE][0][i] = tmp[0]; // 1 - 3
        _state[BLUE][1][i] = tmp[1];
        _state[BLUE][2][i] = tmp[2];
    }

    void down(int i)
    {
        unsigned char tmp[3] = {0};
        tmp[0] = _state[YELLOW][0][i];
        tmp[1] = _state[YELLOW][1][i];
        tmp[2] = _state[YELLOW][2][i];

        _state[YELLOW][0][i] = _state[BLUE][0][i];
        _state[YELLOW][1][i] = _state[BLUE][1][i];
        _state[YELLOW][2][i] = _state[BLUE][2][i];

        _state[BLUE][0][i] = _state[WHITE][0][i];
        _state[BLUE][1][i] = _state[WHITE][1][i];
        _state[BLUE][2][i] = _state[WHITE][2][i];

        _state[WHITE][0][i] = _state[GREEN][0][i];
        _state[WHITE][1][i] = _state[GREEN][1][i];
        _state[WHITE][2][i] = _state[GREEN][2][i];

        _state[GREEN][0][i] = tmp[0];
        _state[GREEN][1][i] = tmp[1];
        _state[GREEN][2][i] = tmp[2];
    }

    void left(int i)
    {
        unsigned char tmp[3] = {0};
        tmp[0] = _state[YELLOW][i][0];
        tmp[1] = _state[YELLOW][i][1];
        tmp[2] = _state[YELLOW][i][2];

        _state[YELLOW][i][0] = _state[ORANGE][i][0];
        _state[YELLOW][i][1] = _state[ORANGE][i][1];
        _state[YELLOW][i][2] = _state[ORANGE][i][2];

        _state[ORANGE][i][0] = _state[WHITE][2-i][2];
        _state[ORANGE][i][1] = _state[WHITE][2-i][1];
        _state[ORANGE][i][2] = _state[WHITE][2-i][0];

        _state[WHITE][2-i][2] = _state[RED][i][0];
        _state[WHITE][2-i][1] = _state[RED][i][1];
        _state[WHITE][2-i][0] = _state[RED][i][2];

        _state[RED][i][0] = tmp[0];
        _state[RED][i][1] = tmp[1];
        _state[RED][i][2] = tmp[2];
    }

    void right(int i)
    {
        unsigned char tmp[3] = {0};
        tmp[0] = _state[YELLOW][i][0];
        tmp[1] = _state[YELLOW][i][1];
        tmp[2] = _state[YELLOW][i][2];

        _state[YELLOW][i][0] = _state[RED][i][0];
        _state[YELLOW][i][1] = _state[RED][i][1];
        _state[YELLOW][i][2] = _state[RED][i][2];

        _state[RED][i][0] = _state[WHITE][2-i][2];
        _state[RED][i][1] = _state[WHITE][2-i][1];
        _state[RED][i][2] = _state[WHITE][2-i][0];

        _state[WHITE][2-i][2] = _state[ORANGE][i][0];
        _state[WHITE][2-i][1] = _state[ORANGE][i][1];
        _state[WHITE][2-i][0] = _state[ORANGE][i][2];

        _state[ORANGE][i][0] = tmp[0];
        _state[ORANGE][i][1] = tmp[1];
        _state[ORANGE][i][2] = tmp[2];
    }

    void up_orange(int i)
    {
        unsigned char tmp[3] = {0};
        tmp[0] = _state[ORANGE][0][i];
        tmp[1] = _state[ORANGE][1][i];
        tmp[2] = _state[ORANGE][2][i];

        _state[ORANGE][0][i] = _state[GREEN][i][2];
        _state[ORANGE][1][i] = _state[GREEN][i][1];
        _state[ORANGE][2][i] = _state[GREEN][i][0];

        _state[GREEN][i][0] = _state[4][0][2-i];
        _state[GREEN][i][1] = _state[4][1][2-i];
        _state[GREEN][i][2] = _state[4][2][2-i];

        _state[4][0][2-i] = _state[BLUE][2-i][2];
        _state[4][1][2-i] = _state[BLUE][2-i][1];
        _state[4][2][2-i] = _state[BLUE][2-i][0];

        _state[BLUE][2-i][0] = tmp[0];
        _state[BLUE][2-i][1] = tmp[1];
        _state[BLUE][2-i][2] = tmp[2];
    }

    void down_orange(int i)
    {
        unsigned char tmp[3] = {0};
        tmp[0] = _state[ORANGE][0][i];
        tmp[1] = _state[ORANGE][1][i];
        tmp[2] = _state[ORANGE][2][i];

        _state[ORANGE][0][i] = _state[BLUE][2-i][0];
        _state[ORANGE][1][i] = _state[BLUE][2-i][1];
        _state[ORANGE][2][i] = _state[BLUE][2-i][2];

        _state[BLUE][2-i][0] = _state[RED][2][2-i];
        _state[BLUE][2-i][1] = _state[RED][1][2-i];
        _state[BLUE][2-i][2] = _state[RED][0][2-i];

        _state[RED][2][2-i] = _state[GREEN][i][2];
        _state[RED][1][2-i] = _state[GREEN][i][1];
        _state[RED][0][2-i] = _state[GREEN][i][0];

        _state[GREEN][i][2] = tmp[0];
        _state[GREEN][i][1] = tmp[1];
        _state[GREEN][i][0] = tmp[2];
    }

    void rotate_left(int i)
    {
        unsigned char tmp[2] = {0};

        tmp[0] = _state[i][0][0];
        tmp[1] = _state[i][0][1];

        _state[i][0][0] = _state[i][0][2];
        _state[i][0][1] = _state[i][1][2];
        _state[i][0][2] = _state[i][2][2];

        _state[i][1][2] = _state[i][2][1];
        _state[i][2][2] = _state[i][2][0];

        _state[i][2][1] = _state[i][1][0];
        _state[i][2][0] = tmp[0];
        _state[i][1][0] = tmp[1];

    }

    void rotate_right(int i)
    {
        unsigned char tmp[2] = {0};

        tmp[0] = _state[i][0][2];
        tmp[1] = _state[i][0][1];

        _state[i][0][2] = _state[i][0][0];
        _state[i][0][1] = _state[i][1][0];
        _state[i][0][0] = _state[i][2][0];

        _state[i][1][0] = _state[i][2][1];
        _state[i][2][0] = _state[i][2][2];

        _state[i][2][1] = _state[i][1][2];
        _state[i][2][2] = tmp[0];
        _state[i][1][2] = tmp[1];
    }


    void step(Step s)
    {
        // UP: 0 -> 1 -> 2 -> 3
        // LEFT: 0 -> 4
        // RIGHT: 0 -> 5

        switch (s) {
            case UP0:
                up(0);
                rotate_left(RED);
                break;
            case DOWN0:
                down(0);
                rotate_right(RED);
                break;
            case LEFT0:
                left(0);
                rotate_right(BLUE);
                break;
            case RIGHT0:
                right(0);
                rotate_left(BLUE);
                break;
            case UP1:
                up(1);
                break;
            case DOWN1:
                down(1);
                break;
            case LEFT1:
                left(1);
                break;
            case RIGHT1:
                right(1);
                break;
            case UP2:
                up(2);
                rotate_right(ORANGE);
                break;
            case DOWN2:
                down(2);
                rotate_left(ORANGE);
                break;
            case LEFT2:
                left(2);
                rotate_left(GREEN);
                break;
            case RIGHT2:
                right(2);
                rotate_right(GREEN);
                break;
            case UP3:
                up_orange(0);
                rotate_left(YELLOW);
                break;
            case DOWN3:
                down_orange(0);
                rotate_right(YELLOW);
                break;
            case UP4:
                up_orange(1);
                break;
            case DOWN4:
                down_orange(1);
                break;
            case UP5:
                up_orange(2);
                rotate_right(WHITE);
                break;
            case DOWN5:
                down_orange(2);
                rotate_left(WHITE);
                break;
            default:
                break;

        }

    }

    bool operator==(const State &other) const
    {
        return memcmp(_state, other._state, sizeof(_state)) == 0;
    }

    bool operator!=(const State &other) const
    {
        return !operator==(other);
    }

    bool operator<(const State &other) const
    {
        return memcmp(_state, other._state, sizeof(_state)) < 0;
    }

    void print()
    {
        for (int k = 0; k < 6; ++k) {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    switch (_state[k][i][j]) {
                        case YELLOW:
                            std::cout <<"Y";
                            break;
                        case BLUE:
                            std::cout <<"B";
                            break;
                        case WHITE:
                            std::cout <<"W";
                            break;
                        case GREEN:
                            std::cout <<"G";
                            break;
                        case RED:
                            std::cout <<"R";
                            break;
                        case ORANGE:
                            std::cout <<"O";
                            break;
                        default:
                            break;
                    }
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }

    }

    bool validate() const
    {
        int colors_count[6] = {0};
        for (int k = 0; k < 6; ++k) {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int color = _state[k][i][j];
                    ++colors_count[color];
                }
            }
        }
        for (int k = 0; k < 6; ++k) {
            if (colors_count[k] != 9) {
                std::cout << k <<"="<< colors_count[k] << ": wrong color count" << std::endl;
                return false;
            }
        }

        return true;
    }

    unsigned char _state[6][3][3];
};
