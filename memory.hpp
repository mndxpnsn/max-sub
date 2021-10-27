/*
 * memory.hpp
 *
 *  Created on: 27 Oct 2021
 *      Author: derekharrison
 */

#ifndef MEMORY_HPP_
#define MEMORY_HPP_


#include "user_types.hpp"

m_table** new_memo_table(int n);
void free_memo_table(m_table** r, int n);


#endif /* MEMORY_HPP_ */
