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

int Solution::sumSubarrayMins(vector<int>& arr)
{
    int len = arr.size();
    vector<int> left(len, -1), right(len, len);
    stack<int> temp;
    for (int i = 0; i < len; ++i)
    {
        while (!temp.empty() && arr[temp.top()] >= arr[i])
            temp.pop();
        if (!temp.empty())
            left[i] = temp.top();
        temp.push(i);
    }
    temp = stack<int>();
    for (int i = len - 1; i >= 0; --i)
    {
        while (!temp.empty() && arr[temp.top()] > arr[i])
            temp.pop();
        if (!temp.empty())
            right[i] = temp.top();
        temp.push(i);
    }
    long sum = 0;
    for (int i = 0; i < len; ++i)
        sum += (long)(i - left[i]) * (right[i] - i) * arr[i];
    return sum % (int)(1e9 + 7);
}

int Solution::maxWidthRamp(vector<int>& nums)
{
    int len = nums.size(), width = 0;
    vector<pair<int, int> > v;
    for (int i = 0; i < len; ++i)
        v.push_back({ nums[i], i });
    sort(v.begin(), v.end());
    int temp = v[0].second;
    for (int i = 1; i < len; ++i)
        if (v[i].second > temp)
            width = max(width, v[i].second - temp);
        else
            temp = v[i].second;
    return width;
}

int Solution::maxWidthRamp_(vector<int>& nums)
{
    int len = nums.size(), width = 0;
    stack<int> temp;
    temp.push(0);
    for (int i = 1; i < len; ++i)
        if (nums[i] < nums[temp.top()]) // 所有可能的 i 构成的子序列一定是单调递减的
            temp.push(i);
    for (int i = len - 1; i; --i)
    {
        while (!temp.empty() && nums[i] >= nums[temp.top()])
        {
            width = max(width, i - temp.top());
            temp.pop();
        }
        if (temp.empty())
            break;
    }
    return width;
}

int Solution::maxChunksToSorted(vector<int>& arr)
{
    int len = arr.size(), count = 0;
    stack<int> temp;
    temp.push(0);
    for (int i = 1; i < len; ++i)
        if (arr[i] >= arr[temp.top()])
            temp.push(i);   // 非严格递增的单调栈
    for (int i = len - 1; i; --i)
        if (i == temp.top())
        {
            temp.pop();
            ++count;    // 遇到自己加 1
        }
        else
        {
            int t = temp.top();
            temp.pop();
            while (!temp.empty() && arr[i] < arr[temp.top()])   // 和 top 下面的元素比较大小
            {
                t = temp.top();
                temp.pop();
            }
            temp.push(t);
        }
    return count + 1;
}

int Solution::maxChunksToSorted_(vector<int>& arr)
{
    stack<int> temp;
    for (auto& i : arr)
        if (temp.empty() || temp.top() <= i)
            temp.push(i);
        else
        {
            int t = temp.top();
            temp.pop();
            while (!temp.empty() && temp.top() > i) // 遇到比 top 下面的元素小的值就弹掉这个元素
                temp.pop();
            temp.push(t);
        }
    return temp.size();
}

long long Solution::subArrayRanges(vector<int>& nums)
{
    int len = nums.size();
    vector<int> leftMax(len, -1), leftMin(len, -1), rightMax(len, len), rightMin(len, len);
    stack<int> tempMax, tempMin;
    for (int i = 0; i < len; ++i)
    {
        while (!tempMax.empty() && nums[tempMax.top()] < nums[i])
            tempMax.pop();
        if (!tempMax.empty())
            leftMax[i] = tempMax.top();
        tempMax.push(i);
        while (!tempMin.empty() && nums[tempMin.top()] >= nums[i])  // 注意等号要出现在一边
            tempMin.pop();
        if (!tempMin.empty())
            leftMin[i] = tempMin.top();
        tempMin.push(i);
    }
    tempMax = stack<int>();
    tempMin = stack<int>();
    for (int i = len - 1; i >= 0; --i)
    {
        while (!tempMax.empty() && nums[tempMax.top()] <= nums[i])
            tempMax.pop();
        if (!tempMax.empty())
            rightMax[i] = tempMax.top();
        tempMax.push(i);
        while (!tempMin.empty() && nums[tempMin.top()] > nums[i])
            tempMin.pop();
        if (!tempMin.empty())
            rightMin[i] = tempMin.top();
        tempMin.push(i);
    }
    long long sum = 0;
    for (int i = 0; i < len; ++i)
        sum += (long long)nums[i] * ((rightMax[i] - i) * (i - leftMax[i]) - (rightMin[i] - i) * (i - leftMin[i]));
    return sum;
}

