#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

std::string generateRandomString(int length) {
    std::string randomString;
    static const char alphabet[] = {'A', 'G', 'T', 'C'};
    int alphabetSize = sizeof(alphabet) / sizeof(alphabet[0]);

    for (int i = 0; i < length; ++i) {
        char randomChar = alphabet[rand() % alphabetSize];
        randomString.push_back(randomChar);
    }

    return randomString;
}

std::string findLCS(const std::string& str1, const std::string& str2) {
    int m = str1.length();
    int n = str2.length();

    std::vector<std::vector<int> > dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = m, j = n;
    std::string lcs;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs = str1[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

int main() {
    std::srand(std::time(0)); // Seed for random number generation

    int length1 = rand() % 26 + 50; // Random length between 50 and 75
    int length2 = rand() % 26 + 50;

    std::string randomString1 = generateRandomString(length1);
    std::string randomString2 = generateRandomString(length2);

    std::cout << "Random String 1: " << randomString1 << std::endl;
    std::cout << "Random String 2: " << randomString2 << std::endl;

    std::string lcs = findLCS(randomString1, randomString2);

    std::cout << "Longest Common Subsequence: " << lcs << std::endl;

    return 0;
}