package lib

import (
	"bufio"
	"fmt"
	"log"
	"net"
	"os"
)

const port = "8080"

var _c []net.Conn

// RunHost takes an ip as argument
// and listens for connections on that ip
func RunHost(ip string) {
	ipAndPort := ip + ":" + port
	listener, listenErr := net.Listen("tcp", ipAndPort)
	if listenErr != nil {
		log.Fatal("Error: ", listenErr)
	}

	go hostListener()

	for{
		// fmt.Println("-----------hola folks ! -----------")
		
		fmt.Println("Listening on", ipAndPort)

		conn, acceptErr := listener.Accept()
		if acceptErr != nil {
			log.Fatal("Error: RunGuest", acceptErr)
		}
		_c=append(_c,conn)
		fmt.Print(conn)
		go go_handleHost(conn)

	}
}

func hostListener(){
	for{
		fmt.Print("\nSend message: ")
		replyReader := bufio.NewReader(os.Stdin)
		replyMessage, replyErr := replyReader.ReadString('\n')
		if replyErr != nil {
			log.Fatal("Error: hostlistener", replyErr)
		}
		for i:=0;i<len(_c);i++{

			fmt.Fprint(_c[i], replyMessage)
		}
	}
}

func go_handleHost(conn net.Conn){
	fmt.Println("New connection accepted")

	go handleHost_incoming(conn)
}

func handleHost_incoming(conn net.Conn) {
	for{
		reader := bufio.NewReader(conn)
		message, readErr := reader.ReadString('\n')
		if readErr != nil {
			log.Fatal("Error_incoming: ", readErr)
		}
		fmt.Println("Message received: ", message)
	}
}

// RunGuest takes destination ip
// as argument and connects to that ip
func RunGuest(ip string) {
	ipAndPort := ip + ":" + port
	conn, dialErr := net.Dial("tcp", ipAndPort)
	if dialErr != nil {
		log.Fatal("Error: ", dialErr)
	}

	go handleGuest_outgoing(conn)

	for{
		replyReader := bufio.NewReader(conn)
		replyMessage, replyErr := replyReader.ReadString('\n')
		if replyErr != nil {
			log.Fatal("Error: ", replyErr)
		}
		fmt.Println("Message received:", replyMessage)
	}

}


func handleGuest_outgoing(conn net.Conn){
	
	for{
		fmt.Print("Send message: ")
		reader := bufio.NewReader(os.Stdin)
		message, readErr := reader.ReadString('\n')
		if readErr != nil {
			log.Fatal("Error: ", readErr)
		}
		fmt.Fprint(conn, message)
	}
}
