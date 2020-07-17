//
// Created by TiDu on 6/28/2020.
//
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>

using str = std::string;

std::map<int, int> findQuestionMark(str in_str) {
    std::map<int, int> questionMarkMap;
    for (int i = 0; i < in_str.size(); ++i) {
        char c = in_str[i];
        if (c == '?')
            questionMarkMap.insert(std::make_pair(i, 0));
    }
    return questionMarkMap;
}

str replaceQuestionMark(str in_str, std::map<int, int> &questionMarkMap) {
    auto it = questionMarkMap.begin();
    for (; it != questionMarkMap.end(); it++) {
        int index = it->first, value = it->second;
        in_str[index] = std::to_string(value)[0];
    }
    return in_str;
}

int calNSwap(str in_str) {
    return 0;
}

int main() {
    str inpStr;
    std::cin >> inpStr;
    std::map<int, int> questionMarkMap = findQuestionMark(inpStr);
    int nSwap = 0;
    int cases = pow(2, questionMarkMap.size());
    auto it = questionMarkMap.end();
    while (cases--) {
        std::cout << cases << '\n';
        if (cases % 2 == 0) {
            questionMarkMap[it->first] = 1;
            if (it != questionMarkMap.begin())
                it--;
        }

        str replacedStr = replaceQuestionMark(inpStr, questionMarkMap);
        std::cout << replacedStr << '\n';
        nSwap += calNSwap(replacedStr);
    }
    std::cout << nSwap % 1000000007;
    return 0;
}


