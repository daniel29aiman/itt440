import socket

ClientSocket = socket.socket()

host = '192.168.0.8'
port = 4308

print('Waiting for a connection')

try:
        ClientSocket.connect((host, port))
except socket.error as e:
        print(str(e))

Response = ClientSocket.recv(1024)
print(Response.decode('utf-8'))

while True:
        fahrenheit = int(input("Enter the temperature in Fahrenheit: "))
        ClientSocket.sendall(str.encode(str(fahrenheit)))

        Response = ClientSocket.recv(1024)
        print(Response.decode('utf-8'))

ClientSocket.close()
