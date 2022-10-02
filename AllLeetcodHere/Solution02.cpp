#include "Solution02.h"

void BinaryIndexedTree::update(int index, int value)
{
    while (index <= length)
    {
        v[index] += value;
        index += lowbit(index);
    }
}

int BinaryIndexedTree::query(int index)
{
    int sum = 0;
    while (index > 0)
    {
        sum += v[index];
        index -= lowbit(index);
    }
    return sum;
}

vector<int> Solution::getModifiedArray(int length, vector<vector<int> >& updates)
{
    vector<int> result(length, 0);
    for (auto it : updates)
    {
        result[it[0]] = it[2];
        if (it[1] + 1 < length) result[it[1]] -= it[2]; // 差分数组
    }
    for (int i = 1; i < length; ++i) result[i] += result[i - 1];
    return result;
}

vector<int> Solution::getModifiedArray_(int length, vector<vector<int> >& updates)
{
    BinaryIndexedTree* bitree = new BinaryIndexedTree(length);
    for (auto it : updates)
    {
        int start = it[0], end = it[1], inc = it[2];
        bitree->update(start + 1, inc);
        bitree->update(end + 2, -inc);
    }
    vector<int> result;
    for (int i = 0; i < length; ++i)
        result.push_back(bitree->query(i + 1));
    delete bitree;
    return result;
}

bool Solution::possibleToStamp(vector<vector<int> >& grid, int stampHeight, int stampWidth)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int> > sums1(m + 1, vector<int>(n + 1));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            sums1[i + 1][j + 1] = sums1[i][j + 1] + sums1[i + 1][j] - sums1[i][j] + grid[i][j];
    vector<vector<int> > sums2(m + 1, vector<int>(n + 1));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
        {
            int x = i + stampHeight, y = j + stampWidth;
            if (x <= m && y <= n && sums1[x][y] - sums1[i][y] - sums1[x][j] + sums1[i][j] == 0)
            {
                sums2[i][j] += 1;
                sums2[x][j] -= 1;
                sums2[i][y] -= 1;
                sums2[x][y] += 1;
            }
        }
    vector<vector<int> > sums3(m + 1, vector<int>(n + 1));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
        {
            sums3[i + 1][j + 1] = sums3[i + 1][j] + sums3[i][j + 1] - sums3[i][j] + sums2[i][j];
            if (sums3[i + 1][j + 1] == 0 && grid[i][j] == 0) return false;
        }
    return true;
}

int Solution::lengthOfLongestSubstring(string s)
{
    int len = s.length(), count = 0, left = 0;
    unordered_set<char> chars;
    for (int i = 0; i < len; ++i)
    {
        while (chars.find(s[i]) != chars.end())
            chars.erase(s[left++]);
        chars.insert(s[i]);
        count = max(count, i - left + 1);   // 不用写为(int)chars.size()
    }
    return count;
}

int Solution::numSubarrayProductLessThanK(vector<int>& nums, int k)
{
    //auto f = [](int x)->int   // 不需要
    //{
    //    return x * (x + 1) / 2;
    //};
    int len = nums.size(), l = 0, r = 0, acc = 1, sum = 0, temp;
    for (l = 0, r = 0; l < len && r < len;)
        if (nums[r] >= k && l == r) // 注意 l == r
        {
            ++r;
            l = r;
            acc = 1;
        }
        else
        {
            acc *= nums[r];
            temp = l;
            while (acc >= k)
                acc /= nums[l++];
            //if (temp != l)
            //    sum += f(l - temp + r - l) - f(r - l);
            sum += r - l + 1;   // 效率更高
            ++r;
        }
    //sum += f(r - l);
    return sum;
}

int Solution::numSubarrayProductLessThanK_(vector<int>& nums, int k)
{
    int len = nums.size(), acc = 1, sum = 0;
    for (int r = 0, l = 0; r < len; ++r)
    {
        acc *= nums[r];
        while (l <= r && acc >= k)
        {
            acc /= nums[l];
            ++l;
        }
        sum += r - l + 1;
    }
    return sum;
}

int Solution::hammingWeight(uint32_t n)
{
    int count = 0;
    while (n > 0)
    {
        if (n % 2 == 1)
            ++count;
        n /= 2;
    }
    return count;
}

int Solution::hammingWeight_(uint32_t n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int Solution::hammingWeight__(uint32_t n)
{
    int count = 0;
    while (n)
    {
        ++count;
        n &= n - 1; // 或 n -= (n & -n);
    }
    return count;
}

vector<vector<int> > Solution::merge(vector<vector<int> >& intervals)
{
    int len = intervals.size();
    vector<vector<int> > result;
    for (auto i = intervals.begin(); i != intervals.end(); ++i)
        for (auto j = i + 1; j != intervals.end(); ++j)
            if ((*j)[1] >= (*i)[0] && (*j)[0] <= (*i)[1])
            {
                (*j)[0] = min((*i)[0], (*j)[0]);
                (*j)[1] = max((*i)[1], (*j)[1]);
                (*i)[0] = inf;
                break;
            }
    for (auto i = intervals.begin(); i != intervals.end(); ++i)
        if ((*i)[0] != inf)
            result.push_back(*i);
    return result;
}

vector<vector<int> > Solution::merge_(vector<vector<int> >& intervals)
{
    int len = intervals.size();
    vector<vector<int> > result;
    sort(intervals.begin(), intervals.end());   // #include <algorithm>
    int st = intervals[0][0], ed = intervals[0][1], s, e;   // 先排序，后遍历合并
    for (auto i = ++intervals.begin(); i != intervals.end(); ++i)
    {
        s = (*i)[0], e = (*i)[1];
        if (s > ed)
        {
            result.push_back({ st, ed });
            st = s, ed = e;
        }
        else
            ed = max(ed, e);
    }
    result.push_back({ st, ed });
    return result;
}

vector<int> Solution::dailyTemperatures(vector<int>& temperatures)
{
    int len = temperatures.size();
    vector<int> result(len);
    stack<pair<int, int> > temp;
    for (int i = 0; i < len; ++i)
    {
        while (!temp.empty())
            if (temp.top().first >= temperatures[i])
            {
                temp.push({ temperatures[i], i });
                break;
            }
            else
            {
                result[temp.top().second] = i - temp.top().second;
                temp.pop();
            }
        if (temp.empty())
            temp.push({ temperatures[i], i });
    }
    while (!temp.empty())
    {
        result[temp.top().second] = 0;  // 不需要，vector 默认初始化值为 0
        temp.pop();
    }
    return result;
}

vector<int> Solution::dailyTemperatures_(vector<int>& temperatures)
{
    int len = temperatures.size();
    vector<int> result(len);
    stack<int> temp;    // 只存索引
    for (int i = 0; i < len; ++i)
    {
        while (!temp.empty() && temperatures[i] > temperatures[temp.top()])
        {
            int t = temp.top();
            result[t] = i - t;
            temp.pop();
        }
        temp.push(i);
    }
    return result;
}
