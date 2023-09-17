#include<iostream>
#include<vector>
using namespace std;

void solve(vector<string>&ans,int n,int open,int close,string output)
{
    //base condition
    //when there will no bracket remaining
    if(open == 0 && close == 0)
    {
        ans.push_back(output);
        return ;
    }
    //include open barcket
    if(open>0)
    {
        output.push_back('(');
        solve(ans,n,open-1,close,output);
        //backtracking
        output.pop_back();
    }
    if(close>open)
    {
        output.push_back(')');
        solve(ans,n,open,close-1,output);
        //backtracking
        output.pop_back();
    }
}

int main()
{
int n=4;
vector<string> ans ;
int open=n;    
int close=n; 
string output = "";
solve(ans,n,open,close,output);
//print ans   
for(auto i:ans)
{
    cout<<i<<" ";
}
return 0;
}

//output will be
//(((()))) ((()())) ((())()) ((()))() (()(())) (()()()) (()())() (())(()) (())()() ()((())) ()(()()) ()(())() ()()(()) ()()()() 
