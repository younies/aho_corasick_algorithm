//
//  aho2.hpp
//  aho2_Resik
//
//  Created by Younies Mahmoud on 2/20/16.
//  Copyright © 2016 Younies Mahmoud. All rights reserved.
//

#ifndef aho2_hpp
#define aho2_hpp

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
#include <fstream>      // std::ofstream



using namespace std;




void aho2( vector<vector<pair<char, int> > > &trie , vector<vector<pair<int, int> > > & qAcceptance, vector<int> &failureLinks , vector<int> &failureSuccess , string & text , string result);

bool qToqdag2(vector<vector<pair<char, int> > > &trie, int & q , int & qdag , char c );


void sort_small_result(vector<pair<int, pair<int, int> > > & result);
void swapResult(vector<pair<int, pair<int, int> > > & result , int i);
void writeSmallResult2(vector<pair<int, pair<int, int> > > & result, string resultFile);


#endif /* aho2_hpp */
