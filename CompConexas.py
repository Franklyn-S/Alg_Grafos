#_*_ coding: utf8 _*_
class No(object):
	def __init__(self, id):
		self.id = int(id)
		self.vizinhos = []
		self.atingido = False

	def addVizinho(self, no):
		self.vizinhos.append(no)
		no.vizinhos.append(self)

	def __str__(self):
		return str(self.id)

def BFS(No):
	componente = []
	fila = []
	fila.append(No)
	while not fila:
		u = fila.pop()
		u.atingido = True
		componente.append(u.id)
		for v in u.vizinhos:
			if not v.atingido:
				fila.append(v)
				v.atingido = True
	return componente.sort(key = id)



#input("")
#input("")
num_vertices = int(input().split("=")[1])
#input("")

grafo = []
for i in range(1,num_vertices+1):
	no = No(i)
	grafo.append(no)

aux = input()
while aux != "":
	v1, v2 = aux.split(" ")
	v1 = No(int(v1))
	v2 = No(int(v2))

	grafo[v1.id].addVizinho(v2)
	aux = input("")

for n in grafo:
	if not n.atingido:
		print(BFS(n))
		print("\n")

