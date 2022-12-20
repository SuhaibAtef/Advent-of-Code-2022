#include "./../bits/stdc++.h"
using namespace std;
typedef long long ll;
struct Monkey
{
    intmax_t number;
    queue<unsigned long long> startingItems;
    char operation;
    intmax_t changeValue;
    intmax_t testValue;
    intmax_t trueMonkey;
    intmax_t falseMonkey;
    intmax_t counter;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<Monkey> monkeys;
    string s;
    while (getline(cin, s))
    {
        if (s == "")
            continue;
        Monkey m;
        m.counter = 0;
        m.number = s[7] - 48;
        cout << m.number << endl;
        getline(cin, s);
        s = s.substr(17);
        replace(s.begin(), s.end(), ',', ' ');
        // cout << s << endl;
        stringstream stream(s);
        unsigned long long n;
        while (stream >> n)
        {
            m.startingItems.push(n);
        }
        getline(cin, s);
        s = s.substr(22);
        m.operation = s[1];
        if (s.find("old") != string::npos)
        {

            m.changeValue = 69420;
        }
        else
        {
            m.changeValue = stoi(s.substr(2));
        }
        // cout << m.operation << endl;
        // cout << m.changeValue << endl;
        getline(cin, s);
        s = s.substr(s.find("by") + 2);
        m.testValue = stoi(s);
        // cout << m.testValue << endl;
        getline(cin, s);
        s = s.substr(s.find("monkey") + 6);
        m.trueMonkey = stoi(s);
        // cout << m.trueMonkey << endl;
        getline(cin, s);
        s = s.substr(s.find("monkey") + 6);
        m.falseMonkey = stoi(s);
        // cout << m.falseMonkey << endl;
        monkeys.push_back(m);
    }
    unsigned long long cycleLength = 1;
    for (auto m : monkeys)
    {
        cycleLength *= m.testValue;
    }

    vector<Monkey>::iterator it;
    vector<Monkey>::iterator j;
    for (int i = 0; i < 10000; i++)
    {
        // cout << "i:" << i << endl;
        for (j = monkeys.begin(); j != monkeys.end(); j++)
        {
            while (!j->startingItems.empty())
            {

                unsigned long long item = j->startingItems.front();
                j->counter += 1;
                // cout << "before: " << item << " ";
                j->startingItems.pop();
                switch (j->operation)
                {
                case '+':
                    if (j->changeValue == 69420)
                    {
                        item = 2 * item;
                    }
                    else
                        item += j->changeValue;
                    break;
                case '-':
                    if (j->changeValue == 69420)
                    {
                        item = 0;
                    }
                    else
                        item -= j->changeValue;
                    break;
                case '/':
                    if (j->changeValue == 69420)
                    {
                        item = 1;
                    }
                    else
                        item /= j->changeValue;
                    break;
                case '*':
                    if (j->changeValue == 69420)
                    {
                        item = item * item;
                    }
                    else
                        item *= j->changeValue;
                    break;
                }
                // cout << "After op: " << j->changeValue << " " << item << " ";
                // if (i < 20)
                // item = item ;
                while (item > cycleLength)
                {
                    item -= cycleLength;
                }
                // cout << "After Div/3: " << item << " ";
                if (item % j->testValue == 0)
                {
                    for (it = monkeys.begin(); it != monkeys.end(); it++)
                    {
                        if (it->number == j->trueMonkey)
                        {
                            it->startingItems.push(item);
                            break;
                        }
                    }
                }
                else

                {
                    for (it = monkeys.begin(); it != monkeys.end(); it++)
                    {
                        if (it->number == j->falseMonkey)
                        {
                            it->startingItems.push(item);
                            break;
                        }
                    }
                }
                // cout << "After: " << item << endl;
            }
        }
    }
    vector<unsigned long long> sum;
    for (auto m : monkeys)
    {
        cout << " counter: " << m.counter << " ";
        sum.push_back(m.counter);
        while (!m.startingItems.empty())
        {
            // cout << " " << m.startingItems.front();
            m.startingItems.pop();
        }
        cout << endl;
    }
    sort(sum.begin(), sum.end());
    reverse(sum.begin(), sum.end());
    cout << sum[1] * sum[0] << endl;
    return 0;
}