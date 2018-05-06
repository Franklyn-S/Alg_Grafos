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

def BFS(*grafo, No):
	componente = []
	fila = []
	fila.append(No)
	while not fila:
		u.atingido = True
		u = fila.pop()
		componente.append(u)
		for v in u.vizinhos:
			if not v.atingido:
				fila.append(v)
				v.atingido = True
	return componente.sort(key = id)

def main():

	#input("")
	#input("")
	s = input("")
	#input("")

	n1, n = s.split("=")
	n = int(n)

	grafo = []
	for i in range(1,n+1):
		grafo.append(No(i))

	aux = input("")
	while aux != "":
		v1, v2 = aux.split(" ")
		v1 = int(v1)
		v2 = int(v2)
		grafo[v1].vizinhos.addVizinho(v2)
		aux = input("")

	for No in grafo:
		if not No.atingido:
			s = ""
			for i in BFS(*grafo, NO):
				print(i, end = " ")
			print("\n")


if __name__ == "__main__":
	main()

