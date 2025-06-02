# Minitalk – 42 Project
**About:**<br/>
minitalk is a small program to send messages between two processes using Unix signals in C.<br/>
The goal is to learn how to use kill(), signal(), and how to send data bit by bit between a client and a server process.<br/>
<br/>
**Compile:**

    make

**Usage:**<br/>
First, run the server:

    ./server

It will print its PID (process ID).<br/>
Then run the client with the server’s PID and your message:

    ./client <server_pid> "your message here"

**Example:**

    ./client 12345 "Hello, World!"

**What I Learned:**<br/>
Using Unix signals (SIGUSR1, SIGUSR2) for communication<br/>
Converting characters to bits and sending them one by one<br/>
Process synchronization with signals<br/>
Handling edge cases in inter-process communication<br/>
