/**
 * @file sort.hpp
 * @author Manuel Fernando Galindo Semanate (mfdogalindo@outlook.com)
 * @brief utils.cpp header
 * @version 0.1
 * @date 2019-01-20
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>

typedef enum algorithm {_GNOME, _QUICK} Algorithm; //Algorithms methods enumeration

int lineValidator(std::string &lin);
void sortWorker(std::vector<std::string> &lines, algorithm alg);