class TextBoard{
    public:
        sf::Font* font;
        sf::Text* text;
        char text_s[201];

        TextBoard();
        TextBoard(int op);
        ~TextBoard();
};
