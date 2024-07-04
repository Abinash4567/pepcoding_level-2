#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
const ll INF = LLONG_MAX >> 1;

bool is_palindrome(string str)
{
    int low = 0, high = str.size() - 1;
    while(low < high)
    {
        if(str[low]!=str[high])
            return false;
        low++;
        high--;
    }  
    return true;
}

void solve(string str, string soFar)
{
    if(str.size()<=0)
    {
        cout<<soFar<<endl;
        return;
    }
    for(int i=0; i<str.size(); i++)
    {
        string prefix = str.substr(0, i+1);
        string temp = str.substr(i+1);
        if(is_palindrome(prefix))            
            solve(temp, prefix);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
    #endif

    //code 
    string str = "aabbaa";
    solve(str, "");


    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}
