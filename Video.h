#ifndef VIDEO_H
#define VIDEO_H

#include "Date.h"
#include <string>

class Video {
    public:
        Video(const std::string& title, const std::string& content, const Date& date);
        
        Video(const Video& other);

        ~Video();

        Video& operator=(const Video& other);

        std::string getTitle() const;

        bool lessThan(const Video& other) const;
        void print() const;
        void play() const;

    private:
        std::string title;
        std::string content;
        Date uploadDate;
};

#endif 
