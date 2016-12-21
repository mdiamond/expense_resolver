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
 * 250.00
 * 300.00\tmc
 * 400.00\t\tmc
 *
 * people.txt
 * Chris\t\tc\t500.00
 * Matthew\tm\t450.00
 *
 * This example would result in all three expenses being split evenly between
 * Chris and Matthew, as providing no characters for an expense defaults to
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
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Person.hpp"
#include "Expense.hpp"
 balance sort map and then pay
/*
 * Tokenize a string using whitespace as the delimeter.
 */
split(const std::string &line, std::vector<string> &split_data)
{   
    std::string word;
    for(auto it = line.begin(); it != line.end(); it++)
    {
        if(*it != " ")
        {
            word.push_back(*it);
        }
        else
        {
            while(*it == " ")
                {
                    it++;     
                }
        split_data.push_back(word);
        word.clear();
        }
    } 
}

/*
 * Turn a string of characters into a vector of Person references.
 */
std::vector<Person &> chars_to_people(std::string &chars,
                                      std::map<Person> &people)
{
    std::vector<Person &> purchasers;
    for(auto it = chars.begin(); it != chars.end(); it ++)
    {
        purchasers.push_back(people[*it]);
    }
    return purchasers;
}

/*
 * Main function.
 */
int main(void)
{
    // Current line from an input file, map of people keyed on their associated
    // characters, input stream for people.txt
    std::string line;
    std::map<char, Person> people;
    std::ifstream people_txt("people.txt");
   
    if(people_txt.is_open())
    {
        // Current person's name, associated character, amount paid, and vector
        // of words from the current line
        std::string name;
        char ch;
        float amount_paid;
        vector<string> split_data;

        // Iterate through lines in the file, split them into words, populate
        // the above variables, and initialize Person objects in the people map
        while(getline(myfile,line))
        {

            split(line, split_data);

            name = split_data[0];
            ch = split_data[1][0];
            amount_paid = atof(split_data[2].c_str);

            people[ch] = Person(name, amount_paid);

            split_data.clear();
        }
        people_txt.close();
    }
    else std::cout << "Unable to open file" << std::endl; 
    
    // Vector of expenses, input stream for expenses.txt
    std::vector<Expense> expenses;
    std::ifstream expenses_txt("expenses.txt");
   
    if(expenses_txt.is_open())
    {
        // Vector of references to Person objects (purchasers of the expense),
        // cost of the expense, string of characters representing which people
        // are purchasers of the expense, and vector of words from the current
        // line
        std::vector<Person &> purchasers;
        float cost;
        std::string chs;
        vector<string> split_data;

        // Iterate through lines in the file, split them into words, populate
        // the above variables, and initialize Expense objects in the expenses
        // vector
        while(getline(expenses_txt, line))
        {
            split(line, split_data);

            cost = atof(split_data[0].c_str());
            chs = split_data[1];

            purchasers = chars_to_people(chs, people);

            expenses.push_back(Expense(cost, purchasers));
            split_data.clear();
        }
        expenses_txt.close();
    }
    else std::cout << "Unable to open file" << std::endl; 
  
    // Go through Purchasers calculate balance and then pay???    
    for(auto it == purchasers.begin(); *it != purchasers.end(); it++)
    {
        it->calculate_balance();   
        // pay other person? 
    }


    return 0;
}

