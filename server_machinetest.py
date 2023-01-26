import socket
from _thread import *

Svr_Soc = socket.socket()

host = ''
port = 4308
ThreadCount = 0

try:
        Svr_Soc.bind((host, port))
except socket.error as e:
        print(str(e))

print('WAITING FOR A CONNECTION TO BE RECEIVED........')
Svr_Soc.listen(5)

def threaded_client(connection):
        connection.send(str.encode('.....WELCOME TO SERVER.....'))
        while True:
                D = connection.recv(2048)
                if not D:
                        break
                frht = int(D.decode('utf-8'))
                cels = (frht - 32) * (5/9)
                reply = 'Server Says: ' + str(cels) + 'C'
                connection.sendall(str.encode(reply))
        connection.close()

while True:
        C, addr = Svr_Soc.accept()
        print('Connected to: ' + addr[0] + ':' + str(addr[1]))

        start_new_thread(threaded_client, (C, ))
        ThreadCount += 1
        print('Thread Number: ' + str(ThreadCount))

ServerSocket.close()
