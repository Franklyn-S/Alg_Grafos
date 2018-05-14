#_*_ coding: utf8 _*_
# class No(object):
# 	def __init__(self, id):
# 		self.id = int(id)
# 		self.vizinhos = []
# 		self.atingido = False

# 	def addVizinho(self, no):
# 		self.vizinhos.append(no)
# 		no.vizinhos.append(self)

# 	def __str__(self):
# 		return str(self.id)

# def BFS(*grafo, No):
# 	componente = []
# 	fila = []
# 	fila.append(No)
# 	while not fila:
# 		u = fila.pop()
# 		u.atingido = True
# 		componente.append(u)
# 		for v in u.vizinhos:
# 			if not v.atingido:
# 				fila.append(v)
# 				v.atingido = True
# 	return componente.sort(key = id)

#def main():

dl = input("")
format = input("")

num_vertice = int(input().split("=")[1])

data = input()

aux = input().split()

grafo = []
atingidos = []
LA = []
for x in xrange(1,num_vertice+1):
	atingidos.append(False)
	LA.append([])

int i = 0
while aux != []:
	v1 = int(aux[0])
	v2 = int(aux[1])
	aresta = [v1, v2]
	grafo[i].append(aresta)
	i++
	try:
		print(aux)
		aux = input().split()
	except EOFError:
		break

for n in grafo:
	if not n.atingido:
		s = ""
		for i in BFS(*grafo, n):
			print(i, end = " ")
		print("\n")


# if __name__ == "__main__":
# main()

