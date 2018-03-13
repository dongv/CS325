/*
* File:   tour.cpp
* Author: orcutts
*/

#include <iostream>
#include <algorithm>
#include <random>
#include <array>
#include <chrono>
#include "tour.hpp"
#include "tspFileHandler.hpp"

Tour::Tour() {
	
}

// Creates a random individual													***  NEED TO DEBUG WHEN CONNECTED AND GET VECTOR FROM CITY FILES ***
void Tour::generateIndividual(tspCity thisTour[]) {
	// Loop through all our destination cities and add them to our tour
	for (int i = 0; i < cityIndex; i++) {		
		setCity(thisTour, i, getCity(thisTour, i));
	}

	// Randomly reorder the tour
	//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();			//Next two lines were the code we looked at Sunday evening - in hangout chat
	//std::shuffle(*thisTour.begin()), thisTour.end(), std::default_random_engine(seed));
	std::random_shuffle(&thisTour[0], &thisTour[cityIndex]);
}

// Sets a city in a certain position within a tour	--DONE
void Tour::setCity(tspCity thisTour[], int tourPosition, tspCity thisCity) {
	thisTour[tourPosition] = thisCity;
	fitness = 0;
	distance = 0;
}

// Gets the total distance of the tour				--ALIGN
int Tour::getDistance(tspCity thisTour[]) {
	if (distance == 0) {
		int tourDistance = 0;
		// Loop through our tour's cities
		for (int i = 0; i < cityIndex; i++) {
			// Get city we're travelling from
			tspCity fromCity = getCity(thisTour, i);						//check when aligned
			// City we're travelling to
			tspCity destinationCity;										//check when aligned
			// Check we're not on our tour's last city, if we are set our 
			// tour's final destination city to our starting city
			if (i + 1 < cityIndex) {
				destinationCity = getCity(thisTour, i + 1);
			}
			else {
				destinationCity = getCity(thisTour, 0);
			}
			// Get the distance between the two cities
			tourDistance += fromCity.distanceTo(destinationCity);		//This will call function in tspCity when the code is aligned.  
		}
		distance = tourDistance;
	}
	return distance;
}

// Gets a city from the tour						--DONE
tspCity Tour::getCity(tspCity thisTour[], int tourPosition) {
	return thisTour[tourPosition];
}

// Gets the tours fitness							-- DONE
double Tour::getFitness() {
	if (fitness == 0) {
		fitness = 1 / (double)getDistance();
	}
	return fitness;
}

// Check if the tour contains a city				-- DONE
bool Tour::containsCity(tspCity thisTour[], tspCity thisCity) {
	for (int i = 0; i < cityIndex; i++) {
		if (thisTour[i] == thisCity.getId()
			return true;
	}
	return 0;
}
