/*
 * C++ Design Patterns: Builder
 * Author: lackywind [github.com/xjbevasion]
 * 2021
 *
 */

#ifndef __BUILDER_H__
#define __BUILDER_H__

#include <iostream>
#include <string>

/*
* Product
* the final object that will be created using Builder
*/
class Product
{
public:
	Product() {}
		
	void makePartA(const std::string &strPart);
	void makePartB(const std::string &strPart);
	void makePartC(const std::string &strPart);
	std::string productShow();
private:
	std::string strPartA;
	std::string strPartB;
	std::string strPartC;
};

/*
* Builder 
* abstract interface for creating products
*/
class AbstractBuilder
{
public:
	AbstractBuilder(){ pProduct = new Product;}
	~AbstractBuilder()
	{
		if(NULL != pProduct)
		{
			delete pProduct;
			pProduct = NULL;	
		}
	}
	
	virtual void buildPartA() = 0;
	virtual void buildPartB() = 0;
	virtual void buildPartC() = 0;
	Product* getProduct(){return pProduct;};

	Product *pProduct;
};

/*
* Concrete Builder X and Y
* create real products and store them in the composite structure
*/
class BuilderX:public AbstractBuilder
{
	void buildPartA();
	void buildPartB();
	void buildPartC();
};

class BuilderY:public AbstractBuilder
{
	void buildPartA();
	void buildPartB();
	void buildPartC();
};

/*
* Director
* responsible for managing the correct sequence of object creation
*/
class Director
{
public:
	Director(){pBuilder = NULL;};
	~Director()	{};
	
	void setBuilder(AbstractBuilder *pAbsBuilder);
	void construct();
	Product* getProduct();	
private:
	AbstractBuilder *pBuilder;
};

#endif