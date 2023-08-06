#include <string>
#include <iostream>
#include "Classes.h"
#include <time.h>
#include <cstdlib>

using namespace std;

int randomico();

//////////////////////////////////////////////////////
//   definicoes das funcoes
//////////////////////////////////////////////////////
//   superlasse Personagem

Personagem::Personagem(string n, int fca, int arm, int vd)
    : nome{n}, forca{fca}, armadura{arm}, vida{vd} { }

bool Personagem::defineCansaso ()
{
  if (stamina <= 0)
  {
    stamina = 5;
    if (this->flagJogador == true)
      cout << "[Sem stamina] Voce precisou descansar e nao atacou!" << endl;
    else
      cout << "[Sem stamina] O inimigo precisou descansar e nao atacou!" << endl;

    return false;
  }
  return true;
}

void Personagem::imprimeCaracteres ()
{
  cout << endl;
  cout << "Personagem: " << nome << endl;
  cout << "Classe: " << classe();
  cout << "\nNivel: ";
  imprimeNivel();
  cout << endl;
  cout << "Status da Vida: ";
  if (vida <= 0) cout << "Morto";
  for (int i=0; i<vida; i++){
    cout << "|";
  } 
  cout << endl;
  cout << "Forca: " << forca << endl;
  cout << "Armadura: " << armadura << endl;
  if (stamina <= 0) stamina = 0;
  cout << "Stamina: " << stamina << endl << endl;
}

void Personagem::alteraAtributos(int a){
  switch (a){
    case 1: vida++; break;
    case 2: forca++; break;
    case 3: armadura++; break;
    default: cout << "Opcao invalida! O atributo upado foi a vida." << endl;
             vida++; break;
  }
}



//////////////////////////////////////////////////////
//   subclasses derivadas de Personagem
//
//////////////////////////////////////////////////////
//   subclasse Vampiro

Vampiro::Vampiro(string n, int fca, int arm, int vd)
    : Personagem{n, fca, arm, vd} { }

int Vampiro::defesa()
{
  int poderDefesa = (this->stamina/5) + (this->armadura) + nivel;
  if (poderDefesa > 10) return 10;
  return poderDefesa;
}

void Vampiro::atacar(Personagem* a)
{
  if (defineCansaso())
  {
    int poderV = 10*forca + (3*stamina)/5 + nivel - a->defesa();
    if (poderV >= randomico())
    {
      a->perdeVida();
      alteraStamina(-5);
      if (this->flagJogador == true)
        cout << "Voce tirou uma vida do seu inimigo!" << endl;
      else
        cout << "O inimigo tirou uma vida sua!" << endl;
      passiva(a);
    }
    else{
      if (this->flagJogador == true)
        cout << "O inimigo esquivou do seu ataque!" << endl;
      else
        cout << "Voce esquivou do ataque inimigo!" << endl;
    }
  }
}

void Vampiro::passiva(Personagem* a){
  if (randomico() <= 20){
    this->vida++;
    if (this->flagJogador == true)
      cout << "[Passiva] Voce roubou a vida que tirou do inimigo" << endl;
    else
      cout << "[Passiva] O inimigo roubou a vida que tirou de voce" << endl;
  }
}



//////////////////////////////////////////////////////
//   subclasse Atirador

Atirador::Atirador(string n, int fca, int arm, int vd)
    : Personagem{n, fca, arm, vd} { }

int Atirador::defesa()
{
  int poderDefesa = (this->stamina/5) + (this->armadura) + nivel; 
  if (poderDefesa > 10) return 10;
  return poderDefesa;
}

void Atirador::atacar (Personagem* a)
{
  if (defineCansaso())
  {
    int poderV = 10*forca + (3*stamina)/5 + nivel - a->defesa();
    if (poderV >= randomico())
    {
      passiva(a);
      a->perdeVida();
      alteraStamina(-5);
      if (this->flagJogador == true)
        cout << "Voce tirou uma vida do seu inimigo!" << endl;
      else
        cout << "O inimigo tirou uma vida sua!" << endl;
    }
    else{
      if (this->flagJogador == true)
        cout << "O inimigo esquivou do seu ataque!" << endl;
      else
        cout << "Voce esquivou do ataque inimigo!" << endl;
    }
  }
}

void Atirador::passiva(Personagem *a)
{
  if (randomico() <= 30){
    int poderV = 10*forca + (3*stamina)/5 + nivel - a->defesa();
    if (poderV >= randomico()){
      a->perdeVida();
      if (this->flagJogador == true)
        cout << "[Passiva] Voce deu um ataque extra" << endl;
      else
        cout << "[Passiva] O inimigo deu um ataque extra" << endl;
    }
  }
}


