#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
const ll INF = LLONG_MAX >> 1;

void solve(int index, vector<string> arr, string ans, vector<bool> vis)
{
    if(index >= arr.size())
    {
        cout<<ans<<endl;
        return;
    }
    if(vis[index])
    {
        solve(index+1, arr, ans, vis);
    }
    else
    {
        vis[index] = true;
        solve(index + 1, arr, ans + "( " + arr[index] + " )", vis);
        for(int i=index+1; i<arr.size(); i++)
        {
            if(!vis[i])
            {
                vis[i] = true;
                solve(index + 1, arr, ans + "( " + arr[index] + " " + arr[i] + " )", vis);
                vis[i] = false;
            }
        }
        vis[index] = false;
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

    // code
    vector<string> arr = {"a", "b", "c", "d"};
    vector<bool> vis(arr.size(), false);
    solve(0, arr, "", vis);
    // cout<<"Hello";

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}
