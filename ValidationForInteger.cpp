#include <iostream>

bool isNumber(std::string);

int main()
{
	std::string number;
	bool valid=false;
	do{
		std::cout << "Enter an integer and wait for the validation: ";
		std::getline(std::cin,number);
		valid=isNumber(number);
    
	}while(!valid);

	std::cout << "Welcome to the team " << number << ". We're glad to have you here with us!" << std::endl;
return 0;
}

bool isNumber(std::string number)
{
	if(number.empty()) return false;
	for(size_t i{0}; i<number.length(); i++)
		{
			if(!isdigit(number[i]))
			{
				std::cout << "Found character '" << number[i] << "' which is not a valid character for a name. \n";
				return false;
			}
		}
	return true;
}
