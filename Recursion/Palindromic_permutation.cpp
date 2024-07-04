#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
const ll INF = LLONG_MAX >> 1;


void solve(map<char, int> &map, int index, int len, char repeated, string ans)
{
    if(index > map.size())
    {
        string temp = ans;
        reverse(temp.begin(), temp.end());
        if(repeated!='-')
        {
            string tt = ans + repeated + temp;
            cout<<tt<<endl;
        }
        else
        {
            string tt = ans + temp;
            cout<<tt<<endl;
        }

        return;
    }
    for(auto i: map)
    {
        int cc = i.second;
        char ch = i.first;

        if(cc == 0)
            continue;
        map[ch] = cc - 1;
        solve(map, index + 1, len, repeated, ans + ch);
        map[ch] = cc;
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
    string str = "aabb";
    map<char, int> map;
    for(int i=0; i<str.size(); i++)
        map[str[i]]++;

    int count = 0;
    int len=0;
    char repeated = '-';
    for(auto it:map)
    {
        int rep = it.second;
        if(rep%2)
        {
            count++;
            repeated = it.first;
        }
        else
        {
            len++;
            map[it.first] = it.second / 2;
        }
    }
    if(count>1)
    {
        cout<<"NOT POSSIBLE";
        return 1;
    }

    solve(map, 1, len, repeated, "");


    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}
