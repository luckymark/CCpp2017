#include "Game.h"
Game::Game()
: mWindow(sf::VideoMode(screenX, screenY), "He is living")
//, mPlayer()
{
	//mPlayer.setRadius(40.f);
	//mPlayer.setPosition(screenX-300, screenY-300);
	//mPlayer.setFillColor(sf::Color::Cyan);
	backgroundText.loadFromFile("resources/image/it2.png");//stared background
	gameover.loadFromFile("resources/image/gameover.png");//ending background
    background.setTexture(backgroundText);
    srand((unsigned) time(NULL));
    PlayerHP=3;//几条生命
    Score=0;//开始分数
    mPlayer=new Hero;
    fail=victory=haveBoss=false;
    //mWindow.setFramerateLimit(120);

//加载字体相关信息
    font.loadFromFile("resources/font/STHeiti Light.ttc");
    mScore.setFont(font);
    mHP.setFont(font);
    mScore.setPosition(0,0);//score的放置位置
    mHP.setPosition(0,25);//HP的放置位置

//加载声音资源
    BGM1.openFromFile("resources/sound/cat.ogg");//添加音乐文件
    BGM1.setLoop(true);
    BGM1.play();
}
void Game::enemyAction()//敌机
{
    //创建敌机
    if(Score==10&&!haveBoss)
        {
            allEnemy.push_back(new Enemy(boss));//击落10架敌机后放boss
            haveBoss=true;
        }
    if(rand()%2000==1)//控制小飞机产生的的数量
    {
        allEnemy.push_back(new Enemy(normal));
    }

    if(rand()%6000==1)//控制中飞机产生的数量
    {
        allEnemy.push_back(new Enemy(elite));
    }

    //敌机开火
    for (std::vector<Enemy*>::iterator it = allEnemy.begin(); it != allEnemy.end(); ++it)
    {
        if((*it)->getType()==boss)
        {
            if(rand()%1000==1)//大飞机的发射速度
                (*it)->fire();
        }
        if(rand()%2000==1)//数值越小 小飞机和中飞机发射的越快
        {
            (*it)->fire();
        }
    }
}

void Game::run()//Y
{
	sf::Clock clock;
	while (mWindow.isOpen())
	{
	    if(fail)
        {
            processEvents();//Y
            background.setTexture(gameover);

            char s[30],s2[30]="Oh Fuck! You Score: ";//change from char s[20],s2[20]="You Score: ";
            snprintf(s,9,"%d",Score);
            strcat(s2,s);
            mScore.setPosition(75,600);//oh fuck your score的位置
            mScore.setString(s2);

            mWindow.clear();
            mWindow.draw(background);
            mWindow.draw(mScore);
            mWindow.display();
            continue;
        }
		sf::Time deltaTime = clock.restart();
		if(mPlayer->checkAlive()>0)
            processEvents();
		else
            if(mPlayer->ruin())
            {
                delete mPlayer;//毁机
                PlayerHP--;//续命
                if(PlayerHP>0)
                    mPlayer=new Hero;
                else
                {
                    fail=true;
                    continue;
                }
            }
		update(deltaTime);
		enemyAction();
		checkCollide();
		render();//Y
		deleteCrash();
		mPlayer->deleteDie();
	}
}
void Game::processEvents()//INPUT EVENTS  // IT IS KEYBOARD INPUT ;open and closed
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			if(PlayerHP)handlePlayerInput(event.key.code, true);//use hp to judge
			break;
		case sf::Event::KeyReleased:
			if(PlayerHP)handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}
void Game::update(sf::Time deltaTime)//EVERYTHING HAPPENS IN THE GAME

{
    mPlayer->moveNode(deltaTime);
    for (std::vector<Enemy*>::iterator it = allEnemy.begin(); it != allEnemy.end(); ++it)
    {
        Enemy *temp=*it;
        temp->moveNode(deltaTime);
    }

}
void Game::render()
{
    std::vector<Bullet*> p=mPlayer->getBulletVector();
	mWindow.clear();
	mWindow.draw(background);
	mWindow.draw(*mPlayer);
	//»­×Óµ¯
    for (std::vector<Bullet*>::iterator it = p.begin(); it != p.end(); ++it)
    {
        Bullet *temp=*it;
        mWindow.draw(*temp);
    }
    //
    for (std::vector<Enemy*>::iterator it = allEnemy.begin(); it != allEnemy.end(); ++it)
    {
        Enemy *temp=*it;
        mWindow.draw(*temp);

        //渲染每台敌机的子弹
        p=(*it)->getBulletVector();
        for (std::vector<Bullet*>::iterator it2 = p.begin(); it2 != p.end(); ++it2)
        {
            Bullet *temp=*it2;
            mWindow.draw(*temp);
        }
    }

//显示字符串
    char s[20],s2[20]="Score: ";
    snprintf(s,9,"%d",Score);
    strcat(s2,s);
    mScore.setString(s2);
    mWindow.draw(mScore);

    strcpy(s2,"HP: ");
    snprintf(s,9,"%d",PlayerHP);
    strcat(s2,s);
    mHP.setString(s2);
    mWindow.draw(mHP);
/////////////
	mWindow.display();
}
void Game::handlePlayerInput(sf::Keyboard::Key key,
	bool isPressed)//控制键的设置
{
	if (key == sf::Keyboard::Up)
		mPlayer->isMovingUp(isPressed);
	else if (key == sf::Keyboard::Down)
		mPlayer->isMovingDown(isPressed);
	else if (key == sf::Keyboard::Left)
		mPlayer->isMovingLeft(isPressed);
	else if (key == sf::Keyboard::Right)
		mPlayer->isMovingRight(isPressed);
    if(key==sf::Keyboard::Space)
    {
        mPlayer->fire();
    }
}

