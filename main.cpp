#include<bits/stdc++.h>
using namespace std;


bool isValid(vector<int> column, int ROW)
{
    for (int i = 0; i < ROW; i++)
        if (column[i] == column[ROW] || abs(column[i] - column[ROW]) == (ROW - i))
            return false;
    return true;
}

void dfs(vector<vector<string>>& result, vector<int>& column, int n, int ROW)
{
    if (ROW == n)
    {
        vector<string> solution;
        for (int row = 0; row < n; row++)
        {
            string line;
            for (int col = 0; col < n; col++)
                line.push_back(column[row] == col ? 'Q' : '_');
            solution.push_back(line);
        }
        result.push_back(solution);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        column[ROW] = col;
        if (isValid(column, ROW))
            dfs(result, column, n, ROW + 1);
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> result;
    vector<int> column(n, 0);

    dfs(result, column, n, 0);
    return result;
}
int main() {
    int n;
    cout<<"enter the size of the board\n";
    cin>>n;
    vector<vector<string>>ans = solveNQueens(n);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j];
            cout<<"\n";

        }
        cout<<"\n\n\n";
        }

}