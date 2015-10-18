#ifndef __NUMBER_H_INCLUDED__
#define __NUMBER_H_INCLUDED__
#include <cmath>
#include <cstdlib>
#include <string>
#include <iostream>

class Number {

	public:
    virtual double l1norm() =0;
    virtual int size() = 0;
    virtual std::string type()=0;
};

#endif
