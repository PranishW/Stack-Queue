// Stack using Linked List
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
class Stack
{
	Node* head;
	int stacksize;
	public:
		Stack();
		void push(int);
		void pop();
		int size();
		int empty();
		int top();
};
Stack::Stack()
{
	head = NULL;
	stacksize=0;
}
void Stack::push(int data)
{
	Node* n = new Node(data);
	if(head==NULL)
		head = n;
	else
	{
		n->next = head;
		head = n;
	}
	stacksize++;
}
void Stack::pop()
{
	if(head!=NULL)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		stacksize--;
	}
}
int Stack::size()
{
	return stacksize;
}
int Stack::top()
{
	if(head!=NULL)
		return head->data;
	return 0;
}
int Stack::empty()
{
	return stacksize==0?1:0;
}
int main()
{
	Stack st;
	cout<<st.top()<<endl;
	cout<<st.empty()<<endl;
	st.push(10);
	st.push(-3);
	st.push(12);
	cout<<st.top()<<endl;
	cout<<st.size()<<endl;
	cout<<st.empty()<<endl;
	st.pop();
	cout<<st.top()<<endl;
	cout<<st.size()<<endl;
	st.pop();
	cout<<st.top()<<endl;
	cout<<st.size()<<endl;
	return 0;
}
