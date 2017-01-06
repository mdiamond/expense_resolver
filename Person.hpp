/*
 * Expense Resolver Program
 * Chris Correll & Matthew Diamond 2016
 * Person class
 *
 * This class contains information about a person, including their name, what
 * expenses they owe money towards, and other information. It also provides
 * some functions for calculating and transferring money.
 */

#ifndef EXPENSE_RESOLVER_PERSON_HPP
#define EXPENSE_RESOLVER_PERSON_HPP

#include <string>
#include <vector>
#include <iostream>

// Forward declare Expense class
class Expense;

class Person
{
public:
    // Default constructor
    Person() = default;

    // Constructor
    Person(std::string &, float);

    // Calculate how much this person owes based on expenses
    void calculate_balance();

    // Pay another person based on this person's amount owed
    void pay(Person &);

    // > operator for comparisons
    bool operator>(const Person &) const;

    // Return a string explaining this person's current status
    std::string const to_str() const;

    // This person's name
    std::string name;
    // How much this person has already paid
    float amount_paid = 0;
    // How much this person owes to others based on total balance
    float balance = 0;
    // How much this person owes total
    float balance_total = 0;
    // A vector of expenses that this person is responsible for
    std::vector<Expense *> expenses;

private:
    // Overload << operator
    friend std::ostream & operator<<(std::ostream &, const Person &);
};

#endif // EXPENSE_RESOLVER_PERSON_HPP

