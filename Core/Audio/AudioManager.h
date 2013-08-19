#ifndef ROCKET_AUDIO_H
#define ROCKET_AUDIO_H

#include "SDL.h"
#include "SDL_mixer.h"

namespace Rocket
{

class AudioManager
{
private:
	//TODO: dynamic sounds and music array
	Mix_Chunk *sound[10];
	Mix_Music *music[2];

	int musicVolume, soundVolume;

public:
	AudioManager();
	~AudioManager();
	void setSoundVolume(int soundVolume);
	void setMusicVolume(int musicVolume);

	bool loadSound(const char *filename);
	bool loadMusic(const char *filename);

	void playSound(int sound);
	void playMusic(int music);
	void playMusicOnce();

	void pause();
	void resume();
	void stopMusic();
	void fadeMusic();

	void free();
	void destroy();
};

}

#endif