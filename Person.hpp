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
    Person(std::string &name_, float amount_paid_) :
        name(name_), amount_paid(amount_paid_)
    {}

    // Destructor
    virtual ~Person()
    {}

    // Calculate how much this person owes based on expenses
    // doesnt this need to check epxenses to make sure person is in list
    void calculate_balance()
    {
        for(auto it = expenses.begin(); it != expenses.end(); it ++)
        {
            for(auto it_ = expenses.purchasers.begin(); it_ != expenses.purchasers.end(); it_++)
            {
                if(*it_ == name)
                {
                    balance_total += it->determine_cost();
                }
            }
        }
        balance = balance_total - amount_paid;
    }

    // Pay another person based on this person's amount owed
    void pay(Person &other_person)
    {
        std::cout << name << " paying " << other_person.name << balance
                  << std::endl;
        other_person.amount_paid -= balance;
        other_person.balance += balance;
        amount_paid += balance;
        balance = 0;
    }

    // < operator for comparisons
    bool operator<(const Person &other_person) const
    {
        return amound_paid < other_person.amount_paid;
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
std::ostream & operator<<(std::ostream &os, const Person &person)
{
    return os << person.to_str();
}

#endif // EXPENSE_RESOLVER_PERSON_HPP

