#include "Double.h"

Double::Double(double val){
    primitive=val;
}

Double::Double(){
    primitive=0;
}

double Double::getPrimitive() const{
    return primitive;
}

int Double::size(){
    return 1;
}

std::string Double::type(){ //introspection
    return "Double";
}

double Double::l1norm(){
  return primitive;
}
Double Double::multiply(double x) const{
    return Double(x*primitive);
}

Double Double::multiply(Double &x) const{
    return Double(x.getPrimitive()*primitive);
}

Double Double::subtract(double x) const{
    return Double(primitive-x);
}

Double Double::subtract(Double &x) const{
    return Double(primitive-x.getPrimitive());
}

Double Double::add(double x) const{
    return Double(primitive+x);
}

Double Double::add(Double &x) const{
    return Double(primitive+x.getPrimitive());
}

Double Double::divide(double x) const{
    return Double(primitive/x);
}

Double Double::divide(Double &x) const{
    return Double(primitive/x.getPrimitive());
}

Double Double::pow(double alph) const{
    return Double(std::pow(primitive, alph));
}

Double Double::pow(Double &alph) const{
    return Double(std::pow(primitive, alph.getPrimitive()));
}

Double Double::exp() const{
    return Double(std::exp(primitive));
}

Double Double::operator=(const double x) {
    return Double(x);
}

bool operator==(Double &x1, double x2) {
    return x1.getPrimitive()==x2;
}

bool operator==(Double &x1, Double &x2) {
    return x1.getPrimitive()==x2.getPrimitive();
}

bool operator==(double x1, Double &x2) {
    return x1==x2.getPrimitive();
}

Double operator+(Double &x1, Double &x2){
    return x1.add(x2);
}

Double operator+(double x1, Double &x2){
    return x2.add(x1);
}

Double operator+(Double &x1, double x2){
    return x1.add(x2);
}

Double operator-(Double &x1, double x2){
    return x1.subtract(x2);
}

Double operator-(Double &x1, Double &x2){
    return x1.subtract(x2);
}

Double operator-(double x1, Double &x2){
    return x1-x2.getPrimitive();
}

Double operator/(Double &x1, Double &x2){
    return x1.divide(x2);
}

Double operator/(Double &x1, double x2){
    return x1.divide(x2);
}

Double operator/(double x1, Double &x2){
    return x1/x2.getPrimitive();
}

Double operator*(Double &x1, Double &x2){
    return x1.multiply(x2);
}

Double operator*(double x1, Double &x2){
    return x2.multiply(x1);
}

Double operator*(Double &x1, double x2){
    return x1.multiply(x2);
}



/*std::ostream& operator<<(const Double &x, std::ostream& out){
    return x.getPrimitive()<<out;
}*/
