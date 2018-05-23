#_*_ coding: utf8 _*_
class No(object):
	def __init__(self, id):
		self.id = int(id)
		self.vizinhos = []
		self.atingido = False

	def addVizinho(self, no):
		if no not in self.vizinhos:
			self.vizinhos.append(no)
			no.vizinhos.append(self)

	def __str__(self):
		return str(self.id)

def BFS(*grafo,no):
	componente = []
	fila = []
	fila.append(no)
	while fila:
		u = fila.pop(0)
		componente.append(u)
		for v in u.vizinhos:
			if not v.atingido:
				fila.append(v)
				v.atingido = True
		u.atingido = True
	return sorted(componente, key=id)

dl = input("")
formatt = input("")
num_vertices = int(input().split("=")[1])
data = input("")	



grafo = []
for i in range(1,num_vertices+1):
	no = No(i)
	grafo.append(no)

aux = input()
while aux != "":
	v1, v2 = aux.split(" ")
	v1 = int(v1)
	v2 = int(v2)

	grafo[v1 - 1].addVizinho(grafo[v2 - 1])
	try:
		aux = input("")
	except Exception as e:
		break
	
result = ""
for n in grafo:
	if not n.atingido:
		for j in BFS(*grafo,no=n):
			result += str(j)+' '
		result+="\n"
print(result)
