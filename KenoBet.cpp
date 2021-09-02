#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "KenoBet.hpp"
using namespace std;

void KenoBet::nrepetir(vector<int> &v){
  int cont = 0;

  for(int i = 0; i < v.size(); i++) { 
    for(int j = 0; j < i; j++) { 
      if(v[i] == v[j]){ 
        cont++;
        break; 
      }
    }
  }

  if (cont > 0){
    cout << "Você digitou números repetidos ou um espaço vazio, rode o código novamente com diferentes valores na aposta." << endl;
    abort();
  }  
}

float KenoBet::aposta(vector <int> &v,vector <int> &hits,float &a,int &b, float round){
  float m[15][16];
  //primeira linha
  m[0][0]= 0;
  m[0][1]= 3;
  //segunda linha
  m[1][0]= 0; m[1][1]= 1; m[1][2]= 9;
  //terceira
  m[2][0]= 0; m[2][1]= 1; m[2][2]= 2; m[2][3]= 16;
  //quarta
  m[3][0]= 0; m[3][1]= 0.5;m[3][2]= 2;m[3][3]= 6;
  m[3][4]= 12;
  //quinta
  m[4][0]= 0;m[4][1]= 0.5;m[4][2]= 1;m[4][3]= 3;
  m[4][4]= 15;m[4][5]= 50;
  //sexta
  m[5][0]= 0;m[5][1]= 0.5;m[5][2]= 1;m[5][3]= 2;
  m[5][4]= 3;m[5][5]= 30;m[5][6]= 75;
  //sétima
  m[6][0]= 0;m[6][1]= 0.5;m[6][2]= 0.5;m[6][3]= 1;
  m[6][4]= 6;m[6][5]= 12;m[6][6]= 36;m[6][7]= 110;
  //oitava
  m[7][0]= 0;m[7][1]= 0.5;m[7][2]= 0.5;m[7][3]= 1;
  m[7][4]= 3;m[7][5]= 6;m[7][6]= 19;m[7][7]= 90;
  m[7][8]= 720;
  //nona
  m[8][0]= 0;m[8][1]= 0.5;m[8][2]= 0.5;m[8][3]= 1;
  m[8][4]= 2;m[8][5]= 4;m[8][6]= 8;m[8][7]= 20;
  m[8][8]= 80;m[8][9]= 1200;
  //décima
  m[9][0]= 0;m[9][1]= 0;m[9][2]= 0.5;m[9][3]= 1;
  m[9][4]= 2;m[9][5]= 3;m[9][6]= 5;m[9][7]= 10;
  m[9][8]= 30;m[9][9]= 600;m[9][10]= 1800;
  //11
  m[10][0]= 0;m[10][1]= 0;m[10][2]= 0.5;m[10][3]= 1;
  m[10][4]= 1;m[10][5]= 2;m[10][6]= 6;m[10][7]= 15;
  m[10][8]= 25;m[10][9]= 180;m[10][10]= 1000;
  m[10][11]= 3000;
  //12
  m[11][0]= 0;m[11][1]= 0;m[11][2]= 0;m[11][3]= 0.5;
  m[11][4]= 1;m[11][5]= 2;m[11][6]= 4;m[11][7]= 24;
  m[11][8]= 72;m[11][9]= 250;m[11][10]= 500;
  m[11][11]= 2000;m[11][12]= 4000;
  //13
  m[12][0]= 0;m[12][1]= 0;m[12][2]= 0;m[12][3]= 0.5;
  m[12][4]= 0.5;m[12][5]= 3;m[12][6]= 4;m[12][7]= 5;
  m[12][8]= 20;m[12][9]= 80;m[12][10]= 240;
  m[12][11]= 500;m[12][12]= 3000;m[12][13]= 6000;
  //14
  m[13][0]= 0;m[13][1]= 0;m[13][2]= 0;m[13][3]= 0.5;
  m[13][4]= 0.5;m[13][5]= 2;m[13][6]= 3;m[13][7]= 5;
  m[13][8]= 12;m[13][9]= 50;m[13][10]= 150;
  m[13][11]= 500;m[13][12]= 1000;m[13][13]= 2000;
  m[13][14]= 7500;
  //15
  m[14][0]= 0;m[14][1]= 0;m[14][2]= 0;m[14][3]= 0.5;
  m[14][4]= 0.5;m[14][5]= 1;m[14][6]= 2;m[14][7]= 5;
  m[14][8]= 15;m[14][9]= 50;m[14][10]= 150;
  m[14][11]= 300;m[14][12]= 600;m[14][13]= 1200;
  m[14][14]= 2500;m[14][15]=10000;

  int qv = v.size();
  int qhits = hits.size();
  cout << "Sua taxa de retorno é " << m[qv-1][qhits] << endl;
  cout << "Assim, você sai com: ";
  
  float retorno = m[qv-1][qhits];
  cout << retorno * round << endl;
  
  if(retorno>1){
    a = a + retorno *(round) - round;
  } 
  
  if(retorno>0 && retorno<1){
    a = a-retorno*round;
  }
  if(retorno == 0){
    a = a-round;
  }
  
  cout << "Você possui um total de " << a << " créditos!" << endl;
  cout << "--------------------------------------"<<endl;
  return m[qv-1][qhits] * a ;
}

void KenoBet::keno(vector <int> &v,vector <int> &hits,float &a,int &b,unsigned seed, float round){
  cout << "Você irá iniciar essa rodada com "<< a << " créditos" << endl;
  cout << "Sua aposta será de " << round <<  endl;
  cout << "Sua aposta tem " << v.size() << " números, eles são:" << endl;
  
  for (int i = 0; i < v.size(); i++) {
    //printa os valores do vector (IC)
    cout << v[i] << " " ;
    
  }
  cout << endl;

int v2[20];
int aux2;

int k = 0, repetido = 0, tam_vetor = 0;
//verifica se tem algum número repetido no arquivo de entrada.
while(tam_vetor < 20){
  aux2 = 1+rand()%80;
  for(int j=0; j<k; j++){
    if(aux2 == v2[j]){
      repetido++;
    }
  }

  //se não tiver ele não entra no if e roda outro aleatório, até que seja diferente.
  if(repetido == 0){
    v2[k] = aux2;
    tam_vetor++;
    k++;
  }

  if(repetido == 1){
    repetido = 0;
  }
}

//insertion sort
int i, j, tmp;
for (i = 1; i < 20; i++) {
  j = i;
  while (j > 0 && v2[j - 1] > v2[j]) {
    tmp = v2[j];
    v2[j] = v2[j - 1];
    v2[j - 1] = tmp;
    j--;
  }
}

cout << "Os números sorteados são:" << endl;
for(int l=0; l < 20; l++){
  cout << v2[l] << " ";
}
cout << endl;
//não repete os números aleatórios
for(int m=0;m<v.size();m++){
  for(int n=0;n<20;n++){
    if(v[m]==v2[n]){
      hits.push_back(v[m]);
    }
  }
}
for (int p = 0; p < hits.size(); p++) {
  //printa os valores do vector (IC)
  cout << "Você acertou o número " << hits[p] << "! " << endl;
} 
cout << "O total de acertos é " << hits.size(); 
cout << " de " << v.size() << endl;
aposta(v,hits,a,b,round);
}