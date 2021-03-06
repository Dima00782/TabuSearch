#ifndef SIMPLEASSIGNMENTPROBLEMTABUSEARCH_HPP
#define SIMPLEASSIGNMENTPROBLEMTABUSEARCH_HPP

#include "InitialStandardData/TaskData.hpp"
#include "ITabuSearch.hpp"
#include "Neighborhood/INeighborhood.hpp"
#include "TabuList/ITabuList.hpp"
#include "AspirationCriteria/IAspirationCriteria.hpp"

template<class Solution, class Neighborhood, class AssignmentProblemNeighborhood, class TabuList, class AspirationCriteria>
class SimpleAssignmentProblemTabuSearch : public ITabuSearch<Solution>
{
public:
    SimpleAssignmentProblemTabuSearch
    (
            Solution&&                      _initSolution,
            Neighborhood&&                  _neighborhood,
            AssignmentProblemNeighborhood&& _assignmentProblemNeighborhood,
            TabuList&&                      _tabuList,
            AspirationCriteria&&            _aspirationCriteria
    );

    virtual void run(const size_t numberOfSteps) override;

    virtual Solution getBestSolution() override;

private:
    Neighborhood neighborhood;

    AssignmentProblemNeighborhood assignmentProblemNeighborhood;

    TabuList tabuList;

    AspirationCriteria aspirationCriteria;

    Solution bestSolution;

    size_t badSolutionCount;
};


#include "SimpleAssignmentProblemTabuSearch-inl.hpp"

#endif // SIMPLEASSIGNMENTPROBLEMTABUSEARCH_HPP
