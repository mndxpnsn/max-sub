/*
 * max_subarr_dp.cpp
 *
 *  Created on: 27 Oct 2021
 *      Author: derekharrison
 *
 *      Solution to the maximum subarray problem
 *      using dynamic programming.
 *
 *      Complexity is O(n*n)
 */

#include <vector>

#include "support.hpp"
#include "user_types.hpp"

int max_subarr_dp(std::vector<int>& arr, int i, int j, m_table** memo_table) {
    int result = 0;

    if(memo_table[i][j].is_set == true) {
        return memo_table[i][j].val;
    }

    if(i == j) {
        return arr[i];
    }

    //Compute upper sum
    int upper_sum = 0;
    for(int it = i; it <= j; ++it) {
        upper_sum = upper_sum + arr[it];
    }

    //Compute max subarray
    for(int k = i + 0; k < j; ++k) {
        int sum1 = max_subarr_dp(arr, i, k, memo_table);
        int sum2 = max_subarr_dp(arr, k + 1, j, memo_table);
        int max_sum_loc = max(sum1, sum2);
        max_sum_loc = max(max_sum_loc, upper_sum);
        if(max_sum_loc > result) { result = max_sum_loc; }
    }

    return result;
}

