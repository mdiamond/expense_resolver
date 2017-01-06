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
    std::cout << name << " paying " << other_person.name << balance
              << std::endl;
    other_person.amount_paid -= balance;
    other_person.balance += balance;
    amount_paid += balance;
    balance = 0;
}

bool Person::operator<(const Person &other_person) const
{
    return balance < other_person.balance;
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

