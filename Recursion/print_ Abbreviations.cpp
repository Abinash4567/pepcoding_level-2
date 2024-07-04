#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1;

void solve(string str, string temp, int index, int count)
{
    if(index==str.size())
    {
        if(count)
            temp+=to_string(count);
        cout<<temp<<endl;
        return;
    }
    solve(str, temp, index + 1, count + 1);
    if(count!=0)
        temp+=to_string(count);
    temp+=str[index];
    solve(str, temp, index + 1, 0);
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
   string str = "pep";
   solve(str, "", 0, 0);

   #ifndef ONLINE_JUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
   #endif
   return 0;
}