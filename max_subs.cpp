/*
 * max_subs.cpp
 *
 *  Created on: 27 Oct 2021
 *      Author: derekharrison
 */

#include <vector>

int max_subsequence(std::vector<int>& arr) {
    int max_subs = 0;

    int size_arr = (int) arr.size();
    for(int i = 0; i < size_arr; ++i) {
        if(arr[i] >= 0) {
            max_subs = max_subs + arr[i];
        }
    }

    return max_subs;
}


