/*
 * Expense Resolver Program
 * Chris Correll & Matthew Diamond 2016
 * Person class implementation
 */

#include "Expense.hpp"
#include "Person.hpp"

Person::Person()
{}

Person::Person(std::string &name_, float amount_paid_):
    name(name_), amount_paid(amount_paid_)
{}

Person::~Person()
{}

void Person::calculate_balance()
{
    for(auto it = expenses.begin(); it != expenses.end(); it ++)
    {
        balance_total += (*it)->determine_cost();
    }
    balance = balance_total - amount_paid;
}

void Person::pay(Person &other_person)
{
    std::cout << name << " paying " << other_person.name << balance
              << std::endl;
    other_person.amount_paid -= balance;
    other_person.balance += balance;
    amount_paid += balance;
    balance = 0;
}

bool Person::operator<(const Person &other_person) const
{
    return amount_paid < other_person.amount_paid;
}

std::string const Person::to_str() const
{
    return name + " paid $" + std::to_string(amount_paid) + ", owes $"
           + std::to_string(balance) + ", and is responsible for "
           + std::to_string(expenses.size()) + " expenses worth a total of $"
           + std::to_string(balance_total);
}

std::ostream & operator<<(std::ostream &os, const Person &person)
{
    return os << person.to_str();
}

