#include <iostream>
#include <fstream>
#include <string>

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

    else if(argc == 3 || argc == 4) {
        string line;

        if(argc == 3){
            string search_string = argv[1];
            string filename = argv[2];
            ifstream file(filename);

            if (!file.is_open()) {
            cerr << "Error opening file " << filename << endl;
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

            string options = argv[1];
            string search_string = argv[2];
            string filename = argv[3];

            ifstream file(filename);

            if (!file.is_open()) {
            cerr << "Error opening file " << filename << endl;
            return 0;
            }

            bool linenumber_option = false;
            bool occurrance_option = false;

            for (int i = 2; i < options.size()/sizeof(options[0]); i++) {
                if (options[i] == 'l') {
                    linenumber_option = true;
                }

                if (options[i] == 'o') {
                    occurrance_option = true;
                }
            }

            if(occurrance_option == true && linenumber_option == true){
                while (getline(file, line)) {
                    if (line.find(search_string) != string::npos) {
                        cout << line_number << ": " << line << endl;
                        linecount++;
                    }
                    line_number++;
                }
                cout << "Occurrances of lines containing " << search_string << ": " << linecount;
            }

            else{
                if(linenumber_option){
                    while (getline(file, line)) {
                        if (line.find(search_string) != string::npos) {
                            cout << line_number << ": " << line << endl;
                        }
                        line_number++;
                    }
                }

                if(occurrance_option){
                    while (getline(file, line)) {
                        if (line.find(search_string) != string::npos) {
                            cout << line << endl;
                            linecount++;
                        }
                    }
                    cout << "Occurrances of lines containing " << search_string << ": " << linecount;
                }
            }
        }

    }

    else {
        cerr << "Usage: mygrep <options> <search string> <filename>" << endl;
        return 1;
    }

    return 0;
}