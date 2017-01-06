/*
 * Expense Resolver Program
 * Chris Correll & Matthew Diamond 2016
 * Expense class implementation
 */

#include "Expense.hpp"

Expense::Expense(std::vector<Person *> purchasers_, float cost_):
    purchasers(purchasers_), cost(cost_)
{}

float Expense::determine_cost() const
{
    return cost / purchasers.size();
}

void Expense::distribute_expense()
{
    for(auto it = purchasers.begin(); it != purchasers.end(); it ++)
    {
        (*it)->expenses.push_back(this);
    }
}

std::string const Expense::to_str() const
{
    std::string result = "$" + std::to_string(cost) + " expense to be split between "
                         + std::to_string(purchasers.size()) + " people (";
    for(auto it = purchasers.begin(); it != purchasers.end(); it ++)
    {
        result += (*it)->name + ", ";
    }
    if(purchasers.size() != 0)
    {
        result.pop_back();
        result.pop_back();
    }
    result += ")";
    return result;
}

std::ostream & operator << (std::ostream &os, const Expense &expense)
{
    return os << expense.to_str();
}

