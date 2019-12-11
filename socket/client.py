import socket                   # Import socket module
import sys

def main():
    s = socket.socket()             # Create a socket object
    # host = socket.gethostname()     # Get local machine name
    # port = 60000                    # Reserve a port for your service.
    port = int(sys.argv[1])
    host = sys.argv[2]
    filename = sys.argv[3]
    
    connected = False
    while not connected:
        try:
            s.connect((host,port))
            connected = True
        except Exception as e:
            pass #Do nothing, just try again
    
    # s.connect((host, port))
    s.send("Hello server!".encode())

    with open(filename, 'wb') as f:
        print ('file opened')
        while True:
            print('receiving data...')
            data = s.recv(1024)
            #print('data=%s', (data))
            if not data:
                break
            # write data to a file
            f.write(data)

    f.close()
    print('Successfully get the file')
    s.close()
    print('connection closed')

if __name__ == '__main__':
    main()
