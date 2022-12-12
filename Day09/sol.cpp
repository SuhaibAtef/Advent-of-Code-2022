#include "../bits/stdc++.h"
using namespace std;
typedef long long ll;

pair<int, int> comparePair(pair<int, int> &H, pair<int, int> &T)
{
    if (H.first == T.first && H.second == T.second)
    {
        // cout << "Covers each other" << endl;
    }
    else if (abs(H.first - T.first) + abs(H.second - T.second) <= 1)
    {
        // cout << "No Move" << endl;
    }
    else if (abs(H.first - T.first) + abs(H.second - T.second) == 2)
    {
        if (H.first - T.first < 0)
            T.first = T.first - abs(H.first - T.first) / 2;
        else
            T.first = T.first + abs(H.first - T.first) / 2;

        if (H.second - T.second > 0)
            T.second = T.second + abs(H.second - T.second) / 2;
        else
            T.second = T.second - abs(H.second - T.second) / 2;
    }
    else if (abs(H.first - T.first) + abs(H.second - T.second) > 2)
    {
        if (H.first - T.first < 0)
            T.first = T.first - 1;
        else
            T.first = T.first + 1;

        if (H.second - T.second > 0)
            T.second = T.second + 1;
        else
            T.second = T.second - 1;
    }
    return (make_pair(T.first, T.second));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>> map;
    pair<int, int> T[10];
    set<pair<int, int>> solution;
    solution.insert(make_pair(0, 0));
    char move;
    int amount;

    for (int i = 0; i < 10; i++)
    {
        T[i] = make_pair(0, 0);
    }

    while (cin >> move >> amount)
    {
        int xDirection = 0;
        int yDirection = 0;
        if (move == 'R')
        {
            xDirection = 1;
        }
        else if (move == 'U')
        {
            yDirection = -1;
        }
        else if (move == 'L')
        {
            xDirection = -1;
        }
        else if (move == 'D')
        {
            yDirection = 1;
        }
        for (int i = amount; i > 0; i--)
        {
            xDirection = 0;
            yDirection = 0;
            if (move == 'R')
            {
                xDirection = 1;
            }
            else if (move == 'U')
            {
                yDirection = -1;
            }
            else if (move == 'L')
            {
                xDirection = -1;
            }
            else if (move == 'D')
            {
                yDirection = 1;
            }
            T[0].first = T[0].first + yDirection;
            T[0].second = T[0].second + xDirection;
            for (int j = 1; j < 10; j++)
            {
                int yOld = T[j].second;
                int xOld = T[j].first;

                T[j] = comparePair(T[j - 1], T[j]);
                yDirection = yOld - T[j].second;
                xDirection = T[j].first - xOld;
            }
            // cout << T[0].first << T[0].second << endl;
            solution.insert(T[9]);
        }
    }
    cout << solution.size() << endl;
    return 0;
}