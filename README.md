## Transforma algarismos romanos em algarismos arábicos
### Dependências:
- make
- g++
- cpplint
- cppcheck
- valgrind

### Como rodar:
- No terminal digite "make run"

### Extras:
- Para limpar os arquivos objetos e main, digite "make clean" no terminal. 
- Para fazer verificações do cpplint, cppcheck e valgrind digite "make check" no terminal.

## Documentação dos testes:
- O Test_Case (linha 6) testa se a função "romanToInt" aceita uma string maior que 30 caracteres, se ocorrer deve retornar -1.
- O Test_Case (linha 9) testa se a função "romanToInt" retorna um valor maior que 3000, se ocorrer deve retornar -1.
- O Test_Case (linha 14) testa se a computação dos valores está correta.
- O Test_Case (linha 22) testa se a string possui caracteres inválidos e retorna -1 em caso verdadeiro.
- O Test_Case (linha 29) testa se a função "value" retorna um inteiro na conversão dos algarismos
  - Por exemplo: I = 1, V = 5, X = 10, L = 50, C = 100, D = 500 e M = 1000.
- O Test_Case (linha 39) testa se a função "romanToInt" retorna -1 em caso de 4 ou mais repetições seguidas dos caracteres I, X, C e M.
- O Test_Case (linha 46) testa se a função "romanToInt" retorna -1 em caso de repetições seguidas dos caracteres V, L e D.
- O Test_Case (linha 52) testa se a função retorna -1 em caso do caractere I vir antes dos caracteres L, C, D e M, e o valor correto para o caso dos caracteres V e X.
- O Test_Case (linha 61) testa se na string digitada, tem o caractere X antes do D e M e retorna -1. Para os demais caracteres, é retornado o valor correspondente correto.
