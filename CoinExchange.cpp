#include <iostream>
#include <vector>
#include <climits>

std::vector<int> minCoinsCombination(int amount, const std::vector<int>& denominations) {
    int n = denominations.size();
    std::vector<int> dp(amount + 1, INT_MAX);
    std::vector<std::vector<int> > selectedCoins(amount + 1, std::vector<int>(n, 0));

    dp[0] = 0; // No coins needed to make change for amount 0

    for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j < n; ++j) {
            if (denominations[j] <= i && dp[i - denominations[j]] != INT_MAX) {
                if (dp[i] > dp[i - denominations[j]] + 1) {
                    dp[i] = dp[i - denominations[j]] + 1;
                    selectedCoins[i] = selectedCoins[i - denominations[j]];
                    selectedCoins[i][j]++;
                }
            }
        }
    }

    return selectedCoins[amount];
}

int main() {
    int numDenominations;

    // Get the number of denominations from the user
    std::cout << "Enter the number of denominations: ";
    std::cin >> numDenominations;

    // Get the denominations from the user
    std::vector<int> denominations(numDenominations);
    std::cout << "Enter the denominations:\n";
    for (int i = 0; i < numDenominations; ++i) {
        std::cout << "Denomination " << i + 1 << ": ";
        std::cin >> denominations[i];
    }

    // Get the amount from the user
    int amount;
    std::cout << "Enter the amount: ";
    std::cin >> amount;

    // Calculate and display the minimum number of coins and the combination
    std::vector<int> selectedCoins = minCoinsCombination(amount, denominations);

    if (selectedCoins.empty()) {
        std::cout << "It's not possible to make change for the given amount." << std::endl;
    } else {
        std::cout << "Minimum number of coins needed: " << selectedCoins.size() << std::endl;
        std::cout << "Combination of denominations: ";
        for (int i = 0; i < numDenominations; ++i) {
            for (int j = 0; j < selectedCoins[i]; ++j) {
                std::cout << denominations[i] << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}