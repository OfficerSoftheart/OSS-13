#pragma once

#include <string>

#include "Shared/Types.hpp"
#include "Shared/Log.hpp"

using std::string;

class Window;
class UI;

class Player {
private:
    string pkey;
};

class ClientController {
private:
    /* Unique_ptr will delete it contents in the destruction. So we don't need destructor.
    But unique_ptr can be just one for it content. So we need to use links. See Get-functions. */
    uptr<Player> player;
    uptr<Window> window;
    static ClientController * instance;

public:
    /* Work of Client processing in this constructor.
    Such system allow as awake just 1 function of Client from main. */
    ClientController();
    void Run();
    
    ClientController(const ClientController &) = delete;
    ClientController &operator=(const ClientController &) = delete;
    ~ClientController() = default;

	Player *GetClient();
	Window *GetWindow();
	UI *GetUI();
	static ClientController *const Get();

    static uf::Log log;
};

using CC = ClientController;