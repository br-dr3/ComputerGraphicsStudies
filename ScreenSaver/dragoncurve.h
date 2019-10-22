#ifndef DRAGONCURVE_H
#define DRAGONCURVE_H

#include <vector>
#include <complexnumber.h>

class DragonCurve
{
    int iteration;
    std::vector<std::pair<std::pair<ComplexNumber, ComplexNumber>, int>> vertexes;

public:
    DragonCurve();
    void generateCurve(int iterations);
    void nextIteration();
    void add(std::pair<std::pair<ComplexNumber, ComplexNumber>, int> next);
    int getIteration();
    std::vector<std::pair<std::pair<ComplexNumber, ComplexNumber>, int> > getVertexes();
    std::vector<std::pair<ComplexNumber, int> > getResumedVertexes();
};

#endif // DRAGONCURVE_H
