#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1;

bool isSafe(vector<vector<int>> board, int i, int j, int k)
{
    int xIndex = i - i % 3;
    int yIndex = j - j % 3;

    for(int l=0; l<3; l++)
    {
        for(int m=0; m<3; m++)
        {
            if(board[l+xIndex][m+yIndex]==k)
                return false;
        }
    }

    for(int l=0; l<9; l++)
    {
        if(board[l][j]==k or board[i][l]==k)
            return false;
    }
    return true;
}


bool solve(vector<vector<int>> &board)
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(board[i][j]==0)
            {
                for(int k=1; k<=9; k++)
                {
                    if(isSafe(board, i, j, k))
                    {
                        board[i][j] = k;
                        if(solve(board))
                            return true;
                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
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
    vector<vector<int>> board = 
    { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
     {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
     {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
     {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
     {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
     {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
     {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
     {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
     {0, 0, 5, 2, 0, 6, 3, 0, 0} };

    solve(board);
     for(int i=0; i<9; i++)
     {
        for(int j=0; j<9; j++)
            cout<<board[i][j]<<"  ";
        cout<<endl;
    }
        cout<<endl;

   #ifndef ONLINE_JUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
   #endif
   return 0;
}