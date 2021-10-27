/*
 * main.cpp
 *
 *  Created on: 27 Oct 2021
 *      Author: derekharrison
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "max_subarr.hpp"
#include "max_subarr_kad.hpp"
#include "max_subarr_ref.hpp"
#include "support.hpp"
#include "user_types.hpp"


int main(int argc, const char * argv[]) {

	std::vector< std::vector<int> > results_arr;

    std::ifstream input_file;
    input_file.open("data.txt");

    int t = 0;
    int n = 0;

    if (!input_file.is_open()) {
        std::cout << "Could not open the file" << std::endl;
    }

    input_file >> t;

    for(int tc = 0; tc < t; ++tc) {
        input_file >> n;
        std::vector<int> arr_loc;
        for(int i = 0; i < n; ++i) {
        	int val;
        	input_file >> val;
        	arr_loc.push_back(val);
        }

        std::vector<int> results = max_subarray(arr_loc);
        results_arr.push_back(results);
    }

    input_file.close();

    std::vector< std::vector<int> > results_ref_arr;
    std::ifstream results_ref;
    results_ref.open("results_ref.txt");

    if (!results_ref.is_open()) {
        std::cout << "Could not open the file" << std::endl;
    }

    for(int tc = 0; tc < t; ++tc) {
    	std::vector<int> results_ref_elem;
    	int val1, val2;
    	results_ref >> val1;
    	results_ref >> val2;
    	results_ref_elem.push_back(val1);
    	results_ref_elem.push_back(val2);
    	results_ref_arr.push_back(results_ref_elem);
    }

    results_ref.close();

    for(int tc = 0; tc < t; ++tc) {
		std::cout << "max subarray: " << results_arr[tc][0] << ", ";
		std::cout << "max subsequence: " << results_arr[tc][1] << std::endl;
		std::cout << "max subarray: " << results_ref_arr[tc][0] << ", ";
		std::cout << "max subsequence: " << results_ref_arr[tc][1] << std::endl;

    }

    std::cout << "done" << std::endl;

    return 0;
}


