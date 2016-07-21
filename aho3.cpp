//
//  aho3.cpp
//  aho3_Resik
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
#include <fstream>      // std::ifstream


#include "aho3.hpp"

void aho3( vector<vector<pair<char, int> > > &trie , vector<vector<pair<int, int> > > & qAcceptance, vector<int> &failureLinks , vector<int> &failureSuccess ,  vector<pair<int, pair<int, int> > > & result, string corpus , string resultFile);

bool qToqdag3(vector<vector<pair<char, int> > > &trie, int & q , int & qdag , char c );


void sort_small_result3(vector<pair<int, pair<int, int> > > & result);
void swapResult3(vector<pair<int, pair<int, int> > > & result , int i);


void writeSmallResult(vector<pair<int, pair<int, int> > > & result, string resultFile);




void aho3( vector<vector<pair<char, int> > > &trie , vector<vector<pair<int, int> > > & qAcceptance, vector<int> &failureLinks , vector<int> & failureSuccess , vector<pair<int, pair<int, int> > > & result , string corpus  , string  resultFile)
{
    int q = 0;
    int l = 0;
    int qdag;
   // int textSize = (int)text.size();
    char c;
    
    ifstream fileCorpus(corpus);
    bool flag = true;
    while (/*l < textSize*/ flag && fileCorpus.get(c))
    {
        flag = true;

        vector<pair<int, pair<int, int> > > smallResult;
        while (qToqdag3(trie , q , qdag , /*text[l]*/ c))
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
                sort_small_result3(smallResult);
                writeSmallResult(smallResult, resultFile);
                //result.insert(result.end(), smallResult.begin(),smallResult.end());
                smallResult.clear();
                cout << l << endl;
            }
           // cout << c << endl;
            
        }
        
        if (q == 0)
        {
            ++l;
        }
        else
        {
            flag = false;
        }
        //cout << l << endl;
        q = failureLinks[q];
    }
    
    fileCorpus.close();
}


bool qToqdag3(vector<vector<pair<char, int> > > &trie, int & q , int & qdag , char c )
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


void sort_small_result3(vector<pair<int, pair<int, int> > > & result)
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
                swapResult3(result, i);
            }
            else if (result[i].second.second > result[i+1].second.second)
            {
                flag = true;
                swapResult3(result, i);
            }
        }
        
    }while(flag);
    
    
    
}


void swapResult3(vector<pair<int, pair<int, int> > > & result , int i)
{
    pair<int, pair<int, int> > element = result[i];
    result[i] = result[i+1];
    result[i+1] = element;
    return;
}



void writeSmallResult(vector<pair<int, pair<int, int> > > & result, string resultFile)
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
