/*
 * Expense Resolver Program
 * Chris Correll & Matthew Diamond 2016 
 * Main function and helper functions
 *
 * This program helps people to figure out how to settle up on a list of
 * expenses. Given N people and some expenses, as well as how much each person
 * has already paid towards those expenses, it will determine a series of N - 1
 * transactions that will get everyone settled.
 *
 * This program reads from two files. One for a list of people containing 1)
 * their name, 2) their associated char to use as a key to a map of people, and
 * 3) the amount of money they have paid toward the expenses so far. The other
 * for a list of expenses containing 1) the dollar amount of the expense, and
 * 2) which people are splitting the expenses (indicated using their associated
 * chars from the person map). The two files should be named expenses.txt and
 * people.txt, and be in the same folder as the executable when run.
 *
 * Formatting for the two files is simple, and whitespace of any length is used
 * as the delimeter.
 * Example files...
 *
 * expenses.txt
 * 250.00\t*
 * 300.00\tmc
 * 400.00\t\tmc
 *
 * people.txt
 * Chris\t\tc\t500.00
 * Matthew\tm\t450.00
 *
 * This example would result in all three expenses being split evenly between
 * Chris and Matthew, as providing the '*' character for an expense defaults to
 * splitting it evenly, and all other expenses are specifically split between
 * Chris and Matthew. In this case, the result would be that Matthew needs to
 * pay Chris 25, so that at the end they have both paid a total of 475.
 *
 * Note: All whitespace is skipped through to reach the next piece of valuable
 * information, allowing for pretty formatting of the input files if desired.
 *
 * Also note: The total amount paid so far by those involved should be
 * equivalent to the total cost of the expenses for the program to work properly.
 */

#include <fstream>
#include <map>
#include <string>
#include <vector>

#include "Person.hpp"
#include "Expense.hpp"

/*
 * Turn a string of characters into a vector of Person pointers.
 */
std::vector<Person *> chars_to_people(std::string &chars,
                                      std::map<char, Person> &people)
{
    // Resulting vector of Person pointers
    std::vector<Person *> purchasers;

    // If chars string is just "*", it means the expense is shared equally
    // between all
    if(chars == "*")
    {
        for(auto it = people.begin(); it != people.end(); it ++)
        {
            purchasers.push_back(&it->second);
        }
    }
    // Otherwise, determine who is responsible for the expense normally
    else
    {
        for(auto it = chars.begin(); it != chars.end(); it ++)
        {
            purchasers.push_back(&people[*it]);
        }
    }

    return purchasers;
}

/*
 * Main function.
 */
int main(void)
{
    // Map of people keyed on their associated characters, input stream for
    // people.txt
    std::map<char, Person> people;
    std::ifstream people_txt("people.txt");
    // Vector of expenses, input stream for expenses.txt
    std::vector<Expense> expenses;
    std::ifstream expenses_txt("expenses.txt");
   
    if(people_txt.is_open())
    {
        // Current person's name, associated character, amount paid
        std::string name;
        char ch;
        float amount_paid;
        unsigned int line_num = 0;

        // Iterate through tokens in the file, 3 per line, populate the above
        // variables, and initialize Person objects in the people map
        while(people_txt >> name >> ch >> amount_paid)
        {
            std::cout << "people.txt line " << line_num << std::endl;
            std::cout << name << " " << ch << " " << amount_paid << std::endl;
            people[ch] = Person(name, amount_paid);
            line_num ++;
        }
        people_txt.close();
    }
    else
    {
        std::cout << "Unable to open file people.txt" << std::endl;
        return 1;
    }
   
    if(expenses_txt.is_open())
    {
        // Vector of references to Person objects (purchasers of the expense),
        // cost of the expense, string of characters representing which people
        // are purchasers of the expense
        std::vector<Person *> purchasers;
        float cost;
        std::string chars;
        unsigned int line_num = 0;

        // Iterate through tokens in the file, 2 per line, populate the above
        // variables, and initialize Expense objects in the expenses vector
        while(expenses_txt >> cost >> chars)
        {
            std::cout << "expenses.txt line " << line_num << std::endl;
            std::cout << cost << " " << chars << std::endl;
            purchasers = chars_to_people(chars, people);
            expenses.push_back(Expense(purchasers, cost));
            line_num ++;
        }
        expenses_txt.close();
    }
    else
    {
        std::cout << "Unable to open file expenses.txt" << std::endl;
        return 1;
    }

    // Iterate through expenses, ensure they all have correct records of who
    // is responsible for them, print them out
    for(auto it = expenses.begin(); it != expenses.end(); it++)
    {
        it->distribute_expense();
        std::cout << *it << std::endl;
    }

    // Iterate through people, calculate their balances, print them out
    for(auto it = people.begin(); it != people.end(); it++)
    {
        it->second.calculate_balance();
        std::cout << it->second << std::endl;
    }

    return 0;
}

