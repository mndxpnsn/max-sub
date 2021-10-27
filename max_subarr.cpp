/*
 * max_subarr.cpp
 *
 *  Created on: 27 Oct 2021
 *      Author: derekharrison
 */

#include <vector>

#include "max_subarr_ref.hpp"
#include "max_subs.hpp"

bool all_nums_neg(std::vector<int>& arr, int& max_val) {
    int size_arr = (int) arr.size();
    max_val = -3e+8;
    bool all_nums_are_neg = true;

    for(int i = 0; i < size_arr; ++i) {
        if(arr[i] >= 0) {
            all_nums_are_neg = false;
        }
        if(arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    return all_nums_are_neg;
}

std::vector<int> max_subarray(std::vector<int>& arr) {
    std::vector<int> result;

    //Check if all numbers are negative
    int max_neg_val = 0;
    int all_nums_are_neg = all_nums_neg(arr, max_neg_val);

    if(all_nums_are_neg) {
        result.push_back(max_neg_val);
        result.push_back(max_neg_val);
        return result;
    }

    //Max subarray
    int max_suba = max_subarray_wrap(arr);

    //Max subsequence
    int max_subs = max_subsequence(arr);

    //Add values to results
    result.push_back(max_suba);
    result.push_back(max_subs);

    return result;
}


