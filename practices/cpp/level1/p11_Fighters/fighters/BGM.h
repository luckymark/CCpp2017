#ifndef BGM_h
#define BGM_h

class BGM {
    
    
private:
    bool reset=0;
    float volume;
public:
    bool active=0;
    sf::Clock clock;
    sf::Music music;
    BGM(std::string name) {
        music.openFromFile(resourcePath()+"using/"+name+".wav");
        music.setLoop(true);
        //music.setVolume(0);
        volume=music.getVolume();
    }
    
    void reseting() {
        active=1;
        stop();
        volume=100;
        music.setVolume(volume);
    }
    
    void play() {
        if(!active){
            music.play();
            clock.restart();
            active=1;
        }
        reset=0;
    }
    void pause() {
        if(active) {
            music.pause();
            active=0;
        }
        reset=0;
    }
    void restart() {
        if(!reset) {
            stop();
            play();
            reset=1;
        }
    }
    void stop() {
        if(active) {
            music.stop();
            active=0;
        }
        reset=0;
    }
    bool go() {
        if(active) {
            if(volume>0.5){
                volume-=0.2;
                music.setVolume(volume);
                return 0;
            }
            else stop();
        }
        return 1;
    }
    
};


#endif
