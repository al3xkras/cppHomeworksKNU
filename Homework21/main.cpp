#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <cassert>
#include <vector>
#include <set>
#include <sstream>

std::vector<std::string> split (const std::string& s, const std::string& delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr(pos_start));
    return res;
}

// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

void task21_05(std::string s){
    std::cout<<"String before transform: \""<<s<<'"'<<std::endl;
    std::transform(s.begin(), s.end(),s.begin(), toupper);
    std::cout<<"String after transform (to upper case): \""<<s<<'"'<<std::endl;
}

struct Date{
    int day;
    int month;
    int year;

    bool operator==(const Date &rhs) const {
        return day == rhs.day &&
               year == rhs.year &&
               month == rhs.month;
    }

    bool operator!=(const Date &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const Date &rhs) const {
        if (year < rhs.year)
            return true;
        if (rhs.year < year)
            return false;

        if (month < rhs.month)
            return true;
        if (rhs.month < month)
            return false;

        return day < rhs.day;
    }

    bool operator>(const Date &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Date &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Date &rhs) const {
        return !(*this < rhs);
    }
};
void task21_14(){
    std::map<std::string, int> months = {
            {"December",12},
            {"January",1},
            {"February",2},
            {"March",3},
            {"April",4},
            {"May",5},
            {"June",6},
            {"July",7},
            {"August",8},
            {"September",9},
            {"October",10},
            {"November",11}
    };

    std::map<int,std::string> months_reverse;

    for (std::pair<std::string,int> p: months){
        std::pair<int,std::string> p_rev(p.second,p.first);
        months_reverse.insert(p_rev);
    }



    std::ofstream f1("dates.txt", std::ios_base::trunc | std::ios_base::out);

    assert(f1.is_open());
    f1<<"12 11 2020, 20 July 2004, 17 September 2017, 01 07 2009, 17 09 2017";
    f1.close();

    std::ifstream f2("dates.txt", std::ios_base::in);

    assert(f2.is_open());

    std::stringstream buffer;
    buffer << f2.rdbuf();
    std::string data = buffer.str();

    f2.close();

    std::cout<<data<<std::endl;

    std::vector<std::string> dates = split(data,",");

    std::set<Date> realDates;

    for (std::string date: dates){
        trim(date);
        std::vector<std::string> DD_MM_YYYY = split(date," ");
        int day = std::stoi(DD_MM_YYYY[0]);
        int month;
        if (months.count(DD_MM_YYYY[1])){
            month = months[DD_MM_YYYY[1]];
        } else {
            month = std::stoi(DD_MM_YYYY[1]);
        }
        int year = std::stoi(DD_MM_YYYY[2]);


        realDates.insert({day,month,year});
        //std::cout<<year<<'/'<<months_reverse[month]<<'/'<<day<<std::endl;
    }


    for (Date d: realDates){
        std::cout<<d.year<<'/'<<months_reverse[d.month]<<'/'<<d.day<<std::endl;
    }
}

template<typename _InputIterator,typename _OutputIterator,
        typename _UnaryOperation, typename _Predicate>
_OutputIterator
transform_if(_InputIterator _first, _InputIterator _last,_OutputIterator _result,
                    _UnaryOperation _unary_op, _Predicate _predicate){

    __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>)
    __glibcxx_function_requires(_OutputIteratorConcept<_OutputIterator,
            // "the type returned by a _UnaryOperation"
            __typeof__(__unary_op(*__first))>)
    __glibcxx_requires_valid_range(__first, __last)

    for (; _first != _last; ++_first, (void)++_result) {

        if (_predicate(*_first)) {
            *_result = _unary_op(*_first);
        }
    }

    return _result;
}


void task21_16(){
    std::string s = "aaaAbacdefGH^7";

    std::cout<<"String before conditional transform: \n    \""<<s<<'"'<<std::endl;


    transform_if(s.begin(),s.end(),s.begin(),
                 [](char s){return s+1;},
                 [](char s){return s!='a';});

    std::cout<<"String after conditional transform (char->char+1, if not equal to 'a'):\n    \""<<s<<'"'<<std::endl;
}

int main() {
    /*
     * Домашнє завдання (для всіх):
     * 21.05,
     * 21.14,
     * 21.16
     */

    std::cout<<std::endl<<std::endl<<std::endl<<"Task 21.05"<<std::endl;
    task21_05("1234_abcdefghIJKLMnoP_][]'';");

    std::cout<<std::endl<<std::endl<<std::endl<<"Task 21.14"<<std::endl;
    task21_14();

    std::cout<<std::endl<<std::endl<<std::endl<<"Task 21.16"<<std::endl;
    task21_16();
    return 0;
}
