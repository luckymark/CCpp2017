#ifndef Menu_h
#define Menu_h

struct score {
    std::string name;
    int num;
};

bool cmp(score score1,score score2) {
    return score1.num>score2.num;
}

class Menu {
    
    
private:
    sf::Clock cursor_clock;
    bool cursor_active=0;
    float cursor_position=255;
    int position;
    sf::CircleShape page1,page2,page3;
    
public:
    sf::Texture title_texture,subtitle_texture,start_texture,rank_texture,help_texture,story_texture,contrast_texture,contrast0_texture,back_menu_texture,back_menu_dead_texture,back_menu_rank_texture,back_game_texture,story_texture1,story_texture2,story_texture3,helping_texture;
    sf::Sprite title,subtitle,start,rank,help,story,contrast,contrast0,back_menu,back_menu_rank,back_menu_dead,back_game,story_sprite1,story_sprite2,story_sprite3,helping;
    sf::Text rank_name[10],rank_num[10],yourname,typeiname;
    sf::Font font;
    std::string typeiname_string="";
    std::string typein;
    sf::RectangleShape cursor,nameblank,namend;
    int state=0,final_score=0;
    score scores[10];
    bool updated=1;
    //0:main menu; 1:game; 2:pause; 3:dead; 4:rank;
    
    Menu() {
        
        //main menu
        title_texture.loadFromFile(resourcePath()+"using/title.png");
        title.setTexture(title_texture);
        title.setPosition(-30,50);
        subtitle_texture.loadFromFile(resourcePath()+"using/subtitle.png");
        subtitle.setTexture(subtitle_texture);
        subtitle.setPosition(400,180);
        start_texture.loadFromFile(resourcePath()+"using/start.png");
        start.setTexture(start_texture);
        start.setPosition(405,400);
        rank_texture.loadFromFile(resourcePath()+"using/rank.png");
        rank.setTexture(rank_texture);
        rank.setPosition(405,640);
        help_texture.loadFromFile(resourcePath()+"using/help.png");
        help.setTexture(help_texture);
        help.setPosition(410,880);
        story_texture.loadFromFile(resourcePath()+"using/story.png");
        story.setTexture(story_texture);
        story.setPosition(408,1120);
        contrast_texture.loadFromFile(resourcePath()+"using/contrast.png");
        contrast.setTexture(contrast_texture);
        contrast.setPosition(-20,-200);
        contrast.setColor(sf::Color(200,200,200,150));
        
        //pause menu
        back_game_texture.loadFromFile(resourcePath()+"using/back_game.png");
        back_game.setTexture(back_game_texture);
        back_game.setPosition(273,450);
        back_menu_texture.loadFromFile(resourcePath()+"using/back_menu.png");
        back_menu.setTexture(back_menu_texture);
        back_menu.setPosition(160,900);
        contrast0_texture.loadFromFile(resourcePath()+"using/contrast0.png");
        contrast0.setTexture(contrast0_texture);
        contrast0.setColor(sf::Color(200,200,200,150));
        
        //dead menu
        back_menu_dead_texture.loadFromFile(resourcePath()+"using/back_menu_dead.png");
        back_menu_dead.setTexture(back_menu_dead_texture);
        back_menu_dead.setPosition(275,1150);
        yourname.setFont(font);
        yourname.setString("YOUR NAME HERE:");
        yourname.setPosition(310,650);
        yourname.setCharacterSize(40);
        yourname.setFillColor(sf::Color::Black);
        nameblank.setSize(sf::Vector2f(500,0));
        nameblank.setPosition(250,850);
        nameblank.setOutlineThickness(1);
        nameblank.setOutlineColor(sf::Color::Black);
        cursor.setSize(sf::Vector2f(0,80));
        cursor.setPosition(cursor_position,765);
        cursor.setOutlineThickness(1.5);
        cursor.setFillColor(sf::Color::Black);
        cursor.setOutlineColor(sf::Color::Black);
        typeiname.setFont(font);
        typeiname.setCharacterSize(60);
        typeiname.setOutlineThickness(1);
        typeiname.setFillColor(sf::Color::Black);
        typeiname.setPosition(250,770);
        typeiname.setString(typeiname_string);cursor.setSize(sf::Vector2f(0,80));
        namend.setSize(sf::Vector2f(0,80));
        namend.setPosition(710,765);
        namend.setOutlineThickness(1.5);
        namend.setFillColor(sf::Color::Black);
        namend.setOutlineColor(sf::Color::Black);
        
        //rank menu
        std::ifstream data(resourcePath()+"using/data.txt");
        for(int i=0;i<9;i++) {
            data>>scores[i].name>>scores[i].num;
        }
        data.close();
        back_menu_rank_texture.loadFromFile(resourcePath()+"using/back_menu_dead.png");
        back_menu_rank.setTexture(back_menu_dead_texture);
        back_menu_rank.setPosition(270,1190);
        font.loadFromFile(resourcePath()+"using/font.ttf");
        for(int i=0;i<9;i++) {
            //name
            rank_name[i].setFont(font);
            rank_name[i].setFillColor(sf::Color::Black);
            rank_name[i].setString(scores[i].name);
            rank_name[i].setPosition(220,i*100+150);
            rank_name[i].setCharacterSize(40);
            rank_name[i].setOutlineThickness(0.5);
            //num
            rank_num[i].setFont(font);
            rank_num[i].setFillColor(sf::Color::Black);
            rank_num[i].setString(std::to_string(scores[i].num));
            rank_num[i].setPosition(700,i*100+150);
            rank_num[i].setCharacterSize(40);
            rank_num[i].setOutlineThickness(0.5);
        }
        
        //story menu
        story_texture1.loadFromFile(resourcePath()+"using/story1.png");
        story_texture2.loadFromFile(resourcePath()+"using/story2.png");
        story_texture3.loadFromFile(resourcePath()+"using/story3.png");
        story_sprite1.setTexture(story_texture1);
        story_sprite2.setTexture(story_texture2);
        story_sprite3.setTexture(story_texture3);
        story_sprite1.setPosition(20,0);
        story_sprite2.setPosition(985,0);
        story_sprite3.setPosition(1930,0);
        story_sprite1.setColor(sf::Color(255,255,255,180));
        story_sprite2.setColor(sf::Color(255,255,255,180));
        story_sprite3.setColor(sf::Color(255,255,255,180));
        story_sprite1.setOrigin(100,0);
        story_sprite2.setOrigin(100,0);
        story_sprite3.setOrigin(100,0);
        page1.setRadius(14);
        page2.setRadius(14);
        page3.setRadius(14);
        page1.setPosition(443,1138);
        page2.setPosition(493,1138);
        page3.setPosition(543,1138);
        page1.setFillColor(sf::Color(100,100,100,240));
        page2.setFillColor(sf::Color(100,100,100,60));
        page3.setFillColor(sf::Color(100,100,100,60));

        //help menu
        helping_texture.loadFromFile(resourcePath()+"using/helping.png");
        helping.setTexture(helping_texture);
        helping.setPosition(25,30);
    
        
    }
    
