/* 给你两个长度为 n 的字符串 s1 和 s2 ，以及一个字符串 evil 。请你返回 好字符串 的数目。

好字符串 的定义为：它的长度为 n ，字典序大于等于 s1 ，字典序小于等于 s2 ，且不包含 evil 为子字符串。

由于答案可能很大，请你返回答案对 10^9 + 7 取余的结果。

输入：n = 2, s1 = "aa", s2 = "da", evil = "b"
输出：51 
解释：总共有 25 个以 'a' 开头的好字符串："aa"，"ac"，"ad"，...，"az"。还有 25 个以 'c' 开头的好字符串："ca"，"cc"，"cd"，...，"cz"。最后，还有一个以 'd' 开头的好字符串："da"。
 */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    const int MOD = 1000000007;
    int findGoodStrings(int n, string a, string b, string s)
    {
        if (a > b)
            return 0;

        int m = s.size();
        vector<int> fail(m + 1);
        for (int i = 2; i <= m; ++i)
        {
            int j = fail[i - 1];
            while (j && s[j + 1 - 1] != s[i - 1])
                j = fail[j];
            fail[i] = s[j + 1 - 1] == s[i - 1] ? j + 1 : 0;
        }
        vector<vector<int>> next(m + 1, vector<int>(26));
        for (int i = 0; i < m; ++i)
            for (int c = 0; c < 26; ++c)
            {
                int j = i;
                while (j && s[j + 1 - 1] != c + 'a')
                    j = fail[j];
                next[i][c] = s[j + 1 - 1] == c + 'a' ? j + 1 : 0;
            }

        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        for (int j = 0; j < m; ++j)
            f[0][j] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                f[i][j] = 0;
                for (int c = 0; c < 26; ++c)
                {
                    (f[i][j] += f[i - 1][next[j][c]]) %= MOD;
                }
                //printf("%d ", f[i][j]);
            }
            //puts("");
        }

        auto go = [&](string s, int flag) {
            int cur = 0;
            int ret = 0;
            for (int i = 0; i < n; ++i)
            {
                for (int c = 0; c < s[i] - 'a'; ++c)
                {
                    (ret += f[n - i - 1][next[cur][c]]) %= MOD;
                }
                cur = next[cur][s[i] - 'a'];
                if (cur == m)
                    break;
            }
            if (flag && cur != m)
                ret++;
            ret %= MOD;
            return ret;
        };

        int nb = go(b, 1);
        //printf("nb = %d\n", nb);
        int na = go(a, 0);
        //printf("na = %d\n", na);
        return (nb - na + MOD) % MOD;
    }
};