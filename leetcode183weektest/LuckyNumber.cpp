/* 
在整数数组中，如果一个整数的出现频次和它的数值大小相等，我们就称这个整数为「幸运数」。

给你一个整数数组 arr，请你从中找出并返回一个幸运数。

如果数组中存在多个幸运数，只需返回 最大 的那个。
如果数组中不含幸运数，则返回 -1 。 

*/
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> res;
        for (auto ele : arr)
        {
            res[ele]++;
        }
        int ans = -1;
        for (auto [a, b] : res)
            if (a == b)
            {
                ans = max(ans, a);
            }
        return ans;
    }
};