    //write score rank to data.txt;
    ~Menu() {
        std::ofstream data(resourcePath()+"using/data.txt");
        for(int i=0;i<9;i++) {
            data<<scores[i].name<<" "<<scores[i].num<<std::endl;
        }
        data.close();
    }

    void reset() {
        update_rank(final_score);
        updated=1;
        cursor_position=253;
        position=0;
        page1.setFillColor(sf::Color(100,100,100,240));
        page2.setFillColor(sf::Color(100,100,100,60));
        page3.setFillColor(sf::Color(100,100,100,60));
        position=70;
    }
    
    void main_check_mouse(float x,float y) {
        if(start.getGlobalBounds().contains(x,y)){
            contrast.setPosition(-20,400);
            state=1;
        }
        else if(rank.getGlobalBounds().contains(x,y)) {
            contrast.setPosition(-20,640);
            state=4;
        }
        else if(help.getGlobalBounds().contains(x,y)) {
            contrast.setPosition(-20,880);
            state=6;
        }
        else if(story.getGlobalBounds().contains(x,y)) {
            contrast.setPosition(-20,1120);
            state=7;
        }
        else {
            contrast.setPosition(-20,-200);
            state=0;
        }
        reset();
    }
    
    void pause_check_mouse(float x,float y) {
        if(back_game.getGlobalBounds().contains(x,y)) {
            contrast0.setPosition(-20,430);
            state=1;
        }
        else if(back_menu.getGlobalBounds().contains(x,y)) {
            contrast0.setPosition(-20,900);
            state=0;
        }
        else {
            contrast0.setPosition(-20,-200);
            state=2;
        }
        
    }
    
    void dead_check_mouse(float x,float y) {
        if(back_menu_dead.getGlobalBounds().contains(x,y)) {
            contrast0.setPosition(-20,1120);
            state=0;
        }
        else {
            contrast0.setPosition(-20,-200);
            state=3;
        }
    }
    
