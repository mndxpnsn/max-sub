/*
 * user_types.hpp
 *
 *  Created on: 27 Oct 2021
 *      Author: derekharrison
 */

#ifndef USER_TYPES_HPP_
#define USER_TYPES_HPP_


extern int num_ops_dp;
extern int num_ops_dc;
extern int num_ops_kad;

typedef struct memo_table {
    bool is_set;
    int val;
} m_table;


#endif /* USER_TYPES_HPP_ */
