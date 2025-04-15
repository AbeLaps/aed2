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

    # Exemplo de dados
    tamanhos = [100_000, 200_000, 300_000, 400_000, 500_000, 600_000, 700_000, 800_000, 900_000, 1_000_000]
    tempos_seq = [1.2, 1.5, 1.8, 2.0, 2.2, 2.5, 2.7, 2.9, 3.0, 3.2]
    tempos_bin = [0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1, 1.2, 1.3, 1.4]

    # Criando o gráfico
    plt.figure(figsize=(10, 6))

    plt.plot(tamanhos, tempos_seq, marker='o', label='Busca Sequencial', color='blue')
    plt.plot(tamanhos, tempos_bin, marker='s', label='Busca Binária', color='green')

    # Configurando o gráfico
    plt.xlabel('Tamanho do Vetor')
    plt.ylabel('Tempo de Execução (ms)')
    plt.title('Tempo Médio de Execução vs Tamanho do Vetor')
    plt.legend()
    plt.grid(True)
    plt.tight_layout()

    # Exibindo o gráfico
    plt.show()
else:
    print("Erro: As listas de 'Busca Sequencial' e 'Busca Binária' não têm o mesmo número de elementos!")
