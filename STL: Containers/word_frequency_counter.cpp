#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <chrono>
using namespace std;

vector<string> loadWords(const string &filename)
{
    vector<string> words;
    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "file not found" << endl;

        return words;
    };

    string word;

    while (file >> word)
        words.push_back(word);

    return words;
}

int main()
{
    auto allWords = loadWords("filename.txt");

    map<string, int> wordMap;
    unordered_map<string, int> wordUnorderedMap;

    auto map_start = chrono::high_resolution_clock::now();
    for (const string &word : allWords)
    {
        wordMap[word]++;
    };
    auto map_end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> map_time = map_end - map_start;

    auto unordered_map_start = chrono::high_resolution_clock::now();
    for (const string &word : allWords)
    {
        wordUnorderedMap[word]++;
    };
    auto unordered_map_end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> unordered_map_time = map_end - map_start;

    for (const auto &word : wordMap)
    {
        cout << word.first << " " << word.second << endl;
    }

    cout << map_time.count() << endl;

    for (int i = 0; i < 100; i++)
        cout << endl;

    for (const auto &word : wordUnorderedMap)
    {
        cout << word.first << " " << word.second << endl;
    }

    cout << unordered_map_time.count() << endl;
}