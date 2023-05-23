#include "GstPlayer.h"
#include <iostream>
#include <fstream>

/**
 * Create instance of GstPlayer for playing a video
 * @param play_unaccelerated	true if you should play with acceleration, false otherwise
 */
GstPlayer::GstPlayer()
{
	mode = VIDEO;
	gst_init(NULL, NULL);
	init_pipeline();
}

/**
 * Destroy instance of GstPlayer
 */
GstPlayer::~GstPlayer()
{
}

/**
 * Play video
 */
void
GstPlayer::play()
{
	gst_element_set_state(pipeline, GST_STATE_PLAYING);
}

/**
 * Pause video
 */
void
GstPlayer::pause()
{
	gst_element_set_state(pipeline, GST_STATE_PAUSED);
}

/**
 * Stop video
 */
void
GstPlayer::stop()
{
	destroy();
	init_pipeline();
}

/**
 * Destroy this instance of GstPlayer by removing all references to components.
 * Necessary step in some cases before starting the stream after a STOP, so
 * this should be called whenever restarting the stream
 */
void
GstPlayer::destroy()
{
	gst_element_set_state(pipeline, GST_STATE_NULL);
	//gst_object_unref(videorate);
	gst_object_unref(pipeline);
	gst_object_unref(bus);
}

/**
 * Provide reference to pipeline bus for monitoring pipe status
 * @return	reference to pipeline bus
 */
GstBus*
GstPlayer::get_bus()
{
	return bus;
}


/**
 * Initialize pipeline based on configuration file
 */
void
GstPlayer::init_pipeline()
{
	const int MAX_LENGTH = 500;
	char pipeline_string[MAX_LENGTH];

	// Retrieve pipeline configuration
    /*if (mode == VIDEO)
		get_config("pipeline", pipeline_string);
	else
		get_config("pipeline_camera", pipeline_string);
*/
	printf("Pipeline string is: %s\n", pipeline_string);

	// Create pipeline from configuration string
	pipeline = gst_parse_launch(pipeline_string, NULL);

	// Find the videorate element to be used to calculate FPS
	GstElement *item;
	char *ename;
	bool done = FALSE;

	GstIterator *it = gst_bin_iterate_elements((GstBin *) pipeline);
	while (!done) {
		switch (gst_iterator_next(it, (void**) &item)) {

		case GST_ITERATOR_RESYNC:
			gst_iterator_resync(it);
			break;
		case GST_ITERATOR_ERROR:
		case GST_ITERATOR_DONE:
			done = TRUE;
			break;

		case GST_ITERATOR_OK:

			ename = gst_element_get_name(item);

			if (strlen(ename) < strlen("videorate"))
				break;
			if (memcmp(ename, "videorate", strlen("videorate")) == 0) {
				videorate = item;
				done = true;
			}
				break;
		}
		//g_value_unset((GValue *) item);
	}
	gst_iterator_free(it);

	// Retrieve pipeline signal bus
	bus = gst_pipeline_get_bus(GST_PIPELINE(pipeline));

	// Set pipeline to ready
	gst_element_set_state(pipeline, GST_STATE_READY);

}

/**
 * Set whether this video should play with acceleration or not
 * By default, this resets the pipeline, so do not call this midstream.
 * @param newMode	new mode of play, whether accelerated, nonaccelerated,
 * 	camera, or other
 */
void
GstPlayer::set_mode(unsigned int newMode)
{
	mode = newMode;
	//stop();
    init_pipeline();    //TODO nahrazeno jiri - stop ma destroy - delalo blikani
}

/*
 * calculate "instanteous" FPS =
 * number of frames passed since last called / seconds since last called
 */
#include <QTime>
QTime last_time;
int last_out, last_drop;
float
GstPlayer::get_fps()
{
	if(videorate == NULL)
		return 0;

	// get cumulative frames out since beginning of video
	guint64 out, drop;
	g_object_get(G_OBJECT(videorate), "out", &out, "drop", &drop, (void *)NULL);

	// if first call, set time, record frames
	QTime now = QTime::currentTime();
	if(last_time.isNull()) {
		last_time = now;
		last_out = out;
		last_drop = drop;
	}

	// elapsed milliseconds since last call (or 0 if first call)
	float elapsed_ms = last_time.msecsTo(now);

	// frames out since last called
	float frames = out - last_out;

	float fps = frames / (elapsed_ms / 1000.0);

	last_out = out;
	last_drop = drop;
	last_time = now;

	return fps;
}
