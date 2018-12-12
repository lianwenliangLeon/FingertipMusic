#pragma once

#ifndef __SYNTH_H__
#define __SYNTH_H__

#include <fluidsynth.h>

class MySynth {
public:
	fluid_settings_t *settings;
	fluid_synth_t *synth;
	fluid_audio_driver_t *adriver;
	fluid_midi_driver_t *mdriver;
	int sfont_id;

	MySynth();
	MySynth(handle_midi_event_func_t midiCallBack, void *data);
	~MySynth();

private:
	void initSettings();
	void initSynth();
	void initADriver();
	void initMDriver();
	void initMDriver(handle_midi_event_func_t callBack, void *data);
	void loadSF(const char *path);
};

#endif // __SYNTH_H__