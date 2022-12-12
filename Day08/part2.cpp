#include "../bits/stdc++.h"
using namespace std;
typedef long long ll;

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<vector<char>> map, temp;
        vector<vector<int>> temp2;
        set<pair<int, int>> visibleTrees;
        string line;
        while (cin >> line)
        {
                vector<char> r(line.begin(), line.end());
                map.push_back(r);
                temp.push_back(r);
                vector<int> vet(r.size(), 1);
                temp2.push_back(vet);
        }
        int ans = 0;
        for (int i = 0; i < (int)map.size(); i++)
        {
                for (int j = 0; j < (int)map[i].size(); j++)
                {
                        temp2[i][j] = 0;
                        int t1s = 0, t2s = 0, t3s = 0, t4s = 0;
                        for (int k = (i + 1); k < (int)map.size(); k++)
                        {
                                t1s++;
                                if (map[i][j] <= map[k][j])
                                        break;
                        }

                        for (int k = (i - 1); k > -1; k--)
                        {
                                t2s++;
                                if (map[i][j] <= map[k][j])
                                        break;
                        }

                        for (int k = (j + 1); k < (int)map[i].size(); k++)
                        {
                                t3s++;
                                if (map[i][j] <= map[i][k])
                                        break;
                        }

                        for (int k = (j - 1); k > -1; k--)
                        {
                                t4s++;
                                if (map[i][j] <= map[i][k])
                                        break;
                        }

                        temp2[i][j] = t1s * t2s * t3s * t4s;
                        ans = max(ans, temp2[i][j]);
                }
        }
        cout << ans << endl;
        // for (int i = 0; i < (int)map.size(); i++)
        // {
        //         char seen = map[0][i];
        //         visibleTrees.insert(make_pair(0, i));
        //         temp[0][i] = 'v';
        //         temp2[0][i] = 0;
        //         for (int j = 1; j < (int)map[i].size(); j++)
        //         {
        //                 if (map[j][i] > seen)
        //                 {
        //                         seen = map[j][i];
        //                         visibleTrees.insert(make_pair(j, i));
        //                         temp[j][i] = 'v';
        //                         temp2[j][i] *= j;
        //                 }

        //                 else
        //                 {
        //                         // break;
        //                 }
        //         }
        //         seen = map[map[i].size() - 1][i];
        //         visibleTrees.insert(make_pair(map[i].size() - 1, i));
        //         temp[map[i].size() - 1][i] = 'v';
        //         temp2[map[i].size() - 1][i] = 0;
        //         for (int j = map[i].size() - 2; j != -1; j--)
        //         {
        //                 if (map[j][i] > seen)
        //                 {
        //                         seen = map[j][i];
        //                         visibleTrees.insert(make_pair(j, i));
        //                         temp[j][i] = 'v';
        //                         temp2[j][i] *= map[i].size() - j - 1;
        //                 }
        //                 else
        //                 {
        //                         // break;
        //                 }
        //         }
        // }
        // // Print Map
        // for (int i = 0; i < (int)map.size(); i++)
        // {
        //         char seen = map[i][0];
        //         visibleTrees.insert(make_pair(i, 0));
        //         temp[i][0] = 'v';
        //         temp2[i][0] = 0;
        //         for (int j = 1; j < (int)map[i].size(); j++)
        //         {
        //                 if (map[i][j] > seen)
        //                 {
        //                         seen = map[i][j];
        //                         visibleTrees.insert(make_pair(i, j));
        //                         temp[i][j] = 'v';
        //                         temp2[i][j] *= j - 1;
        //                 }

        //                 else
        //                 {
        //                         // break;
        //                 }
        //         }
        //         seen = map[i][map[i].size() - 1];
        //         visibleTrees.insert(make_pair(i, map[i].size() - 1));
        //         temp[i][map[i].size() - 1] = 'v';
        //         temp2[i][map[i].size() - 1] = 0;
        //         for (int j = map[i].size() - 2; j != -1; j--)
        //         {
        //                 if (map[i][j] > seen)
        //                 {
        //                         seen = map[i][j];
        //                         visibleTrees.insert(make_pair(i, j));
        //                         temp[i][j] = 'v';
        //                         temp2[i][j] *= (map[i].size() - j);
        //                 }

        //                 else
        //                 {
        //                         // break;
        //                 }
        //         }
        // }

        cout << visibleTrees.size() << endl;
        return 0;
}