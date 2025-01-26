#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int main()
{
    // Flip this to true if you want to shuffle resulting list
    const bool shouldShuffle = false;

    std::string pathA = "..\\a.txt";
    std::string pathB = "..\\b.txt";
    std::ifstream fileA(pathA);
    std::ifstream fileB(pathB);

    if (!fileA.is_open() || !fileB.is_open()) {
        std::cerr << "Error: Unable to open files." << std::endl;
        return 1;
    }

    std::vector<std::string> wordsA, wordsB;

    // Read words from file A
    std::string line;
    while (std::getline(fileA, line)) {
        wordsA.push_back(line);
    }

    // Read words from file B
    while (std::getline(fileB, line)) {
        wordsB.push_back(line);
    }

    fileA.close();
    fileB.close();

    // Generate all combinations of words from list A and B
    std::vector<std::string> combinations;
    for (const auto& wordA : wordsA) {
        for (const auto& wordB : wordsB) {
            combinations.push_back(wordA + " " + wordB);
        }
    }

    // Shuffle the combinations if shouldShuffle = true
    if (shouldShuffle)
    {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(combinations.begin(), combinations.end(), g);
    }

    // Output
    int lineCount = 1;
    for (const auto& combination : combinations) {
        // Styles like an MD table: | column1 | column2 |
        std::cout << "| " << lineCount << " | " << combination << " |\n";
        lineCount++;
    }

    return 0;
}
