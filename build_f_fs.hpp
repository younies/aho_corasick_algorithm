//
//  build_f_fs.hpp
//  Aho_Resik
//
//  Created by Younies Mahmoud on 2/20/16.
//  Copyright © 2016 Younies Mahmoud. All rights reserved.
//

#ifndef build_f_fs_hpp
#define build_f_fs_hpp

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


vector<int> buildFailureLinks( vector<vector<pair<char, int> > > &trie , vector<vector<pair<int, int> > > & qAcceptance);

vector<int> failureSuccess(  vector<vector<pair<char, int> > > &trie , vector<int> failureLinks , vector<vector<pair<int, int> > > & qAcceptance);


#endif /* build_f_fs_hpp */
