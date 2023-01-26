import socket

c = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
c.connect(("192.168.126.128", 8888))

resp = c.recv(4096).decode()
print(resp)

c.close()

