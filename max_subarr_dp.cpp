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

int num_ops_dp = 0;
int num_ops_dp_saved = 0;

int max_subarr_dp(std::vector<int>& arr, int i, int j, m_table** memo_table) {
    int result = 0;

    if(memo_table[i][j].is_set == true) {
        num_ops_dp_saved++;
        return memo_table[i][j].val;
    }

    if(i == j) {
        memo_table[i][j].is_set = true;
        memo_table[i][j].val = result;
        return arr[i];
    }

    //Compute upper sum
    int upper_sum = 0;
    for(int it = i; it <= j; ++it) {
        num_ops_dp++;
        upper_sum = upper_sum + arr[it];
    }

    //Compute max subarray
    for(int k = i; k < j; ++k) {
        int sum1 = max_subarr_dp(arr, i, k, memo_table);
        int sum2 = max_subarr_dp(arr, k + 1, j, memo_table);
        int max_sum_loc = max(sum1, sum2);
        max_sum_loc = max(max_sum_loc, upper_sum);
        if(max_sum_loc > result) { result = max_sum_loc; }
    }

    memo_table[i][j].is_set = true;
    memo_table[i][j].val = result;

    return result;
}

int max_subarray_dp_wrap(std::vector<int>& arr, m_table** memo_table) {

    int n = (int) arr.size();

    int result = max_subarr_dp(arr, 0, n - 1, memo_table);

    return result;
}
