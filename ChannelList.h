#ifndef CHANNELLIST_H
#define CHANNELLIST_H

#include "Channel.h"
#include "defs.h"

class ChannelList {
    
    public:
        ChannelList();
        ~ChannelList();
        bool addChannel(Channel*);
        Channel* getChannel(const std::string& title) const;
        Channel* getChannel(int) const;
        Channel* removeChannel(const std::string& title);
        Channel* removeChannel(int);
        int size() const;
        bool isFull() const;
        void print() const;

    private:
        int numChannels;
        Channel** channels;
};

#endif
