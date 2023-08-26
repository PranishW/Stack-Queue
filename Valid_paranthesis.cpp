//Given an expression string exp, write a program to examine whether the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” 
//are correct in the given expression.
#include <bits/stdc++.h>
using namespace std;
struct node
{
	char data;
	node *next;
	node(char data)
	{
			this->data = data;
			next = NULL;
	}	
};
class Stack
{
	node *top;
	int size;
	public:
		Stack()
		{
			top = NULL;
			size = 0;
		}
		void push(char data)
		{
			node *n = new node(data);
			n->next = top;
			top = n;
			size++;
		}
		bool isEmpty()
		{
			return size==0;
		}
		char pop()
		{
			node *temp;
			if(isEmpty())
				return 0;
			else
			{
				char ans = top->data;
				temp = top;
				top = temp->next;
				size--;
				delete temp;
			}
		}
		char peek()
		{
			if(isEmpty())
				return 0;
			return top->data;
		}
};
int match(char a, char b){
    if(a=='{' && b=='}'){
        return 1;
    }
    if(a=='(' && b==')'){
        return 1;
    }
    if(a=='[' && b==']'){
        return 1;
    }
  return 0;  
}
int main()
{
	string exp;
	Stack st;
	cout<<"Enter any expression :-";
	cin>>exp;
	for(int i=0;i<exp.size();i++)
	{
		if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
			st.push(exp[i]);
		else if((exp[i]==')'||exp[i]=='}'||exp[i]==']'))
		{
			if(st.isEmpty())
			{
				cout<<"String unbalanced";
				return 0;
			}
			if(match(st.peek(),exp[i]))
				st.pop();
			else
			{
				cout<<"String unbalanced";
				return 0;
			}
		}
	}
	if(st.isEmpty())
		cout<<"String balanced ";
	else
		cout<<"String unbalanced";
	return 0;
}
