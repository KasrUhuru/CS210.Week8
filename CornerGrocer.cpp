#include <iostream>
#include <fstream>
#include <map> // included to build my dictionary
#include <string>
#include <algorithm> // included to use the tolower transformation

using namespace std;

// create a dictionary for building my reference
void buildFrequencyMap(const string& inputFileName,
    map<string, int>& wordList) {
    ifstream inFile(inputFileName);
    if (!inFile.is_open()) {
        cerr << "Error: Could not open input file: " << inputFileName << endl;
        return;
    }

    string currentWord;
    while (inFile >> currentWord) {
        // Convert to lowercase
        for (char& c : currentWord) {
            c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
        }

        // Increment frequency
        ++wordList[currentWord];
    }

    inFile.close();
}

void writeFrequenciesToFile(const string& outputFileName,
    const map<string, int>& wordList) {
    ofstream outFile(outputFileName);
    if (!outFile.is_open()) {
        cerr << "Error: Could not open output file: " << outputFileName << endl;
        return;
    }

    for (const auto& pair : wordList) {
        outFile << pair.first << " " << pair.second << '\n';
    }

    outFile.close();
}

void option1_searchWord(const map<string, int>& wordList) {
    string target;
    cout << "Enter a target word: ";
    cin >> target;

    // Normalize to lowercase
    for (char& c : target) {
        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    }

    auto it = wordList.find(target);
    if (it != wordList.end()) {
        cout << it->first << " " << it->second << endl;
    }
    else {
        cout << "That word doesn't appear in our logs, try again." << endl;
    }
}

void option2_printAll(const map<string, int>& wordList) {
    for (const auto& pair : wordList) {
        cout << pair.first << " " << pair.second << endl;
    }
}

void option3_histogram(const map<string, int>& wordList) {
    for (const auto& pair : wordList) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "+";
        }
        cout << endl;
    }
}

int main() {
    map<string, int> wordList;

    // build the frequency dictionary from file and write Frequency.dat
    buildFrequencyMap("CS210_Project_Three_Input_File.txt", wordList);
    if (wordList.empty()) {
        cerr << "No words were read. Exiting." << endl;
        return 1;
    }

    writeFrequenciesToFile("frequency.dat", wordList);

    // Menu loop
    bool quitProgram = false;
    int userChoice = 0;

    while (!quitProgram) {
        cout << "\nMENU\n";
        cout << "1 - Search for a word\n";
        cout << "2 - Print all words and counts\n";
        cout << "3 - Print histogram\n";
        cout << "4 - Quit\n";
        cout << "Enter your choice: ";

        if (!(cin >> userChoice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 4.\n";
            continue;
        }

        switch (userChoice) {
        case 1:
            option1_searchWord(wordList);
            break;

        case 2:
            option2_printAll(wordList);
            break;

        case 3:
            option3_histogram(wordList);
            break;

        case 4:
            quitProgram = true;
            break;

        default:
            cout << "Invalid choice. Please enter 1-4.\n";
            break;
        }
    }

    return 0;
}
