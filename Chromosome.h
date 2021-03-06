#ifndef TRANSIT_CHROMOSOME_H
#define TRANSIT_CHROMOSOME_H

#include <vector>

#include "RoutesCache.h"
#include "Gene.h"
#include "Passenger.h"


class Chromosome {
private:
  std::vector<Gene> genes;
public:
  Chromosome() { };
  size_t size() {
    return genes.size();
  }
  const Gene &getGene(size_t id) const {
    return genes[id];
  }
  void addGene(const Gene &gene) {
    genes.push_back(gene);
  }
  Graph generateSolutionGraph(const Graph &original,
                              RoutesCache &routesCache) const;
  float calculateCost(const Graph &original,
                      const std::vector<Passenger> &passengers,
                      RoutesCache &routesCache) const;
};


#endif //TRANSIT_CHROMOSOME_H
