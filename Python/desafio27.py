nome = input('Digite seu nome completo: ')
print(nome.strip().title())
print('Seu primeiro nome é {}'.format(nome.split()[0]))
print('Seu último nome é {}'.format(nome.split()[-1])) 
# o indice -1 é o último elemento da lista, o indice -2 é o penúltimo elemento da lista, e assim por diante.