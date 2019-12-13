#ifndef FOLHDECCIC_H
#define FOLHDECCIC_H

#include <iostream>
#include <fstream>
#include "Lhdeccic.cpp"

using namespace std;

class Folhdeccic : public Lhdeccic {
    public:
        //default constructor
        Folhdeccic();

        //default constructor with parameters
        Folhdeccic(double, double, double);

    public:
        //set b
        virtual void set_b(double);

        //set ini_time
        virtual void set_ini_time(double);

        //set ini_k
        virtual void set_ini_k(double);

        //set label
        virtual void set_label(string);

        //pure virtual implementations

        virtual string get_expression() const;

		virtual string get_ini_condition() const;

        virtual void write_ode(ofstream &) const;

		virtual void calc_solution();
};

#endif