#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
using namespace std;

const string OPERATORS[] = { "+", "-", "*", "/", "%", "=", "==", "!=", ">", "<", ">=", "<=", "&&", "||", "!", "int", "scanf", "main", "printf" };
const int OPERATOR_COUNT = sizeof(OPERATORS) / sizeof(OPERATORS[0]);
const string FILE_NAME = "1.txt";

int findn1(string line) {
    set<string> foundOperators; 
    for (const string& op : OPERATORS) {
        size_t pos = line.find(op);
        if (pos != string::npos) {
            foundOperators.insert(op); 
            line = line.substr(pos + op.length());
        }
    }
    return foundOperators.size();
};

int findN1(const string& line) {
    int count = 0;
    for (const string& op : OPERATORS) {
        size_t pos = 0;
        while ((pos = line.find(op, pos)) != string::npos) {
            count++; 
            pos += op.length(); 
        }
    }
    return count;
}

int main() {
    ifstream file(FILE_NAME);
    if(!file.is_open()) {
        cerr << "File neeh bolomjgui " << endl;
        return 1;
    }

    int n1 = 0;
    int N1 = 0;
    string line;
    while (getline(file, line)) {
        istringstream iss(line); 
        string word;
        while (iss >> word) { 
            n1 += findn1(word);
            N1 += findN1(word);
        }
    }

    cout << "n1:" << n1 << endl;
    cout << "N1: " << N1 << endl;

    file.close();
    return 0;

}
