#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
  srand(time(NULL));

  int paresEncontrados = 0;
  int tentativas = 0;
  int indice = 0;
  int principal[4][4];
  int gabarito[4][4];
  int opcao = rand() % 4;
  int jogo[4][4];
  int pares[16] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8};
 
  /* ele vai randomizar os pares */
  for (int i = 0; i < 16; i++) {
    int j = rand() % 16;

    int aux = pares[i];
    pares[i] = pares[j];
    pares[j] = aux;
  }
  /*  faz o loop pra construir a matriz Indice= J (coluna)*/
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      principal[i][j] = pares[indice];
      indice++;
    }
  }

  if (opcao == 0) {
   /* cout << "Modo normal" << endl;*/
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {

        gabarito[i][j] = principal[i][j];
      }
      cout << endl;
    }
  }

  else if (opcao == 1) {
   /* cout << "Matriz Transposta:" << endl;*/
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        gabarito[i][j] = principal[j][i];
      }
    }
  } else if (opcao == 2) {
    /*cout << "Matriz invertida linha" << endl;*/
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        gabarito[i][j] = principal[3 - i][j];
      }
    }
  } else if (opcao == 3) {
   /* cout << "Matriz coluna invertida" << endl;*/
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        gabarito[i][j] = principal[i][3 - j];
      }
    }
  }
  /*cout << "Matriz gabarito:" << endl;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << gabarito[i][j] << " ";
    }
    cout << endl;
  }*/

  /*matriz jogo*/
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      jogo[i][j] = 0;
    }
  }
    
  /* Começo jogo*/
  cout << "Bem vindo ao jogo da memória" << endl;
  cout << "Escolha um Numero de 1 a 4 para cada linha/coluna e divirta-se!"
       << endl;
  cout << "Esta preparado?" << endl;
  cin.get();
  system("clear");
  do {
    int linha, coluna, linha2, coluna2;

    cout << "Tentativas usadas: " << tentativas <<"/24"<< endl;
    cout << "Matriz jogo:" << endl;

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        cout << jogo[i][j] << " ";
      }
      cout << endl;
    }

    cout << "Escolha uma linha do primeiro numero" << endl;
    cin >> linha;
    cout << "Escolha uma coluna do primeiro numero" << endl;
    cin >> coluna;
    cout << "Escolha uma linha do segundo numero" << endl;
    cin >> linha2;
    cout << "Escolha uma coluna do segundo numero" << endl;
    cin >> coluna2;
    linha--;
    coluna--;
    linha2--;
    coluna2--;
    
    if(linha < 0 || linha > 3 || coluna < 0 || coluna > 3 ||
   linha2 < 0 || linha2 > 3 || coluna2 < 0 || coluna2 > 3)
{
    cout << "Posicao invalida. Use numeros de 1 a 4." << endl;
}   
    else if(linha == linha2 && coluna == coluna2){
        cout<<"Posicões iguais, tente novamente."<<endl;
    cin.ignore();
    cin.get();
   
    }
    else if(jogo[linha][coluna] != 0 || jogo[linha2][coluna2] != 0){
        cout<<"Posição ja foi descoberta, tente novamente."<<endl;
    cin.ignore();
    cin.get();
    }
    else{
    tentativas++;
    cout<<"Primeiro numero: "<<gabarito[linha][coluna]<<endl;
    cout<<"Segundo numero: "<<gabarito[linha2][coluna2]<<endl;
    cin.ignore();
    cin.get();

    if (gabarito[linha][coluna] == gabarito[linha2][coluna2])
    {
      paresEncontrados++;
      cout << "JOGADA OK - Um par encontrado!, restam " << (8 - paresEncontrados)
           << " pares" << endl;
      jogo[linha2][coluna2] = gabarito[linha2][coluna2];
      jogo[linha][coluna] = gabarito[linha][coluna];

    } else {

      cout << "JOGADA NOK - Nenhum par encontrado, restam " << (8 - paresEncontrados)
           << " pares" << endl;
    }
    cout << "Pressione qualquer tecla para continuar..." << endl;
    cin.ignore();
    cin.get();
    system("clear");
    
}
    /* mostra a matriz do jogo e pergunta qual é a linha e coluna que o  jogador
     * quer adivinhar*/
  } while (paresEncontrados < 8 && tentativas < 24);
 
    /*mensagem de fim de jogo*/ 
  if(paresEncontrados == 8)
  {
    cout << "Parabens! Voce venceu!" << endl;
}
else
{
    cout << "Voce perdeu! Acabaram as 24 jogadas." << endl;
}

  return 0;
}
