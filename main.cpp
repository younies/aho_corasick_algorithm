//
//  main.cpp
//  Aho_Resik
//
//  Created by Younies Mahmoud on 2/19/16.
//  Copyright © 2016 Younies Mahmoud. All rights reserved.
//

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <fstream>
using namespace std;

#include "reversDNA.hpp"
#include "building_trie.hpp"
#include "build_f_fs.hpp"
#include "aho.hpp"
#include "aho2.hpp"
#include "aho3.hpp"




void func(vector<int > & vec)
{
    vec.push_back(10);
}


int main(int argc, const char * argv[]) {
    // insert code here...

    //initialting the trie
    vector<vector<pair<char, int> > > trie;
    trie.push_back(vector<pair<char,int> > ());
    
    //initiating the q acceptance
    vector<vector<pair<int, int> > >  qAcceptance;
    qAcceptance.push_back(vector<pair<int, int> >());
    
    //initialting the patterns
    vector<string> patterns;
    
    //input the pattern ******
    string fileName;
    cout << "Enter the path to the patterns' file\n";
    cin >> fileName;
    
    //for text name
    string textName;
    cout << "Enter the path to the text's file\n";
    cin >> textName;
    
    //for result name
    string resultPath;
    cout << "Enter the path to the result's file\n";
    cin >> resultPath;

    
    ifstream patternFile_(fileName);
    string line;
    if (patternFile_.is_open())
    {
        while (getline(patternFile_,  line))
        {
            patterns.push_back(line);
        }
        patternFile_.close();
    }

    
    //building the trie and qAcceptance
    buildTrie(patterns, trie, qAcceptance);

    //initialting f
    vector<int> failureLinks = buildFailureLinks(trie , qAcceptance);
    
    
    //initializing FS
    vector<int> FSuccess = failureSuccess(trie,failureLinks, qAcceptance);
    
    
    
    
    //initializing the result
    vector< pair<int ,pair<int, int> >  > result;
    
    
    
    //run the algo
    cout << "input 2 for aho2 and  3 for aho3\n";
    int label;
    cin >> label;
    if(label == 2)
    {
        //reading the text
        string text;
        
        
        string File = textName;
        ifstream textFile(File);
        if (textFile.is_open())
        {
            
            getline(textFile, text);
            textFile.close();
            
        }

        aho2(trie, qAcceptance, failureLinks, FSuccess, text, resultPath);
    
    }
    else
        aho3(trie, qAcceptance, failureLinks, FSuccess, result, textName, resultPath);
    
    
}
