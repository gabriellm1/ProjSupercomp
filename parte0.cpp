#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<chrono>
#include <functional>
#include <fstream>
#include "funcs.h"


using namespace std;
using namespace chrono;



int main(){

    ofstream output;
    vector<double> r_log,r_sqrt,r_pow3,r_pow3mult,r_sum,size_v;


    r_log = teste_incremental(log_v);
    r_sqrt = teste_incremental(sqrt_v);
    r_pow3 = teste_incremental(pow3_v);
    r_pow3mult = teste_incremental(pow3mult_v);
    r_sum = teste_incremental([](vector<double>& vrt_i) {
		double soma = sum_v(vrt_i);
		vector<double> vrt_soma;
		vrt_soma.push_back(soma);
		return vrt_soma;
	});

    output.open("output.csv");
    output << "Tamanho,log,sqrt,pow3,pow3mult,soma\n";

    output << "100" << "," << r_log.at(0) << "," << r_sqrt.at(0) << "," << r_pow3.at(0) << "," << r_pow3mult.at(0) << "," << r_sum.at(0) << "\n";

    output << "1000" << "," << r_log.at(1) << "," << r_sqrt.at(1) << "," << r_pow3.at(1) << "," << r_pow3mult.at(1) << "," << r_sum.at(1) << "\n";

    output << "10000" << "," << r_log.at(2) << "," << r_sqrt.at(2) << "," << r_pow3.at(2) << "," << r_pow3mult.at(2) << "," << r_sum.at(2) << "\n";

    output << "100000" << "," << r_log.at(3) << "," << r_sqrt.at(3) << "," << r_pow3.at(3) << "," << r_pow3mult.at(3) << "," << r_sum.at(3) << "\n";

    output << "1000000" << "," << r_log.at(4) << "," << r_sqrt.at(4) << "," << r_pow3.at(4) << "," << r_pow3mult.at(4) << "," << r_sum.at(4) << "\n";
               
    output << "10000000" << "," << r_log.at(5) << "," << r_sqrt.at(5) << "," << r_pow3.at(5) << "," << r_pow3mult.at(5) << "," << r_sum.at(5) << "\n";
    
    output << "100000000" << "," << r_log.at(6) << "," << r_sqrt.at(6) << "," << r_pow3.at(6) << "," << r_pow3mult.at(6) << "," << r_sum.at(6) << "\n";
                
    output.close();

}