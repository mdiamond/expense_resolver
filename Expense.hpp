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

#include <vector>

#include "Person.hpp"

class Expense
{
public:
    // Constructor
    Expense(std::string, std::vector<Person *>, float);

    // Return the cost of this item per person based on how many people are
    // responsible for paying for it
    float determine_cost() const;

    // Add this expense to the expenses vector in each Person object from the
    // purchasers vector
    void distribute_expense();

    // Return a string explaining this expense
    std::string const to_str() const;

    // The name of the expense
    std::string name;
    // A vector of people responsible for this expense
    std::vector<Person *> purchasers;
    // The cost of this expense
    float cost = 0;

private:
    // Overload << operator
    friend std::ostream & operator << (std::ostream &, const Expense &);
};

#endif // EXPENSE_RESOLVER_EXPENSE_HPP