    void rank_check_mouse(float x,float y){
        if(back_menu_rank.getGlobalBounds().contains(x,y)) {
            contrast0.setPosition(-20,1170);
            state=0;
        }
        else {
            contrast0.setPosition(-20,-200);
            state=4;
        }
    }
    
    void help_check_mouse(float x,float y){
        if(back_menu_rank.getGlobalBounds().contains(x,y)) {
            contrast0.setPosition(-20,1170);
            state=0;
        }
        else {
            contrast0.setPosition(-20,-200);
            state=6;
        }
    }
    
    
    void story_check_mouse(float x,float y) {
        if(back_menu_rank.getGlobalBounds().contains(x,y)) {
            contrast0.setPosition(-20,1170);
            state=0;
        }
        else {
            contrast0.setPosition(-20,-200);
            state=7;
            if(page1.getGlobalBounds().contains(x,y)) {
                page1.setFillColor(sf::Color(100,100,100,240));
                page2.setFillColor(sf::Color(100,100,100,60));
                page3.setFillColor(sf::Color(100,100,100,60));
                position=70;
            }
            else if(page2.getGlobalBounds().contains(x,y)) {
                page1.setFillColor(sf::Color(100,100,100,60));
                page2.setFillColor(sf::Color(100,100,100,240));
                page3.setFillColor(sf::Color(100,100,100,60));
                position=-990;
            }
            else if(page3.getGlobalBounds().contains(x,y)) {
                page1.setFillColor(sf::Color(100,100,100,60));
                page2.setFillColor(sf::Color(100,100,100,60));
                page3.setFillColor(sf::Color(100,100,100,240));
                position=-2050;
            }
        }
    }

    void draw_main_menu(sf::RenderWindow* window) {
        window->draw(contrast);
        window->draw(title);
        window->draw(subtitle);
        window->draw(start);
        window->draw(rank);
        window->draw(help);
        window->draw(story);
        
    }
    
    void draw_pause_menu(sf::RenderWindow* window) {
        window->draw(contrast0);
        window->draw(back_game);
        window->draw(back_menu);
        
    }
    
    void draw_dead_menu(sf::RenderWindow* window) {
        window->draw(contrast0);
        window->draw(back_menu_dead);
        window->draw(yourname);
        window->draw(nameblank);
        window->draw(typeiname);
        //window->draw(namend);
        if(cursor_clock.getElapsedTime().asMilliseconds()>500){
            cursor_active^=1;
            cursor_clock.restart();
        }
        if(cursor.getGlobalBounds().intersects(typeiname.getGlobalBounds())) cursor_position+=10;
        cursor.setPosition(cursor_position,765);
        if(cursor_active and !cursor.getGlobalBounds().intersects(typeiname.getGlobalBounds())) window->draw(cursor);
        
    }
    
    void draw_story_menu(sf::RenderWindow* window) {
        story_move();
        window->draw(contrast0);
        window->draw(back_menu_rank);
        window->draw(story_sprite1);
        window->draw(story_sprite2);
        window->draw(story_sprite3);
        window->draw(page1);
        window->draw(page2);
        window->draw(page3);
    }
    
    void draw_rank_menu(sf::RenderWindow* window) {
        for(int i=0;i<9;i++) {
            window->draw(rank_name[i]);
            window->draw(rank_num[i]);
        }
        window->draw(contrast0);
        window->draw(back_menu_rank);
    }
    
    void draw_help_menu(sf::RenderWindow* window) {
        window->draw(contrast0);
        window->draw(helping);
        window->draw(back_menu_rank);
    }
    
    void type_react() {
        if(!typeiname.getGlobalBounds().intersects(namend.getGlobalBounds())) typeiname_string+=typein;
        typeiname.setString(typeiname_string);
    }
    
    void pop_back() {
        typeiname_string.pop_back();
        typeiname.setString(typeiname_string);
        if(cursor_position-80>=253) cursor_position-=80;
        else cursor_position=255;
    }
    
    
    
    void update_rank(int score) {
        if(!updated) {
            scores[9].name=typeiname_string;
            if(scores[9].name=="") scores[9].name="NONAME";
            scores[9].num=score;
            std::sort(scores,scores+10,cmp);
            for(int i=0;i<9;i++) {
                rank_name[i].setString(scores[i].name);
                rank_num[i].setString(std::to_string(scores[i].num));
                updated=1;
            }
        }
    }
    
    void story_move() {
        story_sprite1.move((position-story_sprite1.getPosition().x+50)/10.0,0);
        story_sprite2.move((position-story_sprite1.getPosition().x+50)/10.0,0);
        story_sprite3.move((position-story_sprite1.getPosition().x+50)/10.0,0);
        
    }
    
};

#endif
