Given a string expression which consists only ‘}’ and ‘{‘. The expression may not be balanced. You need to find the minimum number of bracket reversals which are required to make the expression balanced.
Return -1 if the given expression can't be balanced.
Input Format :
String S
Output Format :
Required count
Sample Input 1 :
{{{
Sample Output 1 :
-1
Sample Input 2 :
{{{{}}
Sample Output 2 :
1

------------------------------------------------------------------------------------------------------------------


#include <stack>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int countBracketReversals(char input[]){
    
    int cnt=0;
    stack<char > st;
    if(strlen(input)%2==1)
    {
        return -1;
    }
    for(int i=0;input[i]!='\0';i++)
    {
        if(input[i]=='}')
        {
            if((st.size()>0)&&st.top()=='{')  st.pop();
            else st.push(input[i]);
        }
        else
        {
            st.push('{');
        }
    }
    while(st.size()>0)
    {
        if(st.top()=='{')
        {
            cnt+=1;
            st.pop();
            if(st.top()=='}')
            {
                cnt++;
            }
            st.pop();
            continue;
        }
        if(st.top()=='}')
        {
            //cnt+=1;
            st.pop();
            if(st.top()=='}')
            {
                cnt++;
            }
             st.pop();
        }
    }
    return cnt;

}
