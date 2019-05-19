Reverse a given Stack with the help of another empty stack. Two stacks will be given. Out of which first contains some integers and second one is empty. You need to reverse the first one using second stack. Change in the given first stack itself.
Note : You don't need to print or return the stack, just reverse the given stack and it will be printed internally.
****************************************************************************************************************************

#include <stack>
using namespace std;
void solve(stack<int> &input, stack<int> &extra)
{
    if(extra.size()==1)
    {
        int t=extra.top();
        extra.pop();
        input.push(t);
        return;
    }
    int t1=extra.top();
    extra.pop();
    solve(input,extra);
    input.push(t1);
    return;
    
}
void reverseStack(stack<int> &input, stack<int> &extra) {
	while(input.size()!=0)
    {
        int temp=input.top();
        input.pop();
        extra.push(temp);
    }
  solve(input,extra);   
}
