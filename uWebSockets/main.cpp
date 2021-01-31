#include <iostream>
#include <uWebSockets/App.h>

int main(int argc, char * argv[]){
    std::cout << "Hello World" << std::endl;

	/* Overly simple hello world app */
	uWS::SSLApp({
	  .key_file_name = "../misc/key.pem",
	  .cert_file_name = "../misc/cert.pem",
	  .passphrase = "1234"
	}).get("/*", [](auto *res, auto /*req*/) {
	    res->end("Hello world!");
	}).listen(3000, [](auto *listen_socket) {
	    if (listen_socket) {
			std::cout << "Listening on port " << 3000 << std::endl;
	    }
	}).run();

	std::cout << "Failed to listen on port 3000" << std::endl;
}