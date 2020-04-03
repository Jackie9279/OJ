#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct paper
{
    vector<int> id;
    vector<string> q1;
    vector<string> q2;
    vector<string> q3;
};
bool check(string *p1, string *p2)
{
    int flag = 0;
    int len1 = (*p1).size();
    int len2 = (*p2).size();
    int minlen = len1 > len2 ? len2 : len1;
    for (size_t i = 0; i < minlen; i++)
    {
        if (p1[i] == p2[i])
        {
            flag++;
        }
    }
    return flag > minlen * 0.5;
}
int main()
{
    int t;
    paper q;
    int flag = 0;
    cin >> t;
    int id;
    string qq1;
    string qq2;
    string qq3;
    for (int i = 0; i < t; ++i)
    {
        cin >> id >> qq1 >> qq2 >> qq3;
        q.id.push_back(id);
        q.q1.push_back(qq1);
        q.q2.push_back(qq2);
        q.q3.push_back(qq3);
    }
    for (size_t i = 0; i < q.q1.size() - 1; i++)
    {
        for (size_t j = 0; j < q.q1.size() - 1 - i; j++)
        {
            if (check(&q.q1[j], &q.q1[j + 1]))
            {
                cout << q.id[j] << " " << q.id[j + 1] << " "
                     << "1";
            }
        }
    }
    for (size_t i = 0; i < q.q2.size() - 1; i++)
    {
        for (size_t j = 0; j < q.q2.size() - 1 - i; j++)
        {
            if (check(&q.q2[j], &q.q2[j + 1]))
            {
                cout << q.id[j] << " " << q.id[j + 1] << " "
                     << "2";
            }
        }
    }
    for (size_t i = 0; i < q.q3.size() - 1; i++)
    {
        for (size_t j = 0; j < q.q3.size() - 1 - i; j++)
        {
            if (check(&q.q3[j], &q.q3[j + 1]))
            {
                cout << q.id[j] << " " << q.id[j + 1] << " "
                     << "3";
            }
        }
    }
}