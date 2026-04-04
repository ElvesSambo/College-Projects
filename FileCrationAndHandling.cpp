#include <iostream>
#include <string>
#include <fstream>
#include <limits>

void ProductName();
void ProductPrice(std::string nameOfProduct);
void addItemToList(std::string name, float price);
void readInventory();
int main()
{
	size_t option{0};

	std::cout << "*=====* MENU *=====*\n";
	std::cout << "1. Add Item(s) and it's price(s)\n";
	std::cout << "2. Look at inventory\n";
	std::cout << "3. Clean inventory\n";
	std::cout << "Option: ";
	std::cin >> option;

	switch (option)
	{
		case 1:
			{
				size_t numberOfItems{0};
				std::cout << "How many Items you will insert: ";
				std::cin >> numberOfItems;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
				for(size_t i{0}; i<numberOfItems; i++)
					{
						ProductName();
					}
				break;
			}
		case 2:
			readInventory();
			break;
		
		case 3:
			{
				std::ofstream file("inventory.txt");
	
				if(file.is_open())
				{
					std::cout << "File has been cleaned " << std::endl;
					file.close();
				}else
				{
					std::cout << "****COULDN'T OPEN FILE TO CLEAN...****" << std::endl;
				}
				
				break;
			}
		default:
			std::cout << "INVALID OPTION... RESTART THE PROCCES." << std::endl;
			break;
	}
	
	return 0;
}

void ProductName()
{
	std::string name{};
	std::cout << "NAME OF PRODUCT: ";
	std::getline(std::cin,name);
	ProductPrice(name);
}

void ProductPrice(std::string nameOfProduct)
{
	float price{};
	std::cout << "PRICE OF " << nameOfProduct << ": ";
	std::cin >> price;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	addItemToList(nameOfProduct,price);
}

void addItemToList(std::string name, float price)
{
	std::ofstream file("inventory.txt",std::ios::app);

	if(file.is_open())
	{
		file << name << " ==== " << price << std::endl;
		file.close();
	}else
	{
		std::cout << "****PROBLEM OPENING FILE...****" << std::endl;
	}

}

void readInventory()
{
	std::ifstream file("inventory.txt");

	std::string line;
	if(file.is_open())
	{	
		while(std::getline(file,line))
		{
				std::cout << line << std::endl;
		}
		file.close();
	}else
	{
		std::cout << "****COULDN'T READ INVENTORY...****" << std::endl;
	}
}
