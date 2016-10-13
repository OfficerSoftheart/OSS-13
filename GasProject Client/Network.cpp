#include <SFML\Network.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <list>
#include "../GasProject Server/net_const.hpp"

using namespace std;
using namespace sf;


class network {
	string ip;
	int port;
	sf::TcpSocket socket;
public:
	network(string ip = "127.0.0.1", int port = start_port) {
		this->ip = ip;
		this->port = port;
	}
	result connect() {
		sf::Socket::Status status;
		int i = 0;
		do {
			status = socket.connect(ip, port + i, seconds(20));
		} while (status != sf::Socket::Done && i++ < 100);
		if (status != sf::Socket::Done)
			return connection_error;
		else return ok;
	}

	result send_command(comand_code cc, list<string> args) {
		sf::Packet pac;
		string s = string{ (char)cc };
		for (auto arg = args.begin(); arg != args.end(); arg++)
			s += " " + *arg;

		pac << s;
		socket.send(pac);
		int i = 0;
		//string s;
		while (i++ < 150) {
			sleep(seconds(0.01f));
			socket.receive(pac);
			if (pac.getDataSize() != 0) {
				pac >> s;
				return (result)s[0];
			}
		}
		return connection_error;
	}
};
/*
int main()
{
	network nt;
	int a;
	cout << nt.connect() << endl;
	cout << nt.send_command(login_code, {"login", "pass"}) << endl;
	cin >> a;

	return 0;
}

*/