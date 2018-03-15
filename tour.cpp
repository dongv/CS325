/*
* File:   tour.cpp
* Author: orcutts
*/

#include <vector>
#include <algorithm>
#include "tour.hpp"
using std::vector;

// Constructor
Tour::Tour(vector<tspCity> cities){
	createIndividual(cities);
}

// Default constructor
Tour::Tour(){
	size = 0;
}

// Generates a random tour of all cities
void Tour::createIndividual(vector<tspCity> cities){
	tour = cities;								// Copies vector of cities
	random_shuffle(tour.begin(), tour.end());	// Shuffles tour vector
}

//Returns a tspCity, for city at given tour position
tspCity Tour::getCity(int tourPosition){
	return tour.at(tourPosition);
}

// Pushes city onto tour
void Tour::setCity(tspCity thisCity){
	tour.push_back(thisCity);
	size++;
}

// Sets city at a given tour position
void Tour::setCity(int tourPosition, tspCity thisCity){
	tour.at(tourPosition) = thisCity;
}

// Gets distance between two cities
double Tour::distanceTwoCities(tspCity fromCity, tspCity destinationCity){
	int xDist = abs(fromCity.getX() - destinationCity.getX());
	int yDist = abs(fromCity.getY() - destinationCity.getY());
	return round(sqrt((xDist * xDist) + (yDist * yDist)));
}

//Returns a double, for tour distance
double Tour::getDistance(){
	if (distance == 0)
	{
		int size = tour.size();
		for (int i = 0; i < size - 1; i++)
		{
			distance += distanceTwoCities(tour.at(i), tour.at(i + 1));
		}
		distance += distanceTwoCities(tour.at(0), tour.at(size - 1));
	}
	return distance;
}

//Returns a double, for tour fitness
double Tour::getFitness(){
	return 1 / getDistance();
}

// Returns an integer, for size of tour
int Tour::getTourSize(){
	return tour.size();
}