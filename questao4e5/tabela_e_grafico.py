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
    tamanhos = [10_000, 20_000, 30_000, 40_000, 50_000, 60_000, 70_000, 80_000, 90_000, 100_000]
    tempos_bubble = [0.06600000, 0.25500000, 0.56099999, 1.01300001, 1.56599998, 2.25900006, 2.25900006, 3.07200003, 4.01100016, 5.07600021]
    tempos_inserction = [0.00000000, 0.00000000, 0.00000000, 0.00000000, 0.00000000,
    0.00000000, 0.00000000, 0.00100000, 0.00000000]
    tempos_selection = [ 0.05800000, 0.23100001, 0.51300001, 0.91799998, 1.44299996,
    2.07800007, 2.82800007, 3.68700004, 4.73199987]
    tempos_quick = [0.00000000, 0.00100000, 0.00100000, 0.00200000, 0.00200000,
    0.00200000, 0.00200000, 0.00300000, 0.00300000]
    tempos_merge = [0.00000000, 0.00100000, 0.00200000, 0.00200000, 0.00200000,
    0.00400000, 0.00400000, 0.00400000, 0.00600000]

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
