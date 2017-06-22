#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <windows.h>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Object.h"
#include "Ultimate.h"
#include "Boom.h"
#define XRANGE 800
#define YRANGE 1080
#define BULLET_TYPE 2
#define ULTIMATE_BULLET_TYPE 3
#define ENEMY0_TYPE 4
#define ENEMY1_TYPE 5
#define BOSS1 6
#define BOSS2 8
#define BOSS_BULLET_TYPE 11
#define HERO 1
#define ENEMY1_BULLET_TYPE 7
#define FPS 144
#define GETINTOBOSS 40
using namespace std;
void setScoreString(string &a,int score);
void setLifeString(string &a,int life);
bool needErase(sf::Vector2f obj);
bool isCrash(sf::Vector2f a,sf::Vector2f b,double r);
sf::Vector2f forMove(sf::Vector2f a);
sf::Vector2i mousePositionReset(sf::Vector2i windowPosition);
int main()
{

    //**********************↓辅助参数↓******************
    srand(time(NULL));
    bool bossIsDead=0;
    int score=0,enemyType=ENEMY0_TYPE;
    int countBullet=0,countEnemy0=0,countTime,tmpInt,bulletType=BULLET_TYPE,countEnemy0Bullet=0;
    const double Rhero=55,Renemy0[2]={25,40},Rbullet=3,Rboss=80;
    string ScoreString="Score:0",LifeString="Life:50";
    vector<sf::Sprite>::iterator itSprite;
    vector<Object>::iterator itObject,itObject1,itObject2;
    vector<BOOM>::iterator itBOOM;
    sf::Vector2f heroPositionRecorrect(50,62),bulletRecorrection(5,10);
    sf::Vector2f enemy0PositionRecorrect(25,20),enemy0PositionRecorrect1(25,46);
    sf::Vector2f Bullet1move(0,-0.25),tmpVector2f,tmpVector2f1,tmpVector2f2;
    sf::Vector2f Bullet2move,HorizontalNormal(1,0);
    sf::Vector2f windowPositionRecorrect,mouseOriginPosition(XRANGE/2,YRANGE),gameOverPosition(-175+XRANGE/2,-156+YRANGE/2);
    sf::Vector2f BossPositionRecorrect(+84,+120);
    sf::Vector2f BossPositionOringin(XRANGE/2,0);
    sf::Vector2i tmpVector2i1,tmpVector2i2;
    sf::Sprite *spritetmp,test;
    Object *objecttmp;
    BOOM *tmpBoom;
    //**********************↑辅助参数↑******************
    //**********************↓对象参数↓******************
    sf::Uint32 style=sf::Style::Fullscreen;
    sf::RenderWindow window(sf::VideoMode(XRANGE,YRANGE), "Fighters:Just For Fun!");
            while(!sf::Keyboard::isKeyPressed(sf::Keyboard::A));
    sf::Texture HeroPic,BulletPicture1,BulletPicture2,backgroundPicture,enemyPicture[2],winPicture;
    sf::Texture bossPic,gameOverPic,enemyBoom[2][6],bossBoom[6];
    sf::Sprite background,gameOver,winView;
    sf::Event event;
    sf::Music music;
    sf::Font font;
    sf::Text scoreTex,life,ultimate1CDTex,ultimate2CDTex,heroLifeTex;
    sf::Sound ultimate1Sound,ultimate2Sound,boomSound,shootSound;
    sf::SoundBuffer ultimate1SoundBuffer,ultimate2SoundBuffer,boomBuffer,shootBuffer;
    vector<BOOM> boom;
    vector<Object> enemy0,bullet1,bullet2;
    window.setFramerateLimit(FPS);
    if (!enemyBoom[0][1].loadFromFile("material\\image\\enemy0.png"))
        return EXIT_FAILURE;
    if (!enemyBoom[0][2].loadFromFile("material\\image\\enemy0_down1.png"))
        return EXIT_FAILURE;
    if (!enemyBoom[0][3].loadFromFile("material\\image\\enemy0_down2.png"))
        return EXIT_FAILURE;
    if (!enemyBoom[0][4].loadFromFile("material\\image\\enemy0_down3.png"))
        return EXIT_FAILURE;
    if (!enemyBoom[0][5].loadFromFile("material\\image\\enemy0_down4.png"))
        return EXIT_FAILURE;
    if (!enemyBoom[1][1].loadFromFile("material\\image\\enemy1.png"))
        return EXIT_FAILURE;
    if (!enemyBoom[1][2].loadFromFile("material\\image\\enemy1_down1.png"))
        return EXIT_FAILURE;
    if (!enemyBoom[1][3].loadFromFile("material\\image\\enemy1_down2.png"))
        return EXIT_FAILURE;
    if (!enemyBoom[1][4].loadFromFile("material\\image\\enemy1_down3.png"))
        return EXIT_FAILURE;
    if (!enemyBoom[1][5].loadFromFile("material\\image\\enemy1_down4.png"))
        return EXIT_FAILURE;
    if (!bossBoom[1].loadFromFile("material\\image\\enemy2_down1.png"))
        return EXIT_FAILURE;
    if (!bossBoom[2].loadFromFile("material\\image\\enemy2_down2.png"))
        return EXIT_FAILURE;
    if (!bossBoom[3].loadFromFile("material\\image\\enemy2_down4.png"))
        return EXIT_FAILURE;
    if (!bossBoom[4].loadFromFile("material\\image\\enemy2_down5.png"))
        return EXIT_FAILURE;
    if (!bossBoom[5].loadFromFile("material\\image\\enemy2_down6.png"))
        return EXIT_FAILURE;
    if (!HeroPic.loadFromFile("material\\image\\hero1.png"))
        return EXIT_FAILURE;
    if (!enemyPicture[0].loadFromFile("material\\image\\enemy0.png"))
        return EXIT_FAILURE;
    if (!enemyPicture[1].loadFromFile("material\\image\\enemy1.png"))
        return EXIT_FAILURE;
    if (!bossPic.loadFromFile("material\\image\\boss.png"))
        return EXIT_FAILURE;
    if (!BulletPicture1.loadFromFile("material\\image\\bullet1.png"))
        return EXIT_FAILURE;
    if (!BulletPicture2.loadFromFile("material\\image\\bullet2.png"))
        return EXIT_FAILURE;
    if (!backgroundPicture.loadFromFile("material\\image\\BackGround.png"))
        return EXIT_FAILURE;
    if (!gameOverPic.loadFromFile("material\\image\\gameOver.png"))
        return EXIT_FAILURE;
    if (!winPicture.loadFromFile("material\\image\\win.png"))
        return EXIT_FAILURE;
    if (!font.loadFromFile("material\\font\\Marker Felt.ttf"))
        return EXIT_FAILURE;
    if (!music.openFromFile("material\\sound\\Victory.ogg"))
        return EXIT_FAILURE;
    if (!ultimate1SoundBuffer.loadFromFile("material\\sound\\ultimate1.ogg"))
        return EXIT_FAILURE;
    if (!ultimate2SoundBuffer.loadFromFile("material\\sound\\ultimate2.ogg"))
        return EXIT_FAILURE;
    if (!boomBuffer.loadFromFile("material\\sound\\enemy0_down.ogg"))
        return EXIT_FAILURE;
    if (!shootBuffer.loadFromFile("material\\sound\\bullet.ogg"))
        return EXIT_FAILURE;
    ultimate1Sound.resetBuffer();ultimate1Sound.setBuffer(ultimate1SoundBuffer);
    ultimate2Sound.resetBuffer();ultimate2Sound.setBuffer(ultimate2SoundBuffer);
    boomSound.resetBuffer();boomSound.setBuffer(boomBuffer);
    shootSound.resetBuffer();shootSound.setBuffer(shootBuffer);
    music.setLoop(true);
    music.play();
    Ultimate ultimate1(1,font),ultimate2(2,font);
    scoreTex.setColor(sf::Color::Red);
    scoreTex.setCharacterSize(20);
    scoreTex.setFont(font);
    heroLifeTex=scoreTex;
    sf::Vector2f LifeTexPosition(20,YRANGE-80);
    heroLifeTex.setPosition(LifeTexPosition);
    background.setTexture(backgroundPicture);
    winView.setTexture(winPicture);
    gameOver.setTexture(gameOverPic);
    gameOver.setPosition(gameOverPosition);
    Object Hero(HeroPic,HERO);
    //**********************↑对象参数↑******************
    //**********************↓运行过程1↓******************
    restart:
    windowPositionRecorrect=(sf::Vector2f)window.getPosition();
    tmpVector2i1=(sf::Vector2i)(windowPositionRecorrect+mouseOriginPosition);
    sf::Mouse::setPosition(tmpVector2i1);

    while (window.isOpen())
    {
        //window.setMouseCursorVisible(0);
        // Process events
        while (window.pollEvent(event))
        {
            //Close window: exit
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        // Clear screen
        window.clear();
        if (score>=GETINTOBOSS&&enemy0.empty()&&boom.empty()&&bullet1.empty()&&bullet2.empty()){
            _sleep(800);
            break;
        }
        else if (score>=GETINTOBOSS>>1){
            enemyType=ENEMY1_TYPE;
        }
        // Draw the sprite
        window.draw(background);
        countTime=(int)clock();

        setLifeString(LifeString,Hero.life);
        //*****************正义的分割线**********************
        //*****************↓Ultimate↓********************
        ultimate1.upDate(countTime);
        ultimate2.upDate(countTime);
        ultimate1.setText(countTime);
        ultimate2.setText(countTime);
        if (sf::Mouse::isButtonPressed(sf::Mouse::XButton1)&&ultimate1.able){
            ultimate1.useUltimate(countTime);
            ultimate1Sound.play();
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::XButton2)&&ultimate2.able){
            ultimate2.useUltimate(countTime);
            ultimate2Sound.play();
        }
        //*****************↑Ultimate↑********************
        //*****************↓Crash Pending↓********************
        for (itObject1=enemy0.begin();itObject1<enemy0.end();itObject1++){
            tmpVector2f1=itObject1->sprite.getPosition()+enemy0PositionRecorrect;
            for (itObject2=bullet1.begin();itObject2<bullet1.end();itObject2++){
                tmpVector2f2=itObject2->sprite.getPosition()+bulletRecorrection;
                if (isCrash(tmpVector2f1,tmpVector2f2,Renemy0[enemyType==ENEMY1_TYPE]+Rbullet)){
                    itObject1->life--;
                    itObject2->life--;
                    itObject2->speedChange(tmpVector2f1-tmpVector2f2);
                }
                if (itObject1->life<=0){
                    score++;setScoreString(ScoreString,score);boomSound.play();
                    tmpBoom=new BOOM(enemyBoom[itObject1->type==ENEMY1_TYPE],countTime);
                    for (int i=1;i<=5;i++){
                        tmpBoom->sprite[i].setPosition(itObject1->sprite.getPosition());
                    }
                    boom.push_back(*tmpBoom);
                    free(tmpBoom);tmpBoom=NULL;
                    enemy0.erase(itObject1);itObject1--;
                    goto crashGoto1;
                }
                if (itObject2->life<=0){
                    bullet1.erase(itObject2);itObject2--;
                }
            }
            crashGoto1:int rubbish=1;
        }
        tmpVector2f1=Hero.sprite.getPosition()+heroPositionRecorrect;
        for (itObject2=bullet2.begin();itObject2<bullet2.end();itObject2++){
            tmpVector2f2=itObject2->sprite.getPosition()+bulletRecorrection;
            //printf("%lf %lf     %lf %lf\n",tmpVector2f1.x,tmpVector2f1.y,tmpVector2f2.x,tmpVector2f2.y);
            if (isCrash(tmpVector2f1,tmpVector2f2,Rhero+Rbullet)){
                Hero.life--;
                setLifeString(LifeString,Hero.life);
                itObject2->life--;
                itObject2->speedChange(tmpVector2f1-tmpVector2f2);
            }
            if (itObject2->life==0){
                bullet2.erase(itObject2);itObject2--;
            }
        }
        //*****************↑Crash Pending↑********************
        //*****************↓Creat && Draw↓********************
        if (countEnemy0+932<countTime&&!ultimate1.on&&score<40){//制造敌机
            countEnemy0=countTime;
            objecttmp=new Object(enemyPicture[enemyType==ENEMY1_TYPE],enemyType);
            enemy0.push_back(*objecttmp);
            tmpVector2f.x=rand()%(XRANGE-100)+50;tmpVector2f.y=rand()%180;
            enemy0[enemy0.size()-1].sprite.setPosition(tmpVector2f);
            free(objecttmp);objecttmp=NULL;
        }
        for (itObject=enemy0.begin();itObject!=enemy0.end();itObject++){
            tmpVector2f=itObject->sprite.getPosition();
            if (needErase(tmpVector2f)){
                enemy0.erase(itObject);
                itObject--;continue;
            }
            if (tmpVector2f.x<0||tmpVector2f.x>XRANGE)
                itObject->speedChange(HorizontalNormal);
            if(!ultimate1.on){
                itObject->sprite.setPosition(tmpVector2f+forMove(itObject->speed));
            }
            window.draw(itObject->sprite);
        }
        //------------------------------------------------
        if (ultimate2.on){
            bulletType=ULTIMATE_BULLET_TYPE;
        }
        else{
            bulletType=BULLET_TYPE;
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&!enemy0.empty()){//制造子弹
            if (countTime>countBullet+60){
                countBullet=countTime;
                objecttmp=new Object(BulletPicture1,bulletType);
                bullet1.push_back(*objecttmp);
                tmpVector2f=Hero.sprite.getPosition()+heroPositionRecorrect-bulletRecorrection;
                bullet1[bullet1.size()-1].sprite.setPosition(tmpVector2f);
                free(objecttmp);objecttmp=NULL;
                shootSound.play();
            }
        }
        for (itObject=bullet1.begin();itObject!=bullet1.end();itObject++){
            tmpVector2f=itObject->sprite.getPosition();
            if (needErase(tmpVector2f)){
                bullet1.erase(itObject);
                itObject--;continue;
            }
            if (tmpVector2f.x<0||tmpVector2f.x>XRANGE)
                itObject->speedChange(HorizontalNormal);
            itObject->sprite.setPosition(tmpVector2f+forMove(itObject->speed));
            window.draw(itObject->sprite);
        }
        //------------------------------------------------
        if (countEnemy0Bullet+466<countTime){//敌机子弹
            for (itObject=enemy0.begin();itObject!=enemy0.end();itObject++){
                countEnemy0Bullet=countTime;
                countBullet=countTime;
                objecttmp=new Object(BulletPicture2,ENEMY1_BULLET_TYPE);
                bullet2.push_back(*objecttmp);
                tmpVector2f=itObject->sprite.getPosition()+enemy0PositionRecorrect1-bulletRecorrection;
                bullet2[bullet2.size()-1].sprite.setPosition(tmpVector2f);
                free(objecttmp);objecttmp=NULL;
            }
        }
        for (itObject=bullet2.begin();itObject!=bullet2.end();itObject++){
            tmpVector2f=itObject->sprite.getPosition();
            if (needErase(tmpVector2f)){
                bullet2.erase(itObject);
                itObject--;continue;
            }
            if (tmpVector2f.x<0||tmpVector2f.x>XRANGE)
                itObject->speedChange(HorizontalNormal);
            itObject->sprite.setPosition(tmpVector2f+forMove(itObject->speed));
            window.draw(itObject->sprite);
        }
        //----------------------------------------------------
        sf::Vector2i a=mousePositionReset((sf::Vector2i)windowPositionRecorrect);
        sf::Vector2f b=(sf::Vector2f)a-heroPositionRecorrect-windowPositionRecorrect;
        Hero.sprite.setPosition(b);
        window.draw(Hero.sprite);
        //*****************↑Creat && Draw↑********************
        //*****************↓爆炸就是艺术↓********************
        for (itBOOM=boom.begin();itBOOM!=boom.end();itBOOM++){
            if (itBOOM->time+80<countTime){
                itBOOM->index=itBOOM->index+1;
                itBOOM->time=countTime;
            }
            if (itBOOM->index>5){
                boom.erase(itBOOM);
                itBOOM--;continue;
            }
            window.draw(itBOOM->sprite[itBOOM->index]);
        }
        //*****************↑爆炸就是艺术↑********************
        //*****************↓字符显示↓********************
        scoreTex.setString(ScoreString);
        heroLifeTex.setString(LifeString);
        window.draw(heroLifeTex);
        window.draw(scoreTex);
        window.draw(ultimate1.text);
        window.draw(ultimate2.text);
        //*****************↑字符显示↑********************
        // Draw the string
        // Update the window
        if  (Hero.life<=0){
            window.draw(gameOver);
            window.display();
            _sleep(2000);
            while(!sf::Mouse::isButtonPressed(sf::Mouse::Right)&&!sf::Mouse::isButtonPressed(sf::Mouse::Left)){};
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                bullet1.clear();
                bullet2.clear();
                enemy0.clear();
                goto restart;
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
                window.close();
        }
        window.display();
    }
    //**********************↑运行过程1↑******************


    enemy0.clear();
    bullet1.clear();
    bullet2.clear();
    boom.clear();
    Object Boss1(bossPic,BOSS1);
    Boss1.sprite.setPosition(-BossPositionRecorrect+BossPositionOringin);
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            //Close window: exit
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(background);
        countTime=(int)clock();
        //*****************正义的分割线**********************

        Boss1.sprite.setPosition(Boss1.sprite.getPosition()+forMove(Boss1.speed));
        tmpVector2f=Boss1.sprite.getPosition();
        if (tmpVector2f.y>=80) break;
        window.draw(Boss1.sprite);
        window.draw(Hero.sprite);
        window.display();
    }
    sf::Mouse::setPosition((sf::Vector2i)(windowPositionRecorrect+Hero.sprite.getPosition()+heroPositionRecorrect));
    //**********************↓运行过程2↓******************
    Object Boss(bossPic,BOSS2);
    Boss.sprite.setPosition(tmpVector2f);
    countTime=clock();
    ultimate1.reNew(countTime);
    ultimate2.reNew(countTime);
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            //Close window: exit
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        // Clear screen
        if (boom[0].index==5){
            window.draw(winView);
            window.display();
            _sleep(2000);
            while(!sf::Mouse::isButtonPressed(sf::Mouse::Right)&&!sf::Mouse::isButtonPressed(sf::Mouse::Left)){};
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                bullet1.clear();
                bullet2.clear();
                enemy0.clear();
                goto restart;
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
                window.close();
        }
        window.clear();
        // Draw the sprite
        window.draw(background);
        countTime=(int)clock();
        //*****************正义的分割线**********************
        //*****************↓Ultimate↓********************
        ultimate1.upDate(countTime);
        ultimate2.upDate(countTime);
        ultimate1.setText(countTime);
        ultimate2.setText(countTime);
        if (sf::Mouse::isButtonPressed(sf::Mouse::XButton1)&&ultimate1.able){
            ultimate1.useUltimate(countTime);
            ultimate1Sound.play();
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::XButton2)&&ultimate1.able){
            ultimate2.useUltimate(countTime);
            ultimate2Sound.play();
        }
        //*****************↑Ultimate↑********************
        //*****************↓Crash Pending↓********************
        tmpVector2f1=Boss.sprite.getPosition()+BossPositionRecorrect;
        for (itObject2=bullet1.begin();itObject2<bullet1.end();itObject2++){
            tmpVector2f2=itObject2->sprite.getPosition()+bulletRecorrection;
            if (isCrash(tmpVector2f1,tmpVector2f2,Rboss+Rbullet)){
                Boss.life--;
                itObject2->life--;
                itObject2->speedChange(tmpVector2f1-tmpVector2f2);
            }
            if (Boss.life<=0&&bossIsDead==0){
                bossIsDead=1;
                score++;setScoreString(ScoreString,score);
                tmpBoom=new BOOM(bossBoom,countTime);
                for (int i=1;i<=5;i++){
                    tmpBoom->sprite[i].setPosition(Boss.sprite.getPosition());
                }
                boom.push_back(*tmpBoom);
                free(tmpBoom);tmpBoom=NULL;
                break;
            }
            if (itObject2->life<=0){
                bullet1.erase(itObject2);itObject2--;
            }
        }
        tmpVector2f1=Hero.sprite.getPosition()+heroPositionRecorrect;
        for (itObject2=bullet2.begin();itObject2<bullet2.end();itObject2++){
            tmpVector2f2=itObject2->sprite.getPosition()+bulletRecorrection;
            //printf("%lf %lf     %lf %lf\n",tmpVector2f1.x,tmpVector2f1.y,tmpVector2f2.x,tmpVector2f2.y);
            if (isCrash(tmpVector2f1,tmpVector2f2,Rhero+Rbullet)){
                Hero.life--;
                setLifeString(LifeString,Hero.life);
                itObject2->life--;
                itObject2->speedChange(tmpVector2f1-tmpVector2f2);
            }
            if (itObject2->life==0){
                bullet2.erase(itObject2);itObject2--;
            }
        }
        //*****************↑Crash Pending↑********************
        //*****************↓Creat && Draw↓********************
        if (ultimate2.on){
            bulletType=ULTIMATE_BULLET_TYPE;
        }
        else{
            bulletType=BULLET_TYPE;
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){//制造子弹
            if (countTime>countBullet+120){
                countBullet=countTime;
                objecttmp=new Object(BulletPicture1,bulletType);
                bullet1.push_back(*objecttmp);
                tmpVector2f=Hero.sprite.getPosition()+heroPositionRecorrect-bulletRecorrection;
                bullet1[bullet1.size()-1].sprite.setPosition(tmpVector2f);
                free(objecttmp);objecttmp=NULL;
                shootSound.play();
            }
        }
        for (itObject=bullet1.begin();itObject!=bullet1.end();itObject++){
            tmpVector2f=itObject->sprite.getPosition();
            if (needErase(tmpVector2f)){
                bullet1.erase(itObject);
                itObject--;continue;
            }
            if (tmpVector2f.x<0||tmpVector2f.x>XRANGE)
                itObject->speedChange(HorizontalNormal);
            itObject->sprite.setPosition(tmpVector2f+forMove(itObject->speed));
            window.draw(itObject->sprite);
        }
        //------------------------------------------------
        if (countEnemy0Bullet+233<countTime&&Boss.life>0){//敌机子弹
            countEnemy0Bullet=countTime;
            for (int i=1;i<=1;i++){
                objecttmp=new Object(BulletPicture2,BOSS_BULLET_TYPE);
                bullet2.push_back(*objecttmp);
                tmpVector2f=Boss.sprite.getPosition()+BossPositionRecorrect-bulletRecorrection;
                bullet2[bullet2.size()-1].sprite.setPosition(tmpVector2f);
                free(objecttmp);objecttmp=NULL;
            }
        }
        for (itObject=bullet2.begin();itObject!=bullet2.end();itObject++){
            tmpVector2f=itObject->sprite.getPosition();
            if (needErase(tmpVector2f)){
                bullet2.erase(itObject);
                itObject--;continue;
            }
            if (tmpVector2f.x<0||tmpVector2f.x>XRANGE)
                itObject->speedChange(HorizontalNormal);
            itObject->sprite.setPosition(tmpVector2f+forMove(itObject->speed));
            window.draw(itObject->sprite);
        }
        //----------------------------------------------------
        if (Boss.life>0){
            if (!ultimate1.on)  Boss.sprite.setPosition(Boss.sprite.getPosition()+forMove(Boss.speed));
            window.draw(Boss.sprite);
            tmpVector2f=Boss.sprite.getPosition()+BossPositionRecorrect;
            if (tmpVector2f.x<=50||tmpVector2f.x>=XRANGE-50){
                Boss.speed.x*=-1;
            }
        }
        //print(Boss.sprite.getPosition());
        //--------------------------------------------------------
        sf::Vector2i a=mousePositionReset((sf::Vector2i)windowPositionRecorrect);
        sf::Vector2f b=(sf::Vector2f)a-heroPositionRecorrect-windowPositionRecorrect;
        Hero.sprite.setPosition(b);
        window.draw(Hero.sprite);
        //*****************↑Creat && Draw↑********************
        //*****************↓爆炸就是艺术↓********************
        for (itBOOM=boom.begin();itBOOM!=boom.end();itBOOM++){
            if (itBOOM->time+150<countTime){
                itBOOM->index=itBOOM->index+1;
                itBOOM->time=countTime;
            }
            if (itBOOM->index>5){
                boom.erase(itBOOM);
                itBOOM--;continue;
            }
            else   {
                window.draw(itBOOM->sprite[itBOOM->index]);
            }
        }
        //*****************↑爆炸就是艺术↑********************
        // Draw the string
        scoreTex.setString(ScoreString);
        heroLifeTex.setString(LifeString);
        window.draw(heroLifeTex);
        window.draw(scoreTex);
        window.draw(ultimate1.text);
        window.draw(ultimate2.text);
        // Update the window
        if  (Hero.life<=0){
            window.draw(gameOver);
            window.display();
            _sleep(2000);
            while(!sf::Mouse::isButtonPressed(sf::Mouse::Right)&&!sf::Mouse::isButtonPressed(sf::Mouse::Left)){};
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                bullet1.clear();
                bullet2.clear();
                enemy0.clear();
                goto restart;
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
                window.close();
        }
        window.display();
    }
    //**********************↑运行过程2↑******************
    return EXIT_SUCCESS;
}

