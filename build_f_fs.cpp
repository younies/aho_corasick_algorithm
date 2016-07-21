//
//  build_f_fs.cpp
//  Aho_Resik
//
//  Created by Younies Mahmoud on 2/20/16.
//  Copyright © 2016 Younies Mahmoud. All rights reserved.
//

#include "build_f_fs.hpp"
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



vector<int> buildFailureLinks( vector<vector<pair<char, int> > > &trie , vector<vector<pair<int, int> > > & qAcceptance);

vector<int> failureSuccess(  vector<vector<pair<char, int> > > &trie , vector<int> failureLinks , vector<vector<pair<int, int> > > & qAcceptance);



int checkRforC( int r , char c , vector<vector<pair<char, int> > > &trie );


vector<int> buildFailureLinks( vector<vector<pair<char, int> > > &trie , vector<vector<pair<int, int> > > & qAcceptance)
{
    vector<int> failureLinks((int)trie.size() , 0);
    queue <int> BFS;
    BFS.push(failureLinks[0]);
    
    
    
    while (!BFS.empty())
    {
        //cout << BFS.front() << " $$$$"<<endl;
        int parent = BFS.front();
        for (int i = 0 , n = (int)trie[parent].size(); i < n ; ++i)
        {
            int child = trie[parent][i].second;
            
            //insert the child inside the BFS
            BFS.push(child);
            
            int r = parent;
            char c = trie[parent][i].first;
            r = failureLinks[r];
           // cout << checkRforC(r, c , trie) << " ####" << endl;
            while (r != 0 && checkRforC(r , c , trie) == -1)
            {
                r = failureLinks[r];

            }
            
            
            if (checkRforC(r,c,trie) != -1 && checkRforC(r,c,trie) != child)
            {
                failureLinks[child] = checkRforC(r,c,trie);
            }
            else
            {
                failureLinks[child] = 0;
            }
        }
        
        
        
        //quit the parent from the queue
        BFS.pop();
        
    }
    
    return failureLinks;

}










//to check if there is any edge with label c from r and return the r' or -1
int checkRforC( int r , char c , vector<vector<pair<char, int> > > &trie )
{
    for (int i = 0 , n = (int)trie[r].size() ; i < n ; ++i)
    {
        if(trie[r][i].first == c)
            return trie[r][i].second;
    }
    
    return -1;
}









//Failure success implementation


vector<int> failureSuccess(  vector<vector<pair<char, int> > > &trie , vector<int> failureLinks , vector<vector<pair<int, int> > > & qAcceptance )
{
    vector<int> FS ((int)failureLinks.size(), 0);

    queue <int> BFS;
    BFS.push(FS[0]);
    
    while (!BFS.empty())
    {
        //cout << BFS.front() << " $$$$"<<endl;
        int parent = BFS.front();
        for (int i = 0 , n = (int)trie[parent].size(); i < n ; ++i)
        {
            int child = trie[parent][i].second;
            //insert the child inside the BFS
            BFS.push(child);
        }
        
        if(qAcceptance[ failureLinks[parent]].size()>0)
            FS[parent] = failureLinks[parent];
        else
            FS[parent] = FS[failureLinks[parent]];
        
        //quit the parent from the queue
        BFS.pop();
        
    }

    
    

    

    return FS;
    
}
















/*{
    vector<int> FS ((int)failureLinks.size(), 0);
    
    
    
    for (int i = 0  , n = (int)FS.size(); i < n ; ++i)
    {
        if(qAcceptance[ failureLinks[i] ].size() > 0 )
            FS[i] = failureLinks[i];
        else
            FS[i] = FS[failureLinks[i]];
    }
    
    return FS;
}
*/







































