/*
 * Chris Correll 2016 
 * Main class to take it input and output 
 */
#ifndef EXPENSE_RESOLVER_MAIN_CPP
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

split(const std::string &line, std::vector <string> &split_data)
{   
    std::stringstream ss;
    ss.str(line);
    std::string item;
    while (std::getline(ss, item, "\t")) {
        split_data.push_back(item);
}

//open list of people and list of expenses
int main(void)
{
    std::string line;
    std::vector < vector <Person> > people;
    std::ifstream people_txt ("people.txt");
   
    if (people_txt.is_open())
    {
        while (getline (myfile,line))
        {
            vector <string> split_data;
            split(line);
            people_txt.push_back(Person(split_data[0], split_data[2]));
        }

        people_txt.close();
    }
 
    else cout << "Unable to open file"; 
    
    std::vector < vector <Person> > people;
    std::ifstream expenses_txt ("expenses.txt");
   
    if (expenses_txt.is_open())
    {
        while (getline (expenses_txt,line))
        {
            vector <string> split_data;
            split(line);
            expenses.push_back(Expense(split_data[0], split_data[1]));
        }

        expenses_txt.close();
    }
 
    else cout << "Unable to open file"; 
  
    return 0;
}
