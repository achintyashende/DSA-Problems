//lets take a string abc the print all the permutation of it.
#include<iostream>
#include<string.h>
using namespace std;

void printPermutations(string& str,int i)
{
    //base case
    if(i >= str.length())
    {
        cout<<str<<" ";
        return;
    }
    //swapping
    for(int j=i;j<str.length();j++)
    {
        swap(str[i],str[j]);
        // recall
        printPermutations(str,i+1);

        //backtracking
        swap(str[i],str[j]);
    }
}

int main()
{
    string str = "ABSG";
    int i =0;
    printPermutations(str,i);
return 0;
}