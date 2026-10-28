n1 = int(input('Digite um número: '))
n2 = int(input('Digite outro número: '))
s = n1 + n2 # soma
m = n1 * n2 # multiplicação
d = n1 / n2 # divisão normal, ou seja, o resultado é um número real
di = n1 // n2 # divisão inteira, ou seja, o resultado é arredondado para baixo
e = n1 ** n2 # potência
r = n1 % n2 # resto da divisão
print(' A soma é {},\n a multiplicação é {},\n a divisão é {},\n a divisão int é {}\n e a potência é {} '.format(s,m, d, di, e))

