#include "../common.h"
#include <stack>
#include <queue>

using std::stack;
using std::queue;

// 0ms
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while (q.size() > 1)
        {
            aux.push(q.front());
            q.pop();
        }
        q.pop();
        while (!aux.empty())
        {
            q.push(aux.front());
            aux.pop();
        }
    }

    // Get the top element.
    int top() {
        while (q.size() > 1)
        {
            aux.push(q.front());
            q.pop();
        }
        int v = q.front();
        aux.push(v);
        q.pop();

        while (!aux.empty())
        {
            q.push(aux.front());
            aux.pop();
        }

        return v;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;
    queue<int> aux;
};


int main()
{
    Stack q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while (!q.empty())
    {
        cout << q.top() << endl;
        q.pop();
    }

    return 0;
}

