//
//  building_trie.hpp
//  Aho_Resik
//
//  Created by Younies Mahmoud on 2/20/16.
//  Copyright © 2016 Younies Mahmoud. All rights reserved.
//

#ifndef building_trie_hpp
#define building_trie_hpp

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

using namespace std;



void buildTrie(vector<string> & patterns , vector<vector<pair<char, int> > > &trie , vector<vector<pair<int, int> > > & qAcceptance);

void insert_pattern(string pattern , int pos , vector<vector<pair<char, int> > > &trie , vector<vector<pair<int, int> > > & qAcceptance);
void insert_only_pattern(string pattern, int pos , int s , vector<vector<pair<char, int> > > &trie , vector<vector<pair<int, int> > > & qAcceptance);




#endif /* building_trie_hpp */
