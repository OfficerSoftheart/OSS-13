#pragma once

#include <SFML/Graphics.hpp>

#include "UI.hpp"

class InfoLabel {
private:
    sf::RectangleShape rectangle;
    sf::Text text;
public:
    InfoLabel(const sf::Font &font);
    void Draw(sf::RenderWindow *window);
    void CountPosition(int width, int height);
    void SetText(string text);
};

class GameProcessUI : public UIModule {
    InfoLabel infoLabel;
    sptr<sfg::Window> chatWindow;

    void generateChatWindow();
public:
    GameProcessUI(UI *ui);


    virtual void Resize(int width, int height) final;
    virtual void Draw(sf::RenderWindow* renderWindow) final;
    InfoLabel * GetInfoLabel() {
        return &infoLabel;
    }
    virtual void Hide() final;
    virtual void Show() final;
};