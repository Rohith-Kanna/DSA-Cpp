#include <iostream>
#include "Stack.cpp"
using namespace std;

int precedence(char c)
{
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else if (c == '(')
		return 0;
	else
		return -1;
}

bool inToPostFix(string s, string &ans)
{
	Stack st;
	for (int i = 0; i < s.size(); i++)
	{
		if (isalpha(s[i])) //operands
		{
			ans += s[i];
		}

		else if (s[i] == '(')
			st.PushStack(s[i]);
		else if (s[i] == ')')
		{
			while (!st.EmptyStack() && st.StackTop() != '(')
			{
				ans += st.StackTop();
				st.PopStack();
			}
			if (st.EmptyStack())
			{
				return false;
			}
			else
				st.PopStack(); 	
		}
		else //operator
		{
			int p = precedence(s[i]);
			if (p == -1)
				return false;
			while (!st.EmptyStack() && p <= precedence(st.StackTop())) //condition for removing if the operator has low predecence
			{
				ans += st.StackTop();
				st.PopStack();
			}
			st.PushStack(s[i]);
		}
	}

	while (!st.EmptyStack())
	{
		if (st.StackTop() == '(')
			return false;
		ans += st.StackTop();
		st.PopStack();
	}
	return true;
	
}

int main()
{
	string s, ans = "";
	cout << "Enter Infix Expression: ";
	cin >> s;
	if (inToPostFix(s, ans))
		cout << "Final PostFix Expression: " << ans << endl;
	else
		cout << "Please enter a valid expression!!!\n";
	return 0;
}
