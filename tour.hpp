/*
* File:   tour.hpp
* Author: orcutts
*/

#ifndef TOUR_HPP
#define TOUR_HPP
#include "tspCity.hpp"

#include <vector>
using std::vector;


class Tour {
private:
	vector<tspCity> tour;
	double distance = 0;
	double fitness = 0;
	int size;

	// Gets distance between two cities
	double distanceTwoCities(tspCity, tspCity);

public:
	// Constructor
	Tour(vector<tspCity> cities);

	// Default constructor
	Tour();

	//Destructor
	virtual ~Tour();

	// Generates a random tour of all cities
	void createIndividual(vector<tspCity> cities);

	// Gets city at position i
	tspCity getCity(int);

	// Pushes city onto tour
	void setCity(tspCity);

	// Sets city at position i
	void setCity(int, tspCity);

	// Gets distance traveled
	double getDistance();

	// Gets fitness of tour individual
	double getFitness();

	// Gets size of tour
	int getTourSize();
};
#endif /* TOUR_HPP */
