/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tspFileHandler.hpp
 * Author: Sam
 *
 * Created on March 11, 2018, 12:42 AM
 */

#ifndef TSPFILEHANDLER_HPP
#define TSPFILEHANDLER_HPP

#define DEBUG false

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

#include "tspCity.hpp"
#include "tour.hpp"


void loadInput(string* filename, vector<tspCity> *cities);

void printOutput(string* filename, int tourValue, Tour finalTour);

#endif /* TSPFILEHANDLER_HPP */

