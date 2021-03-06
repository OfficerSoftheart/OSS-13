#pragma once

#include "CustomWidget.h"

#include <functional>
#include <string>
#include <vector>

class Entry : public CustomWidget {
public:
    explicit Entry(const uf::vec2i &size = {});

    void Update(sf::Time timeElapsed) override final;
    bool HandleEvent(sf::Event event) override final;

    void Clear();
    void HideSymbols(wchar_t hider = '*');
    void ShowSymbols();
    void SetOnEnterFunc(std::function<void()>);

    std::string GetText();
    bool Empty() const;

protected:
    void draw() const override final;

private:
    sf::Text text;
    sf::RectangleShape cursor;

    unsigned showPos;
    int cursorPos;
    sf::Time cursorTime;

    std::vector<float> getLetterSizes(wchar_t);
    void moveCursorRight(wchar_t);
    void moveCursorLeft(wchar_t);

    std::wstring entryString;

    bool hidingSymbols;
    
    wchar_t hidingSymbol;
    std::wstring hidingString;

    void setSymbol(wchar_t c);
    void deleteSymbol();

    void moveLeft();
    void moveRight();

    std::function<void()> onEnterFunc;
};