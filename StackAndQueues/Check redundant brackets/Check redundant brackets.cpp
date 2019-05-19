Given a string mathematical expression, return true if redundant brackets are present in the expression. Brackets are redundant if there is nothing inside the bracket or more than one pair of brackets are present.
Sample Input 1:
((a + b)) 
Sample Output 1:
true
Sample Input 2:
(a+b) 
Sample Output 2:
false
-------------------------------------------------------------------------------------------------------------------------------------

#include <stack>
using namespace std;
bool checkRedundantBrackets(char *input) {
	stack<char> st;
    bool flag=false;
    for(int i=0; input[i]!='\0'; i++)
    {
        if(input[i]==')')
        {
            int cnt=0;
            while(st.top()!='(')
            {
                st.pop();
                cnt++;
            }
            st.pop();
            if(cnt==0)
            {
                flag=true;
            }
        }
        else
        {
            st.push(input[i]);
        }
    }
    if(flag) return true;
    else  return false;

}
