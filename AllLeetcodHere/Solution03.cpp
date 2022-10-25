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

vector<vector<int>> Solution::highestPeak(vector<vector<int>>& isWater)
{
    int m = isWater.size(), n = isWater[0].size();
    vector<vector<int> > result(m, vector<int>(n, -1));
    deque<pair<int, int> > q;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (isWater[i][j])
            {
                result[i][j] = 0;
                q.emplace_back(i, j);
            }
    vector<int> dis = { 0, 1, 0, -1, 0 };
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

int Solution::minKnightMoves(int x, int y)
{
    x += 310;
    y += 310;
    vector<pair<int, int> > dis = { { 1, 2 }, { 1, -2 }, { 2, 1 }, { 2, -1 }, { -1, 2 }, { -1, -2 }, { -2, 1 }, { -2, -1 } };
    vector<vector<bool> > vis(600, vector<bool>(600));
    deque<pair<int, int> > q;
    q.emplace_back(310, 310);
    int result = 0;
    if (x == 310 && y == 310) return result;
    while (!q.empty())
    {
        for (int i = q.size(); i; --i)
        {
            auto p = q.front();
            q.pop_front();
            vis[p.first][p.second] = true;
            for (auto& j : dis)
            {
                int tx = p.first + j.first;
                int ty = p.second + j.second;
                if (tx == x && ty == y)
                    return result;
                if (!vis[tx][ty])
                    q.emplace_back(tx, ty);
            }
        }
        ++result;
    }
    return -1;
}

int Solution::minKnightMoves_(int x, int y)
{
    if (x == 0 && y == 0) return 0;
    x += 310;
    y += 310;
    deque<pair<int, int> > q1, q2;
    q1.emplace_back(310, 310);
    q2.emplace_back(x, y);
    unordered_map<int, int> m1, m2;
    m1[310 * 700 + 310] = 0;
    m2[x * 700 + y] = 0;
    while (!q1.empty() && !q2.empty())  // 有一个队列为空说明当前方向的搜索进行不下去，这题应该不会出现这个情况
    {
        int t = q2.size() > q1.size() ? extend_1197(m2, m1, q1) : extend_1197(m1, m2, q2);
        if (t != -1)
            return t;
    }
    return -1;
}

int Solution::extend_1197(unordered_map<int, int>& m1, unordered_map<int, int>& m2, deque<pair<int, int>>& q)
{
    vector<pair<int, int> > dis = { { 1, 2 }, { 1, -2 }, { 2, 1 }, { 2, -1 }, { -1, 2 }, { -1, -2 }, { -2, 1 }, { -2, -1 } };
    for (int i = q.size(); i; --i)
    {
        auto p = q.front();
        q.pop_front();
        for (auto& i : dis)
        {
            int x = p.first + i.first, y = p.second + i.second;
            if (m2.count(x * 700 + y)) continue;
            if (m1.count(x * 700 + y))
                return m1[x * 700 + y] + m2[p.first * 700 + p.second] + 1;
            m2[x * 700 + y] = m2[p.first * 700 + p.second] + 1;
            q.emplace_back(x, y);
        }
    }
    return -1;
}

int Solution::shortestPathBinaryMatrix(vector<vector<int>>& grid)
{
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        return -1;
    if (n == 1)
        return 1;

    unordered_map<int, int> m1, m2;
    m1[0 * n + 0] = 1;
    m2[(n - 1) * n + n - 1] = 0;
    deque<pair<int, int> > q1, q2;
    q1.emplace_back(0, 0);
    q2.emplace_back(n - 1, n - 1);
    while (!q1.empty() && !q2.empty())
    {
        int t = q1.size() > q2.size() ? extend_1091(m1, m2, q2, n, grid) : extend_1091(m2, m1, q1, n, grid);
        if (t)
            return t;
    }
    return -1;
}

int Solution::extend_1091(unordered_map<int, int>& m_oppo, unordered_map<int, int>& m, deque<pair<int, int> >& q, int n, vector<vector<int> >& grid)
{
    vector<pair<int, int> > dis = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 }, { 1, 1 }, { 1, -1 }, { -1, 1 }, { -1, -1 } };
    for (int i = q.size(); i; --i)
    {
        auto p = q.front();
        q.pop_front();
        int step = p.first * n + p.second;
        for (auto& j : dis)
        {
            int x = p.first + j.first, y = p.second + j.second;
            if (x >= 0 && x < n && y >= 0 && y < n && !grid[x][y])
            {
                int newStep = x * n + y;
                if (m.count(newStep))
                    continue;
                if (m_oppo.count(newStep))
                    return m_oppo[newStep] + m[step] + 1;
                m[newStep] = m[step] + 1;
                q.emplace_back(x, y);
            }
        }
    }
    return 0;
}

