// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://onlinejudge.org/external/2/230.pdf
// Submit: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=submit_problem&problemid=166&category=0

#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

pair<string, string> get_book(string line) {
	string title;
	string author;
	pair<string, string> book;
	line = line.substr(line.find('"')+1);
	int pos = line.find('"');
	title = line.substr(0, pos);
	author = line.substr(pos+5);
	book.first = author;
	book.second = title;
	return book;
}

struct cmp {
  bool operator() (const string& lhs, const string& rhs) const {return lhs>rhs;}
};

int main(int argc, char const *argv[]) {
	multimap<string, string, cmp> shelve;
	map<string, string> titles;
	map<string, string> returns;

	// Get the list of books
	while (true) {
		string line;
		getline(cin, line);
		if (line == "END") break;
		pair<string, string> book = get_book(line); // (author, title)
		shelve.insert(book);
		titles[book.second] = book.first; // (title, author)
	}

	// Get the list of commands
	while (true) {
		string line;
		getline(cin, line);
		if (line == "END") break;
		if (line[0] == 'B') {	// BORROW
			string title = line.substr(8, line.size()-9);
			string author = titles.find(title)->second;
			multimap<string, string, cmp>::iterator it = shelve.lower_bound(author);
			while (true) {
				if (it->second == title) break;
				it++;
			}
			shelve.erase(it);
		}
		if (line[0] == 'R') {	// RETURN
			string title = line.substr(8, line.size()-9);
			string author = titles.find(title)->second;
			returns.insert(pair<string, string> (author, title));
			continue;
		}
		if (line[0] == 'S') {	// SHELVE
			multimap<string, string>::iterator it;
			for (it=returns.begin(); it!=returns.end(); it++) {
				string author = it->first;
				string title = it->second;
				multimap<string, string, cmp>::iterator it2 = shelve.lower_bound(author);
				while (it2 != shelve.end()) {
					if (it2->first < author) break;
					if (it2->second < title) break;
					it2++;
				}
				if (it2 == shelve.end()) {
					printf("Put \"%s\" first\n", title.c_str());
				}
				else {
					printf("Put \"%s\" after \"%s\"\n", title.c_str(), it2->second.c_str());
				}
				shelve.insert(pair<string, string> (author, title));
			}
			printf("END\n");
			returns.clear();
		}
	}

	return 0;
}
