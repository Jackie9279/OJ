#include <iostream>
using namespace std;

struct Exam
{
	int studentID;
	char ans1[20];
	char ans2[20];
	char ans3[20];
};

bool judge(char *&pA, char *&pB)
{
	int flag = 0, len = 0;
	while (*pA != '\0' && *pB != '\0')
	{
		if (*pA == *pB)
			flag++;
		pA++, pB++, len++;
	}
	return flag >= 0.9 * len;
}

int compare(Exam *A, Exam *B)
{
	char *pA = A->ans1;
	char *pB = B->ans1;
	if (judge(pA, pB))
		return 1;
	pA = A->ans2;
	pB = B->ans2;
	if (judge(pA, pB))
		return 2;
	pA = A->ans3;
	pB = B->ans3;
	if (judge(pA, pB))
		return 3;
	return 0;
}

int main()
{
	int t;
	cin >> t;
	Exam papers[20];
	for (int i = 0; i < t; i++)
		cin >> papers[i].studentID >> papers[i].ans1 >> papers[i].ans2 >> papers[i].ans3;
	for (int i = 0; i < t - 1; i++)
	{
		for (int j = i + 1; j < t; j++)
		{
			int res = compare(papers + i, papers + j);
			if (res != 0)
				cout << papers[i].studentID << " " << papers[j].studentID << " " << res << endl;
		}
	}
	return 0;
}