/* 
n 名士兵站成一排。每个士兵都有一个 独一无二 的评分 rating 。

每 3 个士兵可以组成一个作战单位，分组规则如下：

从队伍中选出下标分别为 i、j、k 的 3 名士兵，他们的评分分别为 rating[i]、rating[j]、rating[k]
作战单位需满足： rating[i] < rating[j] < rating[k] 或者 rating[i] > rating[j] > rating[k] ，其中  0 <= i < j < k < n

 */
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numTeams(vector<int> &a)
    {
        int n = a.size();
        int ret = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                for (int k = j + 1; k < n; ++k)
                    if (a[i] < a[j] && a[j] < a[k] || a[i] > a[j] && a[j] > a[k])
                        ret++;
        return ret;
    }
};