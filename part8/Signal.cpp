#include "Signal.h"

// Signal::Signal() {
//     n_samples=  101;
//     s_frequency = 100;
//     ini_time = 0;
//     set_expression("0");
//     set_label("x");
//     samples.resize(n_samples);
//     std::fill(samples.begin(), samples.end(), 0);
//     time.resize(n_samples);
//     std::fill(time.begin(), time.end(), 0);
//     fill_time();
// }    

//constructor with default values
Signal::Signal(int n, double f, double t) {
    n_samples=  n;
    s_frequency = f;
    ini_time = t;
    set_expression("0");
    set_label("x");
    samples.resize(n_samples);
    std::fill(samples.begin(), samples.end(), 0);
    time.resize(n_samples);
    std::fill(time.begin(), time.end(), 0);
    fill_time();
}

//set number of samples
void Signal::set_n_samples(int n) {
    n_samples = n;   
    samples.resize(n);
    time.resize(n);
    fill_time();
}

//set sampling frequency
void Signal::set_s_frequency(double f) { s_frequency = f; fill_time(); }

//set ini time
void Signal::set_ini_time(double t) { ini_time = t; fill_time(); }

//set label
void Signal::set_label(std::string s) { file_name = "diff_eqn_soln_" + s; label = s; }

//set mathematical expression
void Signal::set_expression(std::string s) { expression = s; }

void Signal::set_samples(std::vector<double> s) { samples = s; }

//get number samples
int Signal::get_n_samples() { return n_samples; }

//get sampling frequency
double Signal::get_s_frequency() { return s_frequency; }

//get initial time
double Signal::get_ini_time() { return ini_time; }

//get expression
std::string Signal::get_expression() const { return expression; }

//get samples vector
std::vector<double> Signal::get_samples() { return samples; }

//get element from samples vector
double Signal::get_samples(int n) { return samples[n]; }

//get time vector
std::vector<double> Signal::get_time() { return time; }

//get element from time vector
double Signal::get_time(int n) { return time[n]; }

//linearly fill time vector
void Signal::fill_time() {
    for (int i = 0; i < n_samples; i++) {
        time[i] = ini_time + (i / s_frequency);
    }
}

//fill samples with constant x
void Signal::fill_constant_samples(double x) {
    std::fill(samples.begin(), samples.end(), x);
    set_expression(textNum(x));
}

//fill samples with exponential signal
void Signal::fill_exponential(double tc, double A) {

    std::string s;
	
	if (ini_time == 0 && tc == 1) {
        s = textNum(A) + " exp( -t )";
    } else if (ini_time < 0) {
        s = textNum(A) + " exp( -(t + " + textNum(abs(ini_time)) + ") / " + textNum(tc) + " )";
    } else {
		s = textNum(A) + " exp( -(t - " + textNum(ini_time) + ") / " + textNum(tc) + " )";
    }

	set_expression(s);
    
    for (int i = 0; i < n_samples; i++) {
        samples[i] = A * exp(-1 * (time[i] - ini_time) / tc);
    }
}

//write info to output file
void Signal::write_info() const {
    std::ofstream f;
    f.open(file_name + ".txt");

    f << "Time-Domain Signal Samples" << std::endl;
    f << "N = " << n_samples << std::endl;
    f << "fs = " << s_frequency << std::endl;
    f << "t0 = " << ini_time << std::endl;
    f << "Signal label: " << label << std::endl;
    f << "Mathematical Expression" << std::endl;
    f << label << "(t) = " << expression << std::endl;
    f << "Time and signal samples in .csv format" << std::endl;
    f << "t, " + label + "(t)" << std::endl;
    f << "-------" << std::endl;

    for (int i = 0; i < n_samples; i++) {
        f << time[i] << ", " << round(samples[i]) << std::endl;
    }

    f.close();
}

void Signal::fill_sinusoid(double A, double f_ini, double phase) {

    set_expression(textNum(A) + "cos(" + textNum(2 * M_PI * f_ini) + textNum(phase) + ")");

    for (int i = 0; i < n_samples; i++) {
      samples[i] = A * cos(2 * M_PI * f_ini * time[i] + phase);
    }
}

Signal Signal::operator = (Signal const &right) {
    n_samples = right.n_samples;
    s_frequency = right.s_frequency;
    ini_time = right.ini_time;
    expression = right.expression;
    samples = right.samples;
    time = right.time;
    return *this;
}

Signal Signal::operator + (Signal const &right) {

    if (right.n_samples != n_samples || right.ini_time != ini_time || right.s_frequency != s_frequency) {
    std::cout << "ERROR! Attempt to add incompatible signals." << std::endl;
    }

    Signal temp(n_samples, s_frequency, ini_time);
    std::vector<double> temp_samples;

    for (int i = 0; i < n_samples; i++) {
        temp.samples[i] = samples[i] + right.samples[i];
    }

    temp.set_expression(expression + " + " +right.expression);

    return temp;
}

Signal Signal::operator * (Signal const &right) {

    if (right.n_samples != n_samples || right.ini_time != ini_time || right.s_frequency != s_frequency) {
    std::cout << "ERROR! Attempt to add incompatible signals." << std::endl;
    }

    Signal temp(n_samples, s_frequency, ini_time);
    std::vector<double> temp_samples;

    for (int i = 0; i < n_samples; i++) {
        temp.samples[i] = samples[i] * right.samples[i];
    }

    temp.set_expression("( " + expression + " )( " + right.expression + " )");

    return temp;
}

void Signal::round_samples() {
    for (int i = 0; i < n_samples; i++) {
    samples[i] = round(samples[i]);
    }
}