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
#include "tspCity.hpp"
#include "tspFileHandler.hpp"


// Constructs a blank tour
Tour::Tour() {

	cityArray = new tspCity;
	this->cityIndex = 0;
	this->fitness = 0;
	this->distance = 0;
	for (int i = 0; i < tourSize(); i++) {
		cityArray[i].setId(-1);
		cityIndex++;
	}
}

Tour::Tour(vector<tspCity> &Cities) {
	for (int i = 0; i < this->tourSize(); i++) {
		this->cityArray[i] = Cities.at(i);
	}
}

Tour::Tour(tspCity tour[]) {
	for (int i = 0; i < this->tourSize(); i++) {
		this->cityArray[i] = tour[i];
	}
}

Tour::~Tour() {
}

//Populate the initial tour from the vector
Tour Tour::createInitialTour(vector<tspCity> &Cities) {
	int size = Cities.size();
    cityIndex = 0;
	tspCity * cityArray = new tspCity[size];
	for (int i = 0; i < size; i++) {
		cityArray[i] = Cities[i];
		cityIndex++;
	}
    
    fitness = 0;
    distance = 0;
    
    return this;
}

// Creates a random individual													
void Tour::generateIndividual() {
	// Loop through all our destination cities and add them to our tour
	for (int i = 0; i < tourSize(); i++) {		
		setCity(i, getCity(i));
	}

	// Randomly reorder the tour
	std::random_shuffle(&this[0], &this[tourSize()]);
}

// Sets a city in a certain position within a tour
void Tour::setCity(int tourPosition, tspCity inputCity) {
	this->cityArray[tourPosition] = inputCity;
	fitness = 0;
	distance = 0;
}

// Gets the total distance of the tour
int Tour::getDistance() {
	if (distance == 0) {
		int tourDistance = 0;
		// Loop through our tour's cities
		for (int i = 0; i < tourSize(); i++) {
			// Get city we're travelling from
			tspCity fromCity = getCity(i);						
			// City we're travelling to
			tspCity destinationCity;										
			// Check we're not on our tour's last city, if we are set our 
			// tour's final destination city to our starting city
			if (i + 1 < tourSize()) {
				destinationCity = getCity(i + 1);
			}
			else {
				destinationCity = getCity(0);
			}
			// Get the distance between the two cities
			tourDistance += fromCity.distanceTo(&destinationCity); 
		}
		distance = tourDistance;
	}
	return distance;
}

// Gets a city from the tour
tspCity Tour::getCity(int tourPosition) {
	return this->cityArray[tourPosition];
}

// Gets the tours fitness
double Tour::getFitness() {
	if (fitness == 0) {
		fitness = 1 / (double)getDistance();
	}
	return fitness;
}

//Get number of cities on our tour
int Tour::tourSize() {
	return this->cityIndex;
}

// Check if the tour contains a city
bool Tour::containsCity(tspCity thisCity) {
	for (int i = 0; i < tourSize(); i++) {
		if ((this->cityArray[i].getId() == thisCity.getId()) & (this->cityArray[i].getId() != -1))
			return true;
	}
	return 0;
}
