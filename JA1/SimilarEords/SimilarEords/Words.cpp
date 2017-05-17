#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	string word;
	cin >> word;
	int procent;
	cin >> procent;
	vector<string> v;

	size_t prev_pos = 0, pos;
	while ((pos = s.find_first_of(".,;!? ", prev_pos)) != string::npos)
	{
		if (pos > prev_pos)
			v.push_back(s.substr(prev_pos, pos - prev_pos));
		prev_pos = pos + 1;
	}
	if (prev_pos< s.length())
		v.push_back(s.substr(prev_pos, string::npos));
	int matches = 0;
	
	for (int i = 0; i < v.size(); i++) {
		double matchingLetters = 0;
		string temp = v[i];
		if (v[i].size() != word.size() || temp[0] != word[0]) {
			continue;
		}
		else {
			for (int j = 0; j < word.size(); j++) {
				if (temp[j] == word[j]) {
					matchingLetters++;
				}
			}
		}
		if (matchingLetters > 0) {
			int check = (matchingLetters / word.size()) * 100;
			if (((matchingLetters/ word.size()) * 100) >= procent) {
				matches++;
			}
		}
	}
	cout << matches << endl;
}