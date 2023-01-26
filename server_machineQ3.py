import threading
import random
import socket

# array of quotes
quotes = ["Fauzul Nub LoL", "Daniel Nub Badminton", "Razin Nub Beyblade", "Adam Nub Overwatch", "Afnan Beriman"]

def handle_client(client_socket):
    quote = random.choice(quotes)
    client_socket.send(quote.encode())
    client_socket.close()

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(("0.0.0.0", 8888))
server.listen(5)

while True:
    client, addr = server.accept()
    print(f"[*] Accepted connection from {addr[0]}:{addr[1]}")
    client_handler = threading.Thread(target=handle_client, args=(client,))
    client_handler.start()

