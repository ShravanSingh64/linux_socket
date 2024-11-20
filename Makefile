CXX= g++
SERVER_TARGET=socket_server
CLIENT_TARGET=socket_client

main : socket_server.cpp socket_client.cpp version.h
	$(CXX) socket_server.cpp -o $(SERVER_TARGET)
	$(CXX) socket_client.cpp -o $(CLIENT_TARGET)

clean:
	rm socket_client socket_server
