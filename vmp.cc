// VMP - Vortex's Music Player

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>

#include "config.hh"
#include "tags.hh"

int main(int argc, char** argv){
    if(argc < 2){
        std::cout << "Usage: vmp [file]" << std::endl;
        return 1;
    }
    
    // todo: create playlist vector
    std::string path(argv[1]);    
    
    sf::RenderWindow win(sf::VideoMode(Config::SCREEN_X, Config::SCREEN_Y), "VMP 1.0");
    sf::Font font;
    if(!font.loadFromFile(Config::FONT_DIR)){
        std::cout << "Cannot load font" << std::endl;
    }
    
    sf::SoundBuffer buf;
    if(!buf.loadFromFile(path)){
        std::cout << "Cannot load music file" << std::endl;
    }
  
    sf::Sound music;
    music.setBuffer(buf);
    music.play();
    
    std::cout << "Artist: " << getArtist(path) << std::endl;
    std::cout << "Title: " << getTitle(path) << std::endl;
                
    while(win.isOpen()){
       sf::Event e;
       std::string vol = "Volume: ";
       vol.append(std::to_string(static_cast<int>(std::floor(music.getVolume()))));
       vol.append("%");

       while(win.pollEvent(e)){
           if(e.type == sf::Event::Closed){
               win.close();
           }
           if(e.type == sf::Event::KeyPressed){
               if(e.key.code == sf::Keyboard::Space){
                    if(music.getStatus() == sf::Sound::Playing){
                        music.pause();
                    } else {
                        music.play();
                    }
               }
               if(e.key.code == sf::Keyboard::Right){
                    if(music.getStatus() == sf::Sound::Stopped){
                        break;
                    } else {
                        music.setPlayingOffset(sf::seconds(music.getPlayingOffset().asSeconds() + 5.0f));
                    }
               }
               if(e.key.code == sf::Keyboard::Left){
                    if(music.getPlayingOffset().asSeconds() < 5){
                        break;
                    } else {
                        music.setPlayingOffset(sf::seconds(music.getPlayingOffset().asSeconds() - 5.0f));
                    }
               }
               if(e.key.code == sf::Keyboard::Up){
                    music.setVolume(music.getVolume() + 5.0f);
                    if(music.getVolume() > 100){
                        music.setVolume(100.0f);
                    }
               }
               if(e.key.code == sf::Keyboard::Down){
                    music.setVolume(music.getVolume() - 5.0f);
                    if(music.getVolume() < 5){
                        music.setVolume(0.0f);
                    }
                    if(music.getVolume() == 0){
                        break;
                    }
               }
           }
       }
       if(music.getStatus() == sf::Sound::Stopped){
           win.close();
       }
       
       int totals = static_cast<int>(music.getPlayingOffset().asSeconds());
       int seconds = totals % 60;
       int minutes = (totals % 3600) / 60;
       int hours = totals / 3600;
       
       std::string stats = "Time: ";
       stats.append(std::to_string(hours));
                    stats+="h:";
                    stats.append(std::to_string(minutes));
                    stats+="m:";
                    stats.append(std::to_string(static_cast<int>(seconds)));
                    stats += "s";
                    
       stats.append("\n");
       stats.append(vol);
       stats.append("\n");
       stats.append("Artist: "); 
       stats += getArtist(path); 
       stats += "\n"; 
       stats += "Title: "; 
       stats += getTitle(path); 
       stats += "\n";
       
       sf::Text s(stats, font, 30);
       s.setFillColor(Config::TXT_COLOR);
              
       win.clear(Config::BG_COLOR);
       win.draw(s);
       win.display();       
    }
    return 0;
}
