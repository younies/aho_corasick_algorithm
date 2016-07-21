//
//  aho2.cpp
//  aho2_Resik
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

#include "aho2.hpp"

void aho2( vector<vector<pair<char, int> > > &trie , vector<vector<pair<int, int> > > & qAcceptance, vector<int> &failureLinks , vector<int> &failureSuccess , string & text , string result);

bool qToqdag2(vector<vector<pair<char, int> > > &trie, int & q , int & qdag , char c );


void sort_small_result(vector<pair<int, pair<int, int> > > & result);
void swapResult(vector<pair<int, pair<int, int> > > & result , int i);


void writeSmallResult2(vector<pair<int, pair<int, int> > > & result, string resultFile);




void aho2( vector<vector<pair<char, int> > > &trie , vector<vector<pair<int, int> > > & qAcceptance, vector<int> &failureLinks , vector<int> & failureSuccess , string & text , string result)
{
    int q = 0;
    int l = 0;
    int qdag;
    int textSize = (int)text.size();
    vector<pair<int, pair<int, int> > > smallResult;

    while (l < textSize)
    {
        while (qToqdag2(trie , q , qdag , text[l]))
        {
            q = qdag;
            ++l;
            int state = q;
            while (failureSuccess[state] != 0)
            {
                state = failureSuccess[state];
                //emitting all the success patterns
                for(int k = 0 , nk = (int)qAcceptance[state].size(); k < nk ; ++k )
                    smallResult.push_back(make_pair(l, qAcceptance[state][k]));
                
            }
            
            if((int)qAcceptance[q].size() > 0)
                for(int k = 0 , nk = (int)qAcceptance[q].size(); k < nk ; ++k )
                    smallResult.push_back(make_pair(l, qAcceptance[q][k]));
            
            if(smallResult.size() > 0)
            {
                sort_small_result(smallResult);
                //result.insert(result.end(), smallResult.begin(),smallResult.end());
                writeSmallResult2(smallResult, result);
                smallResult.clear();
            }
            
        }
        
        if (q == 0)
        {
            ++l;
        }
        
        q = failureLinks[q];
        
       // cout << l << "  " << q << endl;
    }
}


bool qToqdag2(vector<vector<pair<char, int> > > &trie, int & q , int & qdag , char c )
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


void sort_small_result(vector<pair<int, pair<int, int> > > & result)
{
    //bubble sort on p , s
    
    
    bool flag = false;
    int n = (int) result.size();
    do
    {
        flag = false;
        for (int i =0  ; i < n - 1 ; ++i)
        {
            if(result[i].second.first > result[i+1].second.first)
            {
                flag = true;
                swapResult(result, i);
            }
            else if (result[i].second.first > result[i+1].second.first && result[i].second.second > result[i+1].second.second)
            {
                flag = true;
                swapResult(result, i);
            }
        }
    
    }while(flag);
    
}


void swapResult(vector<pair<int, pair<int, int> > > & result , int i)
{
    
    int ai = result[i].first , bi = result[i].second.first , ci = result[i].second.second;
    
    result[i].first = result[i+1].first;
    result[i].second.first = result[i+1].second.first;
    result[i].second.second = result[i+1].second.second;
    
    result[i+1].first = ai;
    result[i+1].second.first = bi;
    result[i+1].second.second = ci;
    /*
    pair<int, pair<int, int> > element = result[i];
    result[i] = result[i+1];
    result[i+1] = element;
     */
    return;
}

void writeSmallResult2(vector<pair<int, pair<int, int> > > & result, string resultFile)
{
    ofstream  puttingResult(resultFile, std::ofstream::out | std::ofstream::app);
    
    if(puttingResult.is_open())
    {
        for (int i = 0 ; i < result.size(); ++i)
        {
            puttingResult << result[i].first << "  " << result[i].second.first << "    " <<result[i].second.second << "\n";
        }
        puttingResult.close();
        
    }
    
    
}
