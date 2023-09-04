#include<bits/stdc++.h>
using namespace std;
int longestValidParentheses(string s) {
    stack<int> st;
    int res=0;
    st.push(-1);
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
            st.push(i);
        else
        {
            st.pop();
            if(st.empty())
                st.push(i);
            else
                res = max(res,i-st.top());
        }
    }
    return res;
}

int main()
{
	string s;
	cout<<"Enter a string containing '(' and ')' only :- ";
	cin>>s;
	cout<<"Longest valid parantheses length in the string is :- "<<longestValidParentheses(s)<<endl;
	return 0;
}
