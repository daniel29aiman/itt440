import threading
import random
import socket

# array of quotes
Q = ["If you see this you are a champion", "What? I already told you are champion", "What did you want!!!?", "Fine", "Look At Your Back"]

def handle_client(c_soc):
    quote = random.choice(Q)
    c_soc.send(quote.encode())
    c_soc.close()

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(("0.0.0.0", 8888))
server.listen(5)

while True:
    C, addr = server.accept()
    print(f"[*] Accepted connection from {addr[0]}:{addr[1]}")
    C_hnd = threading.Thread(target=handle_client, args=(C,))
    C_hnd.start()

