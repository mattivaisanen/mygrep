#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


using namespace std;

int main(int argc, char* argv[]) {

    if(argc==1){
        string text, filename, search_string;
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
    }


    if(argc == 3){
        string line;
        string search_string = argv[1];
        string filename = argv[2];
        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Error opening file " << filename << " \nPlease check filename and permissions" << endl;
            return 0;
        }

        while (getline(file, line)) {
            if (line.find(search_string) != string::npos) {
                cout << line << endl;
            }
        }
    }

    if(argc == 4){
        int linecount = 0;
        int line_number = 1;

        string line;
        string options = argv[1];
        string search_string = argv[2];
        string filename = argv[3];

        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Error opening file " << filename << " \nPlease check filename and permissions" << endl;
            return 0;
        }

        //Bool values for different options
        bool linenumber_option = false;
        bool occurrance_option = false;
        bool reverse_option = false;
        bool caseinsensitive_option = false;


        for (int i = 2; i < options.size()/sizeof(options[0]); i++) {
            if (options[i] == 'l') {
                linenumber_option = true;
            }

            if (options[i] == 'o') {
                occurrance_option = true;
            }

            if (options[i] == 'r') {
                reverse_option = true;
            }

            if (options[i] == 'i') {
                caseinsensitive_option = true;
            }
        }

        if(reverse_option){
            string line_case;
            string search_case;
            search_case = search_string;
            while (getline(file, line)) {
                line_case = line;
                if(caseinsensitive_option){
                    transform(line.begin(), line.end(), line.begin(), ::toupper);
                    transform(search_string.begin(), search_string.end(), search_string.begin(), ::toupper);
                }
                if (line.find(search_string) == string::npos) {
                    if(linenumber_option){
                        cout << line_number << ": ";
                    }
                    cout << line_case << endl;
                    linecount++;
                }
                line_number++;
            }
            if(occurrance_option){
                cout << endl << "Occurrances of lines NOT containing '" << search_case << "': " << linecount;
            }
        }

        else{
            string line_case;
            string search_case;
            search_case = search_string;
            while (getline(file, line)) {
                line_case = line;
                if(caseinsensitive_option){
                    transform(line.begin(), line.end(), line.begin(), ::toupper);
                    transform(search_string.begin(), search_string.end(), search_string.begin(), ::toupper);
                }
                if (line.find(search_string) != string::npos) {
                    if(linenumber_option){
                        cout << line_number << ": ";
                    }
                    cout << line_case << endl;
                    linecount++;
                }
                line_number++;
            }
            if(occurrance_option){
                cout << endl << "Occurrances of lines containing '" << search_case << "': " << linecount;
            }

        }
    }

    else {
        cerr << "Usage: mygrep <options> <search string> <filename>" << endl;
        return 1;
    }

    return 0;
}