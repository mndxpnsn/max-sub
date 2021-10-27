/*
 * max_subarr_dp.hpp
 *
 *  Created on: 27 Oct 2021
 *      Author: derekharrison
 */

#ifndef MAX_SUBARR_DP_HPP_
#define MAX_SUBARR_DP_HPP_


#include <vector>

#include "user_types.hpp"

int max_subarr_dp(std::vector<int>& arr, int i, int j, m_table** memo_table);
int max_subarray_dp_wrap(std::vector<int>& arr, m_table** memo_table);

#endif /* MAX_SUBARR_DP_HPP_ */
