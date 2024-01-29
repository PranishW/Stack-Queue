#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};
class Queue
{
	int qsize;
	Node *tail,*head;
	public:
		Queue();
		void push(int);
		void pop();
		int front();
		int back();
		int size();
		int empty();
};
Queue::Queue()
{
	tail=NULL;
	head=NULL;
	qsize=0;	
}
void Queue::push(int data)
{
	Node* n = new Node(data);
	if(head==NULL)
	{
		head=n;
		tail=n;
	}
	else
	{
		tail->next = n;
		tail = n;
	}
	qsize++;
}
void Queue::pop()
{
	if(head!=NULL)
	{
		Node* temp = head;
		head= head->next;
		delete temp;
		qsize--;
	}
}
int Queue::size()
{
	return qsize;
}
int Queue::back()
{
	return tail==NULL? 0 : tail->data;
}
int Queue::front()
{
	return head==NULL? 0 : head->data;
}
int Queue::empty()
{
	return qsize==0?1:0;
}
int main()
{
	Queue q;
	cout<<q.empty()<<endl;
	cout<<q.size()<<endl;
	cout<<q.front()<<endl;
	cout<<q.back()<<endl;
	q.push(49);
	q.push(12);
	q.push(21);
	q.push(22);
	cout<<q.empty()<<endl;
	cout<<q.size()<<endl;
	cout<<q.front()<<endl;
	cout<<q.back()<<endl;
	q.pop();
	cout<<q.empty()<<endl;
	cout<<q.size()<<endl;
	cout<<q.front()<<endl;
	cout<<q.back()<<endl;
	return 0;
}
