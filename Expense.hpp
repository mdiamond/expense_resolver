/*
 * Expense Resolver Program
 * Chris Correll & Matthew Diamond 2016
 * Expense class
 *
 * This class contains the cost of an item and a vector of references to the
 * people splitting it and provides a function to calculate the amount each
 * person owes towards the item.
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
    Expense(float cost_, std::vector<Person &> purchasers_):
        cost(cost_), purchasers(purchasers_)
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

