#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<chrono>
#include <functional>


using namespace std;
using namespace chrono;

vector<double> gera_vector(int n){
    
    vector<double> vtr; 

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        vtr.push_back( ((double)rand()/RAND_MAX)*(27-5) + 5) ;
    }
    
    return vtr;

}

void log_v(vector<double> &vtr_i){

    double result;
    
    for(auto i = vtr_i.begin(); i != vtr_i.end(); i++)
    {
        result = log(*i);
    }
}


void sqrt_v(vector<double> &vtr_i){
    double result;
    
    for(auto i = vtr_i.begin(); i != vtr_i.end(); i++)
    {
        result = sqrt(*i);
    }
}

void pow3_v(vector<double> &vtr_i){
    double result;
    
    for(auto i = vtr_i.begin(); i != vtr_i.end(); i++)
    {
        result = pow(*i,3);
    }
}

void pow3mult_v(vector<double> &vtr_i){
    double result;
    
    for(auto i = vtr_i.begin(); i != vtr_i.end(); i++)
    {
        result = (*i)*(*i)*(*i);
    }
}

double sum_v(vector<double> &vtr_i){
    double soma = 0;
    for (auto i = vtr_i.begin(); i != vtr_i.end(); i++)
    {
        soma+= *i;
    }
    return soma;
}

vector<double> teste_incremental(function<void(vector<double>&)> func) {

    int nmax = 100000000;

    vector<double> vrt_i;
    // duration<double> tempo_exec;
    time_point<high_resolution_clock> start, end;
    vector<double> results;
    for (int n = 100; n <= nmax; n*=10)
    {

        vrt_i = gera_vector(n);

        start = high_resolution_clock::now();

            func(vrt_i);

        end = high_resolution_clock::now(); 
    
        auto tempo_exec = duration_cast<milliseconds>(end - start);

        results.push_back(tempo_exec.count());

    }

    return results;

}
