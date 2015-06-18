#ifndef TRANSIT_GENE_H
#define TRANSIT_GENE_H

#include <bitset>
#include <vector>

#include "SubGraph.h"
#include "Route.h"


class Gene {
private:
  typedef std::bitset<512> BitSet;
  BitSet verticesMask;
  bool isClosed;
public:
  Gene(bool isClosed) : isClosed(isClosed) { }
  const BitSet &getVerticesMask() const {
    return verticesMask;
  }
  bool getIsClosed() const {
    return isClosed;
  }
  bool operator == (const Gene &other) {
    return isClosed == other.isClosed && verticesMask == other.verticesMask;
  }
  std::vector<int> getVerticesList() const;
  static Gene generateRandomGene(int vertexCount, bool isClosed);
  Route calculateBestRoute(const Graph &graph);
};

namespace std {
template <> struct hash<Gene> {
  size_t operator()(const Gene &gene) const {
    return hash<std::bitset<512>>()(gene.getVerticesMask()) ^
        hash<bool>()(gene.getIsClosed());
  }
};
}

#endif //TRANSIT_GENE_H