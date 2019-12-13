#ifndef LHDECCIC_H
#define LHDECCIC_H

#include <iostream>
#include "Signal.cpp"
using namespace std;

class Lhdeccic {
    private:
        double b;
        double ini_time;
        double ini_k;
        string label;
        Signal solution;

    public:

        //default constructor
        Lhdeccic(double b = 1, double ini_time = 0, double ini_k = 1);

        //set b
        virtual void set_b(double);

        //set ini_time
        virtual void set_ini_time(double);

        //set ini_k
        virtual void set_ini_k(double);

        //set label
        virtual void set_label(string);

        //get b
        double get_b() const;

        //get ini_time
        double get_ini_time() const;

        //get ini_k
        double get_ini_k() const;

        //get label
        string get_label() const;

        //get solution in signal
        Signal* get_solution();

        //get solution expression
        string get_solution_expression() const;

        //write solution to output file
        virtual void write_solution(ofstream &) const;

        //pure virtual functions

        virtual string get_expression() const = 0;

        virtual void write_ode(ofstream &) const = 0;

        virtual string get_ini_condition() const = 0;

        virtual void calc_solution() = 0;

        //helper func
        string textNum(double) const;
};

#endif