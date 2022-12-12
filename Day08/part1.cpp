#include "../bits/stdc++.h"
using namespace std;
typedef long long ll;

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<vector<char>> map, temp;
        set<pair<int, int>> visibleTrees;
        string line;
        while (cin >> line)
        {
                vector<char> r(line.begin(), line.end());
                map.push_back(r);

                vector<int> vet(r.size(), 1);
        }

        for (int i = 0; i < (int)map.size(); i++)
        {
                char seen = map[0][i];
                visibleTrees.insert(make_pair(0, i));

                for (int j = 1; j < (int)map[i].size(); j++)
                {
                        if (map[j][i] > seen)
                        {
                                seen = map[j][i];
                                visibleTrees.insert(make_pair(j, i));
                        }
                }
                seen = map[map[i].size() - 1][i];
                visibleTrees.insert(make_pair(map[i].size() - 1, i));

                for (int j = map[i].size() - 2; j != -1; j--)
                {
                        if (map[j][i] > seen)
                        {
                                seen = map[j][i];
                                visibleTrees.insert(make_pair(j, i));
                        }
                }
        }

        for (int i = 0; i < (int)map.size(); i++)
        {
                char seen = map[i][0];
                visibleTrees.insert(make_pair(i, 0));

                for (int j = 1; j < (int)map[i].size(); j++)
                {
                        if (map[i][j] > seen)
                        {
                                seen = map[i][j];
                                visibleTrees.insert(make_pair(i, j));
                        }
                }
                seen = map[i][map[i].size() - 1];
                visibleTrees.insert(make_pair(i, map[i].size() - 1));
                for (int j = map[i].size() - 2; j != -1; j--)
                {
                        if (map[i][j] > seen)
                        {
                                seen = map[i][j];
                                visibleTrees.insert(make_pair(i, j));
                        }
                }
        }

        cout << visibleTrees.size() << endl;
        return 0;
}