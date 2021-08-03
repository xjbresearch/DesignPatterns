/*
 * C++ Design Patterns: Factory
 * Author: lackywind [github.com/xjbevasion]
 * 2021
 *
 */
 
#include "Factory.h"
 
int main()
{
	productInformation(ProductFactory::A_Product);
	productInformation(ProductFactory::B_Product);
	productInformation(ProductFactory::C_Product);
	
	return 0;
}