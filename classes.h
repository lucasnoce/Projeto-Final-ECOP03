#ifndef CLASSES_H
#define CLASSES_H

#include <string>

using namespace std;


////////////////////////////////////////
//   superclasse Personagem
class Personagem{
  protected:
    string nome;
    int forca = 0, armadura = 0, stamina = 10, vida = 0;
  
  public:
    int nivel = 1;
    bool flagJogador;
    Personagem(string="", int=0, int=0, int=0);
    ~Personagem() { }
    void imprimeCaracteres(); // imprime os caracteres do personagem.
    void imprimeNivel() {cout << nivel;} // imprime o nével.
    void perdeVida() { vida = vida -1; } // reduz a vida do personagem.
    int getVida() { return vida; } // retorna a vida.
    void morte() {vida = 0;} // função usada quando alguem morre.
    void alteraAtributos(int a); // quando o personagem upa de nivel o usuário poderá escolher qual atributo será upado.
    void alteraStamina(int s) { stamina += s; } // a stamina define o cansaso dos personagens, muitos calculos se baseiam na estamina.
    void reducaoArmadura() { armadura *= 0.5; } // função usada na passiva mago, reduz a armadura do inimigo.
    
    virtual int defesa() = 0; // a função defesa entra como parte do calculo presente na função atacar
    virtual void atacar(Personagem*) = 0; // é na função atacar que ocorre os tiros, espada e mortes, está função é definida por um calculo que mostra a porcentagem de chance de tirar uma vida do inimigo, esse calculo leva em conta a força de ataque do atacante e poder de defesa da personagem que está sendo atacado.
    virtual void passiva(Personagem*) = 0; /* cada personagem tem sua passiva, as passivas são ativadas com certa porcentagem de chances de ativação, ou seja, nem sempre são ativadas. as passivas são ativadas dentro da função atacar (no caso do guerreiro ela é presente na função defesa e é sempre ativada 100% de chance de ativação)*/
    virtual string classe() = 0; // função usada para a impressão da classe (mago/atirador/...) na função imprime caracteres
    bool defineCansaso (); // a stamina simula o cansaso do personagem, quando o personagem está com a stamina zerada ele não pode atacar, está função garante isso, obrigando o personagem a "descancar" e recuperar um pouco da sua stamina 
    
};


////////////////////////////////////////
//   subclasses derivadas de Personagem
//
////////////////////////////////////////
//   subclasse Vampiro
class Vampiro : public Personagem{
  public:
    Vampiro(string, int, int, int);
    ~Vampiro() { }

    string tipoClasse = "Vampiro";
    string classe(){ return tipoClasse; }
    int defesa();
    void atacar(Personagem*);
    void passiva(Personagem*); // o vampiro tem 20% de chances de roubar uma vida do inimigo
};

////////////////////////////////////////
//   subclasse Atirador
class Atirador : public Personagem{
  public:
    Atirador(string, int, int, int);
    ~Atirador() { }

    string tipoClasse = "Atirador";
    string classe(){ return tipoClasse; }
    int defesa();
    void atacar(Personagem*);
    void passiva(Personagem*); // o atirador tem 30% de chances de atacar duas vezes.
};

////////////////////////////////////////
//   subclasse Mago
class Mago : public Personagem{
  public:
    Mago(string, int, int, int);
    ~Mago() { }

    string tipoClasse = "Mago";
    string classe(){ return tipoClasse; }
    int defesa();
    void atacar(Personagem*);
    void passiva(Personagem*); // o mago tem 30% de chances de reduzir a armadura do inimigo pela metade, o efeito é acumulativo.
};

////////////////////////////////////////
//   subclasse Guerreiro
class Guerreiro : public Personagem{
  public:
    Guerreiro(string, int, int, int);
    ~Guerreiro() { }

    string tipoClasse = "Guerreiro";
    string classe(){ return tipoClasse; }
    int defesa();
    void atacar(Personagem*);
    void passiva(Personagem*); // o guerreiro tem um upgrade de sua armadura a cada vez que ele ataca, além disso ele pode ultrapassar o máximo de poder de defesa possível (o máximo para outros personagem é 10, o dele é 15).
};

////////////////////////////////////////
//   subclasse Elfo
class Elfo : public Personagem{
  public:
    Elfo(string, int, int, int);
    ~Elfo() { }

    string tipoClasse = "Elfo";
    string classe(){ return tipoClasse; }
    int defesa();
    void atacar(Personagem*);
    void passiva(Personagem*); // o elfo tem 20% de chance de roubar 5 de stamina do inimigo;
};
#endif //CLASSES_H