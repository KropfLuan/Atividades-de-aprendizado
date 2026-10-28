p = float(input('Digite o preço do produto: R$'))
d = p * 0.05
np = p - d
print('O preço original do produto é R${:.2f} e com 5% de desconto é R${:.2f}'.format(p, np))