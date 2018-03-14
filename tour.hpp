/*
* File:   tour.hpp
* Author: orcutts
*/

#ifndef TOUR_HPP
#define TOUR_HPP
#include "tspCity.hpp"

class Tour: public tspCity {
private:
	tspCity *cityArray;
	double fitness;
	int distance;
	int cityIndex;

public:
	Tour(int thisSize) {
		fitness = 0;
		distance = 0;
		cityIndex = thisSize;
		cityArray = new tspCity[cityIndex];
	};

	// Constructs a blank tour
	Tour() {
		for (int i = 0; i < tourSize(); i++) {
			tour.add(null);
		}
	}

	Tour(tspCity tour[]) {
		this[i] = tour;
	}
	~Tour();
	void generateIndividual();
	tspCity getCity(int);
	void setCity(int, tspCity);
	double getFitness();
	int getDistance();
	int tourSize();
	bool containsCity(tspCity);
};
#endif /* TOUR_HPP */