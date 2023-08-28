#include<bits/stdc++.h>
using namespace std;
class Stack {
	queue<int> q1;
	public:
    	void push(int x) {
        	int s = q1.size();
        	q1.push(x);
        	for(int i=1;i<=s;i++)
        	{
        	    q1.push(q1.front());
        	    q1.pop();
        	}
    	}
    	int pop() 
		{
        	int src = q1.front();
        	q1.pop();
        	return src;
    	}
    	int top() 
		{
        	return q1.front();
    	}
    	bool empty() 
		{
        	return q1.empty()==1;
    	}
};
int main()
{
	Stack *s = new Stack();
	s->push(2);
	s->push(3);
	s->push(5);
	s->push(1);
	s->push(7);
	cout<<"Top element in stack :- "<<s->top()<<endl;
	cout<<"Removing top element :- "<<s->pop()<<endl;
	cout<<"Top element in stack :- "<<s->top()<<endl;
	s->push(11);
	s->push(6);
	cout<<"Top element in stack :- "<<s->top()<<endl;
	cout<<"Removing top element :- "<<s->pop()<<endl;
	cout<<"Top element in stack :- "<<s->top()<<endl;
	delete s;
	return 0;
}
