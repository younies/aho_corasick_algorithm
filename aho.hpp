//
//  aho.hpp
//  Aho_Resik
//
//  Created by Younies Mahmoud on 2/20/16.
//  Copyright © 2016 Younies Mahmoud. All rights reserved.
//

#ifndef aho_hpp
#define aho_hpp

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


using namespace std;




void aho( vector<vector<pair<char, int> > > &trie , vector<vector<pair<int, int> > > & qAcceptance, vector<int> &failureLinks , vector<int> &failureSuccess ,string & text  , vector<pair<int, pair<int, int> > > & result);

bool qToqdag(vector<vector<pair<char, int> > > &trie, int & q , int & qdag , char c );


#endif /* aho_hpp */
