import socket

c_soc = socket.socket()

host = '192.168.126.130'
port = 4308

print('WAITING FOR A CONNECTION TO BE RECEIVED...........')

try:
        c_soc.connect((host, port))
except socket.error as e:
        print(str(e))

Resp = c_soc.recv(1024)
print(Resp.decode('utf-8'))

while True:
        frht = int(input("ENTER TEMPERATURE IN FARENHEIT: "))
        c_soc.sendall(str.encode(str(frht)))

        Resp = c_soc.recv(1024)
        print(Resp.decode('utf-8'))

c_soc.close()
