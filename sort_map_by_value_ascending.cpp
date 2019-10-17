#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <iostream>
 
int main() 
{
 
	// Creating & Initializing a map of String & Ints
	std::map<std::string, int> mapOfWordCount = { { "a", 10 }, { "b", 41 }, { "c", 62 }, { "d", 13 } };
 
	// Declaring the type of Predicate that accepts 2 pairs and return a bool
	typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;
 
	// Defining a lambda function to compare two pairs. It will compare two pairs using second field
	Comparator compFunctor =
			[](std::pair<std::string, int> element1 ,std::pair<std::string, int> element2)
			{
				return element1.second < element2.second;
			};
 
	// Declaring a set that will store the pairs using above comparision logic
	std::set<std::pair<std::string, int>, Comparator> setOfWords(mapOfWordCount.begin(), mapOfWordCount.end(), compFunctor);
 
	// Iterate over a set
	// It will display the items in sorted order of values
	for (std::pair<std::string, int> element : setOfWords)
		std::cout << element.first << " :: " << element.second << std::endl;
 
	return 0;
}
