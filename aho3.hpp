//
//  aho3.hpp
//  aho3_Resik
//
//  Created by Younies Mahmoud on 2/20/16.
//  Copyright © 2016 Younies Mahmoud. All rights reserved.
//

#ifndef aho3_hpp
#define aho3_hpp

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


using namespace std;




void aho3( vector<vector<pair<char, int> > > &trie , vector<vector<pair<int, int> > > & qAcceptance, vector<int> &failureLinks , vector<int> &failureSuccess ,  vector<pair<int, pair<int, int> > > & result , string corpus , string resultFile);

bool qToqdag3(vector<vector<pair<char, int> > > &trie, int & q , int & qdag , char c );


void sort_small_result3(vector<pair<int, pair<int, int> > > & result);
void swapResult3(vector<pair<int, pair<int, int> > > & result , int i);

void writeSmallResult(vector<pair<int, pair<int, int> > > & result, string resultFile);


#endif /* aho3_hpp */
