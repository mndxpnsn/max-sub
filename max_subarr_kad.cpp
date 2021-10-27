/*
 * kadane.cpp
 *
 *  Created on: 27 Oct 2021
 *      Author: derekharrison
 *
 *      Kadane's algorithm for determining the maximum
 *      subarray.
 *
 *      Complexity is O(n)
 */

#include <vector>

#include "support.hpp"

int max_subarr_ref(std::vector<int>& arr) {
    int max_val = 0;
    int curr_val = 0;
    int size_arr = (int) arr.size();

    for(int i = 0; i < size_arr; ++i) {
    	curr_val = max(0, curr_val + arr[i]);
    	max_val = max(max_val, curr_val);
    }

    return max_val;
}

