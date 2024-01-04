from pulp import *

prob = LpProblem("Projeto", LpMaximize)

# Variaveis
brinquedosDiferentes, nPacotes, maxBrinquedos = [int(entrada) for entrada in input().split()]
infoBrinquedos = []
for i in range(brinquedosDiferentes):
    lucro, maxBrinquedoI = [int(entrada) for entrada in input().split()]
    brinquedo = LpVariable(f"brinquedo{i + 1}", 0, maxBrinquedoI, LpInteger)
    infoBrinquedos.append([brinquedo, lucro, maxBrinquedoI,[]])
infoPacotes = []
for i in range(nPacotes):
    produto1, produto2, produto3, lucroPacote = [int(entrada) for entrada in input().split()]
    pacotes = LpVariable(f"pacote{i + 1}", 0, None, LpInteger)
    infoPacotes.append([pacotes, infoBrinquedos[produto1 - 1][0], infoBrinquedos[produto2 - 1][0], infoBrinquedos[produto3 - 1][0], lucroPacote])
    infoBrinquedos[produto1 - 1][3].append(pacotes)
    infoBrinquedos[produto2 - 1][3].append(pacotes)
    infoBrinquedos[produto3 - 1][3].append(pacotes)
    # Adicionar no info brinquedos os pacotes que contem o dito brinquedo

# Restricoes
for b in range(brinquedosDiferentes): # Maior numero que pode ser construido de brinquedos b
    # Iterar a partir do 3 indice de info brinquedos ate ao fim para ter os pacotes que ele possui
    prob += infoBrinquedos[b][0] + lpSum(infoBrinquedos[b][3][i] for i in range(len(infoBrinquedos[b][3])))<= infoBrinquedos[b][2]

# Restricao para o numero total de brinquedos
prob += lpSum(infoBrinquedos[b][0] for b in range(brinquedosDiferentes)) + lpSum(3 * infoPacotes[p][0] for p in range(nPacotes)) <= maxBrinquedos

# Funcao Objetivo
prob += lpSum(infoBrinquedos[b][0] * infoBrinquedos[b][1] for b in range(brinquedosDiferentes)) + \
    lpSum(infoPacotes[p][0] * infoPacotes[p][4] for p in range(nPacotes))

prob.solve(GLPK(msg=0))
#print("Status:", LpStatus[prob.status])
print(int(value(prob.objective)))
#for v in prob.variables(): print(v.name, "=", v.varValue)