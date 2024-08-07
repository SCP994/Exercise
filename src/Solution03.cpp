#include "Solution03.h"

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

namespace s03 {
vector<vector<int>> Solution::updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> result(m, vector<int>(n, -1)), vis(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (!mat[i][j] && result[i][j] == -1)
                bfs_542_1(i, j, mat, vis, result);
    bfs_542_2(mat, vis, result);
    return result;
}

void Solution::bfs_542_1(int x, int y, vector<vector<int>>& mat,
                         vector<vector<int>>& vis,
                         vector<vector<int>>& result) {
    int m = mat.size(), n = mat[0].size();
    deque<pair<int, int>> q;
    vector<int> dis = {0, 1, 0, -1, 0};
    q.emplace_back(x, y);
    while (!q.empty()) {
        int x = q.back().first, y = q.back().second;
        result[x][y] = 0;
        // vis[x][y] = 1;
        q.pop_back();
        for (int i = 0; i < 4; ++i) {
            int tx = x + dis[i], ty = y + dis[i + 1];
            if (tx >= 0 && tx < m && ty >= 0 && ty < n && result[tx][ty] == -1)
                if (!mat[tx][ty])
                    q.emplace_back(tx, ty);
                else {
                    result[tx][ty] = 1;
                    // vis[tx][ty] = 1;
                }
        }
    }
}

void Solution::bfs_542_2(vector<vector<int>>& mat, vector<vector<int>>& vis,
                         vector<vector<int>>& result) {
    int m = mat.size(), n = mat[0].size();
    vector<int> dis = {0, 1, 0, -1, 0};
    vector<pair<int, int>> tempV;
    int count = 1;
    do {
        tempV.clear();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (result[i][j] == count)
                    tempV.emplace_back(i, j);
        ++count;
        int len = tempV.size();
        for (int i = 0; i < len; ++i)
            for (int j = 0; j < 4; ++j) {
                int x = tempV[i].first + dis[j],
                    y = tempV[i].second + dis[j + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && mat[x][y] &&
                    result[x][y] == -1) {
                    result[x][y] = count;
                    // vis[x][y] = 1;
                }
            }
    } while (!tempV.empty());
}

vector<vector<int>> Solution::updateMatrix_(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> result(m, vector<int>(n, -1));
    deque<pair<int, int>> q;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (!mat[i][j]) {
                result[i][j] = 0;
                q.emplace_back(i, j);
            }
    vector<int> dis = {-1, 0, 1, 0, -1};
    while (!q.empty()) {
        auto p = q.front();
        q.pop_front();
        for (int i = 0; i < 4; ++i) {
            int x = p.first + dis[i], y = p.second + dis[i + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && result[x][y] == -1) {
                result[x][y] = result[p.first][p.second] + 1;
                q.emplace_back(x, y);
            }
        }
    }
    return result;
}

vector<vector<int>> Solution::highestPeak(vector<vector<int>>& isWater) {
    int m = isWater.size(), n = isWater[0].size();
    vector<vector<int>> result(m, vector<int>(n, -1));
    deque<pair<int, int>> q;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (isWater[i][j]) {
                result[i][j] = 0;
                q.emplace_back(i, j);
            }
    vector<int> dis = {0, 1, 0, -1, 0};
    while (!q.empty()) {
        auto p = q.front();
        q.pop_front();
        for (int i = 0; i < 4; ++i) {
            int x = p.first + dis[i], y = p.second + dis[i + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && result[x][y] == -1) {
                result[x][y] = result[p.first][p.second] + 1;
                q.emplace_back(x, y);
            }
        }
    }
    return result;
}

int Solution::minKnightMoves(int x, int y) {
    x += 310;
    y += 310;
    vector<pair<int, int>> dis = {{1, 2},  {1, -2},  {2, 1},  {2, -1},
                                  {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
    vector<vector<bool>> vis(600, vector<bool>(600));
    deque<pair<int, int>> q;
    q.emplace_back(310, 310);
    int result = 0;
    if (x == 310 && y == 310)
        return result;
    while (!q.empty()) {
        for (int i = q.size(); i; --i) {
            auto p = q.front();
            q.pop_front();
            vis[p.first][p.second] = true;
            for (auto& j : dis) {
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

int Solution::minKnightMoves_(int x, int y) {
    if (x == 0 && y == 0)
        return 0;
    x += 310;
    y += 310;
    deque<pair<int, int>> q1, q2;
    q1.emplace_back(310, 310);
    q2.emplace_back(x, y);
    unordered_map<int, int> m1, m2;
    m1[310 * 700 + 310] = 0;
    m2[x * 700 + y] = 0;
    while (
        !q1.empty() &&
        !q2.empty()) // 有一个队列为空说明当前方向的搜索进行不下去，这题应该不会出现这个情况
    {
        int t = q2.size() > q1.size() ? extend_1197(m2, m1, q1)
                                      : extend_1197(m1, m2, q2);
        if (t != -1)
            return t;
    }
    return -1;
}

int Solution::extend_1197(unordered_map<int, int>& m1,
                          unordered_map<int, int>& m2,
                          deque<pair<int, int>>& q) {
    vector<pair<int, int>> dis = {{1, 2},  {1, -2},  {2, 1},  {2, -1},
                                  {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
    for (int i = q.size(); i; --i) {
        auto p = q.front();
        q.pop_front();
        for (auto& i : dis) {
            int x = p.first + i.first, y = p.second + i.second;
            if (m2.count(x * 700 + y))
                continue;
            if (m1.count(x * 700 + y))
                return m1[x * 700 + y] + m2[p.first * 700 + p.second] + 1;
            m2[x * 700 + y] = m2[p.first * 700 + p.second] + 1;
            q.emplace_back(x, y);
        }
    }
    return -1;
}

int Solution::shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        return -1;
    if (n == 1)
        return 1;

    unordered_map<int, int> m1, m2;
    m1[0 * n + 0] = 1;
    m2[(n - 1) * n + n - 1] = 0;
    deque<pair<int, int>> q1, q2;
    q1.emplace_back(0, 0);
    q2.emplace_back(n - 1, n - 1);
    while (!q1.empty() && !q2.empty()) {
        int t = q1.size() > q2.size() ? extend_1091(m1, m2, q2, n, grid)
                                      : extend_1091(m2, m1, q1, n, grid);
        if (t)
            return t;
    }
    return -1;
}

int Solution::extend_1091(unordered_map<int, int>& m_oppo,
                          unordered_map<int, int>& m, deque<pair<int, int>>& q,
                          int n, vector<vector<int>>& grid) {
    vector<pair<int, int>> dis = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                                  {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for (int i = q.size(); i; --i) {
        auto p = q.front();
        q.pop_front();
        int step = p.first * n + p.second;
        for (auto& j : dis) {
            int x = p.first + j.first, y = p.second + j.second;
            if (x >= 0 && x < n && y >= 0 && y < n && !grid[x][y]) {
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

int Solution::nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int m = maze.size(), n = maze[0].size(), result = 0;
    deque<vector<int>> q;
    q.push_back(entrance);
    maze[entrance[0]][entrance[1]] =
        '+'; // 不用设置标志数组，访问过的直接改为 '+'

    vector<int> dis = {0, 1, 0, -1, 0};
    while (!q.empty()) {
        for (int i = q.size(); i; --i) {
            auto p = q.front();
            q.pop_front();
            for (int j = 0; j < 4; ++j) {
                int x = p[0] + dis[j], y = p[1] + dis[j + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == '.') {
                    if (x == 0 || x == m - 1 || y == 0 || y == n - 1)
                        return result + 1;
                    maze[x][y] = '+';
                    q.push_back({x, y});
                }
            }
        }
        ++result;
    }
    return -1;
}

int Solution::shortestPath(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    if (m == 1 && n == 1)
        return grid[0][0] > k ? -1 : 0;
    if (k >= m + n - 3) // 这种情况可直接返回
        return m + n - 2;
    deque<vector<int>> q;
    q.push_back({0, 0});
    unordered_map<int, int> sign;
    sign[0] = grid[0][0];

    vector<int> dis = {0, 1, 0, -1, 0};
    int result = 0;
    while (!q.empty()) {
        ++result;
        for (int i = q.size(); i; --i) {
            auto p = q.front();
            q.pop_front();
            int key_p = p[0] * n + p[1]; // 横坐标乘以列

            for (int j = 0; j < 4; ++j) {
                int x = p[0] + dis[j], y = p[1] + dis[j + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int key = x * n + y;
                    if (!sign.count(key)) {
                        if (sign[key_p] + grid[x][y] > k)
                            continue;
                        if (x == m - 1 && y == n - 1)
                            return result;
                        q.push_back({x, y});
                        sign[key] = sign[key_p] + grid[x][y];
                    } else if (sign[key_p] + grid[x][y] < sign[key]) {
                        q.push_back({x, y});
                        sign[key] = sign[key_p] + grid[x][y];
                    }
                }
            }
        }
    }
    return -1;
}

int Solution::openLock(vector<string>& deadends, string target) {
    int n = deadends.size();
    unordered_set<string> dead(deadends.begin(), deadends.end());
    if (dead.count("0000"))
        return -1;
    if (target == "0000")
        return 0;
    deque<string> q{{"0000"}};
    dead.insert("0000");

    int result = 0;
    string temp = "";
    while (!q.empty()) {
        ++result;
        for (int i = q.size(); i; --i) {
            auto p = q.front();
            q.pop_front();
            for (int j = 0; j < 4; ++j)
                for (int k = -1; k < 2; k += 2) {
                    temp = p;
                    int t = (p[j] - '0' + k + 10) % 10;
                    temp[j] = '0' + t;
                    if (!dead.count(temp)) {
                        q.push_back(temp);
                        dead.insert(
                            temp); // 注意这里把被访问过的插入集合中，防止重复访问！
                    }
                    if (temp == target)
                        return result;
                }
        }
    }
    return -1;
}

int Solution::openLock_(vector<string>& deadends, string target) {
    unordered_set<string> dead(deadends.begin(), deadends.end());
    if (dead.count("0000"))
        return -1;
    if (target == "0000")
        return 0;
    typedef pair<int, string> PIS;
    priority_queue<PIS, vector<PIS>, greater<PIS>> q; // 小根堆（优先队列）
    q.emplace(f("0000", target), "0000");
    unordered_map<string, int> dist;
    dist["0000"] = 0;

    string temp = "";
    while (!q.empty()) {
        auto p = q.top();
        q.pop();

        for (int i = 0; i < 4; ++i)
            for (int j = -1; j < 2; j += 2) {
                temp = p.second;
                int t = (temp[i] - '0' + 10 + j) % 10;
                temp[i] = '0' + t;
                if (dead.count(temp))
                    continue;
                if (temp == target)
                    return dist[p.second] + 1;
                if (!dist.count(temp)) {
                    dist[temp] = dist[p.second] + 1;
                    q.emplace(f(temp, target) + dist[temp], temp);
                }
            }
    }
    return -1;
}

int Solution::f(string state, string& target) {
    int result = 0;
    for (int i = 0; i < 4; ++i) {
        int a = state[i] - '0', b = target[i] - '0';
        int t = abs(a - b);
        result += min(t, 10 - t);
    }
    return result;
}

int Solution::ladderLength(string beginWord, string endWord,
                           vector<string>& wordList) {
    unordered_set<string> words(wordList.begin(), wordList.end());
    if (!words.count(endWord))
        return 0;
    unordered_set<string> vis{beginWord};
    deque<string> q{beginWord};

    string temp = "";
    int result = 1;
    while (!q.empty()) {
        ++result;
        for (int i = q.size(); i; --i) {
            auto p = q.front();
            q.pop_front();

            for (int j = p.size() - 1; j >= 0; --j)
                for (int k = 0; k < 26; ++k) {
                    temp = p;
                    temp[j] = 'a' + k;
                    if (temp == endWord)
                        return result;
                    if (!vis.count(temp) && words.count(temp)) {
                        vis.insert(temp);
                        q.push_back(temp);
                    }
                }
        }
    }
    return 0;
}

int Solution::minimumOperations(vector<int>& nums, int start, int goal) {
    if (start == goal)
        return 0;

    unordered_map<int, int> m1, m2;
    m1[start] = 0;
    m2[goal] = 0;
    deque<int> q1{start}, q2{goal};

    while (!q1.empty() && !q2.empty()) {
        int t = q1.size() > q2.size() ? extend_2059(m2, m1, q2, nums)
                                      : extend_2059(m1, m2, q1, nums);
        if (t)
            return t;
    }
    return -1;
}

int Solution::extend_2059(unordered_map<int, int>& m_q,
                          unordered_map<int, int>& m, deque<int>& q,
                          vector<int>& nums) {
    for (int i = q.size(); i; --i) {
        auto p = q.front();
        q.pop_front();
        for (int j = nums.size() - 1; j >= 0; --j) {
            for (int k = 0; k < 3; ++k) {
                int temp = p;
                if (k == 0)
                    temp += nums[j];
                else if (k == 1)
                    temp -= nums[j];
                else
                    temp ^= nums[j];
                if (m.count(temp))
                    return m_q[p] + m[temp] + 1;
                if (temp < 0 || temp > 1000 || m_q.count(temp))
                    continue;
                m_q[temp] = m_q[p] + 1;
                q.emplace_back(temp);
            }
        }
    }
    return 0;
}

int Solution::slidingPuzzle(vector<vector<int>>& board) {
    int m = 2, n = 3;
    string start, seq;
    string end = "123450";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            start += char(board[i][j] + '0');
            if (board[i][j] != 0)
                seq += char(board[i][j] + '0');
        }
    if (!check(seq))
        return -1;

    typedef pair<int, string> PIS;
    priority_queue<PIS, vector<PIS>, greater<PIS>> q;
    unordered_map<string, int> dist;
    dist[start] = 0;
    q.push({f_773(start), start});
    vector<int> dis = {-1, 0, 1, 0, -1};
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        int step = dist[p.second];
        if (p.second == end)
            return step;
        int zero = p.second.find('0');
        int i = zero / n, j = zero % n;
        for (int k = 0; k < 4; ++k) {
            int x = i + dis[k], y = j + dis[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                string str = p.second;
                swap(str[i * n + j], str[x * n + y]);
                if (dist.count(str))
                    continue;
                dist[str] = step + 1;
                q.push({step + f_773(str), str});
            }
        }
    }
    return -1;
}

bool Solution::check(string& str) {
    int len = str.size();
    int cnt = 0;
    for (int i = 0; i < len; ++i)
        for (int j = i + 1; j < len; ++j)
            if (str[i] > str[j])
                ++cnt;
    return cnt % 2 == 0;
}

int Solution::f_773(string& state) {
    int m = 2, n = 3, result = 0;
    for (int i = 0; i < m * n; ++i) {
        if (state[i] == '0')
            continue;
        int num = state[i] - '1';
        result += abs(num / n - i / n) + abs(num % n - i % n);
    }
    return result;
}

int Solution::shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<bool>> vis(
        n, vector<bool>(1 << n)); // 用数组保存路径，0 1 2 3 等被表示为 1 2 4 8
    deque<tuple<int, int, int>> q;
    for (int i = 0; i < n; ++i) {
        q.emplace_back(i, 1 << i, 0);
        vis[i][1 << i] = true;
    }

    while (!q.empty()) {
        auto [p, state, step] = q.front();
        q.pop_front();
        if (state == (1 << n) - 1)
            return step;

        for (auto& i : graph[p]) {
            int t = state | (1 << i);
            if (!vis[i][t]) {
                q.emplace_back(i, t, step + 1);
                vis[i][state] = true;
            }
        }
    }
    return 0;
}

int Solution::cutOffTree(vector<vector<int>>& forest) {
    int m = forest.size(), n = forest[0].size();
    vector<vector<int>> trees;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (forest[i][j] > 1)
                trees.push_back({forest[i][j], i, j});

    int heapSize = trees.size();
    for (int i = heapSize >> 1; i >= 0; --i) // 建堆
        maxHeapify(trees, heapSize, i);
    for (int i = heapSize; i; --i) // 堆排序
    {
        --heapSize;
        swap(trees[0], trees[i - 1]);
        maxHeapify(trees, heapSize, 0);
    }
    heapSize = trees.size();

    vector<int> vis(m * n, inf); // 保存访问过的节点，存入步数
    typedef tuple<int, int, int> T;
    priority_queue<T, vector<T>, greater<T>>
        q; // 小根堆，保存估计步数、坐标，存入 tuple 比存入 vector
           // 访问更快，还可以将坐标改为 x * n + y

    vector<int> dis = {0, 1, 0, -1, 0};
    int idx = 0, target = trees[idx][0], targetX = trees[idx][1],
        targetY = trees[idx][2];
    q.push({f_675(0, 0, targetX, targetY), 0, 0});
    vis[0] = 0;
    while (true) {
        if (q.empty())
            break;
        while (!q.empty()) {
            auto [_, px, py] = q.top(); // _ 只用于估计步数
            q.pop();
            int trueStep = vis[px * n + py];
            if (forest[px][py] == target) {
                if (++idx == heapSize)
                    return trueStep;
                target = trees[idx][0], targetX = trees[idx][1],
                targetY = trees[idx][2];
                q = priority_queue<T, vector<T>, greater<T>>(); // 清空栈
                q.push({trueStep + f_675(px, py, targetX, targetY), px, py});
                vis = vector<int>(m * n, inf);
                vis[px * n + py] = trueStep;
                break;
            }
            for (int i = 0; i < 4; ++i) {
                int x = px + dis[i], y = py + dis[i + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && forest[x][y] &&
                    trueStep + 1 <
                        vis[x * n + y]) // 注意 trueStep + 1 < vis[x * n + y]
                                        // 条件，启发式算法独有
                {
                    vis[x * n + y] = trueStep + 1;
                    q.push(
                        {trueStep + 1 + f_675(x, y, targetX, targetY), x, y});
                }
            }
        }
    }
    return -1;
}

void Solution::maxHeapify(vector<vector<int>>& v, int heapSize,
                          int i) // 维护堆（大根堆）的性质
{
    while (true) {
        int rightChild = (i + 1) << 1, leftChild = rightChild - 1, largest = i;
        if (leftChild < heapSize && v[leftChild][0] > v[largest][0])
            largest = leftChild;
        if (rightChild < heapSize && v[rightChild][0] > v[largest][0])
            largest = rightChild;
        if (largest == i)
            break;
        swap(v[largest], v[i]);
        i = largest;
    }
}

inline int Solution::f_675(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int Solution::minCost(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    deque<tuple<int, int, int>> q{{0, 0, 0}};
    vector<pair<int, int>> orient = {
        {-1, -1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> vis(
        m, vector<int>(
               n, inf)); // 可设为布尔型，将四个方向的节点加入队列才算访问过
    vis[0][0] = 0;
    while (!q.empty()) {
        auto [tx, ty, cost] = q.front();
        if (tx == m - 1 && ty == n - 1)
            return cost;
        q.pop_front();
        auto [orientX, orientY] = orient[grid[tx][ty]];
        for (int i = 1; i <= 4; ++i) {
            int x = tx + orient[i].first, y = ty + orient[i].second;
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (i == grid[tx][ty] && cost < vis[x][y]) {
                    vis[x][y] = cost;
                    q.emplace_front(x, y, cost);
                } else if (cost + 1 < vis[x][y]) {
                    vis[x][y] = cost + 1;
                    q.emplace_back(x, y, cost + 1);
                }
            }
        }
    }
    return -1;
}

int Solution::minimumObstacles(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n));
    deque<pair<int, int>> q{{0, 0}};
    vector<int> dis = {0, 1, 0, -1, 0};
    int count = 0;
    while (!q.empty()) {
        auto [p, ret] = q.front();
        q.pop_front();
        int px = p / n, py = p % n;
        if (px == m - 1 && py == n - 1)
            return ret;
        if (vis[px][py])
            continue; // 这个条件是关键，同一个位置可能会被多次添加
        vis[px][py] = true;
        cout << ": " << ++count << endl;
        for (int i = 0; i < 4; ++i) {
            int x = px + dis[i], y = py + dis[i + 1];
            if (x >= 0 && x < m && y >= 0 && y < n &&
                !vis[px]
                    [py]) // !vis[px][py] 不与 if (vis[px][py]) continue; 矛盾
                if (!grid[x][y]) // 没有遇到障碍物
                    q.emplace_front(x * n + y, ret);
                else // 遇到障碍物
                    q.emplace_back(x * n + y, ret + 1);
        }
    }
    return 0;
}

bool Solution::hasPath(vector<vector<int>>& maze, vector<int>& start,
                       vector<int>& destination) {
    int m = maze.size(), n = maze[0].size();
    deque<pair<int, int>> s{{start[0], start[1]}}; // 栈 DFS，队列 BFS
    vector<vector<bool>> vis(m, vector<bool>(n));
    vector<int> dis = {0, 1, 0, -1, 0};
    while (!s.empty()) {
        auto [px, py] = s.front();
        s.pop_front();
        if (vis[px][py])
            continue;
        if (px == destination[0] && py == destination[1])
            return true;
        vis[px][py] = true;
        for (int i = 0; i < 4; ++i) {
            int x = px, y = py;
            do
                x += dis[i], y += dis[i + 1];
            while (x >= 0 && x < m && y >= 0 && y < n &&
                   !maze[x][y]); // 别加 !vis[x][y] 条件
            if (x - dis[i] == px && y - dis[i + 1] == py)
                continue;
            s.emplace_front(x - dis[i],
                            y - dis[i + 1]); // emplace_back 就成了 BFS
        }
    }
    return false;
}

bool Solution::exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size(), len = word.size();
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (board[i][j] == word[0] &&
                dfs_79(i, j, 0, m, n, len, board, word))
                return true;
    return false;
}

bool Solution::dfs_79(int i, int j, int idx, int m, int n, int len,
                      vector<vector<char>>& board, string& word) {
    if (idx == len)
        return true;
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx])
        return false;
    char t = board[i][j];
    board[i][j] = '0';
    vector<int> dis = {0, 1, 0, -1, 0};
    for (int k = 0; k < 4; ++k) {
        int x = i + dis[k], y = j + dis[k + 1];
        if (dfs_79(x, y, idx + 1, m, n, len, board, word))
            return true;
    }
    board[i][j] = t;
    return false;
}

int Solution::getMaximumGold(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), ret = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            if (!grid[i][j])
                continue;
            for (int k = 0; k < 4; ++k) {
                int x = i + dis[k], y = j + dis[k + 1];
                if (x < 0 || x == m || y < 0 || y == n || !grid[x][y]) {
                    ret = max(dfs_1219(grid, m, n, i, j),
                              ret); // 从边上进行 DFS 搜索，能快一些
                    break;
                }
            }
        }
    return ret;
}

int Solution::dfs_1219(vector<vector<int>>& grid, int m, int n, int x, int y) {
    int t = grid[x][y], ret = t;
    grid[x][y] = 0;
    for (int i = 0; i < 4; ++i) {
        int tx = x + dis[i], ty = y + dis[i + 1];
        if (tx >= 0 && tx < m && ty >= 0 && ty < n && grid[tx][ty])
            ret = max(ret, t + dfs_1219(grid, m, n, tx, ty));
    }
    grid[x][y] = t;
    return ret;
}

bool Solution::makesquare(vector<int>& matchsticks) {
    int sum = 0, mx = 0, len = matchsticks.size();
    for (auto& i : matchsticks) {
        sum += i;
        if (i > mx)
            mx = i;
    }
    int avg = sum >> 2;
    if (sum % 4 || mx > avg)
        return false;
    return dfs_473(matchsticks, len, 0, 0, 0, avg);
}

bool Solution::dfs_473(vector<int>& matchsticks, int len, int idx, int count,
                       int sum, int avg) {
    int t = matchsticks[idx], idx_t = idx;
    matchsticks[idx] = 0;
    sum += t;
    if (sum == avg) {
        if (count + 1 == 3)
            return true;
        if (dfs_473(matchsticks, len, 0, count + 1, 0, avg))
            return true;
    } else if (sum < avg)
        while (++idx < len) {
            if (!matchsticks[idx])
                continue; // 没有这个条件不通过，要跳过遍历过的节点
            if (dfs_473(matchsticks, len, idx, count, sum, avg))
                return true;
        }
    matchsticks[idx_t] = t;
    return false;
}

bool Solution::makesquare_(vector<int>& matchsticks) {
    int len = matchsticks.size(), sum = 0, mx = 0;
    for (auto& i : matchsticks) {
        sum += i;
        if (i > mx)
            mx = i;
    }
    int avg = sum >> 2;
    if (sum % 4 || mx > avg)
        return false;
    sort(matchsticks.begin(), matchsticks.end(), greater<int>()); // 逆序
    vector<int> edges(4);
    return dfs_473_(0, avg, len, matchsticks, edges);
}

bool Solution::dfs_473_(int idx, int avg, int len, vector<int>& matchsticks,
                        vector<int>& edges) {
    if (idx == len)
        return true;
    for (int i = 0; i < 4; ++i) {
        if (i && edges[i - 1] == edges[i])
            continue; // edges[i - 1] + matchsticks[idx] 失败，edges[i] 和
                      // edges[i - 1] 相等
        edges[i] += matchsticks[idx];
        if (edges[i] <= avg && dfs_473_(idx + 1, avg, len, matchsticks, edges))
            return true;
        edges[i] -= matchsticks[idx];
    }
    return false;
}

bool Solution::makesquare__(vector<int>& matchsticks) {
    int len = matchsticks.size(),
        sum = accumulate(matchsticks.begin(), matchsticks.end(), 0),
        avg = sum >> 2;
    int mx = *max_element(matchsticks.begin(), matchsticks.end());
    if (sum % 4 || mx > avg)
        return false;
    int total = 1 << len;
    vector<int> dp(total, -1);
    dp[0] = 0;
    for (int i = 1; i < total; ++i)
        for (int j = 0; j < len; ++j) {
            if ((i & 1 << j) == 0)
                continue;
            int t = i & ~(1 << j);
            if (dp[t] >= 0 && dp[t] + matchsticks[j] <= avg) {
                dp[i] = (dp[t] + matchsticks[j]) % avg;
                break;
            }
        }
    return dp[total - 1] == 0;
}

bool Solution::canPartitionKSubsets(vector<int>& nums, int k) {
    int len = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0),
        avg = sum / k;
    int mx = *max_element(nums.begin(), nums.end());
    if (sum % k || mx > avg)
        return false;
    int total = 1 << len;
    vector<int> dp(total, -1);
    dp[0] = 0;
    for (int i = 1; i < total; ++i)
        for (int j = 0; j < len; ++j) {
            if (!(i & 1 << j))
                continue;          // 跳过第 j 个数没有被放入的情形
            int t = i & ~(1 << j); // 第 j 个数没有被放入的情形
            if (dp[t] != -1 && dp[t] + nums[j] <= avg) {
                dp[i] = (dp[t] + nums[j]) % avg;
                break; // 找到就可以 break，没有这条件也能通过
            }
        }
    return dp[total - 1] == 0;
}

int Solution::minimumTimeRequired(vector<int>& jobs, int k) {
    int ret = inf, len = jobs.size();
    vector<int> edges(k);
    // sort(jobs.begin(), jobs.end(), greater<int>());
    sort(jobs.begin(),
         jobs.end()); // 注意这里应该正序排序而非逆序，这样能更快收敛，而且要和
                      // 973 行 break 一起使用才有效果
    ret = dfs_1723(jobs, edges, len, k, 0, ret);
    cout << count_dfs_1723 << endl;
    return ret;
}

int Solution::dfs_1723(vector<int>& jobs, vector<int>& edges, int len, int k,
                       int idx, int ret) {
    ++count_dfs_1723;
    if (idx == len) {
        ret = min(ret, *max_element(edges.begin(), edges.end()));
        return ret;
    }
    for (int i = 0; i < k; ++i) {
        if (edges[i] + jobs[idx] >= ret)
            continue; // 找到最小的 ret 值
        edges[i] += jobs[idx];
        ret = dfs_1723(jobs, edges, len, k, idx + 1, ret);
        edges[i] -= jobs[idx];
        if (edges[i] == 0) {
            cout << jobs[idx] << " ";
            break; // 这里的目的是 edges[0] 到 0 后不用再从 edges[1]
                   // 重新开始，否则有重复计算，同理适应于 edges[1]、edges[2] 等
        }
    }
    return ret;
}

int Solution::distributeCookies(vector<int>& cookies, int k) {
    int len = cookies.size();
    ret_2305 = inf;
    sort(cookies.begin(), cookies.end());
    vector<int> edges(k);
    dfs_2305(cookies, edges, 0, len, k);
    return ret_2305;
}

void Solution::dfs_2305(vector<int>& cookies, vector<int>& edges, int idx,
                        int len, int k) {
    if (idx == len)
        ret_2305 = min(ret_2305, *max_element(edges.begin(), edges.end()));
    else
        for (int i = 0; i < k; ++i) {
            if (edges[i] + cookies[idx] >= ret_2305)
                continue;
            edges[i] += cookies[idx];
            dfs_2305(cookies, edges, idx + 1, len, k);
            edges[i] -= cookies[idx];
            if (!edges[i])
                break;
        }
}

int Solution::longestIncreasingPath(vector<vector<int>>& matrix) {
    int ret = 1;
    m = matrix.size(), n = matrix[0].size();
    memo.resize(m, vector<int>(n, 0));
    this->matrix = matrix;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            ret = max(ret, dfs_329(i, j));
    return ret;
}

int Solution::dfs_329(int x, int y) {
    if (memo[x][y])
        return memo[x][y];
    int ret = 1;
    for (int i = 0; i < 4; ++i) {
        int tx = x + dis[i], ty = y + dis[i + 1];
        if (tx >= 0 && tx < m && ty >= 0 && ty < n &&
            matrix[tx][ty] > matrix[x][y])
            ret = max(ret, dfs_329(tx, ty) + 1);
    }
    memo[x][y] = ret;
    return ret;
}

int Solution::countPaths(vector<vector<int>>& grid) {
    m = grid.size(), n = grid[0].size();
    memo.resize(m, vector<int>(n, 0));
    matrix = grid;
    int sum = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            sum = (sum + dfs_2328(i, j)) % mod;
    return sum;
}

ull Solution::dfs_2328(int x, int y) {
    if (memo[x][y])
        return memo[x][y];
    int sum = 1;
    for (int i = 0; i < 4; ++i) {
        int tx = x + dis[i], ty = y + dis[i + 1];
        if (tx >= 0 && tx < m && ty >= 0 && ty < n &&
            matrix[tx][ty] > matrix[x][y])
            sum += dfs_2328(tx, ty) % mod; // 注意这里和 leetcode 329 的区别
    }
    memo[x][y] = sum;
    return sum;
}

bool Solution::canWin(string currentState) {
    len = currentState.size();
    return dfs_294(currentState);
}

bool Solution::dfs_294(string& currentState) {
    for (int i = 0; i < len - 1; ++i) {
        if (currentState[i] == '+' && currentState[i + 1] == '+') {
            currentState[i] = '-';
            currentState[i + 1] = '-';
            if (!dfs_294(currentState)) {
                currentState[i] = '+'; // 注意这里也要恢复！
                currentState[i + 1] = '+';
                return true;
            }
            currentState[i] = '+';
            currentState[i + 1] = '+';
        }
    }
    return false;
}

bool Solution::canWin_(string currentState) {
    len = currentState.size();
    ll mask = 0;
    for (int i = 0; i < len; ++i)
        if (currentState[i] == '+')
            mask |= 1ll << i; // 注意 1 要转换成 long long 类型
    dfs_294_(mask);
    return memo_294[mask];
}

void Solution::dfs_294_(ll mask) {
    for (int i = 0; i < len - 1; ++i)
        if (mask & 1ll << i && mask & 1ll << (i + 1)) {
            ll temp = mask ^ (1ll << i) ^ (1ll << (i + 1));
            if (!memo_294.count(temp))
                dfs_294_(temp);
            if (memo_294[temp])
                continue;
            memo_294[mask] = true;
            return;
        }
    memo_294[mask] = false;
}

bool Solution::canWin__(string currentState) {
    len = currentState.size();
    sg.resize(len + 1, -1);

    int ret = 0, i = 0;
    while (i < len) {
        int j = i;
        while (j < len && currentState[j] == '+')
            ++j;
        ret ^= win__(j - i); // 子状态异或
        i = j + 1;
    }
    return ret > 0; // 0 为败态，正整数为胜态
}

int Solution::win__(int i) {
    if (sg[i] != -1)
        return sg[i];
    vector<bool> vis(len);
    for (int j = 0; j < i - 1; ++j)
        vis[win__(j) ^ win__(i - j - 2)] = true; // 子状态异或
    for (int j = 0; j < len; ++j)
        if (!vis[j])
            return sg[i] = j; // vis 下表为 SG 值
    return 0;
}

int Solution::countRoutes(vector<int>& locations, int start, int finish,
                          int fuel) {
    len = locations.size();
    vector<vector<int>> fuels(len + 1, vector<int>(fuel + 1, -1)); // 记忆化搜索
    dfs_1575(start, finish, fuel, locations, fuels);
    return fuels[len][fuel];
}

void Solution::dfs_1575(int idx, int finish, int fuel, vector<int>& locations,
                        vector<vector<int>>& fuels) {
    int ret = idx == finish; // 判断 idx 是否等于 finish
    if (fuel < abs(locations[finish] - locations[idx])) // 肯定到不了的情况
    {
        fuels[idx][fuel] = 0;
        return;
    }
    for (int i = 0; i < len; ++i) {
        int sub = fuel - abs(locations[i] - locations[idx]);
        if (i == idx || sub < 0)
            continue;
        if (fuels[i][sub] == -1)
            dfs_1575(i, finish, sub, locations, fuels);
        ret = (ret + fuels[i][sub]) % mod;
    }
    fuels[idx][fuel] = ret;
}

int Solution::ways(vector<string>& pizza, int k) {
    m = pizza.size(), n = pizza[0].size();
    p.assign(m + 1, vector<int>(n + 1)); // 二维差分数组
    mem.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            p[i + 1][j + 1] = p[i + 1][j] + p[i][j + 1] - p[i][j];
            if (pizza[i][j] == 'A')
                ++p[i + 1][j + 1];
        }

    return dfs_1444(0, 0, k - 1);
}

int Solution::dfs_1444(int x, int y, int k) {
    if (mem[x][y][k] != -1)
        return mem[x][y][k];
    if (k == 0)
        return p[m][n] - p[m][y] - p[x][n] + p[x][y] > 0;
    int ret = 0;
    for (int i = x + 1; i < m; ++i)
        if (p[i][n] - p[i][y] - p[x][n] + p[x][y]) // 被切除的部分是否含有苹果
            ret = (ret + dfs_1444(i, y, k - 1)) % mod;
    for (int j = y + 1; j < n; ++j)
        if (p[m][j] - p[m][y] - p[x][j] + p[x][y])
            ret = (ret + dfs_1444(x, j, k - 1)) % mod;

    mem[x][y][k] = ret;
    return ret;
}

} // namespace s03
