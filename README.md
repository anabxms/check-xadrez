## Xadrez em C

O programa checa se o rei do tabuleiro está em cheque, ou não. 
A entrada é formatada da seguinte forma:

```
t c b k q b c t
p p p p p p p p
- - - - - - - -
- - - - - - - -
- - - - - - - -
- - - - - - - -
P P P P P P P P
T C B Q K B C T
```

Onde os hífens representam as casas vazias e as letras representam as peças da seguinte forma (as maiusculas representam as peças do jogador e as minusculas do adversário):

- **P | p** = Peão
- **T | t** = Torre
- **C | c** = Cavalo
- **B | b** = Bispo
- **K | k** = Rei
- **Q | q** = Rainha

## Como executar o programa?

Para executá-lo, basta clonar o diretório e, no seu terminal, digitar:
```
gcc check.c -o check-chess
```
Após o arquivo terminar de ser compilado, você irá digitar:
```
./check-chess
```
O programa irá aguardar seu input e, ao ser inserido corretamente, ele irá retornar XEQUE ou NÃO XEQUE.

*⚠️ É importante não esquecer de checar se o caminho para o diretório está correto ⚠️*


