// Min Stack O(1) space and time complexity
// Find minimum element in the stack
#include<bits/stdc++.h>
using namespace std;
class MinStack
{
	stack<int> st;
	int mini;
	public:
		void push(int data)
		{
			if(st.empty())
			{
				st.push(data);
				mini = data;
			}
			else
			{
				if(mini>data)
				{
					st.push(2*data - mini);
					mini = data;
				}
				else
					st.push(data);
			}
		}
		void pop()
		{
			if(st.empty())
				return ;
			else
			{
				int curr = st.top();
				st.pop();
				if(curr>mini)
					return;
				else
					mini = 2*mini - curr;
			}
		}
		int top()
		{
			return st.top();
		}
		int getMin()
		{
			return mini;
		}
};
int main()
{
	MinStack *ms = new MinStack();
	ms->push(1);
	ms->push(3);
	ms->push(-2);
	cout<<"minimum element :- "<<ms->getMin()<<endl;
	ms->pop();
	cout<<"minimum element :- "<<ms->getMin()<<endl;
	ms->pop();
	ms->push(0);
	ms->push(4);
	cout<<"minimum element :- "<<ms->getMin()<<endl;
	delete ms;
	return 0;
}