void Game::checkCollide()
{
    //检查玩家子弹
    Bullet *tempPlayer;
    std::vector<Bullet*> p=mPlayer->getBulletVector();
    for (std::vector<Bullet*>::iterator it = p.begin(); it != p.end(); ++it)
    {
        tempPlayer=*it;
        for (std::vector<Enemy*>::iterator it2 = allEnemy.begin(); it2 != allEnemy.end(); ++it2)
        {
            if((*it2)->checkHit(tempPlayer->getPosition().x+4,tempPlayer->getPosition().y))
                tempPlayer->die();
        }
    }

    //检查敌人子弹
    int myx=mPlayer->getPosition().x+51;
    int myy=mPlayer->getPosition().y;
    int otherx,othery;
    for (std::vector<Enemy*>::iterator it = allEnemy.begin(); it != allEnemy.end(); ++it)
    {
        //检查飞机有没有碰撞
        otherx=(*it)->getPosition().x;
        othery=(*it)->getPosition().y;
        if((*it)->getType()==normal)
        {
            if(myx<=otherx+57&&
                myx>=otherx&&
                myy<=othery+51&&
                myy>=othery)
            {
                mPlayer->crash();
            }
        }
        else
        {
            if(myx<=otherx+69&&
                myx>=otherx&&
                myy<=othery+95&&
                myy>=othery)
            {
                mPlayer->crash();
            }
        }

        //检查子弹碰撞
        p=(*it)->getBulletVector();
        for (std::vector<Bullet*>::iterator it2 = p.begin(); it2 != p.end(); ++it2)
        {
            otherx=(*it2)->getPosition().x;
            othery=(*it2)->getPosition().y;
            if(myx<=otherx+9&&
               myx>=otherx&&
               myy<=othery+21&&
               myy>=othery)
            {
                mPlayer->crash();
            }
        }
    }
    /*
    //检查玩家子弹
    Bullet *tempPlayer;
    std::vector<Bullet*> p=mPlayer->getBulletVector();
    for (std::vector<Bullet*>::iterator it = p.begin(); it != p.end(); ++it)
    {
        tempPlayer=*it;
        for (std::vector<Enemy*>::iterator it2 = allEnemy.begin(); it2 != allEnemy.end(); ++it2)
        {
            if(tempPlayer->getPosition().x<(*it2)->getPosition().x+69&&
               (*it2)->getPosition().x<tempPlayer->getPosition().x&&
               tempPlayer->getPosition().y<(*it2)->getPosition().y+95&&
               (*it2)->getPosition().y<tempPlayer->getPosition().y)
            {
                (*it2)->die();
                (*it)->die();
            }
        }
    }
    //检查敌机与敌机子弹
    for (std::vector<Enemy*>::iterator it = allEnemy.begin(); it != allEnemy.end(); ++it)
    {
        if((mPlayer.getPosition().x+102<(*it)->getPosition().x+69&&
            mPlayer.getPosition().x+102>(*it)->getPosition().x&&
            mPlayer.getPosition().y>(*it)->getPosition().y)||
           (mPlayer.getPosition().x<(*it)->getPosition().x+69&&
            mPlayer.getPosition().x>(*it)->getPosition().x&&
            mPlayer.getPosition().y>(*it)->getPosition().y))
                mPlayer.die();
        p=(*it)->getBulletVector();
        for (std::vector<Bullet*>::iterator it2 = p.begin(); it2 != p.end(); ++it2)
        {
            Bullet *temp=*it2;
            if(temp->getPosition().x<mPlayer.getPosition().x+102&&
               temp->getPosition().x>mPlayer.getPosition().x&&
               temp->getPosition().y>mPlayer.getPosition().y&&
               temp->getPosition().y<mPlayer.getPosition().y+126)
               mPlayer.die();
        }
    }
    */
}

void Game::deleteCrash()//删除销毁的飞机 并且加分
{
    for (std::vector<Enemy*>::iterator it = allEnemy.begin(); it != allEnemy.end(); ++it)
    {
        if((*it)->checkAlive()<=0||(*it)->getPosition().y>=screenY)
        {
            if((*it)->canDelete())
            {
                delete *it;
                allEnemy.erase(it);
                it--;
                Score++;
                //if((*it)->getType()==normal)
                  //  Score++;
                //else if((*it)->getType()==elite)
                  //  Score=Score+3;
                //else if((*it)->getType()==boss)
                    //Score=Score+10;
            }
        }

    }

    //mPlayer.deleteDie();
}
