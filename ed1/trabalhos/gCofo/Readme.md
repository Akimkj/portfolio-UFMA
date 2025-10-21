# Trabalho de Implementação 01 - TAD Genérico
## Descrição do projeto
Este projeto implementa um Tipo Abstrato de Dado (TAD) genérico para gerenciamento de coleções em linguagem C, aplicado especificamente para armazenar informações sobre jogos. Esta aplicacação oferece uma interface gráfica via terminal no qual o usuário consegue manipular os elementos da coleção.

Como exemplo, utilizamos o tipo de dado <code>Jogo</code> que possui os seguintes campos necessários:
<ul>
  <li><code>char name[100];</code> - Nome do jogo</li>
  <li><code>int anoLancamento;</code> - Ano de lançamento do jogo</li>
  <li><code>float notaSteam;</code> - Nota do jogo na plataforma Steam</li>
</ul>

<hr>

<h2>1. Ambiente de desenvolvimento</h2>
<ul>
  <li><strong>Sistema operacional</strong> - Windows 11 e Linux Ubuntu</li>
  <li><strong>Compilador</strong> - MinGW e GCC</li>
  <li><strong>Bibliotecas externas</strong> - Nenhuma</li>
</ul>

<h2>2. Compilação e Execução</h2>
<h3>No linux/MacOS</h3>
<pre>
  <code>
    gcc -g app.c gCofo.c -o app
    .\app 
  </code>
</pre>
<h3>No Windows</h3>
<pre>
  <code>
    gcc -g app.c gCofo.c -o app
    .\app.exe
  </code>
</pre>

<h2>3. Funcionalidades implementadas</h2>
<table> 
  <ul> 
    <li><strong>Criar uma nova coleção</strong> - Define o tamanho máximo da coleção</li> 
    <li><strong>Adicionar elemento</strong> - Insere um novo jogo na coleção (com nome, ano de lançamento e nota)</li> 
    <li><strong>Remover elemento</strong> - Remove um jogo da coleção pelo nome</li> 
    <li><strong>Consultar elemento</strong> - Verifica se um jogo está na coleção pelo nome</li> 
    <li><strong>Listar elementos</strong> - Exibe todos os jogos na coleção em formato de tabela</li> 
    <li><strong>Esvaziar coleção</strong> - Remove todos os jogos da coleção, liberando a memória</li> 
    <li><strong>Destruir coleção</strong> - Destrói a coleção, desde que esteja vazia</li> <li><strong>Encerrar programa</strong> - Encerra a execução do programa</li> 
  </ul>

<h2>4. Restrições atendidas</h2>
<ul>
  <li>Implementação do TAD Collection Genérico</li>
  <li>Estrutura com três campos: char[30], int e float (expandido para char[100] para melhor usabilidade)</li>
  <li>PROIBIDO: Uso de printf, scanf ou qualquer I/O similar no arquivo gCofo.c</li>
  <li>Trabalho individual</li>
</ul>

<h2>5. Identificação</h2>
<strong>Disciplina:</strong> Estrutura de Dados I <br>
<strong>Aluno:</strong> Mika marques dos Santos Júnior <br>
<strong>Professor: </strong>Anselmo Paiva

