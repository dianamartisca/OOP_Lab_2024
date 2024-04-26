#include <string>
#include <map>
#include <queue>
#include <fstream>
#include <iostream>

using namespace std;

class compare
{
public:
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const
    {
        if (a.second < b.second)
            return true;
        if (a.second > b.second)
            return false;
        return (a.first > b.first);
    }
};

int main()
{
    string line;
    string del(" ,?!.");
    map<string, int> words;
    ifstream f;
    f.open("sentence.txt");
    while (getline(f, line))
    {
        string::iterator it;
        for (it = line.begin(); it != line.end(); it++)
            *it = tolower(*it);
        size_t start, end;
        start = line.find_first_not_of(del, 0);
        while (start != string::npos)
        {
            end = line.find_first_of(del, start + 1);
            if (end == string::npos)
                end = line.length();
            string word(line.substr(start, end - start));
            words[word]++;
            start = line.find_first_not_of(del, end+1);
        }

    }

    f.close();
    priority_queue<pair<string, int>, vector<pair<string, int>>, compare> coada;
    map<string, int>::iterator it;
    for ( it = words.begin(); it != words.end(); it++)
    {
        pair<string, int> word(it->first, it->second);
        coada.push(word);
    }
    while (!coada.empty() )
    {
        cout << coada.top().first << " => " << coada.top().second << '\n';
        coada.pop();
    }
}
