#ifndef KENOBET_H
#define KENOBET_H

#include<vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class KenoBet{

  public:
    void nrepetir(vector<int> &v);
    float aposta(vector <int> &v,vector <int> &hits,float &a,int &b, float round);
    void keno(vector <int> &v,vector <int> &hits,float &a,int &b,unsigned seed, float round);
  
};

#endif