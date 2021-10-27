/*
 * support.cpp
 *
 *  Created on: 27 Oct 2021
 *      Author: derekharrison
 */

#include <vector>

#include "user_types.hpp"

int max(int a, int b) {
    int r = 0;

    if(a > b) { r = a; }
    else { r = b; }

    return r;
}

void init_memo_table(m_table** r, int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            r[i][j].is_set = false;
            r[i][j].val = 0;
        }
    }
}
