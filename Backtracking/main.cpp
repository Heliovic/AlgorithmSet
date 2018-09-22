#include <cstdio>
#include <algorithm>

#define PROBLEM_N 6

using namespace std;

int P[PROBLEM_N + 1];

bool check(int k)   // ��� k ��������ܲ��ܷ���
{
    for (int i = 1; i < k; i++) // ����ǰ k - 1 �����
    {
        if (P[i] == P[k] || // ��ͬһ�У�Ҳ�����ô����
            abs(i - k) == abs(P[i] - P[k])) // ��ͬһб��
            return false;
    }
    return true;
}

// n �ʺ�����ݹ���ݷ�
void gen_j(int j)
{
    if (j == PROBLEM_N + 1)
    {
        for (int i = 1; i <= PROBLEM_N; i++)
            printf("%d ", P[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= PROBLEM_N; i++)
    {
        P[j] = i;
        if (check(j))
            gen_j(j + 1);
        else
            continue;
    }
}

int main()
{
    gen_j(1);
    return 0;
}
