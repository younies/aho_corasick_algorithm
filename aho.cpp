//
//  aho.cpp
//  Aho_Resik
//
//  Created by Younies Mahmoud on 2/20/16.
//  Copyright © 2016 Younies Mahmoud. All rights reserved.
//


#include <stdio.h>
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
#include <queue>

#include "aho.hpp"

void aho( vector<vector<pair<char, int> > > &trie , vector<vector<pair<int, int> > > & qAcceptance, vector<int> &failureLinks , vector<int> &failureSuccess , string & text , vector<pair<int, pair<int, int> > > & result);

bool qToqdag(vector<vector<pair<char, int> > > &trie, int & q , int & qdag , char c );


void aho( vector<vector<pair<char, int> > > &trie , vector<vector<pair<int, int> > > & qAcceptance, vector<int> &failureLinks , vector<int> & failureSuccess , string & text , vector<pair<int, pair<int, int> > > & result)
{
    int q = 0;
    int l = 0;
    int qdag;
    int textSize = (int)text.size();
    
    while (l < textSize)
    {
        while (qToqdag(trie , q , qdag , text[l]))
        {
            q = qdag;
            ++l;
            int state = q;
            while (failureSuccess[state] != 0)
            {
                state = failureSuccess[state];
                //emitting all the success patterns
                for(int k = 0 , nk = (int)qAcceptance[state].size(); k < nk ; ++k )
                    result.push_back(make_pair(l, qAcceptance[state][k]));
                
            }
            
            if((int)qAcceptance[q].size() > 0)
                for(int k = 0 , nk = (int)qAcceptance[q].size(); k < nk ; ++k )
                    result.push_back(make_pair(l, qAcceptance[q][k]));
            
        }
        
        if (q == 0)
        {
            ++l;
        }
        
        q = failureLinks[q];
    }
}


bool qToqdag(vector<vector<pair<char, int> > > &trie, int & q , int & qdag , char c )
{
    for (int i = 0 , n = (int)trie[q].size() ; i < n ; ++i)
    {
        if (trie[q][i].first == c)
        {
            qdag = trie[q][i].second;
            return true;
        }
    }
    return false;
}
