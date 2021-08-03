/*
 * C++ Design Patterns: Factory
 * Author: lackywind [github.com/xjbevasion]
 * 2021
 *
 */
 
#include "Factory.h"

void productInformation(ProductFactory::ProductTpye productType)
{
	AbstractProduct* product = ProductFactory::createProduct(productType);
	if (NULL != product)
	{
		std::cout << "product of " << productType << " is " << product->GetName().c_str() << std::endl;
		delete product;
	}
}