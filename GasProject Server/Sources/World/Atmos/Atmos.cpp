#include "Atmos.hpp"

#include "Server.hpp"
#include "World/World.hpp"

Atmos::Atmos(Map* map) : map(map) {
    
}

void Atmos::Update(sf::Time timeElapsed) {
    for (auto iter = locales.begin(); iter != locales.end(); ) {
        Locale *locale = iter->get();
        if (locale->IsEmpty()) {
            iter = locales.erase(iter);
        } else {
            locale->Update(timeElapsed);
            iter++;
        }
    }
}

void Atmos::CreateLocale(Tile *tile) {
    locales.push_back(std::make_unique<Locale>(this, tile));
}

void Atmos::RemoveLocale(Locale *locale) {
    if (!locale) {
        Server::log << "Error: try to remove nullptr locale from Atmos (Atmos::RemoveLocale)" << std::endl;
        return;
    }
    for (auto iter = locales.begin(); iter != locales.end(); iter++) {
        if (iter->get() == locale) {
            for (auto tile : locale->tiles) {
                tile->CheckLocale();
            }
            locale->Clear();
            locales.erase(iter);
            return;
        }
    }
    Server::log << "Warning: try to remove locale from Atmos which doesn't exist (Atmos::RemoveLocale)" << std::endl;
}