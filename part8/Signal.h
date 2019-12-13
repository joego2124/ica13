#ifndef SIGNAL_H
#define SIGNAL_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <vector>

class Signal {
  private:
    int n_samples;
    double s_frequency;
    double ini_time;
    std::string label;
    std::string file_name;
    std::string expression;
    std::vector<double> samples;
    std::vector<double> time;

    std::string textNum(double x) const
    {
        if (x >= 100)
            // large numbers truncated as int -> string
            return std::to_string(int(x));
        else
        {
            // small numbers will get 3 digits
            std::string x_exp = std::to_string(x);
            // return 4 characters, or 5 if x<0
            return x_exp.substr(0, 4 + (x<0));
        }
    }

  public:

    // //constructor 
    // Signal();

    //constructor with default values
    Signal(int n = 101, double f = 100, double t = 0);

    //set number of samples
    void set_n_samples(int);

    //set sampling frequency
    void set_s_frequency(double);

    //set ini time
    void set_ini_time(double);

    //set label
    void set_label(std::string);

    //set mathematical expression
    void set_expression(std::string);

    void set_samples(std::vector<double>);

    //get number samples
    int get_n_samples();

    //get sampling frequency
    double get_s_frequency();

    //get initial time
    double get_ini_time();

    //get expression
    std::string get_expression() const;

    //get samples vector
    std::vector<double> get_samples();

    //get element from samples vector
    double get_samples(int);

    //get time vector
    std::vector<double> get_time();

    //get element from time vector
    double get_time(int);

    //linearly fill time vector
    void fill_time();

    //fill samples with constant x
    void fill_constant_samples(double);

    //fill samples with exponential signal
    void fill_exponential(double, double);

    //write info to output file
    void write_info() const;

    void fill_sinusoid(double, double, double);

    Signal operator = (Signal const &right);

    Signal operator + (Signal const &right);

    Signal operator * (Signal const &right);

    void round_samples();
};


#endif