objects = main.o View.o Control.o Client.o ViewTube.o Channel.o Video.o ChannelList.o VideoList.o Date.o
testobjects = test.o View.o TestControl.o Tester.o Client.o ViewTube.o Channel.o Video.o ChannelList.o VideoList.o Date.o

all: a2 a2test

a2: $(objects)
	g++ -o a2 $(objects)

a2test: $(testobjects)
	g++ -o a2test $(testobjects)

main.o: main.cc Control.o
	g++ -c main.cc 

View.o: View.h View.cc 
	g++ -c View.cc

TestControl.o: TestControl.h TestControl.cc ViewTube.o
	g++ -c TestControl.cc

Tester.o: Tester.h Tester.cc
	g++ -c Tester.cc

Control.o: Control.h Control.cc ViewTube.o
	g++ -c Control.cc

Client.o: Client.h Client.cc ViewTube.o
	g++ -c Client.cc

ViewTube.o: ViewTube.h ViewTube.cc ChannelList.o
	g++ -c ViewTube.cc

VideoList.o: VideoList.h VideoList.cc
	g++ -c VideoList.cc

ChannelList.o: ChannelList.cc ChannelList.h Channel.o
	g++ -c ChannelList.cc

Channel.o: Channel.cc Channel.h Video.h
	g++ -c Channel.cc
	
Video.o: Video.cc Video.h Channel.h
	g++ -c Video.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

clean:
	rm -f a2 a2test *.o	

