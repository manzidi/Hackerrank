def fibonacci_modified(a, b, n):
	for i in range(2, n):
		results = a + b * b
		a = b
		b = results
	return results

x = raw_input()
x = x.split()
a, b, c = int(x[0]), int(x[1]), int(x[2])

print fibonacci_modified(a, b, c)

