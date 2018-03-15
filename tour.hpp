/*
* File:   tour.hpp
* Author: orcutts
*/

#ifndef TOUR_HPP
#define TOUR_HPP
#include "tspCity.hpp"
#include <vector>
#include <new> 

using std::vector;

class Tour {
private:
	tspCity* cityArray;
	double fitness;
	int distance;
	int cityIndex;

public:
	Tour();
	Tour(vector<tspCity>* );
	Tour(const Tour&);
	~Tour();
	void createInitialTour(vector<tspCity>* );
	void generateIndividual();
	tspCity getCity(int);
	void setCity(int, tspCity);
	double getFitness();
	int getDistance();
	int tourSize();
	void setSize(int);
	bool containsCity(tspCity);
};
#endif /* TOUR_HPP */