int Solution::maxSumMinProduct(vector<int>& nums)
{
    int len = nums.size();
    vector<int> leftMin(len, -1), rightMin(len, len);
    stack<int> temp;
    for (int i = 0; i < len; ++i)
    {
        while (!temp.empty() && nums[temp.top()] >= nums[i])
            temp.pop();
        if (!temp.empty())
            leftMin[i] = temp.top();
        temp.push(i);
    }
    temp = stack<int>();
    for (int i = len - 1; i >= 0; --i)
    {
        while (!temp.empty() && nums[temp.top()] >= nums[i])
            temp.pop();
        if (!temp.empty())
            rightMin[i] = temp.top();
        temp.push(i);
    }

    vector<long> prefixSums(len + 1);
    for (int i = 1; i <= len; ++i)
        prefixSums[i] += prefixSums[i - 1] + nums[i - 1];   // 前缀和 *

    long result = 0;
    for (int i = 0; i < len; ++i)
        result = max(result, (long)(prefixSums[rightMin[i]] - prefixSums[leftMin[i] + 1]) * nums[i]);
    return result % (int)(1e9 + 7);
}

vector<int> Solution::maxSlidingWindow(vector<int>& nums, int k)
{
    int len = nums.size();
    vector<int> result, leftMax(len, -1), rightMax(len, len);
    stack<int> temp;
    for (int i = 0; i < len; ++i)
    {
        while (!temp.empty() && nums[temp.top()] < nums[i])
            temp.pop();
        if (!temp.empty())
            leftMax[i] = i - temp.top() > k ? i - k : temp.top();
        else if (i + 1 > k)
            leftMax[i] = i - k;
        temp.push(i);
    }
    temp = stack<int>();
    for (int i = len - 1; i >= 0; --i)
    {
        while (!temp.empty() && nums[temp.top()] <= nums[i])
            temp.pop();
        if (!temp.empty())
            rightMax[i] = temp.top() - i > k ? i + k : temp.top();
        else if (len - i > k)
            rightMax[i] = i + k;
        temp.push(i);
    }
    for (int i = 0; i < len; ++i)
    {
        if (rightMax[i] - leftMax[i] <= k)
            continue;
        for (int j = 0; j < rightMax[i] - leftMax[i] - k; ++j)
            result.push_back(nums[i]);
    }
    return result;
}

vector<int> Solution::maxSlidingWindow_(vector<int>& nums, int k)
{
    int len = nums.size();
    deque<int> q;   // 双端队列
    vector<int> result;
    for (int i = 0; i < len; ++i)   // 单调队列
    {
        if (!q.empty() && q.front() < i - k + 1)
            q.pop_front();
        while (!q.empty() && nums[q.back()] <= nums[i])
            q.pop_back();
        q.push_back(i);
        if (i >= k - 1)
            result.push_back(nums[q.front()]);
    }
    return result;
}

int Solution::findMaxValueOfEquation(vector<vector<int> >& points, int k)
{
    int len = points.size(), result = -0x3f3f3f3f;
    deque<int> q;
    for (int i = 0; i < len; ++i)
    {
        while (!q.empty() && points[i][0] - points[q.front()][0] > k)
            q.pop_front();
        if (!q.empty())
        {
            result = max(result, points[i][0] - points[q.front()][0] + points[i][1] + points[q.front()][1]);    // 和单调队列最大值相加并更新
            while (!q.empty() && points[i][0] - points[q.back()][0] + points[q.back()][1] <= points[i][1])  // 递减的单调队列
                q.pop_back();
        }
        q.push_back(i);
    }
    return result;
}

int Solution::findMaxValueOfEquation_(vector<vector<int> >& points, int k)
{
    int result = -0x3f3f3f3f;
    deque<vector<int> > q;
    for (auto& item : points)
    {
        int x = item[0], y = item[1];
        while (!q.empty() && x - q.front()[0] > k)
            q.pop_front();
        if (!q.empty())
            result = max(result, x - q.front()[0] + y + q.front()[1]);
        while (!q.empty() && y >= q.back()[1] + x - q.back()[0])
            q.pop_back();
        q.push_back(item);
    }
    return result;
}

int Solution::shortestSubarray(vector<int>& nums, int k)
{
    int len = nums.size(), result = inf;
    vector<long> prefixSums(len + 1);
    for (int i = 0; i < len; ++i)
        prefixSums[i + 1] += prefixSums[i] + nums[i];   // 前缀和
    deque<int> q;
    for (int i = 0; i <= len; ++i)
    {
        while (!q.empty() && prefixSums[i] - prefixSums[q.front()] >= k)
        {
            result = min(result, i - q.front());
            q.pop_front();
        }
        while (!q.empty() && prefixSums[i] <= prefixSums[q.back()]) // 递增的单调队列
            q.pop_back();
        q.push_back(i);
    }
    return result == inf ? -1 : result;
}

int Solution::constrainedSubsetSum(vector<int>& nums, int k)
{
    int len = nums.size(), result = -inf;
    vector<int> dp(len);
    deque<int> q;
    for (int i = 0; i < len; ++i)
    {
        if (!q.empty() && i - q.front() > k)
            q.pop_front();
        dp[i] = max(0, q.empty() ? 0 : dp[q.front()]) + nums[i];
        result = max(result, dp[i]);
        while (!q.empty() && dp[q.back()] <= dp[i])
            q.pop_back();
        q.push_back(i);
    }
    return result;
}
