#!/bin/bash

# Nome do seu programa compilado em C (ajuste se for diferente)
PROGRAMA="./main"

# Nome do arquivo de saída
SAIDA="tabela_tempos.txt"

echo "Iniciando os testes de desempenho..."

# Cria o cabeçalho da tabela no arquivo txt
echo "Tabela de Tempo de Execução (Crivo de Eratóstenes) - Marcador Tipo Char" > $SAIDA
echo "---------------------------------------------------" >> $SAIDA
echo -e "Entrada (N)\t|\tTempo User (segundos)" >> $SAIDA
echo "---------------------------------------------------" >> $SAIDA

# O laço itera para i = 3 até 10, conforme o roteiro
for i in {3..9}; do
    # Calcula 10 elevado a i
    N=$((10**i))
    
    echo "Executando para N = $N (10^$i)..."
    
    # O comando /usr/bin/time -f "%U" extrai apenas o tempo 'user'.
    # A saída padrão do seu programa em C é enviada para /dev/null para não sujar o terminal.
    # O descritor de erro (onde o time escreve) é redirecionado para ser salvo na variável.
    TEMPO_USER=$( { /usr/bin/time -f "%U" $PROGRAMA $N > /dev/null; } 2>&1 )
    
    # Verifica se o tempo foi capturado com sucesso (caso o programa trave ou falhe por falta de memória)
    if [ $? -eq 0 ]; then
        echo -e "10^$i\t\t|\t$TEMPO_USER" >> $SAIDA
    else
        echo -e "10^$i\t\t|\tFALHA/MEMÓRIA EXCEDIDA" >> $SAIDA
        echo "Aviso: A execução para 10^$i falhou (provavelmente devido a limites de memória)."
    fi
done

echo "Testes finalizados!"
echo "Resultados salvos em: $SAIDA"
echo "---------------------------------------------------"
cat $SAIDA