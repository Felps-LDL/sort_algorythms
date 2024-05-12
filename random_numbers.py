import numpy as np

with open("200.txt", "w") as arquivo:
  for i in range(200): # gera 200 números
    arquivo.write(str(np.random.randint(0, 30000)) + '\n') # gera números na faixa de 0 a 30000
