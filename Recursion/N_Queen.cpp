#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1;

void solve(int n, vector<vector<int>> board, vector<bool> diagonal1, vector<bool> diagonal2, vector<bool> rowCheck, int index1, vector<vector<int>> & ans)
{
    if(index1==n)
    {
        vector<int> temp;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[j][i]==1)
                {
                    temp.push_back(j);
                    break;
                }
            }
        }
        ans.push_back(temp);
    }


    for(int i=0; i<n; i++)
    {
        if(!rowCheck[i])
        {
            if(!diagonal1[i+index1] and !diagonal2[n+index1-i-1])
            {
                board[i][index1] = 1;
                diagonal1[i+index1] = true;
                diagonal2[n+index1-i-1] = true;
                rowCheck[i] = true;
                solve(n, board, diagonal1, diagonal2, rowCheck, index1+1, ans);
                rowCheck[i] = false;
                board[i][index1] = -1;
                diagonal1[i+index1] = false;
                diagonal2[n-1-index1-i] = false;
            }
        }
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
    int n;
    cin>>n;
    vector<vector<int>> board(n, vector<int>(n, -1));
    vector<bool> diagonal1(2*n-1,false);
    vector<bool> diagonal2(2*n-1, false);
    vector<bool> rowCheck(n, false);
    vector<vector<int>> ans;
    solve(n, board, diagonal1, diagonal2, rowCheck, 0, ans);

   #ifndef ONLINE_JUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
   #endif
   return 0;
}