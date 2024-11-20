$(shell echo "#ifndef VERSION_H \n#define VERSION_H\n\n#define GIT_COMMIT_HASH $$(git log -n1 --format=format:\"%H\")\n#endif" > version.h.tmp; if diff -q version.h.tmp version.h >/dev/null 2>&1; then rm version.h.tmp; else mv version.h.tmp version.h; fi)
CXX= g++
SERVER_TARGET=socket_server
CLIENT_TARGET=socket_client

main : socket_server.cpp socket_client.cpp version.h
	$(CXX) socket_server.cpp -o $(SERVER_TARGET)
	$(CXX) socket_client.cpp -o $(CLIENT_TARGET)

clean:
	rm socket_client socket_server
