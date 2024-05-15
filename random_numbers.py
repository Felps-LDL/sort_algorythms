import numpy as np

with open("150000.txt", "w") as arquivo:
  for i in range(150000): # gera 200 números
    arquivo.write(str(np.random.randint(0, 30000)) + '\n') # gera números na faixa de 0 a 30000
