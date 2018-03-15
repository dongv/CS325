/*
* File:   population.hpp
* Author: orcutts
*/

#ifndef POPULATION_HPP
#define POPULATION_HPP
#include "tour.hpp"
#include <vector>

// Population of tours
class Population
{
	vector<Tour> tours;			// Holds tour of tours
	//***CLEANUP		CityList cl;
	int size = 0;
public:
	// Constructor that seeds random tours of cities
	Population(int, vector<tspCity>);

	// Default constructor
	Population();

	//Destructor
	~Population();
	
	//***CLEANUP		Adds a tour
	//***CLEANUP		void addTour(Tour);	
	//***CLEANUP		Adds a tour to a specific index
	//***CLEANUP		void addTour(Tour, int);

	// Saves a tour
	void saveTour(Tour);

	// Gets tour at i
	Tour getTour(int);

	// Finds shortest tour
	Tour getFittest();

	int populationSize();
};
#endif /* POPULATION_HPP */