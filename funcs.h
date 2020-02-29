#ifndef FUNC_H
#define FUNC_H

#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<chrono>
#include <functional>

using namespace std;
using namespace chrono;

vector<double> gera_vector(int n);

void log_v(vector<double> &vtr_i);

void sqrt_v(vector<double> &vtr_i);

void pow3_v(vector<double> &vtr_i);

void pow3mult_v(vector<double> &vtr_i);

double sum_v(vector<double> &vtr_i);

vector<double> teste_incremental(function<void(vector<double>&)> func) ; 

#endif

