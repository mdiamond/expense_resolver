/*
 * Expense Resolver Program
 * Chris Correll & Matthew Diamond 2016
 * Person class implementation
 */

#include "Expense.hpp"
#include "Person.hpp"

Person::Person(std::string &name_, float amount_paid_):
    name(name_), amount_paid(amount_paid_)
{}

void Person::calculate_balance()
{
    balance = 0;
    for(auto it = expenses.begin(); it != expenses.end(); it ++)
    {
        balance_total += (*it)->determine_cost();
    }
    balance = balance_total - amount_paid;
}

void Person::pay(Person &other_person)
{
    std::cout << name << " pays " << other_person.name << " " << balance;
    
    // Other person receives this person's balance as payment
    other_person.amount_paid -= balance;
    other_person.balance += balance;

    // If other person's balance is under one cent, round to 0
    if(other_person.balance < .01)
    {
        other_person.balance = 0;
    }

    // This person's amount paid increased by their balance, their balance is
    // now 0
    amount_paid += balance;
    balance = 0;

    std::cout << ", " << name << " has now paid a total of $" << amount_paid
              << " and has a balance of $" << balance << std::endl;
}

bool Person::operator > (const Person &other_person) const
{
    return balance > other_person.balance;
}

std::string const Person::to_str() const
{
    return name + " has paid a total of $" + std::to_string(amount_paid) + ", is responsible for "
           + std::to_string(expenses.size()) + " expenses worth a total of $"
           + std::to_string(balance_total) + ", and has a balance of $"
           + std::to_string(balance);
}

std::ostream & operator << (std::ostream &os, const Person &person)
{
    return os << person.to_str();
}

