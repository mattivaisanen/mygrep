#include <iostream>
#include <string>

using namespace std;

int main() {
    string search_string, text;
    size_t position;

    cout << "Give a string from which to search for: ";
    getline(cin, text);

    cout << "Give search string: ";
    getline(cin, search_string);

    position = text.find(search_string);

    if (position != string::npos) {
        cout << "\"" << search_string << "\" found in \"" << text << "\" in position " << position << endl;
    } else {
        cout << "\"" << search_string << "\" not found in \"" << text << "\"" << endl;
    }

    return 0;
}
