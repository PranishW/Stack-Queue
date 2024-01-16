// Creating an expression tree using Stack
#include <bits/stdc++.h>
using namespace std;
struct Node
{
	char data;
	Node *left,*right;
	Node(char data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};
class Expression_tree
{
	stack<Node*> st;
	public :
		Node* create(Node*,string); // creating expression tree using postfix expression
		void prefix(Node*);
		void postfix(Node*);
		void infix(Node*);
};
Node* Expression_tree::create(Node* root,string postfix)
{
	for(int i=0;i<postfix.size();i++)
	{
		Node* n = new Node(postfix[i]);
		if(isalpha(postfix[i]) or isdigit(postfix[i]))  // operands as leaf nodes
		{
			n->right = NULL;
			n->left = NULL;
		}
		else				// operators as branches
		{
			n->right = st.top();
			st.pop();
			n->left = st.top();
			st.pop();
		}
		st.push(n);
	}
	root=st.top();
	st.pop();
	cout<<"***Tree Created***"<<endl;
	return root;
}
void Expression_tree::infix(Node* root)
{
	if(root==NULL)
		return;
	infix(root->left);
	cout<<root->data<<" ";
	infix(root->right);
}
void Expression_tree::prefix(Node* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	prefix(root->left);
	prefix(root->right);
}
void Expression_tree::postfix(Node* root)
{
	if(root==NULL)
		return;
	postfix(root->left);
	postfix(root->right);
	cout<<root->data<<" ";
}
int main()
{
	Expression_tree ext;
	string s;
	cout<<"Enter postorder expression :-";
	cin>>s;
	Node* root = NULL;
	root = ext.create(root,s);
	cout<<"Infix conversion :- ";
	ext.infix(root);
	cout<<endl;
	cout<<"Postfix conversion :- ";
	ext.postfix(root);
	cout<<endl;
	cout<<"Prefix conversion :- ";
	ext.prefix(root);
	return 0;
}
