#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "List.h"
#include "BinaryTree.h"
using namespace std;
/*
template<typename T>
void parse(WordArray<T> text, ifstream & input){
    string data = "";
    while(input >> data){
        for(int i = 0; i < data.length(); i++){
            if(!isalpha(data.at(i))){
                data.erase(i,1);
                i--;
            }
            else if(isupper(data.at(i))){
                data.at(i) = tolower(data.at(i));
            }
        }
    }
    for(int j = 0; j < text.length(); j++) {
        text.add(data);
    }
    data = "";
}*/
int main() {
    BST<string> t = BST<string>();
    fstream inFile;
    string filename = "test.txt";
    inFile.open(filename);

    string line;  // each line of the text file
    int line_number = 0;
    string word; // each word in a line

    while (!inFile.eof())
    {
        line_number++;
        getline(inFile, line);
        istringstream iss(line);

        while (iss >> word)
            cout << word << "\t\t" << line_number << endl;
    }
    inFile.close();
    return 0;
}

