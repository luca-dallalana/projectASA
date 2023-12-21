from pulp import *

prob = LpProblem("Projeto", LpMaximize)

# Variaveis
brinquedosDiferentes, nPacotes, maxBrinquedos = [int(entrada) for entrada in input().split()]
infoBrinquedos = []
for i in range(brinquedosDiferentes):
    lucro, maxBrinquedoI = [int(entrada) for entrada in input().split()]
    brinquedo = LpVariable(f"brinquedo{i}", 0, None, LpInteger)
    infoBrinquedos.append([brinquedo, lucro, maxBrinquedoI])
infoPacotes = []
for i in range(nPacotes):
    produto1, produto2, produto3, lucroPacote = [int(entrada) for entrada in input().split()]
    pacotes = LpVariable(f"pacote{i}", 0, None, LpInteger)
    infoPacotes.append([pacotes, infoBrinquedos[produto1 - 1], infoBrinquedos[produto2 - 1], infoBrinquedos[produto3 - 1], lucroPacote])

# Funcao Objetivo
prob += lpSum(infoBrinquedos[b][0] * infoBrinquedos[b][1] for b in range(brinquedosDiferentes)) + \
    lpSum(infoPacotes[p][0] * infoPacotes[p][4] for p in range(nPacotes))

# Restricoes
for b in range(brinquedosDiferentes): # Maior numero que pode ser construido de brinquedos b
    prob += lpSum(infoBrinquedos[b][0]) <= infoBrinquedos[b][2]

for p in range(nPacotes): # Limitar a producao de pacotes para o menor numero de brinquedos possiveis entre os 3 do pacote
    minimo = min(min(infoPacotes[p][1], infoPacotes[p][2]), infoPacotes[i][3])
    prob += lpSum(infoPacotes[p][0]) <= minimo

prob += lpSum(infoBrinquedos[b][0] for b in range(brinquedosDiferentes)) + lpSum(3 * infoPacotes[p][0] for p in range(nPacotes)) <= maxBrinquedos

prob.solve(GLPK(msg=0))
print("Status:", LpStatus[prob.status])
print("Valor da funcao objectivo:", value(prob.objective))
for v in prob.variables(): print(v.name, "=", v.varValue)