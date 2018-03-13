//
//  GA.cpp
//
//  Created by Vinh on 3/10/18.
//
//
#include <cstdlib>  //for rand
#include "Population.hpp"
#include "Tour.hpp"
#include "GA.hpp"

GA::GA(){}

    // Evolves a population over one generation
    Population GA::evolvePopulation(Population pop) {
        Population newPopulation = new Population(pop.populationSize(), false);
        
        // Keep our best individual if elitism is enabled
        int elitismOffset = 0;
        if (elitism) {
            newPopulation.saveTour(0, pop.getFittest());
            elitismOffset = 1;
        }
        
        // Crossover population
        // Loop over the new population's size and create individuals from
        // Current population
        for (int i = elitismOffset; i < newPopulation.populationSize(); i++) {
            // Select parents
            Tour parent1 = tournamentSelection(pop);
            Tour parent2 = tournamentSelection(pop);
            // Crossover parents
            Tour child = crossover(parent1, parent2);
            // Add child to new population
            newPopulation.saveTour(i, child);
        }
        
        // Mutate the new population a bit to add some new genetic material
        for (int i = elitismOffset; i < newPopulation.populationSize(); i++) {
            mutate(newPopulation.getTour(i));
        }
        
        return newPopulation;
    }
    
    // Applies crossover to a set of parents and creates offspring
    Tour GA::crossover(Tour parent1, Tour parent2) {
        // Create new child tour
        Tour child = new Tour();
        
        // Get start and end subset tour positions for parent1's tour
        int startPos = (rand() % parent1.tourSize());
        int endPos = (rand() % parent1.tourSize());
        
        // Loop and add the sub tour from parent1 to our child
        for (int i = 0; i < child.tourSize(); i++) {
            // If our start position is less than the end position
            if (startPos < endPos && i > startPos && i < endPos) {
                child.setCity(i, parent1.getCity(i));
            } // If start position is larger than end position it 
            else if (startPos > endPos) {
                if (!(i < startPos && i > endPos)) {
                    child.setCity(i, parent1.getCity(i));
                }
            }
        }
        
        // Loop through parent2's city tour
        for (int i = 0; i < parent2.tourSize(); i++) {
            // If child doesn't have the city add it
            if (!child.containsCity(parent2.getCity(i))) {
                // Loop to find a spare position in the child's tour
                for (int j = 0; j < child.tourSize(); j++) {
                    // Spare position found, add city
                    if (child.getCity(j) == null) {
                        child.setCity(j, parent2.getCity(i));
                    }
                }
            }
        }
        return child;
    }
    
    // Mutate a tour using swap mutation
    void GA::mutate(Tour tour) {
        // Loop through tour cities
        for(int tourPos1=0; tourPos1 < tour.tourSize(); tourPos1++){
            // Apply mutation rate
            if((rand()%100) < mutationRate){
                // Get a second random position in the tour
                int tourPos2 = (rand() % tour.tourSize());
                
                // Get the cities at target position in tour
                tspCity city1 = tour.getCity(tourPos1);
                tspCity city2 = tour.getCity(tourPos2);
                
                // Swap them around
                tour.setCity(tourPos2, city1);
                tour.setCity(tourPos1, city2);
            }
        }
    }
    
    // Selects candidate tour for crossover
    Tour GA::tournamentSelection(Population pop) {
        // Create a tournament population
        Population tournament = new Population(tournamentSize, false);
        // For each place in the tournament get a random candidate tour and
        // add it
        for (int i = 0; i < tournamentSize; i++) {
            int randomId = (rand() % pop.populationSize());
            tournament.saveTour(i, pop.getTour(randomId));
        }
        // Get the fittest tour
        Tour fittest = tournament.getFittest();
        return fittest;
    }
}
