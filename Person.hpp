/*
 * Matthew Diamond 2016
 * A class to represent a person. This class should be used to keep track of
 * what expenses a person is responsible for, and provide functions to
 * determine how much the person should pay for stuff, etc.
 */

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

    // Pay another person based on this person's amount owed
    void pay(Person &p)
    {
        std::cout << name << " paying " << p.name << amount_owed << std::endl;
        p.amount_paid -= amount_owed;
        p.amount_owed += amount_owed;
        amount_paid += amount_owed;
        amount_owed = 0;
    }

    // Return a string explaining this person's current status
    std::string const& to_str() const
    {
        return name + " paid " + amount_paid + " and owes " + amount_owed;
    }

    // This person's name
    std::string name;
    // How much this person has already paid
    float amount_paid;
    // How much this person owes
    float amount_owed;
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
