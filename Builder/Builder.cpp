/*
 * C++ Design Patterns: Builder
 * Author: lackywind [github.com/xjbevasion]
 * 2021
 *
 */
#include "Builder.h"

void Product::makePartA(const std::string &strPart)
{
	strPartA = strPart;
}

void Product::makePartB(const std::string &strPart)
{
	strPartB = strPart;
}

void Product::makePartC(const std::string &strPart)
{
	strPartC = strPart;
}

std::string Product::productShow()
{
	return (strPartA + " " + strPartB + " " + strPartC);
}


void BuilderX::buildPartA()
{
	pProduct->makePartA("Part Ax");
}
	
void BuilderX::buildPartB()
{
	pProduct->makePartB("Part Bx");
}
	
void BuilderX::buildPartC()
{
	pProduct->makePartC("Part Cx");
}


void BuilderY::buildPartA()
{
	pProduct->makePartA("Part Ay");
}
	
void BuilderY::buildPartB()
{
	pProduct->makePartB("Part By");
}
	
void BuilderY::buildPartC()
{
	pProduct->makePartC("Part Cy");
}


void Director::setBuilder(AbstractBuilder *pAbsBuilder)
{
	pBuilder = pAbsBuilder;
}
	
void Director::construct()
{
	if(NULL != pBuilder)
	{
		pBuilder->buildPartA();
		pBuilder->buildPartB();
		pBuilder->buildPartC();
	}
}
	
Product* Director::getProduct()
{
	if(NULL != pBuilder)
	{
		return pBuilder->getProduct();
	}
	
	return NULL;
}