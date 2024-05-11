#ifndef CHANNEL_H
#define CHANNEL_H

#include "VideoList.h"
#include <string>

class Channel {
public:
    Channel(const std::string& title, const std::string& owner);
    Channel(const Channel& other); 

    // Member functions
    std::string getTitle() const;
    std::string getOwner() const;
    bool lessThan(const Channel& other) const;
    bool addVideo(const std::string& title, const std::string& content, const Date& date);
    bool removeVideo(int index);
    int getNumVideos() const;
    void print() const;
    void printVideos() const;
    void playVideo(int index);

private:
    std::string title;
    std::string owner;
    VideoList videoList; 
};

#endif 
