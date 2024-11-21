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


### Cross-Compilation:

    1. If the container and docker has been closed then please start the docker again using`docker run -t testdocker`

    2. Run`pwd` inside the container to check where we are by default we should be at `/opt/DockerEnv/linux_socket`

    3. Run the following commands to navigate to`aarch64_toolchain` and extract the toolchain

```
cd ..
cd aarch64_toolchain/

```

    4. Run`pwd` to make sure you are in `/opt/DockerEnv/aarch64_toolchain`

    5. Run`tar -xvf aarch64--glibc--stable-2024.05-1.tar.xZ`

    6. Now with tool chain extracted, lets go back to linux_socket directory by going back a directory`cd ..` and then entering a directory  `cd linux_socket/`

    7. Check to see is`version.h` file exits by perfoming `ls` and output should be as below `get_latestHash.sh  LICENSE  Makefile  README.md  socket_clientsocket_client.cpp  socket_server  socket_server.cpp  version.h`

    8. if version.h does not exist then from directory`linux_socket` run `./get_latestHash.sh`

    9. Now to cross-compile, we will provide the aarch64 linux g++ and sysroot as below from`linux_socket` directory as shown below

```
sh-5.0# /opt/DockerEnv/aarch64_toolchain/aarch64--glibc--stable-2024.05-1/bin/aarch64-linux-g++ --sysroot=/opt/DockerEnv/aarch64_toolchain/aarch64--glibc--stable-2024.05-1/aarch64-buildroot-linux-gnu/sysroot socket_server.cpp -o socket_server
sh-5.0# /opt/DockerEnv/aarch64_toolchain/aarch64--glibc--stable-2024.05-1/bin/aarch64-linux-g++ --sysroot=/opt/DockerEnv/aarch64_toolchain/aarch64--glibc--stable-2024.05-1/aarch64-buildroot-linux-gnu/sysroot socket_client.cpp -o socket_client
sh-5.0# ls
aarch64-linux-g++  LICENSE   README.md    socket_client.cpp  socket_server.cpp
get_latestHash.sh  Makefile  socket_client  socket_server      version.h
```
