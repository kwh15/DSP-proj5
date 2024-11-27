#include "Similarity.hpp"
#include "LCS.hpp"
#include <algorithm>

using namespace std;

char determineSimilarity(const string &x, const string &y, const string &lcs) {
    int lenX = x.length();
    int lenY = y.length();
    int lenLCS = lcs.length();
    int minLen = min(lenX, lenY);
    int maxLen = max(lenX, lenY);

    if (minLen * 1.1 >= maxLen && lenLCS >= minLen * 0.9) {
        return 'H'; // High similarity
    } else if (minLen * 1.2 >= maxLen && lenLCS >= minLen * 0.8) {
        return 'M'; // Medium similarity
    } else if (minLen * 1.4 >= maxLen && lenLCS >= minLen * 0.5) {
        return 'L'; // Low similarity
    } else {
        return 'D'; // Dissimilar
    }
}

vector<vector<char>> computeSimilarityTable(const vector<string> &sequences) {
    int numStrings = sequences.size();
    vector<vector<char>> similarityTable(numStrings, vector<char>(numStrings, '-'));

    for (int i = 0; i < numStrings; ++i) {
        for (int j = i + 1; j < numStrings; ++j) {
            string lcs = computeLCS(sequences[i], sequences[j]);
            similarityTable[i][j] = determineSimilarity(sequences[i], sequences[j], lcs);
        }
    }

    return similarityTable;
}