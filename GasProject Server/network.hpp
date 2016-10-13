#pragma once
#include <SFML\Network.hpp>
#include <list>
#include <iostream>
#include <fstream>
#include <thread>
#include <atomic>
#include <map>
#include <sstream>
#include "net_const.hpp"

using namespace std;
using namespace sf;


class usersDB
{
	string adr;
	map <string, string> all;
public:
	usersDB(string adr);
	bool content(string &login, string &pass);
	bool add(string login, string pass);
};
class netclient {
public:
	bool logedin = false;
	sf::TcpSocket* socket;
	netclient(sf::TcpSocket* soc);
	result login(string &s);
	result signin(string &s);
	result parse(sf::Packet & pac);
};

class network {
public:

	static int number_listeners;
	static int port;
	//list<TcpSocket> threads;
	static list<thread> threads;
	static thread * main_net;
	static usersDB UBD;

	network(int port = ::PORT);
	static void listen();
	static void session(sf::TcpSocket *);
	~network();
};