<h1 align="center">
  <br>
    <img width="400px" src="https://github.com/user-attachments/assets/a2da68bf-9b98-4650-9953-7358a5a1bf18">
  <br>
  Controle de Pinos GPIO com Teclado Matricial - Microcontroladores
  <br>
</h1>
<div align="center">


</div>

<div align="center"> 

Este código tem o objetivo de fazer o controle de LEDs por meio das entradas e saídas de propósito geral do microcontrolador **RP2040**, simulado pela extensão **Wokwi**. Para isso, foi utilizado um teclado matricial 4x4 para acionar 3 LEDs e um buzzer, sendo que no total foram utilizados 4 GPIOs, sendo elas: **18**, **19**, **20** e **28**. Já para o teclado, foram utilizadas as GPIOs de **2 a 9**.

</div>

<details open="open">
<summary>Sumário</summary>
  
- [Tecnologias e Ferramentas Utilizadas](#tecnologias-e-ferramentas)
- [Objetivos](#objetivos)
- [Comandos Utilizados no Teclado](#comandos-utilizados-no-teclado)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Como Executar](#como-executar)
  - [Pré-requisitos](#pré-requisitos)
  - [Passos para Execução](#passos-para-execução)
- [Testes Realizados](#testes-realizados)
- [Vídeo Demonstração](#vídeo-demonstração)
- [Autores](#autores-do-subgrupo-3)

</details>

## Componentes e Tecnologias 

1. **Teclado Matricial 4x4**: Um teclado de 4 linhas e 4 colunas utilizado para a interação do usuário, permitindo acionar os LEDs e o buzzer.
2. **03 LEDs – tipo RGB**: LEDs de cores distintas (azul, rosa e roxo) usados para representar o controle dos GPIOs no microcontrolador.
3. **Componente Buzzer**: Dispositivo utilizado para emitir um som de sinalização quando acionado pelo teclado.
4. **Microcontrolador Raspberry Pi Pico W**: Placa de desenvolvimento baseada no RP2040, utilizada para o controle dos componentes e execução do código.
5. **Ferramenta Educacional BitDogLab (versão 6.3)**
6. **Simulador Wokwi**: Plataforma online que permite simular circuitos eletrônicos e testar o código, sendo usada para simular a interação com os GPIOs e os periféricos (teclado, LEDs e buzzer) na Raspberry Pi Pico.

## Objetivos

O projeto tem como objetivo:

- Criar uma interface de controle para LEDs e buzzer usando um teclado matricial.
- Acionar LEDs de diferentes cores dependendo da tecla pressionada.
- Gerar sons específicos no buzzer ao pressionar outras teclas.

### Comandos Utilizados no Teclado

- **Aperte A**: Para ligar o **LED Azul**.
- **Aperte B**: Para ligar o **LED Rosa**.
- **Aperte C**: Para ligar o **LED Roxo**.
- **Aperte D**: Para o **Buzzer** tocar uma nota por 1 segundo.
- **Aperte 2**: Para ligar o **LED Azul** e o **LED Rosa**.
- **Aperte 3**: Para ligar o **LED Azul**, o **LED Rosa** e o **LED Roxo**.
- **Aperte 4**: Para ligar o **LED Azul** e o **LED Roxo**.
- **Aperte 5**: Para ligar o **LED Rosa** e o **LED Roxo**.
- **Aperte \***: Para acionar o efeito de **piscar** nos LEDs.
- **Aperte #**: Para ativar o **Buzzer (1kHz)** por 1 segundo.
  
**Obs.1**: É necessário segurar a tecla por alguns segundos até que o comando seja registrado.

**Obs.2**: O programa constantemente envia o feedback da resposta do teclado pelo terminal.

<div align="center">
      <img width="800px" src="https://github.com/user-attachments/assets/d595b771-1715-45c9-82e3-b89dcb8525eef" />
      <p>Fig 1. Simulador.</p>
   </div>

## Estrutura do Projeto

- **main.c**: Contém a lógica principal do programa, que gerencia a interação com o teclado e o controle dos LEDs e buzzer.
- **keypad.c**: Implementação do controle do teclado matricial 4x4.
- **LED_Buzz.c**: Contém as funções para acionar os LEDs e buzzer.
- **README.md**: Este arquivo, contendo as instruções e descrição do projeto.

## Como Executar

### Pré-requisitos

- **VS Code** instalado.
- **Pico SDK** configurado no ambiente de desenvolvimento.
- **Wokwi Simulator** configurado para emular o Raspberry Pi Pico W.

### Passos para Execução

1. Clone este repositório para o seu ambiente local:

   ```bash
   git clone https://github.com/Ukobir/Aula-14-01-Tarefa-1.git

    ```

2. Abra o projeto no VS Code
3. Compile o código.
4. Utilize o simulador Wokwi ou a comunicação real com a placa para testar os comandos. 

## Testes Realizados
Os seguintes testes foram realizados para garantir o funcionamento correto do projeto:

1. **Acionamento individual do LED azul pela tecla A.**  
   <div align="center">
      <img width="800px" src="https://github.com/Ukobir/Aula-14-01-Tarefa-1/blob/master/scr/led-azul-gif.gif" />
      <p>Fig 2. LED azul acionado pela tecla A.</p>
   </div>

2. **Acionamento individual do LED rosa pela tecla B.**  
   <div align="center">
      <img width="800px" src="https://github.com/Ukobir/Aula-14-01-Tarefa-1/blob/master/scr/led-b_gif.gif" />
      <p>Fig 3. LED rosa acionado pela tecla B.</p>
   </div>

3. **Acionamento individual do LED roxo pela tecla C.**  
   <div align="center">
      <img width="800px" src="https://github.com/Ukobir/Aula-14-01-Tarefa-1/blob/master/scr/led-c.gif" />
      <p>Fig 4. LED roxo acionado pela tecla C.</p>
   </div>

4. **Ativação do buzzer com frequências específicas pelas teclas D e #.**  
   <div align="center">
      <img width="800px" src="https://github.com/Ukobir/Aula-14-01-Tarefa-1/blob/master/scr/led-d.gif" />
      <p>Fig 5. Ativação do buzzer pelas teclas D.</p>
   </div>
   
  <div align="center">
      <img width="800px" src="https://github.com/Ukobir/Aula-14-01-Tarefa-1/blob/master/scr/tecla-%23.gif" />
      <p>Fig 6. Ativação do buzzer pelas teclas # por 1 segundo.</p>
   </div>
   
5. **Efeito de piscar LEDs com a tecla `*`.**  
   <div align="center">
      <img width="800px" src="https://github.com/Ukobir/Aula-14-01-Tarefa-1/blob/master/scr/tecla-piscar.gif" />
      <p>Fig 7. LEDs piscando ao pressionar a tecla `*`.</p>
   </div>

6. **Feedback de comandos exibido no terminal para facilitar a depuração.** 
---

## Vídeo Demonstração
[Vídeo do funcionamento](https://youtu.be/wRjZaDKlV44)

## Autores do Subgrupo 3
- Naila Suele
- Leonardo Romão
- Silas Kenji de Souza
- João Vitor Moreira
- Isaias Rodrigues Mendes
