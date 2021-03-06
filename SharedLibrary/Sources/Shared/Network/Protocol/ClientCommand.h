#pragma once

#include <Shared/Network/ISerializable.h>
#include <Shared/Network/Archive.h>

#include "InputData.h"

namespace network {
namespace protocol {

struct ClientCommand : public uf::ISerializable {
	void Serialize(uf::Archive &ar) override {
		uf::ISerializable::Serialize(ar);
	}
};

DEFINE_SERIALIZABLE(AuthorizationClientCommand, ClientCommand)
	std::string login;
	std::string password;

	void Serialize(uf::Archive &ar) override {
		ClientCommand::Serialize(ar);
		ar & login;
		ar & password;
	}
DEFINE_SERIALIZABLE_END

DEFINE_SERIALIZABLE(RegistrationClientCommand, ClientCommand)
	std::string login;
	std::string password;

	void Serialize(uf::Archive &ar) override {
		ClientCommand::Serialize(ar);
		ar & login;
		ar & password;
	}
DEFINE_SERIALIZABLE_END

DEFINE_SERIALIZABLE(GamelistRequestClientCommand, ClientCommand) 
};

DEFINE_SERIALIZABLE(JoinGameClientCommand, ClientCommand)
	int id;

	void Serialize(uf::Archive &ar) override {
		ClientCommand::Serialize(ar);
		ar & id;
	}
DEFINE_SERIALIZABLE_END

DEFINE_SERIALIZABLE(DisconnectionClientCommand, ClientCommand)
DEFINE_SERIALIZABLE_END

DEFINE_SERIALIZABLE(MoveClientCommand, ClientCommand)
	uf::Direction direction;

	void Serialize(uf::Archive &ar) override {
		ClientCommand::Serialize(ar);
		ar & direction;
	}
DEFINE_SERIALIZABLE_END

DEFINE_SERIALIZABLE(MoveZClientCommand, ClientCommand)
	bool up;

	void Serialize(uf::Archive &ar) override {
		ClientCommand::Serialize(ar);
		ar & up;
	}
DEFINE_SERIALIZABLE_END

DEFINE_SERIALIZABLE(ClickObjectClientCommand, ClientCommand)
	int id;

	void Serialize(uf::Archive &ar) override {
		ClientCommand::Serialize(ar);
		ar & id;
	}
DEFINE_SERIALIZABLE_END

DEFINE_SERIALIZABLE(DropClientCommand, ClientCommand)
};

DEFINE_SERIALIZABLE(SendChatMessageClientCommand, ClientCommand)
	std::string message;

	void Serialize(uf::Archive &ar) override {
		ClientCommand::Serialize(ar);
		ar & message;
	}
DEFINE_SERIALIZABLE_END

DEFINE_SERIALIZABLE(BuildClientCommand, ClientCommand)
DEFINE_SERIALIZABLE_END

DEFINE_SERIALIZABLE(GhostClientCommand, ClientCommand)
DEFINE_SERIALIZABLE_END

DEFINE_SERIALIZABLE(UIInputClientCommand, ClientCommand)
	std::string handle;
	uptr<UIData> data;

	void Serialize(uf::Archive &ar) override {
		ClientCommand::Serialize(ar);
		ar & handle;
		if (ar.IsOutput())
			data.reset(dynamic_cast<UIData *>(ar.UnpackSerializable().release()));
		else
			ar << *data;
	}
DEFINE_SERIALIZABLE_END

DEFINE_SERIALIZABLE(UITriggerClientCommand, ClientCommand)
	std::string window;
	std::string trigger;

	void Serialize(uf::Archive &ar) override {
		ClientCommand::Serialize(ar);
		ar & window;
		ar & trigger;
	}
DEFINE_SERIALIZABLE_END

DEFINE_SERIALIZABLE(CallVerbClientCommand, ClientCommand)
	std::string verb;

	void Serialize(uf::Archive &ar) override {
		ClientCommand::Serialize(ar);
		ar & verb;
	}
DEFINE_SERIALIZABLE_END

} // namespace protocol
} // namespace network
