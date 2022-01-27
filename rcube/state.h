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

        UP2, // 8
        DOWN2, // 9

        LEFT2, // 10
        RIGHT2, //11

        UP3, //12
        DOWN3, //13

        UP4, // 14
        DOWN4,// 15

        UP5, // 16
        DOWN5, // 17

        END

    };

    static const char *step_to_str(Step s)
    {
        switch (s) {
            case Step::UP0: return "UP0";
            case Step::DOWN0: return "DOWN0";
            case Step::LEFT0: return "LEFT0";
            case Step::RIGHT0: return "RIGHT0";
            case Step::UP1: return "UP1";
            case Step::DOWN1: return "DOWN1";
            case Step::LEFT1: return "LEFT1";
            case Step::RIGHT1: return "RIGHT1";
            case Step::UP2: return "UP2";
            case Step::DOWN2: return "DOWN2";
            case Step::LEFT2: return "LEFT2";
            case Step::RIGHT2: return "RIGHT2";
            case Step::UP3: return "UP3";
            case Step::DOWN3: return "DOWN3";
            case Step::UP4: return "UP4";
            case Step::DOWN4: return "DOWN4";
            case Step::UP5: return "UP5";
            case Step::DOWN5: return "DOWN5";
            default:
                break;
        }
        return "";
    }

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
        std::cout << entropy() << ":" << std::endl;
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

    int entropy() const
    {
        int e = 0;
        for (int k = 0; k < 6; ++k) {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (_state[k][i][j] != _state[k][1][1])
                        ++e;
                }
            }
        }

        return e;
    }

    int entropy(int k) const
    {
        int e = 0;
        switch (k) {
            case 0:
                e += _state[YELLOW][0][0] != YELLOW || _state[BLUE][2][0] != BLUE || _state[RED][0][2] != RED;
                e += _state[YELLOW][0][1] != YELLOW || _state[BLUE][2][1] != BLUE;
                e += _state[YELLOW][0][2] != YELLOW || _state[BLUE][2][2] != BLUE || _state[ORANGE][0][0] != ORANGE;

                e += _state[BLUE][1][0] != BLUE || _state[RED][0][1] != RED;
                e += _state[BLUE][1][1] != BLUE;
                e += _state[BLUE][1][2] != BLUE || _state[ORANGE][0][1] != ORANGE;

                e += _state[BLUE][0][0] != BLUE || _state[WHITE][2][0] != WHITE || _state[RED][0][0] != RED;
                e += _state[BLUE][0][1] != BLUE || _state[WHITE][2][1] != WHITE;
                e += _state[BLUE][0][2] != BLUE || _state[WHITE][2][2] != WHITE || _state[ORANGE][0][2] != ORANGE;
                break;
            case 1:
                e += _state[YELLOW][1][0] != YELLOW || _state[RED][1][2] != RED;
                e += _state[YELLOW][1][1] != YELLOW;
                e += _state[YELLOW][1][2] != YELLOW || _state[ORANGE][1][0] != ORANGE;

                e += _state[RED][1][1] != RED;
                e += _state[RED][1][0] != RED || _state[WHITE][1][0] != WHITE;

                e += _state[ORANGE][1][1] != ORANGE;
                e += _state[ORANGE][1][2] != ORANGE || _state[WHITE][1][2] != WHITE;

                e += _state[WHITE][1][1] != WHITE;
                break;
            case 2:
                e += _state[YELLOW][2][0] != YELLOW || _state[GREEN][0][0] != GREEN || _state[RED][2][2] != RED;
                e += _state[YELLOW][2][1] != YELLOW || _state[GREEN][0][1] != GREEN;
                e += _state[YELLOW][2][2] != YELLOW || _state[GREEN][0][2] != GREEN || _state[ORANGE][2][0] != ORANGE;

                e += _state[GREEN][1][0] != GREEN || _state[RED][2][1] != RED;
                e += _state[GREEN][1][1] != GREEN;
                e += _state[GREEN][1][2] != GREEN || _state[ORANGE][2][1] != ORANGE;

                e += _state[GREEN][2][0] != GREEN || _state[WHITE][0][0] != WHITE || _state[RED][2][0] != RED;
                e += _state[GREEN][2][1] != GREEN || _state[WHITE][0][1] != WHITE;
                e += _state[GREEN][2][2] != GREEN || _state[WHITE][0][2] != WHITE || _state[ORANGE][2][2] != ORANGE;
                break;
            default:
                break;
        }

        return e;
    }

    unsigned char _state[6][3][3];
};
