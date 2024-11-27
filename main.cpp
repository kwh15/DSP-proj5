#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "LCS.hpp"
#include "Similarity.hpp"

using namespace std;

const int MAX_LENGTH = 5000;

int main() {
    // Part 1: Compute LCS for two strings
    ifstream file("twoStrings.txt");
    string x, y;

    if (file.is_open()) {
        getline(file, x);
        getline(file, y);
        file.close();

         // Ensure strings do not exceed MAX_LENGTH
        if (x.length() > MAX_LENGTH) x = x.substr(0, MAX_LENGTH);
        if (y.length() > MAX_LENGTH) y = y.substr(0, MAX_LENGTH);
    }

    string lcs = computeLCS(x, y);

    cout << "String 1: " << x << endl;
    cout << "String 2: " << y << endl;
    cout << "Longest Common Subsequence: " << lcs << endl;

    // Part 2: Compute similarity measures for multiple strings
    ifstream multiFile("multiStrings.txt");
    int numStrings;
    vector<string> sequences;

    if (multiFile.is_open()) {
        multiFile >> numStrings;
        sequences.resize(numStrings);
        multiFile.ignore(); // Ignore the newline after the number

        for (int i = 0; i < numStrings; ++i) {
            getline(multiFile, sequences[i]);
        }
        multiFile.close();
    }

    vector<vector<char>> similarityTable = computeSimilarityTable(sequences);

    // Display the similarity table
    cout << "   ";
    for (int i = 0; i < numStrings; ++i) {
        cout << (i < 9 ? "0" : "") << (i + 1) << " ";
    }
    cout << endl;

    for (int i = 0; i < numStrings; ++i) {
        cout << (i < 9 ? "0" : "") << (i + 1) << " ";
        for (int j = 0; j < numStrings; ++j) {
            cout << similarityTable[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}