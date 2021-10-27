/*
 * memory.cpp
 *
 *  Created on: 27 Oct 2021
 *      Author: derekharrison
 */

#include "user_types.hpp"

m_table** new_memo_table(int n) {
    m_table** r = new m_table*[n];

    for(int i = 0; i < n; ++i) {
        r[i] = new m_table[n];
    }

    return r;
}

void free_memo_table(m_table** r, int n) {
    for(int i = 0; i < n; ++i) {
        delete [] r[i];
    }

    delete [] r;
}

