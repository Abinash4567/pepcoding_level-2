#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
const ll INF = LLONG_MAX >> 1;

bool canPlaceHorizontally(int i, int j, vector<vector<string>> &pattern, string word)
{
    if(j-1 >= 0 && pattern[i][j-1] != "+")
        return false;
    if(j + word.size() < pattern[0].size() && pattern[i][j + word.size()] != "+")
        return false;

    for(int k = 0; k < word.size(); k++)
    {
        if(j + k >= pattern[0].size())
            return false;
        if(pattern[i][k + j] == "-" || pattern[i][k + j] == string(1, word[k]))
            continue;
        else
            return false;
    }
    return true;
}

bool canPlaceVertically(int i, int j, vector<vector<string>> &pattern, string word)
{
    if(i-1 >= 0 && pattern[i-1][j] != "+")
        return false;
    if(i + word.size() < pattern.size() && pattern[i + word.size()][j] != "+")
        return false;

    for(int k = 0; k < word.size(); k++)
    {
        if(i + k >= pattern.size())
            return false;
        if(pattern[i + k][j] == "-" || pattern[i + k][j] == string(1, word[k]))
            continue;
        else
            return false;
    }
    return true;
}

vector<bool> placeWordHorizontally(int i, int j, vector<vector<string>> &pattern, string word)
{
    vector<bool> arr;
    for(int k = 0; k < word.size(); k++)
    {
        if(pattern[i][j + k] != "-")
        {
            arr.push_back(false);
        }
        else
        {
            arr.push_back(true);
            pattern[i][j + k] = string(1, word[k]);
        }
    }
    return arr;
}

vector<bool> placeWordVertically(int i, int j, vector<vector<string>> &pattern, string word)
{
    vector<bool> placi;
    for(int k = 0; k < word.size(); k++)
    {
        if(pattern[i + k][j] != "-")
        {
            placi.push_back(false);
        }
        else
        {
            placi.push_back(true);
            pattern[i + k][j] = string(1, word[k]);
        }
    }
    return placi;
}

void unplaceHorizontally(int i, int j, vector<vector<string>> &pattern, string word, vector<bool> placi)
{
    for(int k = 0; k < word.size(); k++)
    {
        if(placi[k] == true)
        {
            pattern[i][j + k] = "-";
        }
    }
}

void unplaceVertically(int i, int j, vector<vector<string>> &pattern, string word, vector<bool> placi)
{
    for(int k = 0; k < word.size(); k++)
    {
        if(placi[k] == true)
        {
            pattern[i + k][j] = "-";
        }
    }
}

void solve(vector<vector<string>> &pattern, vector<string> &words, int index)
{
    if(index == words.size())
    {
        // print the array
        for(int i = 0; i < pattern.size(); i++)
        {
            for(int j = 0; j < pattern[i].size(); j++)
            {
                cout << pattern[i][j] << "  ";
            }
            cout << endl;
        }
        return;
    }

    for(int i = 0; i < pattern.size(); i++)
    {
        for(int j = 0; j < pattern[i].size(); j++)
        {
            if(pattern[i][j] == "-" || pattern[i][j] == string(1, words[index][0]))
            {
                if(canPlaceHorizontally(i, j, pattern, words[index]))
                {
                    vector<bool> placedHori = placeWordHorizontally(i, j, pattern, words[index]);
                    solve(pattern, words, index + 1);
                    unplaceHorizontally(i, j, pattern, words[index], placedHori);
                }

                if(canPlaceVertically(i, j, pattern, words[index]))
                {
                    vector<bool> placiVerti = placeWordVertically(i, j, pattern, words[index]);
                    solve(pattern, words, index + 1);
                    unplaceVertically(i, j, pattern, words[index], placiVerti);
                }
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

    // code
    vector<vector<string>> pattern = {
        {"+", "+", "+", "+", "+", "+", "+", "+", "+", "-"},
        {"-", "+", "+", "+", "+", "+", "+", "+", "+", "-"},
        {"-", "-", "-", "-", "-", "-", "-", "+", "+", "-"},
        {"-", "+", "+", "+", "+", "+", "+", "+", "+", "-"},
        {"-", "+", "+", "+", "+", "+", "+", "+", "+", "-"},
        {"-", "+", "+", "+", "+", "-", "-", "-", "-", "-"},
        {"-", "-", "-", "-", "-", "+", "+", "+", "-", "-"},
        {"-", "+", "+", "+", "+", "+", "+", "+", "+", "-"},
        {"+", "-", "-", "-", "-", "-", "-", "-", "-", "-"},
        {"+", "+", "+", "+", "+", "+", "+", "+", "+", "+"}
    };

    vector<string> words = {"delhi", "iceland", "ankara", "london"};
    solve(pattern, words, 0);

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}
