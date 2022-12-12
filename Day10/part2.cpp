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
    int signal = 40;
    int sum = 0;
    cout << "Cycle " << 1 << "\t\t -> ";
    while (cin >> s)
    {
        // cout << cycles << endl;
        if (s == "noop")
        {
            // cout << "Extra cycle yay" << endl;
            cycles++;
            if (cycles % 40 == X || cycles % 40 == (X + 1) || cycles % 40 == (X + 2))
            {
                cout << "#";
            }
            else
            {
                cout << ".";
            }
            if (cycles == signal)
            {
                // cout << "Cycle " << cycles << "th :" << X * cycles << endl;
                cout << "<- Cycle " << signal << endl;
                cout << "Cycle " << signal + 1 << "\t -> ";
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
                if (cycles % 40 == X || cycles % 40 == (X + 1) || cycles % 40 == (X + 2))
                {
                    cout << "#";
                }
                else
                {
                    cout << ".";
                }
                if (cycles == signal)
                {
                    // cout << "Cycle " << cycles << "th :" << X * cycles << endl;
                    cout << "<- Cycle " << signal << endl;
                    cout << "Cycle " << signal + 1 << "\t -> ";
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