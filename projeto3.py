import pulp

brinquedosDiferentes, pacotes, maxBrinquedos = [int(entrada) for entrada in input().split()]
infoBrinquedos = []
for i in range(brinquedosDiferentes):
    lucro, maxBrinquedoI = [int(entrada) for entrada in input().split()]
    infoBrinquedos.append([lucro, maxBrinquedoI])
infoPacotes = []
for i in range(pacotes):
    produto1, produto2, produto3, lucroPacote = [int(entrada) for entrada in input().split()]
    infoPacotes.append([produto1, produto2, produto3, lucroPacote])
print(infoBrinquedos)
print(infoPacotes)