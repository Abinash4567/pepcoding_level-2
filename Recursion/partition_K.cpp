#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
const ll INF = LLONG_MAX >> 1;

void solve(int n, int k, vector<vector<int>> ans, int ssize, int index)
{
    if(index > n)
    {
        if(ssize + 1 == k)
        {
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<"      ";
            }
            cout<<endl;
        }
        return;
    }
    for(int i=0; i<=ssize; i++)
    {
        ans[i].push_back(index);
        solve(n, k, ans, ssize, index+1);
        ans[i].pop_back();
    }
    if(ssize + 1 < k)
    {
        ans.push_back({index});
        solve(n, k, ans, ssize + 1, index + 1);
        ans.pop_back();
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
    int n = 3;
    int k = 2;
    vector<vector<int>> ans;
    solve(n, k, ans, -1, 1);


    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}
