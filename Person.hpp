/*
 * Matthew Diamond 2016
 * A class to represent a person. This class should be used to keep track of
 * what expenses a person is responsible for, and provide functions to
 * determine how much the person should pay for stuff, etc.
 */

#ifndef EXPENSE_RESOLVER_PERSON_HPP
#define EXPENSE_RESOLVER_PERSON_HPP

// Includes
#include <string>
#include <vector>
#include <iostream>

class Person
{
public:
    // Default constructor
    Person()
    {}

    // Overloaded constructor
    Person(std::string &s, float f) :
        name(s), amount_paid(f)
    {}

    // Destructor
    virtual ~Person()
    {}

    // Calculate how much this person owes based on expenses
    void calculate_balance()
    {
        for(auto it = expenses.begin(); it != expenses.end(); it ++)
        {
            balance_total += it->determine_cost();
        }
        balance = balance_total - amount_paid;
    }

    // Pay another person based on this person's amount owed
    void pay(Person &p)
    {
        std::cout << name << " paying " << p.name << balance << std::endl;
        p.amount_paid -= balance;
        p.balance += balance;
        amount_paid += balance;
        balance = 0;
    }

    // Return a string explaining this person's current status
    std::string const& to_str() const
    {
        return name + " paid " + amount_paid + " and owes " + balance;
    }

    // This person's name
    std::string name;
    // How much this person has already paid
    float amount_paid;
    // How much this person owes to others based on total balance
    float balance;
    // How much this person owes total
    float balance_total;
    // A vector of expenses that this person is responsible for
    std::vector<Expense &> expenses;

private:
    // Overload << operator
    friend std::ostream & operator<<(std::ostream &, const Person &);
};

// Overload << operator
std::ostream & operator<<(std::ostream &os, const Person &p)
{
    return os << p.to_str();
}

#endif // EXPENSE_RESOLVER_PERSON_HPP

