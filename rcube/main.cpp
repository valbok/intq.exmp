#include "state.h"
#include <iostream>

#include <queue>
#include <map>

int main()
{
    State s;
    State solved;

    s.step(State::UP2);
    s.step(State::UP2);
    s.step(State::LEFT2);
    s.step(State::UP2);
    s.step(State::LEFT2);
    s.print();

    std::queue<State> q;
    std::map<State, std::pair<State, State::Step>> parent;

    q.push(s);

    int steps_count = 0;
    //std::vector<State::Step> steps = {State::UP2, State::DOWN2, State::LEFT2, State::RIGHT2, State::UP5, State::DOWN5};
    //std::vector<State::Step> steps = {State::LEFT2, State::RIGHT2, State::UP5, State::DOWN5};
    std::vector<State::Step> steps = {State::UP2,  State::LEFT2, State::UP5};
    while (!q.empty()) {
        std::cout << "[" << steps_count++ << "] "<<q.size() << "              \r";
        auto st = q.front();
        q.pop();

        //st.print();

        for (int i = 0; i < steps.size(); ++i) {
            auto step = steps[i];
            auto cp = st;
            cp.step(step);

            auto it = parent.find(cp);
            if (it == parent.end()) {
                q.push(cp);
                parent[cp] = std::make_pair(st, step);

                if (cp == solved) {
                    std::cout << steps_count << "============================================\n";

                    cp.print();
                    for (int ip = 0; cp != s; ++ip) {
                        auto it = parent.find(cp);
                        if (it == parent.end())
                            break;
                        cp = it->second.first;
                        std::cout << ip << ":------" << it->second.second << std::endl;
                        cp.print();
                    }

                    return 0;
                }  
            }
        }

    }
std::cout <<"exited\n";
    return 0;
}