int Solution::nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
{
    int m = maze.size(), n = maze[0].size(), result = 0;
    deque<vector<int> > q;
    q.push_back(entrance);
    maze[entrance[0]][entrance[1]] = '+'; // 不用设置标志数组，访问过的直接改为 '+'

    vector<int> dis = { 0, 1, 0, -1, 0 };
    while (!q.empty())
    {
        for (int i = q.size(); i; --i)
        {
            auto p = q.front();
            q.pop_front();
            for (int j = 0; j < 4; ++j)
            {
                int x = p[0] + dis[j], y = p[1] + dis[j + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == '.')
                {
                    if (x == 0 || x == m - 1 || y == 0 || y == n - 1)
                        return result + 1;
                    maze[x][y] = '+';
                    q.push_back({ x, y });
                }
            }
        }
        ++result;
    }
    return -1;
}

int Solution::shortestPath(vector<vector<int>>& grid, int k)
{
    int m = grid.size(), n = grid[0].size();
    if (m == 1 && n == 1)
        return grid[0][0] > k ? -1 : 0;
    if (k >= m + n - 3) // 这种情况可直接返回
        return m + n - 2;
    deque<vector<int> > q;
    q.push_back({ 0, 0 });
    unordered_map<int, int> sign;
    sign[0] = grid[0][0];

    vector<int> dis = { 0, 1, 0, -1, 0 };
    int result = 0;
    while (!q.empty())
    {
        ++result;
        for (int i = q.size(); i; --i)
        {
            auto p = q.front();
            q.pop_front();
            int key_p = p[0] * n + p[1]; // 横坐标乘以列

            for (int j = 0; j < 4; ++j)
            {
                int x = p[0] + dis[j], y = p[1] + dis[j + 1];
                if (x >= 0 && x < m && y >= 0 && y < n)
                {
                    int key = x * n + y;
                    if (!sign.count(key))
                    {
                        if (sign[key_p] + grid[x][y] > k)
                            continue;
                        if (x == m - 1 && y == n - 1)
                            return result;
                        q.push_back({ x, y });
                        sign[key] = sign[key_p] + grid[x][y];
                    }
                    else if (sign[key_p] + grid[x][y] < sign[key])
                    {
                        q.push_back({ x, y });
                        sign[key] = sign[key_p] + grid[x][y];
                    }
                }
            }
        }
    }
    return -1;
}

int Solution::openLock(vector<string>& deadends, string target)
{
    int n = deadends.size();
    unordered_set<string> dead(deadends.begin(), deadends.end());
    if (dead.count("0000"))
        return -1;
    if (target == "0000")
        return 0;
    deque<string> q { { "0000" } };
    dead.insert("0000");

    int result = 0;
    string temp = "";
    while (!q.empty())
    {
        ++result;
        for (int i = q.size(); i; --i)
        {
            auto p = q.front();
            q.pop_front();
            for (int j = 0; j < 4; ++j)
                for (int k = -1; k < 2; k += 2)
                {
                    temp = p;
                    int t = (p[j] - '0' + k + 10) % 10;
                    temp[j] = '0' + t;
                    if (!dead.count(temp))
                    {
                        q.push_back(temp);
                        dead.insert(temp); // 注意这里把被访问过的插入集合中，防止重复访问！
                    }
                    if (temp == target)
                        return result;
                }
        }
    }
    return -1;
}

int Solution::openLock_(vector<string>& deadends, string target)
{
    unordered_set<string> dead(deadends.begin(), deadends.end());
    if (dead.count("0000"))
        return -1;
    if (target == "0000")
        return 0;
    typedef pair<int, string> PIS;
    priority_queue<PIS, vector<PIS>, greater<PIS> > q; // 小根堆（优先队列）
    q.emplace(f("0000", target), "0000");
    unordered_map<string, int> dist;
    dist["0000"] = 0;

    string temp = "";
    while (!q.empty())
    {
        auto p = q.top();
        q.pop();

        for (int i = 0; i < 4; ++i)
            for (int j = -1; j < 2; j += 2)
            {
                temp = p.second;
                int t = (temp[i] - '0' + 10 + j) % 10;
                temp[i] = '0' + t;
                if (dead.count(temp))
                    continue;
                if (temp == target)
                    return dist[p.second] + 1;
                if (!dist.count(temp))
                {
                    dist[temp] = dist[p.second] + 1;
                    q.emplace(f(temp, target) + dist[temp], temp);
                }
            }
    }
    return -1;
}

int Solution::f(string state, string& target)
{
    int result = 0;
    for (int i = 0; i < 4; ++i)
    {
        int a = state[i] - '0', b = target[i] - '0';
        int t = abs(a - b);
        result += min(t, 10 - t);
    }
    return result;
}

int Solution::ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
    unordered_set<string> words(wordList.begin(), wordList.end());
    if (!words.count(endWord))
        return 0;
    unordered_set<string> vis { beginWord };
    deque<string> q { beginWord };

    string temp = "";
    int result = 1;
    while (!q.empty())
    {
        ++result;
        for (int i = q.size(); i; --i)
        {
            auto p = q.front();
            q.pop_front();

            for (int j = p.size() - 1; j >= 0; --j)
                for (int k = 0; k < 26; ++k)
                {
                    temp = p;
                    temp[j] = 'a' + k;
                    if (temp == endWord)
                        return result;
                    if (!vis.count(temp) && words.count(temp))
                    {
                        vis.insert(temp);
                        q.push_back(temp);
                    }
                }
        }
    }
    return 0;
}

