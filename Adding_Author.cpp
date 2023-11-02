#include <iostream>
#include <vector>
using namespace std;

vector<string> arrangeAuthors(vector<vector<string>> &s) {
    vector<string> ans;

    for (int i = 0; i < s.size(); i++) {
        // Step 1: Prepend the index before the Author {like this way 1. Author, 2. Author}
        s[i][0] = to_string(i + 1) + ". " + s[i][0];
    }

    for (int i = 0; i < s.size(); i++) {
        char ch = 'A';
        for (int j = 1; j < s[i].size(); j++) {
            // Step 2: Prepend the Character before the Book name {like this way A. Book_1, B. Book_2}
            string bookLabel = "\t";
            bookLabel += ch++;
            bookLabel += ". " + s[i][j];
            s[i][j] = bookLabel;
        }
    }

    // Push all elements in the vector.
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s[i].size(); j++) {
            ans.push_back(s[i][j]);
        }
    }
    return ans;
}

int main() {
    vector<vector<string>> authorsAndBooks = {
        {"Author1", "Book1", "Book2"},
        {"Author2", "Book3", "Book4", "Book5"}
    };

    cout << "Normal Printing " << endl;

  for (auto it : authorsAndBooks) {
    for (const string &element : it) {
        cout << element << " ";
    }
    cout << endl;
}
    vector<string> result = arrangeAuthors(authorsAndBooks);

    for (const string &s : result) {
        cout << s << endl;
    }

    return 0;
}
