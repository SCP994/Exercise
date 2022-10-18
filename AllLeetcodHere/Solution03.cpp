#include "Solution03.h"

vector<vector<int> > Solution::updateMatrix(vector<vector<int> >& mat)
{
    int m = mat.size(), n = mat[0].size();
    vector<vector<int> > result(m, vector<int>(n, -1)), vis(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (!mat[i][j] && result[i][j] == -1)
                bfs_542_1(i, j, mat, vis, result);
    bfs_542_2(mat, vis, result);
    return result;
}

void Solution::bfs_542_1(int x, int y, vector<vector<int> >& mat, vector<vector<int> >& vis, vector<vector<int> >& result)
{
    int m = mat.size(), n = mat[0].size();
    deque<pair<int, int> > q;
    vector<int> dis = { 0, 1, 0, -1 , 0 };
    q.emplace_back(x, y);
    while (!q.empty())
    {
        int x = q.back().first, y = q.back().second;
        result[x][y] = 0;
        //vis[x][y] = 1;
        q.pop_back();
        for (int i = 0; i < 4; ++i)
        {
            int tx = x + dis[i], ty = y + dis[i + 1];
            if (tx >= 0 && tx < m && ty >= 0 && ty < n && result[tx][ty] == -1)
                if (!mat[tx][ty])
                    q.emplace_back(tx, ty);
                else
                {
                    result[tx][ty] = 1;
                    //vis[tx][ty] = 1;
                }
        }
    }
}

void Solution::bfs_542_2(vector<vector<int> >& mat, vector<vector<int> >& vis, vector<vector<int> >& result)
{
    int m = mat.size(), n = mat[0].size();
    vector<int> dis = { 0, 1, 0, -1, 0 };
    vector<pair<int, int> > tempV;
    int count = 1;
    do
    {
        tempV.clear();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (result[i][j] == count)
                    tempV.emplace_back(i, j);
        ++count;
        int len = tempV.size();
        for (int i = 0; i < len; ++i)
            for (int j = 0; j < 4; ++j)
            {
                int x = tempV[i].first + dis[j], y = tempV[i].second + dis[j + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && mat[x][y] && result[x][y] == -1)
                {
                    result[x][y] = count;
                    //vis[x][y] = 1;
                }
            }
    } while (!tempV.empty());
}

vector<vector<int>> Solution::updateMatrix_(vector<vector<int>>& mat)
{
    int m = mat.size(), n = mat[0].size();
    vector<vector<int> > result(m, vector<int>(n, -1));
    deque<pair<int, int> > q;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (!mat[i][j])
            {
                result[i][j] = 0;
                q.emplace_back(i, j);
            }
    vector<int> dis = { -1, 0, 1, 0, -1 };
    while (!q.empty())
    {
        auto p = q.front();
        q.pop_front();
        for (int i = 0; i < 4; ++i)
        {
            int x = p.first + dis[i], y = p.second + dis[i + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && result[x][y] == -1)
            {
                result[x][y] = result[p.first][p.second] + 1;
                q.emplace_back(x, y);
            }
        }
    }
    return result;
}
