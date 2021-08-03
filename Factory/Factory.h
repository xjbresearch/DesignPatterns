/*
 * C++ Design Patterns: Factory
 * Author: lackywind [github.com/xjbevasion]
 * 2021
 *
 */

#ifndef __FACTORY_H__
#define __FACTORY_H__

#include <iostream>
#include <string>

/*
 * AbstractProduct
 * products implement the same interface so that the classes can refer
 * to the interface not the concrete product
 */
class AbstractProduct
{
public:
	virtual std::string GetName() = 0;
	virtual ~AbstractProduct() {};
};

/*
 * Product subclass
 * products concreted.
 */
class ProductA:public AbstractProduct
{
public:
	std::string GetName() {return "ProductA";};
	~ProductA() {};
};

class ProductB:public AbstractProduct
{
public:
	std::string GetName() {return "ProductB";};
	~ProductB() {};
};

class ProductC:public AbstractProduct
{
public:
	std::string GetName() {return "ProductC";};
	~ProductC() {};
};

/*
 * Product Factory
 * products should be got from factory.
 */
 class ProductFactory
{
public:
	enum ProductTpye {
		A_Product,
		B_Product,
		C_Product
	};

	static AbstractProduct* createProduct(ProductTpye productType)
	{
		switch(productType)
		{
		case A_Product:
			return (new ProductA());
		case B_Product:
			return (new ProductB());
		case C_Product:
			return (new ProductC());
		}
		std::cout << "invalid product type." << std::endl;
		return NULL;
	}
};

void productInformation(ProductFactory::ProductTpye productType);

#endif