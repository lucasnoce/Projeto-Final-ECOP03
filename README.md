# Projeto-Final-ECOP03
Projeto final da disciplina de Programação Orientada a Objetos (POO), que consistia na criação de um jogo simples de videogame para PC.

----

# Impure Blood

Você estava sentado na cadeira do seu quarto comendo um sorvete e assistindo a um anime isekai. 

De repente, a tela do seu computador e as luzes do seu quarto começam a piscar, a tela do seu computador fica travada no azul e uma voz começa a te chamar lá de dentro, você toca no seu monitor e é sugado para dentro do computador. 

Então você acorda em um mundo alternativo e uma fada te explica que o mundo está em apuros e ela te convocou para derrotar os 5 reis tiranos que assombram o planeta. Você aceita ajudar e ela convoca uma tela na sua frente e pede para você preencher algumas características do seu personagem no planeta.

> Notas de rodapé: (Isekai é um subgênero de animes de fantasia caracterizado por um protagonista normal sendo transportado ou preso em um universo paralelo)  

# Mecânica
Primeiramente, a linha de comando para compilação do programa é: g++ classes.cpp ImpureBlood.cpp -o ImpureBlood.exe

O jogador inicia o jogo tendo que escolher entre um nome para seu personagem e 5 classes: Vampiro, Atirador, Mago, Guerreiro e Elfo. Após essas escolhas, ele terá 20 pontos para serem distribuídos entre os 3 atributos disponíveis: Armadura, Força e Vida. 

Além desses 3 atributos os personagens contam também com o atributo stamina, que é fixado em 10 pontos. A stamina é usada durante a batalha e a cada ataque que o personagem faz, é descontado 5 pontos dela. Quando ela chega em zero, o personagem é obrigado a descansar e durante seu descanso ela é recuperada em 5 pontos. O jogador tem também a opção de descansar antes da stamina ter se esgotado fazendo também com que ela recupere 5 pontos.
 
Ao iniciar a batalha, o jogador é o primeiro a atacar um vilão com classe e atributos gerados aleatoriamente. Tanto jogador, quanto o vilão tem uma chance de acertar o ataque e de esquivar desse ataque. Caso o ataque seja efetuado, o vilão perde vida e existe também a chance da passiva do personagem do jogador ser ativada e seu efeito depende da classe do personagem, como definido acima. Após o ataque do jogador, será a vez do vilão e seu ataque funciona da mesma forma que o ataque do jogador.

Quando a batalha termina, vilão e jogador sobem de nível. Vilão ganha pontos de atributo por subir de nível. Caso o jogador vença, ficará disponível para ele 1 ponto para ele escolher distribuir entre os 3 atributos. Por fim, o jogador terá a opção de começar uma nova batalha.

 
- Personagem:
  - Nome / 20 pontos entre força, armadura, vida / Stamina = 10 (Vampiro)
  - Nome / 20 pontos entre força, armadura, vida / Stamina = 10 (Atirador)
  - Nome / 20 pontos entre força, armadura, vida / Stamina = 10 (Mago)
  - Nome / 20 pontos entre força, armadura, vida / Stamina = 10 (Guerreiro)
  - Nome / 20 pontos entre força, armadura, vida / Stamina = 10 ( Elfo)

- Passivas:
  - Vampiro:  20% chance de roubar vida do inimigo
  - Atirador: 30% chance de acertar dar 2 ataques.
  - Mago:   30% de chances de reduzir a armadura do inimigo pela metade, o efeito é acumulativo
  - Guerreiro:  o guerreiro tem um upgrade de sua armadura a cada vez que ele ataca, além disso ele pode ultrapassar o máximo de poder de defesa possível (o máximo para outros personagem é 10, o dele é 15)
  - Elfo:   o elfo tem 20% de chance de roubar 5 de stamina do inimigo

- Recompensa: a cada batalha ganha ele ganha 1 ponto para dividir em seus atributos.

----
Grupo:
 - Lucas Arturo Noce - 2018001852
 - Davi Gouveia Vilela - 2020015372
 - Henrique Fernandes Saura - 21459
 - Lucio Henrique Souza Silva - 2020007639
 - Gustavo Leonardo Almeida Martins de Vasconcelos - 2019017893
