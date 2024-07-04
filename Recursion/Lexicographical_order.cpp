#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1;

void dfs(int i, int n)
{
    if(i>n)
        return;
    cout<<i<<endl;
    for(int j=0; j<=9; j++)
        dfs(10*i + j, n);
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
    for(int i=1; i<=9; i++)
        dfs(i, n);

   #ifndef ONLINE_JUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
   #endif
   return 0;
}