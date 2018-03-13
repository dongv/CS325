//
//  Genetic.hpp
//
//  Created by Vinh on 3/10/18.
//

#ifndef GA_hpp
#define GA_hpp

#include <stdio.h>

class GA {
private:
    /* GA parameters */
    double mutationRate = 2;
    int tournamentSize = 5;
    bool elitism = true;
    
public:
    
    // Evolves a population over one generation
    Population evolvePopulation(Population pop);
    
    // Applies crossover to a set of parents and creates offspring
    Tour crossover(Tour parent1, Tour parent2);
    
    // Mutate a tour using swap mutation
    void mutate(Tour tour);
    
    // Selects candidate tour for crossover
    Tour tournamentSelection(Population pop);
};

#endif /* Genetic_hpp */
