# expense_resolver
A simple C++ program for resolving expenses that need to be split between 2 or more people

## Building
This project depends on ```cmake``` and ```ninja```. To build, ensure that those two packages are installed, then run ```./build.sh``` from the root directory of the repository.

## Usage
This program requires the user to create two text files that represent the initial conditions for the expenses. Namely, the program must know the names of the people involved, their first initial (or some other single character to represent them), how much they have spent towards the expenses, the cost of each expense, and the people who want to split each expense.

The two input files can have any name, but must be supplied as the only two command line arguments when running the program. The first argument must be the name of the file specifying the people, their initials, and how much they have paid (see ```people.txt```), while the second argument must be the name of the file specifying the cost of each expense, and who is splitting each expense (see ```expenses.txt```). The data in the files may be delimited by any whitespace.

### Example execution
From the root directory of the repository, simply run ```bin/expense_resolver people.txt expenses.txt``` after building the executable.
