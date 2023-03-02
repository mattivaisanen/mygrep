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
            cout << "Arguments 3";
            string search_string = argv[1];
            string filename = argv[2];
            ifstream file(filename);


            while (getline(file, line)) {
                if (line.find(search_string) != string::npos) {
                    cout << line << endl;
                }
            }
        }

        if(argc == 4){
            cout << "Arguments 4";

            int linecount = 0;
            int line_number = 1;

            string options = argv[1];
            string search_string = argv[2];
            string filename = argv[3];

            ifstream file(filename);

            bool linenumber_option;
            bool occurrance_option;

            for (int i = 2; i < options.size()/sizeof(options[0]); i++) {
                if (options[i] == 'l') {
                    cout << "has L" << endl;
                    linenumber_option = true;
                }

                if (options[i] == 'o') {
                    cout << "has O" << endl;
                    occurrance_option = true;
                }
            }

            cout << "1";

            if(occurrance_option == true && linenumber_option == true){
                while (getline(file, line)) {
                    if (line.find(search_string) != string::npos) {
                        cout << line << endl;
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