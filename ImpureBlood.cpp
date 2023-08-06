#include <string>
#include <iostream>
#include "Classes.h"
#include <time.h>
#include <cstdlib>

using namespace std;

void pontosSobrando(int pontos, int atr);
void OpcoesDeLuta ();
void Batalha(int n);
void aleatorizarAtributos(int* atributo, int n);
string aleatorizarNome();
void criarVilao(int n);
void criarJogador(int cl, string nm, int fr, int arm, int vd);
void sobe_de_nivel ();
void definirClasse(int classeDoPersonagem);
void historia (int n);

// jogador e viloes definidos como ponteiros globais
Personagem* Jogador;
Personagem* vilao[5];


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
//   funcao main

int main(){
  srand(time(NULL));
  
  string nome;
  int classeDoPersonagem, atr=0, pontos=20;
  int forca, armadura, vida;

  cout  << "\n####### Impure Blood #######\n" << endl;
  system ("pause");
  system ("cls");
  
  //história:
  cout << "Voce estava sentado na cadeira do seu quarto comendo um sorvete e assistindo a um anime isekai. " << endl;
  cout << "Notas de rodape: (Isekai eh um subgenero animes de fantasia caracterizado por um protagonista normal sendo transportado ou preso em um universo paralelo) " << endl;
  
  // pausa dramática para a história.
  system ("pause");
  system ("cls");

  cout << "De repente a tela do seu computador e as luzes do seu quarto comecam a piscar, a tela do seu computador fica travada no azul e uma voz comeca a te chamar la de dentro, voce toca no seu monitor e eh sugado para dentro do computador. " << endl;
  
  // pausa dramática para a história.
  system ("pause");
  system ("cls");

  cout << "Entao voce acorda em um mundo alternativo e uma fada te explica que o mundo esta em apuros e ela te convocou para derrotar os 5 reis tiranos que assombram o planeta.  voce aceita ajudar e ela convoca uma tela na sua frente e pede para voce preencher algumas caracteristicas do seu personagem no planeta" << endl;
  
  // pausa dramática para a história.
  system ("pause");
  system ("cls");
  // fim da história inicial.

  //inicializando atributos do jogador (o usuário que entra com os dados):
  cout << "De um nome ao personagem: ";  
  getline(cin, nome);
  
  cout << "Escolha a classe do personagem: \n1 - Vampiro\n2 - Atirador\n3 - Guerreiro\n4 - Elfo\n5 - Mago\n";
  cin >> classeDoPersonagem;
  definirClasse(classeDoPersonagem);
  
  cout << "Voce tem no maximo 20 pontos para distribuir entre os atributos a seguir. A vida nao pode ultrapassar 6 pontos e a forca nao pode ultrapassar 8 pontos. Escolha sabiamente:\n(vida e foca nao podem ser menor do que 0)\n";
  pontosSobrando(pontos, atr);

  cout << "Forca: ";
  cin >> forca;
  pontos -= forca;
  atr++;
  pontosSobrando(pontos, atr);
  
  cout << "Armadura: ";
  cin >> armadura;
  pontos -= armadura;
  atr++;
  pontosSobrando(pontos, atr);
  
  cout << "Vida: ";
  cin >> vida;
  pontos -= vida;
  atr++;

  if (pontos < 0 || vida > 6 || vida <=0 || forca > 8 || forca <= 0){
    cout << "Numero de pontos invalido! Seus atributos foram definidos automaticamente" << endl;
    forca = 7;
    armadura = 7;
    vida = 6;
  }

  criarJogador(classeDoPersonagem, nome, forca, armadura, vida);
  
  system("pause");
  system("cls");
  Jogador->flagJogador = true;

  for (int i=0; i<5; i++){ //ideia tirar o laco e criar uma historia.
    if (Jogador->getVida() <= 0) goto morte;
    criarVilao(i);
    historia(i);
    vilao[i]->imprimeCaracteres();
    system("pause");
    system ("cls");
    Batalha(i);
  }

  morte:
  if (Jogador->getVida() > 0)
  {
    cout << "A fada te agradece por ter salvo o mundo dela, ela te faz voltar para casa, no outro dia voce faz um exame para ver se nao estava drogado pois nao consegue acreditar em tudo que aconteceu.\n";
    cout << "parabens por ter finalizado o Jogo!" << endl;
    cout << "obrigado por jogar!" << endl;
  }
  else{
    cout << "Voce morreu, e volta para o seu mundo, samanas se passam e voce fica com depressao, saiu parar beber uma noite e morreu de overdose.\n";
  }

  return 0;
}


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
//   definicoes das funcoes da main

