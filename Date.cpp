#include "Date.h"

Date::Date(std::string &val){
  setPrimitive(val);
}
Date::Date(char const vl[]){
	std::string val(vl);
  setPrimitive(val);
}
Date::Date(){
  time_t rawtime;
	time(&rawtime); //pass rawtime to get changed
	primitiveTM=localtime(&rawtime);
  primitiveTM->tm_sec=0;
  primitiveTM->tm_min=0;
  primitiveTM->tm_hour=0;
  primitive=std::mktime(primitiveTM);
}
Date::Date(std::time_t &tm){
	primitiveTM=localtime(&tm);
  primitive=std::mktime(primitiveTM);
}
Date Date::operator=(std::string &val) {
  return Date(val);
}
Date Date::operator=(char const vl[]) {
  return Date(vl);
}
void Date::IntToDate(int day, int month, int year){
  time_t rawtime;
	time(&rawtime); //pass rawtime to get changed...i wish they would not explicitly require & on this side and just let the function do its thing.
	primitiveTM=localtime(&rawtime);
  primitiveTM->tm_year=year-1900;
  primitiveTM->tm_mon=month-1;
  primitiveTM->tm_mday=day;
  primitiveTM->tm_sec=0;
  primitiveTM->tm_min=0;
  primitiveTM->tm_hour=0;
  primitive=std::mktime(primitiveTM);
}
void Date::parseSlash(std::string &val){
  std::string delimiter="/";
  int loc=val.find(delimiter);
  int delLength=delimiter.length();
  int month=atoi(val.substr(0, loc).c_str());
  val.erase(0, loc+delLength);
  loc=val.find(delimiter);
  int day=atoi(val.substr(0, loc).c_str());
  val.erase(0, loc+delLength);
  int year=atoi(val.c_str());
  IntToDate(day, month, year);
}
void Date::setPrimitive(std::string &val){
  std::string delimiter="/";
  int loc=val.find(delimiter);
  if(loc==std::string::npos){//not found
    parseDash(val);
  }
  else{
    parseSlash(val);
  }
}
void Date::parseDash(std::string &val){
  std::string delimiter="-";
  int loc=val.find(delimiter);
  if(loc==std::string::npos){//not found
    std::cout<<"not a valid date"<<std::endl;
  }
  int delLength=delimiter.length();
  int year=atoi(val.substr(0, loc).c_str());
  val.erase(0, loc+delLength);
  loc=val.find(delimiter);
  int month=atoi(val.substr(0, loc).c_str());
  val.erase(0, loc+delLength);
  int day=atoi(val.c_str());
  IntToDate(day, month, year);
}

double Date::dateDiff(const Date &dt) const{
  if(scale=="day"){
		return difftime(primitive, dt.getPrimitive())/86400; //seconds per day
	}
	else if(scale=="year"){
        return difftime(primitive, dt.getPrimitive())/31104000; //seconds per year (360 days)
    }
	else if(scale=="month"){
        return difftime(primitive, dt.getPrimitive())/2592000; //seconds per month (30 days)
    }
	else{
		return difftime(primitive, dt.getPrimitive()); //try to make this throw an error!
	}
}
int Date::msDiff(Date &dt){
	return difftime(primitive, dt.getPrimitive()); 
}
Date Date::dateAdd(double tm) const{
  time_t newtime;
  if(scale=="day"){
    newtime=primitive+tm*86400;
    return Date(newtime);
  }
  else if(scale=="year"){
    newtime=primitive+tm*31104000;
    return Date(newtime);
  }
  else if(scale=="month"){
    newtime=primitive+tm*2592000;
    return Date(newtime);
  }
  else{
    newtime=primitive+tm;
    return Date(newtime);
  }
}

std::time_t Date::getPrimitive() const{
  return primitive;
}
std::string Date::type(){
  return "Date";
}
std::string Date::strDate() const{
  //return std::to_string(primitiveTM->tm_mon+1)+"/"+std::to_string(primitiveTM->tm_mday)+"/"+std::to_string(primitiveTM->tm_year+1900);
  return std::to_string(localtime(&primitive)->tm_mon+1)+"/"+std::to_string(localtime(&primitive)->tm_mday)+"/"+std::to_string(localtime(&primitive)->tm_year+1900);
}
void Date::setScale(std::string &scale_) {
    scale=scale_;
}
void Date::setScale(char const scale_[]) {
    scale=std::string(scale_);
}
bool operator==(const Date &x1, const Date &x2) {
    return x1.getPrimitive()==x2.getPrimitive();
}

double operator-(const Date &x1, const Date &x2) {
    return x1.dateDiff(x2);
}
Date operator+(const Date &x1, double x2){
    return x1.dateAdd(x2);
}
bool operator<(const Date& dt1, const Date& dt2){
    return dt1.getPrimitive()<dt2.getPrimitive();
}
bool operator>(const Date& dt1, const Date& dt2){
    return dt1.getPrimitive()>dt2.getPrimitive();
}
bool operator!=(const Date& dt1, const Date& dt2){
    return dt1.getPrimitive()!=dt2.getPrimitive();
}

