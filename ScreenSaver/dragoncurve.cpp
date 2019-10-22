#include "dragoncurve.h"
#include <vector>
#include<complexnumber.h>

DragonCurve::DragonCurve(){
    iteration = 0;
}

void DragonCurve::generateCurve(int iterations) {

    if(vertexes.empty()) {
        std::pair<ComplexNumber, ComplexNumber> initial(ComplexNumber(0, 0), ComplexNumber(0, 1));
        add(std::pair<std::pair<ComplexNumber, ComplexNumber>, int>(initial, iteration));
    }

    for(int i = 0; i < iterations; i++)
        nextIteration();
}

void DragonCurve::nextIteration() {
    iteration++;
    std::vector<std::pair<std::pair<ComplexNumber, ComplexNumber>, int>> actualScenario(vertexes);

    for(int i = actualScenario.size() -1; i >= 0; i--) {
        std::pair<ComplexNumber, ComplexNumber>
                pairToRotate(actualScenario[i].first.first, actualScenario[i].first.second);
        std::pair<ComplexNumber, ComplexNumber>
                lastPair(vertexes[vertexes.size()-1].first.first, vertexes[vertexes.size()-1].first.second);

        std::pair<ComplexNumber, ComplexNumber>
                newPair(lastPair.second, ComplexNumber::rotate(pairToRotate).put(lastPair.second));

        std::pair<std::pair<ComplexNumber, ComplexNumber>, int> newElement(newPair, iteration);
        add(newElement);
    }
}

void DragonCurve::add(std::pair<std::pair<ComplexNumber, ComplexNumber>, int> next) {
    vertexes.insert(vertexes.end(), next);
}

int DragonCurve::getIteration() {
    return iteration;
}

std::vector<std::pair<std::pair<ComplexNumber, ComplexNumber>, int>> DragonCurve::getVertexes() {
    return vertexes;
}

std::vector<std::pair<ComplexNumber, int>> DragonCurve::getResumedVertexes() {
    std::vector<std::pair<ComplexNumber, int>> resumedList;

    resumedList.insert(resumedList.begin(), std::pair<ComplexNumber, int>(ComplexNumber(0,0), 0));

    for(std::pair<std::pair<ComplexNumber, ComplexNumber>, int> p : vertexes) {
        resumedList.insert(resumedList.end(), std::pair<ComplexNumber, int>(p.first.second, p.second));
    }
}
