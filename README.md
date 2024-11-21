# linux_socket Repo


### Brief:

This is a simple UNIX client and server socket implementation. That currently handles two commands.

    1. VERSION --> This responds with latest git hash

    2. quit         --> will close the socket server

    3. Server should respond with rejected for anything else


##### Notes:

This is a very rough version of client and server socket implementation. There is not a lot of error checks

The error check that I have right now is only on the amount of arguments that we are passing.



##### Future implementation:

    1. Man page implementation for this

    2. Error checks around the arguments passed

    3. Attempt to clean the code


### Usage:

The docker file should be provided to you in an email or reach out to shravansingh64@gmail.com


1. Create a Directory for you docker on your system
2. Build docker with command `docker build -t testdocker -f ./Dockerfile .`
3. Run docker `docker run -t testdocker`
4. Inside your container run `make all`
5. Start the server `./socket_server /tmp/socket &`
6. run the client with socket path and command for example `./socket_client /tmp/socket VERSION`
7. To stop the server `./socket_client /tmp/socket quit`
8. The server should respond with rejected for everything else
