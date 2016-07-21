//
//  building_trie.cpp
//  Aho_Resik
//
//  Created by Younies Mahmoud on 2/20/16.
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
#include <stdio.h>

#include "building_trie.hpp"
#include "reversDNA.hpp"

void buildTrie(vector<string> & patterns , vector<vector<pair<char, int> > > &trie , vector<vector<pair<int, int> > > & qAcceptance);

void insert_pattern(string pattern , int pos , vector<vector<pair<char, int> > > &trie , vector<vector<pair<int, int> > > & qAcceptance);
void insert_only_pattern(string pattern, int pos , int s , vector<vector<pair<char, int> > > &trie , vector<vector<pair<int, int> > > & qAcceptance);



void buildTrie(vector<string> & patterns , vector<vector<pair<char, int> > > &trie , vector<vector<pair<int, int> > > & qAcceptance)
{
    //go through pattern by pattern
    for (int i = 0 , n = (int)patterns.size() ; i < n ; ++i)
    {
        insert_pattern(patterns[i], i+1, trie, qAcceptance);
    }
    
}







//for inserting one pattern
void insert_pattern(string pattern, int pos , vector<vector<pair<char, int> > > &trie , vector<vector<pair<int, int> > > & qAcceptance)
{
    string revPattern = revese_complement(pattern);// having the complement
    insert_only_pattern(pattern, pos, 1, trie, qAcceptance);
    insert_only_pattern(revPattern, pos, -1, trie, qAcceptance);

}



void insert_only_pattern(string pattern, int pos , int s , vector<vector<pair<char, int> > > &trie , vector<vector<pair<int, int> > > & qAcceptance)
{
    bool flag = false;
    int q = 0;
    int pi;
    int n = (int)pattern.size();
    
    //try to match the pattern with as most as possible with trie
    
    for( pi = 0  ; pi < n ; ++pi)
    {
        
        for (int tj = 0 , m = (int)trie[q].size(); tj < m ; ++tj)
        {
            //if found a match
            if (trie[q][tj].first == pattern[pi])
            {
                flag = true;
                q = trie[q][tj].second;
                break;
            }
        }
        
        if (flag)
        {
            flag = false;
            continue;
        }
        else
        {
            break;
        }
        
    }
    
    
    
    //if pi >= pattern length --> we are done ! else --> we have to insert the otther
    
    // for pushing new letter from the pattern
    for ( ; pi < n ; ++pi)
    {
        trie.push_back(vector<pair<char, int> >());
        int newQ =(int)trie.size() - 1;
        trie[q].push_back(make_pair(pattern[pi], newQ));
        qAcceptance.push_back(vector<pair<int, int> >());
        q = newQ;
    }
    
    
    //pushing the q as an accepting state
    qAcceptance[q].push_back(make_pair(pos, s));
    
    
}













