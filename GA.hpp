//
//  Genetic.hpp
//
//  Created by Vinh on 3/10/18.
//

#ifndef GA_hpp
#define GA_hpp

#include <cstdlib>  //for rand
#include "Population.hpp"
#include "tour.hpp"
#include <vector>

class GA {
private:
    /* GA parameters */
    double mutationRate = 2;
    int tournamentSize = 5;
    bool elitism = true;
    
public:
    
    GA();
    
    virtual ~GA();
    
    // Evolves a population over one generation
    Population* evolvePopulation(Population* pop);
    
    // Applies crossover to a set of parents and creates offspring
    Tour crossover(Tour parent1, Tour parent2);
    
    // Mutate a tour using swap mutation
    void mutate(Tour tour);
    
    // Selects candidate tour for crossover
    Tour tournamentSelection(Population* pop);
};

#endif /* Genetic_hpp */
