/*
 * main.cpp
 *
 *  Created on: 27 Oct 2021
 *      Author: derekharrison
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <string>

#include "max_subarr.hpp"
#include "max_subarr_kad.hpp"
#include "max_subarr_ref.hpp"
#include "support.hpp"
#include "user_types.hpp"


int main(int argc, const char * argv[]) {

    //Input size
    int n = 100;

    //Create random array of ints
    std::vector<int> arr;
    srand((unsigned) time(NULL));
    for(int i = 0; i < n; ++i) {
        int val = rand() % n - n / 2;
        arr.push_back(val);
    }

    //Compute maximum subarray and subsequence
    std::vector<int> results_dc = max_subarray_dc(arr);
    std::vector<int> results_kad = max_subarray_kad(arr);
    std::vector<int> results_dp = max_subarray_dp(arr);

    //Print results
    std::cout << "maximum subarray divide and conquer: " << results_dc[0] << std::endl;
    std::cout << "maximum subsequence: " << results_dc[1] << std::endl;
    std::cout << "maximum subarray kadane: " << results_kad[0] << std::endl;
    std::cout << "maximum subsequence: " << results_kad[1] << std::endl;
    std::cout << "maximum subarray dynamic programming: " << results_dp[0] << std::endl;
    std::cout << "maximum subsequence: " << results_dp[1] << std::endl;

    std::cout << "number of operations:" << std::endl;
    std::cout << "number of operations dynamic programming: " << num_ops_dp << std::endl;
    std::cout << "number of operations divide and conquer: " << num_ops_dc << std::endl;
    std::cout << "number of operations kadane's algorithm: " << num_ops_kad << std::endl;
    std::cout << "number of operations saved: " << num_ops_dp_saved << std::endl;
    std::cout << "done" << std::endl;

    return 0;
}


