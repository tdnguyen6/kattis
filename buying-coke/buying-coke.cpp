#include <iostream>
using namespace std;

void buying_coke_solution();

int main()
{
    int test_count;
    cin >> test_count;
    while (test_count--)
    {
        buying_coke_solution();
    }

    return 0;
}

void buying_coke_solution()
{
    int C, n1, n5, n10;
    cin >> C >> n1 >> n5 >> n10;

    int combo1 = 0; // 1 * n10 + 3 * n1 -> 1 * n5
    int combo2 = 0; // 1 * n10 -> 2 * n1
    int combo3 = 0; // 2 * n5 -> 2 * n1
    int combo4 = 0; // 1 * n5 + 3 * n1 -> none
    int combo5 = 0; // 8 * n1 -> none
    
    combo2 = min(C, n10);
    C -= combo2;

    if (C)
    {
        combo3 = min(C, n5 / 2);
        C -= combo3;

        if (C)
        {
            combo4 = min(C, n5 % 2);
            ;
            C -= combo4;

            if (C)
            {
                combo5 = C;
            }
        }
    }

    int min35 = min(combo3, combo5);
    combo4 += min35 * 2;
    combo3 -= min35;
    combo5 -= min35;

    int min25 = min(combo2, combo5);
    combo1 += min25;
    combo4 += min25;
    combo2 -= min25;
    combo5 -= min25;

    cout << combo1 * 4 + combo2 + combo3 * 2 + combo4 * 4 + combo5 * 8 << '\n';
}
