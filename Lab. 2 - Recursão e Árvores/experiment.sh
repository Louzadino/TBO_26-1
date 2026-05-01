#!/bin/bash

# Define o nome do seu executável em C
# Mude "./main" para o nome correto se o seu for diferente
EXECUTAVEL="./main"
N=1000000
EXECUCOES=10

# Arquivo temporário para guardar as alturas de cada execução
ARQUIVO_ALTURAS="alturas_temp.txt"
> $ARQUIVO_ALTURAS # Limpa o arquivo caso já exista

echo "Iniciando $EXECUCOES execuções da BST com N = $N..."
echo "----------------------------------------------------"

# Verifica se o executável realmente existe na pasta
if [ ! -f "$EXECUTAVEL" ]; then
    echo "Erro: Executável '$EXECUTAVEL' não encontrado."
    echo "Compile seu código C primeiro antes de rodar o script."
    exit 1
fi

# Loop para rodar o programa 10 vezes
for i in $(seq 1 $EXECUCOES); do
    # Executa o programa passando N e captura a saída (altura)
    ALTURA=$($EXECUTAVEL $N)
    
    echo "Execução $i: Altura = $ALTURA"
    
    # Salva a altura no arquivo temporário
    echo $ALTURA >> $ARQUIVO_ALTURAS
done

echo "----------------------------------------------------"

# Usa o 'awk' para ler o arquivo temporário e calcular média e desvio padrão
awk '{
    soma += $1;
    valores[NR] = $1;
}
END {
    # NR é o número total de registros (linhas lidas)
    media = soma / NR;
    
    soma_quadrados = 0;
    for (i = 1; i <= NR; i++) {
        soma_quadrados += (valores[i] - media)^2;
    }
    
    # Cálculo do desvio padrão populacional
    desvio_padrao = sqrt(soma_quadrados / NR);

    printf "Média das alturas: %.2f\n", media;
    printf "Desvio Padrão: %.2f\n", desvio_padrao;
}' $ARQUIVO_ALTURAS

# Remove o arquivo temporário após os cálculos
rm -f $ARQUIVO_ALTURAS