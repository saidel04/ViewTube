#ifndef VIEWTUBE_H
#define VIEWTUBE_H

#include "ChannelList.h"
#include <iostream>

class ViewTube {
public:
    ViewTube();
    ~ViewTube();

    Channel* getChannel(int index) const;
    bool addChannel(const std::string& title, const std::string& owner);
    bool deleteChannel(int index);
    int getNumChannels() const;

    bool addVideo(const std::string& channelTitle, const std::string& videoTitle, const std::string& content, const Date& date);
    bool deleteVideo(int channelIndex, int videoIndex);

    void download(int channelIndex, std::ostream& out);

    void printChannels() const;
    void printChannel(int index) const;
    void playVideo(int channelIndex, int videoIndex);

private:
    int findChannelIndex(const std::string& channelTitle) const;
    ChannelList* channelList;
};

#endif 
