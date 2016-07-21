//
//  tototo.hpp
//  Aho_Resik
//
//  Created by Younies Mahmoud on 2/20/16.
//  Copyright © 2016 Younies Mahmoud. All rights reserved.
//

#ifndef tototo_hpp
#define tototo_hpp

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


void tete( vector<vector<pair<char, int> > > &trie , vector<vector<pair<int, int> > > & qAcceptance, vector<int> &failureLinks , vector<int> &failureSuccess , vector<pair<int, pair<int, int> > > & result);

bool qToqdag(vector<vector<pair<char, int> > > &trie, int & q , int & qdag , char c );



#endif /* tototo_hpp */
