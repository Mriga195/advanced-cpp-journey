#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

struct Task
{
    int priority;
    string description;
};

struct compareTask
{
    bool operator()(const Task &a, const Task &b)
    {
        return a.priority > b.priority ? true : false;
    }
};

bool validParenthesis(const string &parenthesis)
{
    stack<char> st;

    for (const char &val : parenthesis)
    {
        if (val == '(' || val == '{' || val == '[')
            st.push(val);
        else
        {
            if (val == ')')
            {
                if (st.top() != '(')
                    return false;
                else
                    st.pop();
            }
            else if (val == '}')
            {
                if (st.top() != '{')
                    return false;
                else
                    st.pop();
            }
            else if (val == ']')
            {
                if (st.top() != '[')
                    return false;
                else
                    st.pop();
            }
        }
    }

    return st.empty() ? true : false;
}

int main()
{
    string str = "[{())}]";
    string ans = validParenthesis(str) ? "true" : "false";
    cout << ans << endl;

    priority_queue<Task, vector<Task>, compareTask> pq;

    pq.push({10, "Email boss"});
    pq.push({1, "Fire alarm"});
    pq.push({5, "Buy groceries"});

    Task current = pq.top();

    cout << "priority: " << current.priority << endl
         << "description: " << current.description << endl;
}