/*
 * Chris Correll 2016 
 * A class to represent an expense. This class contains the cost of each item
 * and the people splitting it and provides functions to calculate the cost each
 * person owes on the item.
 */

#ifndef EXPENSE_RESOLVER_EXPENSE_HPP
#define EXPENSE_RESOLVER_EXPENSE_HPP

// Includes
#include <vector>

class Expense
{
public:
    // Default constructor
    Expense()
    {}

    // Overloaded constructor
    Expense(float cost_):
        cost(cost_)
    {}

    // Destructor
    virtual ~Expense()
    {}

    // Return the cost of this item per person based on how many people are
    // responsible for paying for it
    float determine_cost() const
    {
        return cost / purchasers.size();
    }

    // A vector of people responsible for this expense
    std::vector<Person &> purchasers;
    // The cost of this expense
    float cost;
}

#endif // EXPENSE_RESOLVER_EXPENSE_HPP

