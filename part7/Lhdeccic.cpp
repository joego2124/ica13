#include "Lhdeccic.h"

//construtor with default values
Lhdeccic::Lhdeccic(double nb, double nini_time, double nini_k) {
    b = nb;
    ini_time = nini_time;
    ini_k = nini_k;
    label = "y";
}

//set b
void Lhdeccic::set_b(double nb) { b = nb; }

//set ini_time
void Lhdeccic::set_ini_time(double nini_time) { ini_time = nini_time; }

//set ini_k
void Lhdeccic::set_ini_k(double nini_k) { ini_k = nini_k; }

//set label
void Lhdeccic::set_label(string nlabel) { label = nlabel; }

//get b
double Lhdeccic::get_b() const { return b; }

//get ini_time
double Lhdeccic::get_ini_time() const { return ini_time; }

//get ini_k
double Lhdeccic::get_ini_k() const { return ini_k; }

//get label
string Lhdeccic::get_label() const { return label; }

//get solution
Signal* Lhdeccic::get_solution() { return &solution; }

//gets solution expression
string Lhdeccic::get_solution_expression() const {
	return (label + "(t) = " + solution.get_expression());
}

//write solution to file
void Lhdeccic::write_solution(ofstream &f) const
{
	f << "Solution" << endl;
	f << "--------" << endl;
	f << get_solution_expression() << endl << endl;
}

//helper func
string Lhdeccic::textNum(double x) const {
    if (x >= 100)
        // large numbers truncated as int -> string
        return std::to_string(int(x));
    else
    {
        // small numbers will get 3 digits
        string x_exp = std::to_string(x);
        // return 4 characters, or 5 if x<0
        return x_exp.substr(0, 4 + (x<0));
    }
}

