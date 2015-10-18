#ifndef __DOUBLE_H_INCLUDED__
#define __DOUBLE_H_INCLUDED__
#include <cmath>
#include <cstdlib>
#include <string>
#include <iostream>
//#include "Number.h"
class Double {
	private:
		double primitive;

	public:
		Double();
    Double(double);
    double getPrimitive() const;
    double l1norm();
    Double multiply(Double&) const;
    Double multiply(double) const;
    Double add(double) const;
    Double add(Double&) const;
    Double subtract(Double&) const;
    Double subtract(double) const;
    Double divide(double) const;
    Double divide(Double&) const;
    Double exp() const;
    Double pow(double) const;
    Double pow(Double&) const;
    Double operator=(double);
    friend std::ostream& operator<<(std::ostream& out, const Double& x) {
        out<<x.getPrimitive();
        return out;
    }
    int size();
    std::string type();

		friend bool operator==(Double&, double);

		friend bool operator==(Double&, Double&);

		friend bool operator==(double, Double&);

		friend Double operator+(Double&, Double&);

		friend Double operator+(double, Double&);

		friend Double operator+(Double&, double);

		friend Double operator-(Double&, double);

		friend Double operator-(Double&, Double&);

		friend Double operator-(double, Double&);

		friend Double operator/(Double&, Double&);

		friend Double operator/(Double&, double);

		friend Double operator/(double, Double&);

		friend Double operator*(Double&, Double&);

		friend Double operator*(double, Double&);

		friend Double operator*(Double&, double);

};

#endif
