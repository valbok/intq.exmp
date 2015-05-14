#include <iostream>
#include <string>
#include <stack>
#include <cassert>

using namespace std;

/** 
 * Implement function check (text) which checks whether brackets within text are
 * correctly nested. You need to consider brackets of three kinds: (), [], {}.
 */

bool check(const string& str) {
    stack<char> st;
    for (int i = 0; i < str.size(); ++i) {
        switch (str[i]) {
            case '(':
                st.push('(');
            break;
            case ')':
                if (st.empty() || st.top() != '(')
                { 
                    return false;
                }
                st.pop();

            break;
            case '[':
                st.push('[');
            break;
            case ']':
                if (st.empty() || st.top() != '[')
                { 
                    return false;
                }
                st.pop();
            break;
            case '{':
                st.push('{');
            break;
            case '}':
                if (st.empty() || st.top() != '{')
                {
                    return false;
                }
                st.pop();
            break;
        }
    }

    return st.empty();
}

int main()
{
    assert(check("a(b)"));
    assert(check("[{}]"));
    assert(check("[(]") == false);
    assert(check("}{") == false);
    assert(check("([()])"));
    assert(check("z([{}-()]{a})"));
    assert(check(""));
    assert(check("([()]") == false);
    assert(check("[(])") == false);
    assert(check("[[[(") == false);
    assert(check("[[[(]") == false);
    assert(check("[[[(]]") == false);
    assert(check("[[[(]]]") == false);
    assert(check("[[[(])]]") == false);
    assert(check("[[[()]]]"));
}