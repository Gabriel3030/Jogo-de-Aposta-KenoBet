#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stdlib.h>
#include "KenoBet.hpp"
using namespace std;

int main(int argc, char *argv[]){

  ifstream arquivo;

  arquivo.open("testeaposta.dat"); //abre o arquivo de entrada

  float a;
  int b;

  arquivo >> a >> b; //armazena os valores do arquivo nas variáveis
  
  if(a == 0 || b ==0){
    cout << "ERRO,Você digitou uma string ou um número inválido" << endl;
  }

  //cout << a << endl;
  //cout << b << endl;

  vector<int> v;
  int aux;

  while(!arquivo.eof()){
    arquivo >> aux;
    v.push_back(aux);
  }

  if(v.size()>15){
    cout << "Não pode ter mais que 15 números na aposta!" << endl;
    abort();
  }

  cout << "Arquivo validado!" << endl;
  cout << "---------------------------------------"<< endl; 
  
  unsigned seed = time(NULL); 
  srand(seed);
  float round = a/b;

  KenoBet instance;

  for(int i=1;i<=b;i++){
    cout << "Esta é a rodada " << i << " de " << b << endl;
    instance.nrepetir(v);
    vector <int> hits;
    instance.keno(v,hits,a,b,seed, round);
  }

  return 0;
}
