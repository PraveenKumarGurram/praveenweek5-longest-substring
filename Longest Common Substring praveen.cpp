#include <iostream>
#include <vector>

// Function to find the longest common substring using dynamic programming
std::string longestCommonSubstring(const std::string &str1, const std::string &str2) {
    int n = str1.size();
    int m = str2.size();

    // Initialize the lookup table with zeros
    std::vector<std::vector<int>> lookup(n + 1, std::vector<int>(m + 1, 0));
    int maxLength = 0; // To keep track of the longest length found
    int endIndex = 0;  // To track the end position of the longest substring

    // Display the top row header (representing characters of str2)
    std::cout << "  "; // Space for the top left corner
    for (int j = 0; j <= m; ++j) {
        if (j == 0)
            std::cout << "0 "; // Leading 0 for the first column
        else
            std::cout << str2[j - 1] << " ";
    }
    std::cout << std::endl;

    // Build the lookup table row by row
    for (int i = 0; i <= n; ++i) {
        // Print the leading character for each row (representing characters of str1)
        if (i == 0) {
            std::cout << "0 ";  // Leading zero for the first row
        } else {
            std::cout << str1[i - 1] << " "; // Display the character from str1
        }

        for (int j = 0; j <= m; ++j) {
            if (i == 0 || j == 0) {
                lookup[i][j] = 0; // Explicitly setting the first row and column to 0
            } else if (str1[i - 1] == str2[j - 1]) {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;

                // Update maximum length and ending index
                if (lookup[i][j] > maxLength) {
                    maxLength = lookup[i][j];
                    endIndex = i;
                }
            } else {
                lookup[i][j] = 0;  // No match at this position
            }

            // Print the value at the current cell
            std::cout << lookup[i][j] << " ";
        }
        std::cout << std::endl;  // Move to the next row
    }

    // Return the longest common substring using the stored endIndex and maxLength
    return str1.substr(endIndex - maxLength, maxLength);
}

int main() {
    // Variables to store the input strings
    std::string str1, str2;

    // Prompt the user to enter the two strings
    std::cout << "Enter the first string: ";
    std::cin >> str1;
    std::cout << "Enter the second string: ";
    std::cin >> str2;

    // Display the DP Table
    std::cout << "\nDP Table:\n";
    std::string result = longestCommonSubstring(str1, str2);

    // Display the longest common substring
    std::cout << "\nThe longest common substring is: " << result << std::endl;
    std::cout << "Length of longest common substring: " << result.length() << std::endl;

    return 0;
}
