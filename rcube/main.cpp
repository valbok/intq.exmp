#include "state.h"
#include <iostream>

#include <queue>
#include <stack>
#include <map>
#include <algorithm>

static void print_path(State st, const State &s, const std::map<State, std::pair<State, State::Step>> &parent)
{    
    for (int ip = 0; st != s; ++ip) {
        auto it = parent.find(st);
        if (it == parent.end())
            break;
        st = it->second.first;
        std::cout << "  " << ip << "> step: " << State::step_to_str(it->second.second) << std::endl;
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

    /*s._state[State::YELLOW][2][1] = State::WHITE;


    s._state[State::WHITE][0][1] = State::ORANGE;


    s._state[State::ORANGE][2][1] = State::YELLOW;
*/
s._state[State::YELLOW][2][1] = State::GREEN;


    s._state[State::WHITE][0][0] = State::RED;
    s._state[State::WHITE][0][1] = State::RED;
    s._state[State::WHITE][0][2] = State::ORANGE;
    s._state[State::WHITE][1][0] = State::GREEN;
    s._state[State::WHITE][1][2] = State::GREEN;

    s._state[State::GREEN][0][1] = State::YELLOW;
    s._state[State::GREEN][1][0] = State::ORANGE;
    s._state[State::GREEN][1][2] = State::WHITE;
    s._state[State::GREEN][2][0] = State::WHITE;
    s._state[State::GREEN][2][1] = State::WHITE;
    s._state[State::GREEN][2][2] = State::WHITE;

    s._state[State::RED][2][0] = State::GREEN;
    s._state[State::RED][2][1] = State::GREEN;

    s._state[State::ORANGE][1][2] = State::WHITE;
    s._state[State::ORANGE][2][2] = State::GREEN;

    if (!s.validate())
        return 1;

    s.print();

    std::cout <<"0:"<<s.entropy(0)<<std::endl;
    std::cout <<"1:"<<s.entropy(1)<<std::endl;
    std::cout <<"2:"<<s.entropy(2)<<std::endl;
    //return 0;
    //std::queue<State> q;
    //std::queue<std::pair<State,int>> q;
    std::stack<std::pair<State,int>> q;
    std::map<State, std::pair<State, State::Step>> parent;

    
        //q.push(s);
    q.push(std::make_pair(s, 0));

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
    std::vector<int> vc = {0};
int ce = 0;
    /*while (!q.empty()) {
        
        auto st = q.front();
        //std::cout << "[" << steps_count++ << "] "<<q.size() << " e:" << prevEntropy << "->" << st.entropy() << "                 \r";
        std::cout << "[" << st.second << "/" << vc[st.second] << "] "<<q.size() << " e:" << prevEntropy << "->" << st.first.entropy() << "                 \r";//<< std::endl;
        q.pop();

        //st.print();

        //std::vector<State> pending;
        for (int i = 0; i < steps.size(); ++i) {
            auto step = steps[i];
            //auto cp = st;
            auto cp = st.first;
            cp.step(step);
cp.print();

            auto it = parent.find(cp);
            if (it == parent.end()) {
                parent[cp] = std::make_pair(st.first, step);
                if (cp.entropy() < prevEntropy) {
                    std::cout << "\n:::::::::" << prevEntropy << "-------------->" << cp.entropy()<<std::endl;
                    prevEntropy = cp.entropy();
                    cp.print();
                    //parent[cp] = std::make_pair(st, step);
                    print_path(cp, s, parent);
                    //parent.clear();
                    //q = std::queue<State>(); 

                }

                //if (cp.entropy() - prevEntropy <= 20)
                //if (cp.entropy(ce) == 0)                    ++ce;
                
                if (cp.entropy() <= 24) {
                //q.push(cp);
                    q.push(std::make_pair(cp, st.second+1));

                    if (vc.size() >= st.second + 1)
                        vc.push_back(0);
                    ++vc[st.second + 1];
                }

                if (cp == solved || cp.entropy() == 0) {
                    std::cout << steps_count << "============================================\n";

                    cp.print();
                    print_path(cp, s, parent);

                    return 0;
                }  
            }

        }
    }*/

    while (!q.empty()) {
        
        auto st = q.top();
        //std::cout << "[" << steps_count++ << "] "<<q.size() << " e:" << prevEntropy << "->" << st.entropy() << "                 \r";
        std::cout << "[" << st.second << "/" << vc[st.second] << "] "<<q.size() << " e:" << prevEntropy << "->" << st.first.entropy() << "                 \r";//<< std::endl;
        q.pop();

        //st.print();

        //std::vector<State> pending;
        for (int i = 0; i < steps.size(); ++i) {
            auto step = steps[i];
            //auto cp = st;
            auto cp = st.first;
            cp.step(step);
cp.print();

            auto it = parent.find(cp);
            if (it == parent.end()) {
                //std::cout << step<<":"<<st.entropy() << "-" << cp.entropy()<<"="<<(cp.entropy()-st.entropy())<<std::endl;
                //std::cout<<"--------\n";
                //cp.print();
                
                //if (cp.entropy() < st.entropy()) {
                //parent[cp] = std::make_pair(st, step);
                parent[cp] = std::make_pair(st.first, step);
                /*if (cp.entropy() < prevEntropy) {
                    std::cout << "\n:::::::::" << prevEntropy << "-------------->" << cp.entropy()<<std::endl;
                    prevEntropy = cp.entropy();
                    cp.print();
                    //parent[cp] = std::make_pair(st, step);
                    print_path(cp, s, parent);
                    //parent.clear();
                    //q = std::queue<State>(); 

                }*/

                //if (cp.entropy() - prevEntropy <= 20)
                //if (cp.entropy(ce) == 0)                    ++ce;
                
                for (int iii = 0; iii < 3; ++iii) {
                    std::cout <<"  " << iii <<":"<<cp.entropy(iii)<<"vs"<<s.entropy(iii)<<std::endl;
                    if (cp.entropy(iii) == 0) continue;

                    if (cp.entropy(iii) > s.entropy(iii))
                        break;


std::cout <<"++++++::"<<cp.entropy() <<"vs"<<s.entropy()<<std::endl<<std::endl;

                    q.push(std::make_pair(cp, st.second+1));

                    if (vc.size() >= st.second + 1)
                        vc.push_back(0);
                    ++vc[st.second + 1];
                    break;
                }

                /*if (cp.entropy() <= 24) {
                //q.push(cp);
                    q.push(std::make_pair(cp, st.second+1));

                    if (vc.size() >= st.second + 1)
                        vc.push_back(0);
                    ++vc[st.second + 1];
                }*/

                if (cp == solved || cp.entropy() == 0
|| cp.entropy(1) == 0
                    ) {
                    std::cout << steps_count << "============================================\n";

                    cp.print();
                    print_path(cp, s, parent);

                    return 0;
                }  
            }

        }
    }

    return 0;
}
