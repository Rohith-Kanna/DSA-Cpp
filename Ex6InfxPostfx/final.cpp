#include <iostream>
using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '/' || op == '*')
        return 2;
    else if (op == '-' || op == '+')
        return 1;
    else if (op == '(')
        return 0;
    else
        return -1;
}
class Node
{
public:
    char data;
    Node *link;
    Node(char d)
    {
        data = d;
        link = NULL;
    }
};
class Stack
{
public:
    Node *top;
    int count;

    Stack()
    {
        top = NULL;
        count = 0;
    }
    void push(char d)
    {
        Node *NN = new Node(d);
        NN->link = top;
        top = NN;
        count++;
    }
    char pop()
    {
        if (top == NULL)
            return '\0';
        Node *temp = top;
        top = top->link;
        char c = temp->data;
        delete temp;
        return c;
    }
    char Top()
    {
        if (top == NULL)
            return '\0';
        return top->data;
    }
    bool empty()
    {
        return (top == NULL);
    }
};
class ITP
{
public:
    Stack s;

    string itp(string in)
    {
        string ans = "";
        for (int i = 0; i < in.size(); i++)
        {
            if (isalpha(in[i]))
                ans += in[i];
            else if (in[i] == '(')
                s.push(in[i]);
            else if (in[i] == ')')
            {
                while (!s.empty() && s.Top() != '(')
                {
                    ans += s.Top();
                    s.pop();
                }
                if (s.empty()) // matching bracket not found
                {
                    cout << "no matching open bracket for the closing bracket" << endl;
                    return "-1";
                }
                else
                {
                    s.pop();
                }
            }
            else // operator
            {
                int p = precedence(in[i]);
                if (p == -1)
                {
                    cout << "invalid operator" << endl;
                    return "-1";
                }
                while (!s.empty() && p <= precedence(s.Top())) // to remove if already high or equal precdence is present
                {
                    ans += s.Top();
                    s.pop();
                }
                s.push(in[i]);
            }
        }
        while (!s.empty())
        {
            if (s.Top() == '(')
            {
                cout << "no matching closing bracket for the open bracket" << endl;
                return "-1";
            }
            ans += s.Top();
            s.pop();
        }

        return ans;
    }
};
int main()
{
    ITP i;
    cout << i.itp("a+b*c-d/e");
    cout << i.itp("((a+b)*(c-d)");
    // s.push('+');
    // s.push('/');
    // cout<<s.pop();
    // cout<<s.pop();

    // cout<<s.Top();
}