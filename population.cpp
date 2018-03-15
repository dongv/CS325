/*
* File:   population.hpp
* Author: orcutts
*/

#include "tour.hpp"
#include "population.hpp"
#include "tspCity.hpp"
#include <vector>
using std::vector;

// Creates a new population
Population::Population(int popSize, vector<tspCity> Cities){
	/*OLD Tour* newTour = new Tour(Cities);
	distance = newTour->getDistance();
	fitness = newTour.getFitness();*/

	/*VECTOR EXAMPLE:  for (int i = 0; i < popSize; i++)
	{
		cl.addCity(tspCity(i));
	}
	for (int i = 0; i < popSize; i++)
	{
		tours.push_back(cl.getCityList());
	}*/
	size = tours.size();
}

// Default constructor
Population::Population(){
	size = 0;
}

//Destructor
Population::~Population() {

}

//Saves a tour
void Population::saveTour(Tour thisTour){
	tours.push_back(thisTour);
	size++;
}

// Adds a tour to a specific index
/*** CLEANUP void Population::addTour(Tour t, int i){
	tours.at(i) = t;
}*/

// Gets tour at i
Tour Population::getTour(int i){
	return tours.at(i);
}

//Returns the shortest tour
Tour Population::getFittest(){
	Tour fittest = tours.at(0);
	for (int i = 1; i < size; i++)
	{
		if (fittest.getFitness() < tours.at(i).getFitness())
		{
			fittest = tours.at(i);
		}
	}
	return fittest;
}

//Returns an integer for the population size
int Population::populationSize(){
	return size;
}