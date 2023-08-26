//The Next greater Element for an element x is the first greater element on the right side of x in the array. 
//Elements for which no greater element exist, consider the next greater element as -1. 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> v(n),ans(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	stack<int> st;
	for(int i=0;i<n;i++)
	{
		while(!st.empty() && v[i]>v[st.top()])
		{
			ans[st.top()] = v[i];
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty())
	{
		ans[st.top()] = -1;
		st.pop();
	}
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