void pontosSobrando(int pontos, int atr){
  if (pontos <= 0 && atr != 3) cout << "Voce nao tem mais pontos para distribuir!\n" << endl;
  else if (pontos > 0) cout << "Voce ainda tem " << pontos << " ponto(s) sobrando!" << endl;
}

void OpcoesDeLuta (int n)
{
  Escolha:
  system("pause");
  system("cls");
  cout << "Eh a sua vez! Escolha uma opcao para o combate:" << endl;
  cout << "1 - Atacar" << endl;
  cout << "2 - Fugir" << endl;
  cout << "3 - Descansar" << endl;
  
  int a;
  cin >> a;
  switch (a)
  {
    case 1: Jogador->atacar(vilao[n]);
            break;
    case 2: cout << "Voce conseguiu fugir com exito !!!" << endl;
            system("pause");
            cout << "Para comemorar sua fuga voce foi a uma casa noturna e bebeu ate cair" << endl;
            system("pause");
            cout << "voce morreu de overdose!" << endl;
            Jogador ->morte();
            break;
    case 3: cout << "Voce esta descansado e pronto para lutar melhor" << endl;
            Jogador ->alteraStamina(5);
            break;
    default: 
            system("cls");
            cout << "Opcao invalida! Escolha novamente" << endl;
            goto Escolha;
  }
  
}

// função que rola a luta.
void Batalha(int n)
{
  if (n>1) sobe_de_nivel();
  
  while (Jogador->getVida() > 0 && vilao[n]->getVida() > 0)
  {
    Jogador->imprimeCaracteres();
    OpcoesDeLuta(n);
    cout << endl;
    
    if (vilao[n]->getVida() > 0){
      cout << "Vez do inimigo:" << endl;
      vilao[n]->imprimeCaracteres();
      vilao[n]->atacar(Jogador);
    }
    else{
      Jogador->nivel++;
      cout << "Voce ganhou esta batalha!" << endl;
      system("pause");
      system("cls");
    }
  }
}

// os atributos (forca e armadura) dos viloes são aleatórios, porém cresce de acordo com o nivel.
void aleatorizarAtributos(int* atributo, int n){
  int soma = 0;
  int aux;
  for (int i=0; i<2; i++){
    atributo[i] = (int) 1 + rand()%((12 + n*2)-soma);
    soma += atributo[i];
  }

  while (soma > (16 + n*4)){ 
    aux = (int) rand()%2;
    if (atributo[aux] > (17 + n*2)){
      atributo[(int) rand()%3]--;
      soma--;
    }
  }
  while (soma < (16 + n*4)){
    aux = (int) rand()%2;
    if (atributo[aux] < (17 + n*2)){
      atributo[(int) rand()%2]++;
      soma++;
    }
  }
}

// o nome dos vilões são aleatórios para não ser tão repetitivo, está função garante isso.
string aleatorizarNome(){
  int r = rand()%10;
  string nome;
  switch(r){
    case 1:   nome = "Abnegazar"; break;
    case 2:   nome = "Rath"; break;
    case 3:   nome = "Gast"; break;
    case 4:   nome = "Amthor"; break;
    case 5:   nome = "Mathmoth"; break;
    case 6:   nome = "Frithcrow"; break;
    case 7:   nome = "Leeken"; break;
    case 8:   nome = "Elithorsam"; break;
    case 9:   nome = "Nandoc"; break;
    case 10:  nome = "Ronda"; break;
    case 11:  nome = "Hilditri"; break;
    case 12:  nome = "Daschris"; break;
    case 13:  nome = "Jeffhew"; break;
    case 14:  nome = "Dajoan"; break;
    case 15:  nome = "Vengardguth"; break;
    case 16:  nome = "Charmen"; break;
    case 17:  nome = "Thangfreyne"; break;
    case 18:  nome = "Freyautarg"; break;
    case 19:  nome = "Daschris"; break;
    case 20:  nome = "Cuthgar"; break;
    default:  nome = "Nethlay"; break;
  }
  return nome;
}

