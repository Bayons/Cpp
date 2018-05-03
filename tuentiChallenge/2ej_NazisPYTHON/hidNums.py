#Programa en python, compilar como python hidNums.py
#Este ejercicio se ha hecho en este lenguaje por soportar numeros de
# gran tamano

#La funcion hidNum calcula la diferencia entre el numero mas grande y
# el mas pequeno en su propia base y lo convierte a decimal
def hidNum (length):
	a = []
	b = []
	c = []
	res = 0	

	for i in range(length):
		a.append((length - 1) - i)
		b.append(i)
		c.append(0)
	b[0] = 1
	b[1] = 0

	for i in range(length-1, -1, -1):
		c[i] = a[i] - b[i]
		if c[i] < 0:
			c[i] += length
			b[i-1] += 1

	for i in range(length-1, -1, -1):
		res += c[i]*length**((length-1)-i)

	print res

#INICIO DEL PROGRAMA
#Primero tomamos el numero de entradas
n = int(raw_input())

#Ahora procesamos las entradas
word = ""
for i in range(n):
	word = raw_input()
	print "Case #"+((str)(i+1))+":",
	hidNum(len(word))
