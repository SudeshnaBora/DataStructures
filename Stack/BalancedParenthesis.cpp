// implement balanced parenthesis using Stack stl and iterator

#include<stack>
#include<string.h>
#include<iostream>
#include<assert.h>
#include<stdio.h>
using namespace std;

int main()
{
    string str,ch1;
    string::iterator it;
    stack<char > stacks;
    bool Unequal = false;
    cout<<"Enter a statement"<<endl;
    cin>>str;
    for(it=str.begin();it<str.end();it++)
    {
        if(stacks.empty() && (*it==')' || *it=='}' || *it==']'))
        {
            cout<<"Error:- Unequal"<<endl;
            return 0;
        }
       if(*it == ')')
       {
           Unequal = (stacks.top()=='(');
           assert(Unequal);
           stacks.pop();
           continue;
       }
       if(*it == '}')
       {
           Unequal = (stacks.top()=='{');
           assert(Unequal);
           stacks.pop();
           continue;
       }
       if(*it == ']')
       {
           Unequal = (stacks.top()=='[');
           assert(Unequal);
           stacks.pop();
       }
       if (*it=='(' || *it == '{' || *it == '[')
           {
             stacks.push(*it);
             continue;
           }
    }
    if(stacks.empty())
       cout<<"Equal Parenthesis\n";
    else
        cout<<"Unequal Parenthesis\n";
    return 0;
}

