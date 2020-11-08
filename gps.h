/******************************************************************************
  Title          : query_tree.cpp
  Author         : Kasey Harvey
  Created on     : September 29, 2019
  Description    : Implementation of query tree
  Purpose        : Uses parser to create a search tree and then allow
                   the user to query it using a recognition
                   sequence. If that sequence exists in the tree then this
                   routine should print all the corresponding
                   enzymes that correspond to that recognition sequence.
******************************************************************************/

#include "avl_tree.h"
#include "SequenceMap.h"
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template <typename TreeType>
void QueryTree(TreeType &a_tree, const string &db_filename);

// @db_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>

void QueryTree(const string &db_filename, TreeType &a_tree) {

    ifstream input_file(db_filename);
    if (!input_file.good())
        cerr << ".... error condition ...." << endl;
    string line;
    while (getline(input_file, line)) {
        if (line[line.length()-1] != '/' && line[line.length()-2] != '/')
            continue;
        stringstream ss;
        ss << line;
        vector<string> sequences;
        string word;
        while (getline(ss, word,'/'))
            sequences.push_back(word);
        for (int i = 1; i < sequences.size(); i++){
            SequenceMap a_map(sequences[i], sequences[0]);
            a_tree->insert(a_map);
        }
    }
    input_file.close();
}


// Main for program queryTrees
int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <databasefilename>" << std::endl;
        return 0;
    }
    const string db_filename(argv[1]);
    cout << "Input filename is " << db_filename << endl;
    AvlTree<SequenceMap> *a_tree;
    QueryTree(db_filename, a_tree);

    string sequence;
    int temp_counter = 0;
    cout << "Please enter recognition sequence: ";
    cin >> sequence;
    SequenceMap map(sequence, "");

    if(a_tree.contains(& map, &temp_counter))
        a_tree->printTree(map);
    else{
        cout << "Tree does not contain the sequence\n";
    }
    return 0;
}
