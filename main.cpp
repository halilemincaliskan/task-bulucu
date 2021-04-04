#include <iostream>
#include <fstream>
#include <filesystem>  //https://en.cppreference.com/w/cpp/filesystem
#include<sstream>
using namespace std;
using namespace std::filesystem;

void printWords(string str)
{
    // word variable to store word
    string word;
    char myLetter;
    

    // making a string stream
    stringstream iss(str);

    // Read and print each word.
    while (iss >> word) {
        myLetter = stoi(word, nullptr, 2);
        cout << myLetter;
    }
}

int main()
{
    string myText;
    try {
        path p("data"); //gets the current path.

        if (!is_directory(p)) {
            cout << "!not in a accessable directory!" << endl;
            return 1;
        }
        cout << "Current Path:" << absolute(p) << endl;
        cout << "--------------------------------------" << endl;
        cout << "Tum dosyalar" << endl;
        cout << "--------------------------------------" << endl;

        /*
        vector<string> v{ "1A==", "2g==", "=Q==", "Mw==" };

        sort(v.begin(), v.end());

        cout << "Sorted \n";
        for (auto x : v)
            cout << x << " ";
            */
        for (const directory_entry& dre : directory_iterator(p))
        {
            if (!is_directory(dre))    // is a files
            {
                
                ifstream myFile(dre.path());
                while (getline(myFile, myText)) {
                    cout << dre.path().filename() << "  |  ";
                    cout << "[";
                    printWords(myText);
                    cout << "]" << endl;
                }

            }
        }
    }
    catch (const filesystem_error& ex)
    {
        cout << ex.what() << endl;
    }
}