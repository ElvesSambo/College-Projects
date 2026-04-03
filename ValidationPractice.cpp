#include <iostream>

bool isName(std::string);

int main()
{
	std::string name;
	bool valid=false;
	do{
		std::cout << "Enter a name and wait for the validation: ";
		std::getline(std::cin,name);
		valid=isName(name);
		if(!valid)
		{
			name="";
		}
	}while(!valid);

	std::cout << "Welcome to the team " << name << ". We're glad to have you here with us!" << std::endl;
return 0;
}

bool isName(std::string name)
{
	if(name.empty()) return false;
	for(size_t i{0}; i<name.length(); i++)
		{
			if(!isalpha(name[i]) && name[i] != ' ' && name[i] != '-')
			{
				std::cout << "Found character: " << name[i] << "which is not a valid character for a name. \n";
				return false;
			}
		}
	return true;
}
