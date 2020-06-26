#include <iostream>

void buying_code_solution();

int main()
{
    int test_num;
    std::cin >> test_num;
    while (test_num--)
    {
        buying_code_solution();
    }
    return 0;
}

void buying_code_solution()
{
    int coke_num, coin1, coin5, coin10;
    std::cin >> coke_num >> coin1 >> coin5 >> coin10;
    std::cout << " " << coke_num << " " << coin1 << " " << coin5 << " " << coin10 << '\n';
}
