/**
 * @author VaL Doroshchuk <valbok@gmail.com>
 * @created 01 Aug 2014
 */

/**
 * The program is supposed to calculate the number of occurrences of every word in the provided file.
 * The result will be printed out to stdout (by default) or stored in specific file.
 */

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>    // std::remove_if

using namespace std;

template <class K, class V>
void print(const map<K, V> &m, ostream &f) {
    for (typename std::map<K, V>::const_iterator p = m.begin(); p != m.end(); p++)
        f << p->first << ": " << p->second << endl;
}

void showHelp(const char *appName) {
    cerr <<  "Usage: " << appName << " [options] INPUT_FILENAME\n\n"
             "  -h, -help                   display this help and exit\n"
             "  --filename=OUTPUT_FILENAME  print result to filename. Will print to stdout by default.\n"
             "\n";
}

bool notalum(char a) {
    return !isalnum(a);
}

int main(int argc, char **argv) {
    string filename, outputFilename;
    for (unsigned arg = 1; arg < argc; ++arg) {
        string opt(argv[arg]);
        if (opt == "-h" || opt == "--help") {
            showHelp(argv[0]);
            return 0;
        }

        if (opt.substr(0,10) == "--filename") {
            outputFilename = opt.substr(11, opt.length());
            continue;
        }

        filename = opt;
    }

    if (filename.empty()) {
        showHelp(argv[0]);

        return 0;
    }

    ifstream file(filename.c_str());
    if (!file.is_open()) {
        cerr << "Could not open the input file: " << filename << endl;

        return 1;
    }

    ofstream outputFile(outputFilename.c_str());
    // Check access before execution to prevent unneeded work
    if (!outputFilename.empty() && !outputFile.is_open()) {
        cerr << "Could not open the output file: " << outputFilename << endl;
        file.close();

        return 1;
    }

    map<string, unsigned> words;
    while (file.good()) {
        string word;
        file >> word;

        // Need to remove non alphabetical characters
        word.erase(std::remove_if(word.begin(), word.end(), notalum), word.end());

        if (word.empty())
            continue;

        if (words.find(word) == words.end())
            words[word] = 1;
        else
            words[word] += 1;
    }

    print<string, unsigned>(words, (outputFilename.empty() ? cout : outputFile));

    if (!outputFilename.empty()) {
        outputFile.close();
    }
    file.close();

    return 0;
}
