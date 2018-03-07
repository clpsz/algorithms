#include "../common.h"
#include <stack>

using std::stack;

// 0ms
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while (!s.empty())
        {
            int v = s.top();
            s.pop();
            aux.push(v);
        }
        aux.pop();
        while (!aux.empty())
        {
            int v = aux.top();
            aux.pop();
            s.push(v);
        }
    }

    // Get the front element.
    int peek(void) {
        while (!s.empty())
        {
            int v = s.top();
            s.pop();
            aux.push(v);
        }
        int v = aux.top();
        while (!aux.empty())
        {
            int v = aux.top();
            aux.pop();
            s.push(v);
        }

        return v;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
private:
    stack<int> s;
    stack<int> aux;
};



int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while (!q.empty())
    {
        cout << q.peek() << endl;
        q.pop();
    }

    return 0;
}

