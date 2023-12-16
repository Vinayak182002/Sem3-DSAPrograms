/*
 *	======================================
 * 		Program Name: InfixToPostfix.cpp
 *  	Created on: December 01,2022
 *      Author: Vinayak Shete
 *  ======================================
 */
 
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//Function to return preedence of character
int precedence(char c)
{
	if(c=='^')
		return 3;
	else if(c=='/'||c=='*')
		return 2;
	else if(c=='+'||c=='-')
		return 1;
	else
		return -1;
}

//Infix to postfix conversion
void infixToPostfix(string s)
{
	stack<char> st;
	string res;
	int i;

	for(i=0;i<s.length();i++)
	{
		char c=s[i];
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'))
			res+=c;
		else if(c=='(')
			st.push('(');
		else if(c==')')
		{
			while(st.top()!='(')
			{	
				res+=st.top();
				st.pop();
			}
			st.pop();
		}
		else
		{
			while(!st.empty()&&precedence(s[i])<=precedence(st.top()))
			{
				res+=st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	while(!st.empty())
	{
		res+=st.top();
		st.pop();
	}
	cout<<"\nThe Postfix Expression is: ";
	cout<<res<<endl;
}

int main()
{
	string exp;
	cout<<"\n===================INFIX TO POSTFIX===================";
	cout<<"\nEnter infix expression to convert to postfix: ";
	cin>>exp;
	//function call
	infixToPostfix(exp);
	return 0;
}

