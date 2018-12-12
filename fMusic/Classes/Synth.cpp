#include "Synth.h"
#include <cocos2d.h>

USING_NS_CC;

// default midi driver callback
static int midiControl(void *data, fluid_midi_event_t *event) 
{ 
	fluid_synth_handle_midi_event(data, event);
	return 0;
}

MySynth::MySynth() 
{
	initSettings();
	initSynth();
	initADriver();
	initMDriver();
	loadSF("D:\\обть\\TOUHOU INSTRUMENT + DRUM KIT.sf2");
}

MySynth::MySynth(handle_midi_event_func_t midiCallBack, void* data) : MySynth()
{
	if (mdriver != NULL)
	{
		delete_fluid_midi_driver(mdriver);
	}
	initMDriver(midiCallBack, data);
}

MySynth::~MySynth() 
{
	delete_fluid_audio_driver(adriver);
	delete_fluid_synth(synth);
	delete_fluid_settings(settings);
	delete_fluid_midi_driver(mdriver);
}

void MySynth::initSettings()
{
	settings = new_fluid_settings();
	if (fluid_settings_setstr(settings, "audio.driver", "dsound") == FLUID_FAILED) 
	{
		log("error on setting audio driver");
	}
	if (fluid_settings_setnum(settings, "synth.gain", 2.0) == FLUID_FAILED) 
	{
		log("error on setting gain");
	}
}

void MySynth::initSynth()
{
	synth = new_fluid_synth(settings);
}

void MySynth::initADriver()
{
	adriver = new_fluid_audio_driver(settings, synth);
}

void MySynth::initMDriver()
{
	mdriver = new_fluid_midi_driver(settings, midiControl, synth);
	if (mdriver == NULL)
	{
		log("no midi device connected");
	}
}

void MySynth::initMDriver(handle_midi_event_func_t callBack, void* data)
{
	mdriver = new_fluid_midi_driver(settings, callBack, data);
	if (mdriver == NULL)
	{
		log("no midi device connected");
	}
}

void MySynth::loadSF(const char* path)
{
	sfont_id = fluid_synth_sfload(synth, path, 1);
	if (sfont_id == FLUID_FAILED) 
	{
		log("oops the SoundFont file doesn't exist");
	}
}
