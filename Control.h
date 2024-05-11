
#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>
#include <vector>

#include "ViewTube.h"
#include "View.h"
#include "Client.h"

using namespace std;


class Control
{
  public:
    Control();
    
    void launch();
    

  private:
	// ViewTube functions
    void printChannels();
    void printChannel();
    void playVideo();
	  void removeChannel();
	  void removeVideo();

	// Client functions
    void downloadChannel();
    void printClientChannel();
	  void playClientVideo();

    //helper function
    void initViewTube();

    ViewTube viewTube;
    View view;
    Client client;


    const static vector<string> menu;

    // Channel information
    const static string channelTitles[5];
    const static string owners[5];

    // Video information
    const static string videoTitles[5][5];
    const static string content[5][5];
    const static Date dates[5][5];


	
};
#endif