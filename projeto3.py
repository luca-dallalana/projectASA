from pulp import *

prob = LpProblem("Projeto", LpMaximize)

# Variaveis
brinquedosDiferentes, pacotes, maxBrinquedos = [int(entrada) for entrada in input().split()]
infoBrinquedos = []
for i in range(brinquedosDiferentes):
    lucro, maxBrinquedoI = [int(entrada) for entrada in input().split()]
    infoBrinquedos.append(["brinquedo{i}", lucro, maxBrinquedoI])
    variavel = LpVariable("brinquedo{i}", 0)
infoPacotes = []
for i in range(pacotes):
    produto1, produto2, produto3, lucroPacote = [int(entrada) for entrada in input().split()]
    infoPacotes.append(["pacote{i}",produto1, produto2, produto3, lucroPacote])
    variavel = LpVariable("pacote{i}", 0)

# Funcao Objetivo
prob += lpSum(infoBrinquedos[b][0] * infoBrinquedos[b][1] for b in range(brinquedosDiferentes)) + \
    lpSum(infoPacotes[p][0] * infoPacotes[p][4] for p in range(pacotes))

# Restricoes
for b in range(brinquedosDiferentes): # Maior numero que pode ser construido de brinquedos b
    prob += lpSum(infoBrinquedos[b][0]) <= infoBrinquedos[b][2]

for p in range(pacotes): # Limitar a producao de pacotes para o menor numero de brinquedos possiveis entre os 3 do pacote
    min = min(min(infoPacotes[p][1], infoPacotes[p][2]), infoPacotes[i][3])
    prob += lpSum(infoPacotes[p][0]) <= min