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
**   [2] Java Example: http://www.theprojectspot.com/tutorial-post/applying-a-genetic-algorithm-to-the-travelling-salesman-problem/5
**   [3] Vector Example: https://github.com/Adam-Flammino/TravelingSalesmanGeneticAlgorithim/blob/master/TravelingSalesmanGeneticAlgorithim.cpp
***********************************************/


#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <time.h>

//Establish a compiler constant for test array
#define ARRQTY 100
#define DEBUG false


//include libraries
#include "tspCity.hpp"
#include "tspFileHandler.hpp"
#include "tour.hpp"
#include "GA.hpp"
#include "population.hpp"


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
    //string inputFilename = ("C:\\Users\\shara\\Documents\\CS325-vectorApproach\\316-1\\316-1\\tsp_short.txt");
   
	//string inputFilename = ("C:\\Users\\shara\\Documents\\CS325-vectorApproach\\316-1\\316-1\\tsp_example_1.txt");
	string inputFilename;
	string outputFilename;
    int finalDistance;
    Tour finalTour;
    vector<tspCity> cities;
    GA geneticAlgo;
    
    
    // Needed so random cities are actually random
	srand(time(nullptr)); 
    
    
    //prepare the loadInput parameters
    inputFilename = argv[1];
    
    //sample call for loadInput
    loadInput(&inputFilename, &cities);
    
//    // Initialize Tour
//    aTour = new Tour();
//    aTour = aTour.createInitialTour(cities);
    
    // Initialize population
    Population pop = Population(50, &cities);	//***CHANGE BACK TO 50
    printf("Initial distance: %f\n", pop.getFittest().getDistance());

    // Evolve population for 100 generations
    pop = geneticAlgo.evolvePopulation(pop);
    for (int i = 0; i < 1000; i++) {
        pop = geneticAlgo.evolvePopulation(pop);
    }
    
    finalTour = pop.getFittest();
    finalDistance = finalTour.getDistance();

    // Print final results
    cout << "Finished\n";
    printf("Final distance: %d\n", finalDistance);
    
    
    
    //prepare the printOutput parameters
    
    outputFilename = inputFilename + ".tour";
    
    
    /*Code to replace *.txt with *.tour 
    int filenameCharQty;
    filenameCharQty = inputFilename.length();
    filenameCharQty = filenameCharQty -3;
    outputFilename = inputFilename.substr(0,filenameCharQty);
    outputFilename = outputFilename + "tour";
    */
    
    //DEBUG_MODE:separation line
    if (DEBUG)
        cout << "---------------------------\n";
    
    
    
    //sample call for printOutput
    printOutput(&outputFilename, finalDistance, finalTour);
    
    
	return 0;
}
