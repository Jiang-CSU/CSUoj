// 有点nb的方法，量化为分数
// 为什么这样写？
// 关键是设计一个不会冲突的分数体系。
// 牌型	分数范围	比较规则
// 豹子	302～307	比较豹子点数优先级
// 对子	222～277	先比较对子，再比较单骰
// 点子	6～15	比较三个点数之和
// 例如：
// - 1 1 1：307 分
// - 6 6 6：306 分
// - 1 1 6：276 分
// - 6 6 1：267 分
// - 4 5 6：15 分
#include <stdio.h>

int getScore(int a, int b, int c)
{
    int count[7] = {0};
    int dice[] = {a, b, c};

    for (int i = 0; i < 3; i++)
    {
        count[dice[i]]++;
    }

    // 1 最大，其次 6、5、4、3、2
    int value[7] = {0, 7, 2, 3, 4, 5, 6};

    // 豹子
    for (int i = 1; i <= 6; i++)
    {
        if (count[i] == 3)
        {
            return 300 + value[i];
        }
    }

    // 对子
    for (int i = 1; i <= 6; i++)
    {
        if (count[i] == 2)
        {
            for (int j = 1; j <= 6; j++)
            {
                if (count[j] == 1)
                {
                    return 200 + value[i] * 10 + value[j];
                }
            }
        }
    }

    // 点子
    return a + b + c;
}

int main(void)
{
    int K;
    scanf("%d", &K);

    while (K--)
    {
        int l1, l2, l3;
        int Y1, Y2, Y3;

        scanf("%d %d %d", &l1, &l2, &l3);
        scanf("%d %d %d", &Y1, &Y2, &Y3);

        int scoreL = getScore(l1, l2, l3);
        int scoreY = getScore(Y1, Y2, Y3);

        if (scoreL > scoreY)
        {
            printf("lcy\n");
        }
        else if (scoreL < scoreY)
        {
            printf("Ypop\n");
        }
        else
        {
            printf("Draw\n");
        }
    }

    return 0;
}