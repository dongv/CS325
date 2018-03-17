//
//  GA.cpp
//
//  Created by Vinh on 3/10/18.
//
//


#include "GA.hpp"
//#include "Population.hpp"
//#include "tour.hpp"

GA::GA(){}

GA::~GA() {
    // empty for now
}

// Evolves a population over one generation
Population GA::evolvePopulation(Population pop) {
    Population newGen = Population();
    
    // Keep our best tour when elite is set to ture
    int eliteOffset = 0;  //elite offset to keep fittest tour from previous gen
    if (elite) {
        newGen.saveTour(pop.getFittest());  //save previous fittest tour to new gen
        eliteOffset = 1;                    
        //change offset to 1 to skip first tour that is save to new gen
    }
   
    // Loop over the new population's size and create child from
    // selected parents, start at i=1 (offset)
    for (int i = eliteOffset; i < pop.populationSize(); i++) {
        // Select parents
        Tour p1 = tournamentSelection(pop);  //select 5 tour from population size
        Tour p2 = newGen.getTour(0);         //use elite tour as parent 2
        // Crossover parents
        Tour child = crossover(p1, p2);      //create child tour from p1 and p2
        // Add child to new population
        newGen.saveTour(child);   // save child to new Gen population
    }
    
   // Mutate the new population to increase variation
    for (int i = eliteOffset; i < pop.populationSize(); i++) {
        mutate(newGen.getTour(i));   
        //mutate all tours in new population except for elite tour
    }
    return newGen;
}
    
// crossover to a set of parents and create child
Tour GA::crossover(Tour p1, Tour p2) {
    // Create new child tour
    Tour child = Tour();
	int pSize = p1.getTourSize();
	std::unordered_set<int> citiesOnTour; // Holds IDs of cities currently on tour, prevents repeats
	int s1 = rand() % (pSize / 2); // How much of tour to take from first half of parent1
	int s2 = rand() % (pSize / 2); // How much of tour to take from second half of parent1
	s2 = pSize - s2; // Where to start taking the subset from parent1
	for (int i = 0; i < s1; i++) // Add cities from first half of parent1;
	{
		child.setCity(p1.getCity(i));
		citiesOnTour.insert(p1.getCity(i).getId());
	}
	for (int i = s2; i < pSize; i++)  // Add cities from 2nd half of parent1;
	{
		child.setCity(p1.getCity(i));
		citiesOnTour.insert(p1.getCity(i).getId());
	}
	// Fill in missing cities using parent 2
	int iter = 0;
	while (child.getTourSize() != pSize)
	{
		if (citiesOnTour.count(p2.getCity(iter).getId()) == 0)
		{
			child.setCity(p2.getCity(iter));
		}
		iter++;
	}
	return child;
}

    
// Mutate a tour using swap mutation
void GA::mutate(Tour tour) {
    // Loop through tour cities
    for(int i=0; i < tour.getTourSize(); i++){
        // Apply mutation rate
        if((rand()%100) < muteRate){
            // Get a second random position in the tour
            int tourPos = (rand() % tour.getTourSize());
            
            // Get the cities at target position in tour
            tspCity city1 = tour.getCity(i);
            tspCity city2 = tour.getCity(tourPos);
            
            // Swap them around
            tour.setCity(tourPos, city1);
            tour.setCity(i, city2);
        }
    }
}
    
// Selects candidate tour for crossover
Tour GA::tournamentSelection(Population pop) {
    // Create a tournament population
	Population tournament;
    // For each place in the tournament get a random candidate tour and
    // add it to population
    for (int i = 0; i < tSize; i++) {
        int randID = (rand() % pop.populationSize());
        tournament.saveTour(pop.getTour(randID));
    }
    // Get the fittest tour in tournament size
    Tour fittest = tournament.getFittest();
    return fittest;
}

