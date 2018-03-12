/*
* File:   tour.hpp
* Author: orcutts
*/

#ifndef TOUR_HPP
#define TOUR_HPP
#include "tspCity.hpp"

class Tour: public tspCity {
private:
	tspCity **cityArray;
	double fitness;
	int distance;
	int cityIndex;

public:
	Tour() {
		fitness = 0;
		distance = 0;
		cityIndex = 2;									//Minimum tour size
		cityArray = new tspCity*[cityIndex];			//NOTE:  *** Can delete this after figuring out how to copy vector to array
	};
	~Tour();
	void generateIndividual(tspCity []);
	tspCity getCity(tspCity [], int);
	void setCity(tspCity [], int, tspCity);
	double getFitness();
	int getDistance(tspCity []);
	bool containsCity(tspCity [], tspCity);
};
#endif /* TOUR_HPP */