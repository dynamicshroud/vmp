#ifndef TAGS_HH
#define TAGS_HH

struct Metadata
{
    std::string artist;
    std::string title;
};

std::string getTitle(std::string&);
std::string getArtist(std::string&);

#endif