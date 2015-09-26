// reverse a string by using stack

#include<iostream> // for cin and cout
#include<string>    // string and stack container class
#include<stack>   // string is a typedef of basic_string , which is almost like a container class
using namespace std;

int main()
{
    std::string str; // make a string
    std::stack<char> stacks;

    cout<<"enter String"<<endl;
    cin>>str;
    int index=0;

    while(str[index])
    {
        stacks.push(str[index++]); // pushes char into stack
    }
    while(!stacks.empty()) // checks if stack is empty
    {
        cout<<stacks.top(); // prints the last inserted or popped element
        stacks.pop(); //pops
    }
    return 0;
}
