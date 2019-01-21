/**
 * @file sort.cpp
 * @author Manuel Fernando Galindo Semanate (mfdogalindo@outlook.com)
 * @brief set of functions to sort a text file with numbers separated by spaces
 * @version 1.0
 * @date 2019-01-20
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "sort.hpp"
#include <inttypes.h>
#include <thread>
#include <assert.h>
#include <chrono>

/**
 * @brief transforms vector of numbers into strings separated by comma
 * 
 * @param input vector
 * @return std::string numbers in string format
 */
std::string dump(const std::vector<uint8_t> &v)
{
    assert(v.size() > 0);

    std::string ret = "";
    for(size_t i = 0; i < v.size(); ++i) {
        ret += (char)(v[i]);
        ret += ",";
    }
    ret.pop_back();
    return ret;
}

/**
 * @brief Split string line into char vector and use spaces as reference to sleep thread
 * 
 * @param line input string to split
 * @param data numbers vector pointer with result
 */
void split(const std::string &line, std::vector<uint8_t> &data)
{
    assert(line.size()>0);

    uint8_t chr=0;
    uint8_t number;

    data.clear();

    for(int x=0; x < line.size(); x++){
        chr = line.at(x);
        if(chr >= 48 && chr < 58){
            data.push_back(chr);
        }
        else if(chr == ' '){
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
}

/**
 * @brief swap values between two pointers
 * 
 * @param a first pointer
 * @param b second pointer
 */
void swapValues(uint8_t* a, uint8_t* b) { 
    uint8_t t = *a; 
    *a = *b; 
    *b = t; 
} 

/**
 * @brief Gnome Sort method
 * 
 * @param data numbers vector to sort
 */
void gnomeSort(std::vector<uint8_t> &data) 
{ 
    int index = 0; 

    while (index < data.size()) { 
        if (index == 0) {
            index++; 
        }
        if (data[index] >= data[index - 1]) {
            index++;
        }
        else { 
            swapValues(&data[index], &data[index - 1]);
            index--; 
        } 
    } 
} 

/**
 * @brief find position of the smallest value in a block of numbers vector, quick sort auxiliary function 
 * 
 * @param data numbers vector to sort
 * @param lPos lower position
 * @param hPos higher position
 * @return int position of smallest value
 */

int partition (std::vector<uint8_t> &data, int lPos, int hPos) 
{ 
    int pivot = data[hPos]; 
    int index = (lPos - 1);  
  
    for (int x = lPos; x <= hPos- 1; x++) 
    { 
        if (data[x] <= pivot) 
        { 
            index++; 
            swapValues(&data[index], &data[x]); 
        } 
    } 
    swapValues(&data[index + 1], &data[hPos]); 
    return (index + 1); 
} 

/**
 * @brief Quick sort method
 * 
 * @param data numbers vector to sort
 * @param lPos lower position on range of vector to sort
 * @param hPos higher position on range of vecto to sort
 */
void quickSort(std::vector<uint8_t> &data, int lPos, int hPos) 
{ 
    if (lPos< hPos) 
    { 
        int pi = partition(data, lPos, hPos);  
        quickSort(data, lPos, pi - 1); 
        quickSort(data, pi + 1, hPos); 
    } 
} 

/**
 * @brief sort numbers from a group of lines
 * 
 * @param lines string vector pointer with numbers
 * @param alg sort algorithm selected 
 * @param beg lower line of group to sort
 * @param end higher line of group to sort
 */
void sortLines(std::vector<std::string> &lines, algorithm alg, uint32_t beg, uint32_t end){
    std::vector<uint8_t> data;
    switch (alg){
        case _GNOME:
            for(int x = beg; x <= end; x++){
                split(lines[x], data);
                gnomeSort(data);
                lines[x] = dump(data);
            }
            break;
        default:
            for(int x = beg; x <= end; x++){
                split(lines[x], data);
                quickSort(data, 0, data.size()-1);
                lines[x] = dump(data);
            }
    }
}

/**
 * @brief create four threads for process
 * 
 * @param lines string vector pointer with numbers
 * @param alg sort algorithm selected
 */
void sortWorker(std::vector<std::string> &lines, algorithm alg){
    int sizz = lines.size()>>2;

    assert(lines.size() > 0);

    std::thread _one (sortLines, std::ref(lines), alg, 0, sizz);
    std::thread _two (sortLines, std::ref(lines), alg, sizz+1, sizz*2);
    std::thread _thr (sortLines, std::ref(lines), alg, (sizz*2)+1, sizz*3);
    std::thread _fou (sortLines, std::ref(lines), alg, (sizz*3)+1, lines.size()-1);

    _one.join();
    _two.join();
    _thr.join();
    _fou.join();
}

/**
 * @brief Simplified verification of the content of string line
 * 
 * @param lin string to verify
 * @return int total of valid characters
 */
int lineValidator(std::string &lin){
    int ret=0;
    for(int i=0;i<lin.size();i++){
        int chr = lin.at(i);
        ret += (chr >= 48 && chr < 58) ? 1:0;
    }
    return ret;
}