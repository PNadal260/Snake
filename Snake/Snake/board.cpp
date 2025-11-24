#include <iostream>

void board() {
	int base = 20, heigth = 10;
	for (int i = 1; i <= heigth; i++) {
		for (int j = 1; j <= base; j++)
		{
			if (i == 1 || i == heigth)
			{
				std::cout << "-";
			}
			else if (j == 1 || j == base)
			{
				std::cout << "|";
			}
			else
			{
				std::cout << " ";
			}

		}
		std::cout << std::endl;
	}
}