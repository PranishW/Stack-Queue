#include <bits/stdc++.h>
using namespace std;
class Queue
{
	stack<int> s1,s2;
	int front;
	public:
		Queue();
		void push(int);
		int pop();
		int peek();
		bool empty();
		int size();
};
Queue::Queue()
{
	front = -1;
}
void Queue::push(int x)
{
	if(s1.empty())
		front = x;
	s1.push(x);
}
int Queue::pop()
{
	if(s2.empty())
	{
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}
	int x = s2.top();
	s2.pop();
	return x;
}
int Queue::peek()
{
	if(!s2.empty())
		return s2.top();
	return front;
}
bool Queue::empty()
{
	return s1.empty() && s2.empty();
}
int Queue::size()
{
	return s1.size() + s2.size();
}

int main()
{
	Queue q;
	q.push(2);
	q.push(3);
	q.push(1);
	q.push(5);
	cout<<"Size of queue - "<<q.size()<<endl;
	cout<<"Front element - "<<q.peek()<<endl;
	q.pop();
	cout<<"Is Queue empty ? "<<q.empty()<<endl;
	q.push(10);
	q.push(12);
	cout<<"Size of queue - "<<q.size()<<endl;
	cout<<"Front element - "<<q.peek()<<endl;
	q.pop();
	cout<<"Size of queue - "<<q.size()<<endl;
	cout<<"Front element - "<<q.peek()<<endl;
	return 0;
}

