#ifndef GSTPLAYER_H_
#define GSTPLAYER_H_

#include "gst/gst.h"
#include <unistd.h>
#include <string>
#include <cstring>
#include "utils.h"

const unsigned int VIDEO = 1;
const unsigned int CAMERA = 2;

void on_pad_added(GstElement *src, GstPad *src_pad, gpointer sink);

class GstPlayer
{
public:
	GstPlayer();
	~GstPlayer();
	void play();
	void pause();
	void stop();
	void destroy();
	GstBus* get_bus();
	void set_mode(unsigned int newMode);
	float get_fps();

private:
	void init_pipeline();
    void check_configuration();
    unsigned int mode;
    bool accelerated;
	GstElement *pipeline;
	GstBus *bus;
	GstElement *videorate;
};

#endif /* GSTPLAYER_H_ */
