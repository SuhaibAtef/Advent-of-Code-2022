#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int R;
    int cycles = 0;
    int X = 1;
    int signal = 20;
    int sum = 0;
    while (cin >> s)
    {
        // cout << cycles << endl;
        if (s == "noop")
        {
            // cout << "Extra cycle yay" << endl;
            cycles++;
            if (cycles == signal)
            {
                cout << "Cycle " << cycles << "th :" << X * cycles << endl;
                signal += 40;
                sum += X * cycles;
            }
        }
        else
        {
            cin >> R;

            for (int i = 0; i < 2; i++)
            {
                cycles++;
                if (cycles == signal)
                {
                    cout << "Cycle " << cycles << "th :" << X * cycles << endl;
                    signal += 40;
                    sum += X * cycles;
                }
            }
            X += R;
        }
    }
    cout << sum << endl;
    return 0;
}