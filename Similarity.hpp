#ifndef SIMILARITY_HPP
#define SIMILARITY_HPP

#include <string>
#include <vector>

using namespace std;

char determineSimilarity(const string &x, const string &y, const string &lcs);
vector<vector<char>> computeSimilarityTable(const vector<string> &sequences);

#endif // SIMILARITY_HPP