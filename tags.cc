#include <string>
#define TAGLIB_STATIC
#include <taglib/fileref.h>
#include "tags.hh"

std::string getTitle(std::string& path){
    TagLib::FileRef f(path.c_str());
    TagLib::String title = f.tag()->title();
    
    if(title == ""){
        return std::string("No Title");
    }
    
    return title.to8Bit();
}

std::string getArtist(std::string& path){
    TagLib::FileRef f(path.c_str());
    TagLib::String artist = f.tag()->artist();
    
    if(artist == ""){
        return std::string("No Artist");
    }
        
    return artist.to8Bit();
}