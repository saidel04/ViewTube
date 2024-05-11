#include "ChannelList.h"

ChannelList::ChannelList() {
    numChannels = 0;
    channels = new Channel*[MAX_CHANNELS];
}

ChannelList::~ChannelList() {
    for (int i = 0; i < numChannels; ++i) {
        delete channels[i];
    }
    delete [] channels;
}

bool ChannelList::addChannel(Channel* c) {
    if (isFull()) return false;
    channels[numChannels] = c;
    ++numChannels;
    return true;
}

Channel* ChannelList::getChannel(const std::string& title) const {
    for (int i = 0; i < numChannels; ++i) {
        if (title == channels[i]->getTitle()) {
            return channels[i];
        }
    }
    return nullptr;
}

Channel* ChannelList::getChannel(int index) const {
    if (index < 0 || index >= numChannels) return nullptr;
    return channels[index];
}

Channel* ChannelList::removeChannel(const std::string& title) {
    for (int i = 0; i < numChannels; ++i) {
        if (title == channels[i]->getTitle()) {
            Channel* goner = channels[i];
            for (int j = i; j < numChannels - 1; ++j) {
                channels[j] = channels[j + 1];
            }
            --numChannels;
            return goner;
        }
    }
    return nullptr;
}

Channel* ChannelList::removeChannel(int index) {
    if (index < 0 || index >= numChannels) return nullptr;
    Channel* goner = channels[index];
    for (int i = index; i < numChannels - 1; ++i) {
        channels[i] = channels[i + 1];
    }
    --numChannels;
    return goner;
}

int ChannelList::size() const {
    return numChannels;
}

bool ChannelList::isFull() const {
    return numChannels >= MAX_CHANNELS;
}

void ChannelList::print() const {
    for (int i = 0; i < numChannels; ++i) {
        channels[i]->print();
    }
}
