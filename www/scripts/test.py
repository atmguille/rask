import sys

print("Inicio")
print("Script Python\n")


print("Recibido por STDIN: ")
try:
    for line in sys.stdin:
        print(line)
except:
    ignorar = True
print("Fin de datos")


print("\n\nRecibido por ARGV:")
for line in sys.argv:
    print(line)
print("Fin de datos")


print("\n\nFin del script")