# Importando bibliotecas necessárias
import pandas as pd
import matplotlib.pyplot as plt

# ------------------------------------------
# Questão 4 - Tabelas com tempos, médias e desvios padrão
# ------------------------------------------

# Dados de exemplo      (trocar pelos reais)
dados_busca = {
    'Execução': list(range(1, 31)),  # 30 execuções
    'Busca Sequencial': [1.23, 2.34, 1.56, 2.12, 1.95, 2.56, 3.12, 2.10, 1.98, 2.44, 
                         2.11, 2.34, 2.00, 1.99, 2.22, 1.88, 2.02, 2.15, 2.09, 1.98, 
                         2.21, 2.44, 2.32, 2.11, 2.15, 2.30, 2.25, 1.95, 2.01, 2.10],
    'Busca Binária': [0.50, 0.75, 0.55, 0.60, 0.70, 0.65, 0.80, 0.85, 0.75, 0.90, 
                      0.65, 0.60, 0.80, 0.75, 0.85, 0.65, 0.90, 0.80, 0.70, 0.60, 
                      0.55, 0.50, 0.70, 0.60, 0.65, 0.80, 0.75, 0.90, 0.55, 0.60]
}

# Verificando se todas as listas têm o mesmo número de elementos
if len(dados_busca['Execução']) == len(dados_busca['Busca Sequencial']) == len(dados_busca['Busca Binária']) == 30:
    # Criando um DataFrame com os dados
    df_busca = pd.DataFrame(dados_busca)

    # Calculando a média e o desvio padrão para cada tipo de busca
    media_seq = df_busca['Busca Sequencial'].mean()
    desvio_seq = df_busca['Busca Sequencial'].std()

    media_bin = df_busca['Busca Binária'].mean()
    desvio_bin = df_busca['Busca Binária'].std()

    # Exibindo a tabela e as estatísticas
    print("Tabela de Execuções e Tempos de Busca:")
    print(df_busca)

    print(f"\nMédia Busca Sequencial: {media_seq:.5f} ms, Desvio Padrão: {desvio_seq:.5f} ms")
    print(f"Média Busca Binária: {media_bin:.5f} ms, Desvio Padrão: {desvio_bin:.5f} ms")

    # ------------------------------------------
    # Questão 5 - Gráficos de Tempo Médio de Execução vs Tamanho do Vetor
    # ------------------------------------------

# Dados de exemplo
tamanhos = [10_000, 20_000, 30_000, 40_000, 50_000, 60_000, 70_000, 80_000, 90_000, 100_000]

# Dados de tempos para cada algoritmo
tempos_bubble = [0.06100000, 0.25299999, 0.55900002, 0.99199998, 1.55799997, 2.23200011, 3.04600000, 4.03700018, 5.12300014, 6.44299984]
tempos_insertion = [0.00000000, 0.00000000, 0.00000000, 0.00000000, 0.00000000, 0.00000000, 0.00000000, 0.00000000, 0.00000000, 0.00000000]
tempos_selection = [0.05700000, 0.21699999, 0.49200001, 0.87300003, 1.36500001, 1.99800003, 2.71099997, 3.57900000, 4.54899979, 5.62699986]
tempos_quick = [0.00000000, 0.00000000, 0.00000000, 0.00000000, 0.00000000, 0.00000000, 0.00000000, 0.00000000, 0.00000000, 0.00000000]
tempos_merge = [0.00100000, 0.00100000, 0.00100000, 0.00200000, 0.00300000, 0.00300000, 0.00400000, 0.00500000, 0.00500000, 0.00500000]

# Criando o gráfico
plt.figure(figsize=(10, 6))

# Plotando os gráficos para cada tipo de ordenação
plt.plot(tamanhos, tempos_bubble, marker='o', label='Bubble Sort', color='blue')
plt.plot(tamanhos, tempos_insertion, marker='s', label='Insertion Sort', color='green')
plt.plot(tamanhos, tempos_selection, marker='^', label='Selection Sort', color='red')
plt.plot(tamanhos, tempos_quick, marker='d', label='Quick Sort', color='yellow')
plt.plot(tamanhos, tempos_merge, marker='x', label='Merge Sort', color='pink')

# Configurando o gráfico
plt.xlabel('Tamanho do Vetor')
plt.ylabel('Tempo de Execução (ms)')
plt.title('Tempo Médio de Execução vs Tamanho do Vetor')
plt.legend()
plt.grid(True)
plt.tight_layout()

# Exibindo o gráfico
plt.show()