//////////////////////////////////////////////////////
//   subclasse Mago

Mago::Mago(string n, int fca, int arm, int vd)
    : Personagem{n, fca, arm, vd} { }

int Mago::defesa()
{
  int poderDefesa = (this->stamina/5) + (this->armadura) + nivel;
  if (poderDefesa > 10) return 10;
  return poderDefesa;
}

void Mago::atacar (Personagem* a)
{
  if (defineCansaso())
  {
    int poderV = 10*forca + (3*stamina)/5 + nivel - a->defesa();
    if (poderV >= randomico())
    {
      passiva(a);
      a->perdeVida();
      alteraStamina(-5);
      if (this->flagJogador == true)
        cout << "Voce tirou uma vida do seu inimigo!" << endl;
      else
        cout << "O inimigo tirou uma vida sua!" << endl;
    }
    else{
      if (this->flagJogador == true)
        cout << "O inimigo esquivou do seu ataque!" << endl;
      else
        cout << "Voce esquivou do ataque inimigo!" << endl;
    }
  }
}

void Mago::passiva(Personagem* a){
  if (randomico() <= 30){
    a->reducaoArmadura();
    if (this->flagJogador == true)
      cout << "[Passiva] Voce quebrou a armadura do inimigo pela metade" << endl;
    else
      cout << "[Passiva] O inimigo quebrou a sua armadura pela metade" << endl;
  }
}

//////////////////////////////////////////////////////
//   subclasse Guerreiro

Guerreiro::Guerreiro(string n, int fca, int arm, int vd)
    : Personagem{n, fca, arm, vd} { }

int Guerreiro::defesa()
{
  int poderDefesa = (this->stamina/5) + (this->armadura) + nivel;
  if (poderDefesa > 15) return 15;
  return poderDefesa;
}

void Guerreiro::atacar (Personagem* a)
{
  if (defineCansaso())
  {
    int poderV = 10*forca + (3*stamina)/5 + nivel - a->defesa();
    if (poderV >= randomico())
    {
      passiva(a);
      a->perdeVida();
      alteraStamina(-5);
      if (this->flagJogador == true)
        cout << "Voce tirou uma vida do seu inimigo!" << endl;
      else
        cout << "O inimigo tirou uma vida sua!" << endl;
    }
    else{
      if (this->flagJogador == true)
        cout << "O inimigo esquivou do seu ataque!" << endl;
      else
        cout << "Voce esquivou do ataque inimigo!" << endl;
    }
  }
}

void Guerreiro::passiva(Personagem* a){
  armadura++;
  if (this->flagJogador == true)
    cout << "[Passiva] A sua armadura foi aumentada em 1 unidade" << endl;
  else
    cout << "[Passiva] A armadura do inimigo foi aumentada em 1 unidade" << endl;
}

//////////////////////////////////////////////////////
//   subclasse Elfo

Elfo::Elfo(string n, int fca, int arm, int vd)
    : Personagem{n, fca, arm, vd} { }

int Elfo::defesa()
{
  int poderDefesa = (this->stamina/5) + (this->armadura) + nivel;
  if (poderDefesa > 10) return 10;
  return poderDefesa;
}

void Elfo::atacar (Personagem *a)
{
  if (defineCansaso())
  {
    int poderV = 10*forca + 3*stamina/5 + nivel - a->defesa();
    if (poderV >= randomico())
    {
      passiva(a);
      a->perdeVida();
      alteraStamina(-5);
      if (this->flagJogador == true)
        cout << "Voce tirou uma vida do seu inimigo!" << endl;
      else
        cout << "O inimigo tirou uma vida sua!" << endl;
    }
    else{
      if (this->flagJogador == true)
        cout << "O inimigo esquivou do seu ataque!" << endl;
      else
        cout << "Voce esquivou do ataque inimigo!" << endl;
    }
  }
}

void Elfo::passiva(Personagem *a){
  if (randomico() <= 20){
    stamina += 5;
    a->alteraStamina(-5);
    if (this->flagJogador == true)
        cout << "[Passiva] Voce roubou 5 de stamina do seu inimigo" << endl;
      else
        cout << "[Passiva] O inimigo roubou 5 de stamina de voce" << endl;
  } 
}


// randomico de 0 a 100

int randomico()
{
  int randon = 0;
  randon = rand()%(101) + 1;
  return randon;
}