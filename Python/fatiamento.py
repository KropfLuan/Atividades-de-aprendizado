frase = 'Curso em Video Python'
print(frase.lower().find('py'))
# len(frase) ver a quantidade de caracteres
# [inicio:fim:passo]
# [0:5] - do indice 0 ao 4
# [0:5:2] - do indice 0 ao 4 pulando de 2 em 2
# [0:5:3] - do indice 0 ao 4 pulando de 3 em 3
# frase.count('o') - conta quantas vezes a letra 'o' aparece na frase
# frase.find('o') - encontra a posição da primeira letra 'o' na frase
# frase.find('o', 5) - encontra a posição da letra 'o' na frase a partir do indice 5
# frase.find('Android') - retorna -1 porque a palavra 'Android' não existe na frase
# frase.rfind('o') - encontra a posição da última letra 'o' na frase
# 'Curso' in frase - retorna True porque a palavra 'Curso' existe na frase
# frase.replace('Python', 'Android') - substitui a palavra 'Python' por 'Android' na frase
# frase.upper() - transforma a frase em maiúscula
# frase.lower() - transforma a frase em minúscula
# frase.capitalize() - transforma a primeira letra da frase em maiúscula
# frase.title() - transforma a primeira letra de cada palavra da frase em maiúscula
# frase.strip() - remove os espaços em branco no início e no final da frase
# frase.rstrip() - remove os espaços em branco no final da frase
# frase.lstrip() - remove os espaços em branco no início da frase
# frase.split() - divide a frase em uma lista de palavras 
# '-'.join(frase) - junta as palavras da frase com o caractere '-' entre elas
#