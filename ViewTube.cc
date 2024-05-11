#include "ViewTube.h"

ViewTube::ViewTube() {
    channelList = new ChannelList();
}

ViewTube::~ViewTube() {
    delete channelList;
}

bool ViewTube::addChannel(const std::string& title, const std::string& owner) {
    Channel* newChannel = new Channel(title, owner);
    if (!channelList->addChannel(newChannel)) {
        delete newChannel;
        std::cerr << "Error: Could not add channel. List might be full." << std::endl;
        return false;
    }
    return true;
}

bool ViewTube::deleteChannel(int index) {
    if (channelList->removeChannel(index) == nullptr) {
        std::cerr << "Error: No such channel to delete." << std::endl;
        return false;
    }
    return true;
}

int ViewTube::getNumChannels() const {
    return channelList->size();
}

bool ViewTube::addVideo(const std::string& channelTitle, const std::string& videoTitle, const std::string& content, const Date& date) {
    int channelIndex = findChannelIndex(channelTitle);
    if (channelIndex == -1) {
        std::cerr << "Error: Channel with title '" << channelTitle << "' not found." << std::endl;
        return false;
    }
    return channelList->getChannel(channelIndex)->addVideo(videoTitle, content, date);
}

int ViewTube::findChannelIndex(const std::string& channelTitle) const {
    for (int i = 0; i < channelList->size(); i++) {
        if (channelList->getChannel(i)->getTitle() == channelTitle) {
            return i;
        }
    }
    return -1; 
}

bool ViewTube::deleteVideo(int channelIndex, int videoIndex) {
    Channel* channel = channelList->getChannel(channelIndex);
    if (channel == nullptr) {
        std::cerr << "Error: Channel does not exist." << std::endl;
        return false;
    }
    return channel->removeVideo(videoIndex);
}

void ViewTube::download(int channelIndex, std::ostream& out) {
    Channel* channel = channelList->getChannel(channelIndex);
    if (channel == nullptr) {
        out << "Error: Channel does not exist." << std::endl;
        return;
    }
    channel->print();
}

void ViewTube::printChannels() const {
    channelList->print();
}

void ViewTube::printChannel(int index) const {
    Channel* channel = channelList->getChannel(index);
    if (channel == nullptr) {
        std::cerr << "Error: Channel does not exist." << std::endl;
        return;
    }
    channel->printVideos();
}

Channel* ViewTube::getChannel(int index) const {
    return channelList->getChannel(index);
}

void ViewTube::playVideo(int channelIndex, int videoIndex) {
    Channel* channel = channelList->getChannel(channelIndex);
    if (channel == nullptr) {
        std::cerr << "Error: Channel does not exist." << std::endl;
        return;
    }
    channel->playVideo(videoIndex);
}
