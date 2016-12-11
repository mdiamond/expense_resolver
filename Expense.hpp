/*
* Chris Correll 2016 
* A class to represent an Expense. This class containes the cost of each item and the
* people splitting it and provides functions to calculate the cost each person owes on the item
*/

//Includes
#include <vector>

class Expense
{
public:
    Expense();
    virtual ~Expense();  //why virtual
    
    float const det_cost() const
    {
        return cost/purchasers.size(); 
    }
            
    std::vector <Person> purchasers;
    float cost;  
}
