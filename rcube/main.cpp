#include "state.h"
#include <iostream>

#include <queue>
#include <map>
#include <algorithm>

static void print_path(State st, const State &s, const std::map<State, std::pair<State, State::Step>> &parent)
{    
    for (int ip = 0; st != s; ++ip) {
        auto it = parent.find(st);
        if (it == parent.end())
            break;
        st = it->second.first;
        std::cout << "  " << ip << "> step:" << it->second.second << std::endl;
        st.print();
    }
}

int main()
{
    State s;
    State solved;

    /*s.step(State::UP2);
    s.step(State::UP2);
    s.step(State::LEFT2);
    s.step(State::UP2);
    s.step(State::LEFT2);
    s.print();*/

    s._state[State::YELLOW][2][0] = State::ORANGE;
    s._state[State::YELLOW][2][1] = State::WHITE;
    s._state[State::YELLOW][2][2] = State::WHITE;

    s._state[State::BLUE][0][0] = State::WHITE;

    s._state[State::WHITE][0][1] = State::YELLOW;
    s._state[State::WHITE][0][2] = State::YELLOW;
    s._state[State::WHITE][2][0] = State::GREEN;

    s._state[State::GREEN][0][2] = State::ORANGE;
    s._state[State::GREEN][2][0] = State::RED;

    s._state[State::RED][2][0] = State::BLUE;
    s._state[State::RED][2][2] = State::YELLOW;

    s._state[State::ORANGE][2][0] = State::GREEN;
    s._state[State::ORANGE][2][2] = State::RED;

    if (!s.validate())
        return 1;

    s.print();

    std::queue<State> q;
    std::map<State, std::pair<State, State::Step>> parent;

    
        q.push(s);

    int steps_count = 0;
    //std::vector<State::Step> steps = {State::UP2, State::DOWN2, State::LEFT2, State::RIGHT2, State::UP5, State::DOWN5};
    //std::vector<State::Step> steps = {State::LEFT2, State::RIGHT2, State::UP5, State::DOWN5};
    

std::vector<State::Step> steps = {
        State::UP0, State::DOWN0, State::LEFT0, State::RIGHT0,
        State::UP1, State::DOWN1, State::LEFT1, State::RIGHT1,
        State::UP2, State::DOWN2, State::LEFT2, State::RIGHT2,
        State::UP3, State::DOWN3,
        State::UP4, State::DOWN4,
        State::UP5, State::DOWN5
    };    
    //steps = {State::UP2,  State::LEFT2, State::UP5};

    int prevEntropy = s.entropy();
    while (!q.empty()) {
        
        auto st = q.front();
        std::cout << "[" << steps_count++ << "] "<<q.size() << " e:" << prevEntropy << "->" << st.entropy() << "                 \r";
        q.pop();

        //st.print();

        //std::vector<State> pending;
        for (int i = 0; i < steps.size(); ++i) {
            auto step = steps[i];
            auto cp = st;
            cp.step(step);

            auto it = parent.find(cp);
            if (it == parent.end()) {
                //std::cout << step<<":"<<st.entropy() << "-" << cp.entropy()<<"="<<(cp.entropy()-st.entropy())<<std::endl;
                //std::cout<<"--------\n";
                //cp.print();
                
                //if (cp.entropy() < st.entropy()) {
                parent[cp] = std::make_pair(st, step);
                if (cp.entropy() < prevEntropy) {
                    std::cout << "\n:::::::::" << prevEntropy << "-------------->" << cp.entropy()<<std::endl;
                    prevEntropy = cp.entropy();
                    cp.print();
                    //parent[cp] = std::make_pair(st, step);
                    print_path(cp, s, parent);
                    //parent.clear();
                    //q = std::queue<State>(); 

                }

                if (cp.entropy() - prevEntropy <= 15)
                q.push(cp);

                //parent[cp] = std::make_pair(st, step);
                //}


                if (cp == solved || cp.entropy() == 0) {
                    std::cout << steps_count << "============================================\n";

                    cp.print();
                    print_path(cp, s, parent);
                    /*for (int ip = 0; cp != s; ++ip) {
                        auto it = parent.find(cp);
                        if (it == parent.end())
                            break;
                        cp = it->second.first;
                        std::cout << ip << ":------" << it->second.second << std::endl;
                        cp.print();
                    }*/

                    return 0;
                }  
            }

        }
        //if (q.size() < 100000000) {
        //std::sort(pending.begin(), pending.end(), [] (State &a, State &b) { return a.entropy() < b.entropy(); });
        //for (auto &a:pending)            q.push(a);
        //}

    }

    return 0;
}
