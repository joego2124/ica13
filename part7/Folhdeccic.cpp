#include "Folhdeccic.h"

//default constructor
Folhdeccic::Folhdeccic() : Lhdeccic() { calc_solution(); }

//default constructor with parameters
Folhdeccic::Folhdeccic(double b, double t, double k) : Lhdeccic(b, t, k) { calc_solution(); }

//set b
void Folhdeccic::set_b(double nb) { Lhdeccic::set_b(nb); calc_solution(); }

//set ini_time
void Folhdeccic::set_ini_time(double nini_time) { Lhdeccic::set_ini_time(nini_time); calc_solution(); }

//set ini_k
void Folhdeccic::set_ini_k(double nini_k) { Lhdeccic::set_ini_k(nini_k); calc_solution(); }

//set label
void Folhdeccic::set_label(string nlabel) { Lhdeccic::set_label(nlabel); calc_solution(); }

//calculate solution signal
void Folhdeccic::calc_solution() {
    //create new signal and fill in member vars
    Signal* s = get_solution();
	s->set_n_samples(501);
	s->set_s_frequency(200);
	s->set_ini_time(get_ini_time());

    //fill w/ vals
	s->fill_exponential(get_ini_k(), 1 / get_b());
}

//get expression
string Folhdeccic::get_expression() const {
	return get_label() + "'(t) + " + textNum(get_b()) + " " + get_label() + "(t) = 0"; 
}

//get ini condition
string Folhdeccic::get_ini_condition() const {
	return get_label() + "(" + textNum(get_ini_time()) + ") = " + textNum(get_ini_k());
}

void Folhdeccic::write_ode(ofstream &f) const {
    f << "---------------------------------" << endl;
	f << "First-Order Differential Equation" << endl;
	f << "---------------------------------" << endl;
	f << get_expression() << endl;
	f << "\nInitial Condition" << endl;
	f << "-----------------" << endl;
	f << get_ini_condition() << "\n" << endl;
}

