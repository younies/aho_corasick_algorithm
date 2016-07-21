//
//  helpers.c
//  Aho_Resik
//
//  Created by Younies Mahmoud on 2/20/16.
//  Copyright © 2016 Younies Mahmoud. All rights reserved.
//

#include <iostream>
#include <string>

#include "helpers.h"


using namespace std;

string revese_complement(string DNA)
{
    string revese = string(DNA);
    for (int  n =  (int)DNA.size() , i = n- 1  ; i >= 0 ; --i)
    {
        if (DNA[i] == 'A')
            revese[ n - i - 1] = 'T';
        else if (DNA[i] == 'T')
            revese[ n - i - 1] = 'A';
        else if (DNA[i] == 'C')
            revese[ n - i - 1] = 'G';
        else
            revese[ n - i - 1] = 'C';
    }
    return revese;
}