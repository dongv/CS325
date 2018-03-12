/***********************************************
** Sam Chew  933191613
** 2018/03/10
** CS325  TSP Group Project
**
** This program loads values from a text file
** and prepares the data for Genetic_Algo solution
** to a Traveling Salesperson Problem (TSP)
**
**
** References:
**   [1] ChewS CS325 Assignment 2
**   [2] 
**   [3] 
***********************************************/


#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

//Establish a compiler constant for test array
#define ARRQTY 100
#define DEBUG false


//include libraries
#include "tspCity.hpp"
#include "tspFileHandler.hpp"


//Establish unique identifiers within namespace
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


// Function to get number of milliseconds elapsed since program started execution
double getMilliseconds()
{
	return 1000.0 * clock() / CLOCKS_PER_SEC;
}



int main(int argc, char* argv[])
{
    //Establish program variable identifiers
    string inputFilename;
    string outputFilename;
    int totalValue;
    vector<int> aTour;
    vector<tspCity> cities;
    
    
    
    //prepare the loadInput parameters
    inputFilename = argv[1];
    
    //sample call for loadInput
    loadInput(&inputFilename, &cities);
    
    
    
    //example calculate distance from origin to each other city
    int testDist;
    tspCity testOrigin;
    testOrigin.setId(-1);
    testOrigin.setX(0);
    testOrigin.setY(0);
    for (int i = 0; i < (int) cities.size(); i++){
        testDist = testOrigin.distanceTo(&cities.at(i));
        printf("Distance from %d to %d: %d \n",testOrigin.getId(),cities.at(i).getId(),testDist);
    }
    
    
    
    //prepare the printOutput parameters
    
    outputFilename = inputFilename + ".tour";
    
    
    /*Code to replace *.txt with *.tour 
    int filenameCharQty;
    filenameCharQty = inputFilename.length();
    filenameCharQty = filenameCharQty -3;
    outputFilename = inputFilename.substr(0,filenameCharQty);
    outputFilename = outputFilename + "tour";
    */
    
    //hardcode a totalvalue
    totalValue = 356;
    //build a test tour of city id values
    int c;
    for (c = 0; c < (int) cities.size(); c++){
        aTour.push_back(cities.at(c).getId());
    }
    
    //DEBUG_MODE:separation line
    if (DEBUG)
        cout << "---------------------------\n";
    
    //sample call for printOutput
    printOutput(&outputFilename, totalValue, &aTour);
    
    
	return 0;
}