// inicializa os viloes.
void criarVilao(int n){
  int atributo[2];
  aleatorizarAtributos(atributo, n);
  string nomeVilao = aleatorizarNome();

  switch(n){
    case 0: vilao[n] = new Vampiro   (nomeVilao, atributo[0], atributo[1], n+1); break;
    case 1: vilao[n] = new Atirador  (nomeVilao, atributo[0], atributo[1], n+1); break;
    case 2: vilao[n] = new Mago      (nomeVilao, atributo[0], atributo[1], n+1); break;
    case 3: vilao[n] = new Guerreiro (nomeVilao, atributo[0], atributo[1], n+1); break;
    case 4: vilao[n] = new Elfo      (nomeVilao, atributo[0], atributo[1], n+1); break;
  }

  vilao[n]->flagJogador = false;
  vilao[n]->nivel = n+1;
}

//inicializa os personagens.
void criarJogador(int cl, string nm, int fr, int arm, int vd){
  switch (cl){
    case 1:  Jogador = new Vampiro    (nm, fr, arm, vd); break;
    case 2:  Jogador = new Atirador   (nm, fr, arm, vd); break;
    case 3:  Jogador = new Guerreiro  (nm, fr, arm, vd); break;
    case 4:  Jogador = new Elfo       (nm, fr, arm, vd); break;
    case 5:  Jogador = new Mago       (nm, fr, arm, vd); break;
    default: Jogador = new Vampiro    (nm, fr, arm, vd); break;
  }
}

// essa função faz o usuário upar uma caracteristica do seu personagem.
void sobe_de_nivel ()
{
  int a;
  cout << "Escolha um atributo para upar" << endl;
  cout << "1 - Para vida" << endl;
  cout << "2 - Para forca" << endl;
  cout << "3 - Para armadura" << endl;
  cin >> a;
  cout << endl;
  Jogador->alteraAtributos(a);
}

// essa função impede a pessoa de escolher uma classe invalida, caso a pessoa escolha uma classe invalida, altomaticamente o programa colocará a pessoa como um vampiro.
void definirClasse(int classeDoPersonagem){
  if (classeDoPersonagem <= 0 || classeDoPersonagem >= 6)
    cout << "Opcao invalida! Voce agora eh um Vampiro!\n\n";
}

// essa função define o enredo das batalhas.
void historia (int n)
{
  switch (n)
  {
    case 0: cout << "A fada te teletransportou para uma caverna onde mora o primeiro rei vampiro que voce ira combrater.\nBoa sorte!" << endl;
    break;

    case 1: cout << "Saindo da caverna, apos derrotar o vampiro, voce se depara com o segundo rei, O atirador, temido pelas suas habilidade com o arco ele eh um grande adiversario.\nBoa sorte!" << endl;
    break;

    case 2: cout << "Com o cadaver do atirador na sua frente a fada aparece para te parabenizar e te presenteia com uma vida e te teleporta para o castelo do mago.\nBoa sorte!" << endl;
    Jogador->alteraAtributos(1); // ganha a vida que a fada deu.
    break;

    case 3: cout << "Apos matar o mago voce revista o corpo dele atras de informacoes, dentro do bolso dele voce encontr uma carta que foi enviada pelo rei guerreiro chamando-o para uma reuniao no lago perto do castelo do mago, entao voce vai no lugar do mago encontra o guerreiro.\nBoa sorte!" << endl;
    break;

    case 4: cout << "Faltoando apenas 1 rei para derrotar a fada aparece na sua frente te fala a localizacao do rei Elfo, ela diz que dessa vez nao podera te teletransportar, voce tera que ir andando.";
            cout << "Indo para o encontro com o elfo voce se sente forte por ter derrotado os 4 reis e fica confiante da sua ultima batalha.\nBoa sorte!" << endl;
    break;
  }
   cout << "Estas sao as caracteristicas do rei " << vilao[n]->classe() << ":";
}