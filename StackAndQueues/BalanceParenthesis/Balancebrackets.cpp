using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    stack<char> st;
	    bool flag=false;
	    for(int i=0;i<s.length();i++)
	    {
	        if(s[i]=='['||s[i]=='{'||s[i]=='(')
	        {
	           st.push(s[i]);
	           continue;
	        }
	        if(s[i]==']'&&st.size()>=1&&st.top()=='[')
	        {
	            st.pop();
	            continue;
	        }
	         if(s[i]==')'&&st.size()>=1&&st.top()=='(')
	        {
	            st.pop();
	            continue;
	        }
	         if(s[i]=='}'&&st.size()>=1&&st.top()=='{')
	        {
	            st.pop();
	            continue;
	        }
	       // cout<<"not balanced"<<endl;
	       flag=true;
	        break;
	    }
	    if((flag)||(st.size()!=0)) cout<<"not balanced"<<endl;
	    else cout<<"balanced"<<endl;
	    while(st.size()!=0) st.pop();
	    //continue;
	}
	return 0;
}
