/*
 * C++ Design Patterns: Builder
 * Author: lackywind [github.com/xjbevasion]
 * 2021
 *
 */
 
#include "Builder.h"
 
int main()
{
	Director *pDirector = NULL;
	AbstractBuilder *pAbsbuilder = NULL;
	Product *pProduct = NULL;
	
	pDirector = new Director();
	
	pAbsbuilder = new BuilderX();
	pDirector->setBuilder(pAbsbuilder);
	pDirector->construct();
	pProduct = pDirector->getProduct();
	std::cout << pProduct->productShow() << std::endl;
	delete pAbsbuilder;
	
	pAbsbuilder = new BuilderY();
	pDirector->setBuilder(pAbsbuilder);
	pDirector->construct();
	pProduct = pDirector->getProduct();
	std::cout << pProduct->productShow() << std::endl;
	delete pAbsbuilder;
	
	delete pDirector;
	
	return 0;
}