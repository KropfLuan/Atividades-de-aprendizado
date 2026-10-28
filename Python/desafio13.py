s = float(input('Digite o salário do funcionário: R$'))
a = s * 0.15
ns = s + a
print('O salário original do funcionário é R${:.2f} e com 15% de aumento é R${:.2f}'.format(s, ns))