void setScoreString(string &a,int score){
    char num[10];
    itoa(score,num,10);
    a="Score:";
    a.append(num);
}

void setLifeString(string &a,int life){
    char num[10];
    itoa(life,num,10);
    a="Life:";
    a.append(num);
}

sf::Vector2f forMove(sf::Vector2f a){
    a.x/=FPS;a.y/=FPS;
    return a;
}

bool needErase(sf::Vector2f obj){
    return obj.y<0||obj.y>YRANGE;
}

bool isCrash(sf::Vector2f a,sf::Vector2f b,double r){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)<r*r;
}

sf::Vector2i mousePositionReset(sf::Vector2i windowPosition){
    sf::Vector2i tmp;
    tmp=sf::Mouse::getPosition();
    tmp.x=tmp.x>windowPosition.x+5?           tmp.x:windowPosition.x+5;
    tmp.x=tmp.x<windowPosition.x+XRANGE-5?    tmp.x:windowPosition.x+XRANGE-5;
    tmp.y=tmp.y>windowPosition.y+5?           tmp.y:windowPosition.y+5;
    tmp.y=tmp.y<windowPosition.y+YRANGE-5?    tmp.y:windowPosition.y+YRANGE-5;
    sf::Mouse::setPosition(tmp);
    return tmp;
}
