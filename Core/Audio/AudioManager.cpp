#include "AudioManager.h"
#include "..\Engine.h"

#include <fstream>

extern Rocket::Engine *engine;

namespace Rocket
{

AudioManager::AudioManager()
{
	for(int i=0; i<10; i++)
	{
		this->sound[i] = NULL;
	}

	for(int i=0; i<2; i++)
	{
		this->music[i] = NULL;
	}

	this->musicVolume = 0;
	this->soundVolume = 0;
}

AudioManager::~AudioManager()
{
}

void AudioManager::setSoundVolume(int soundVolume)
{
	this->soundVolume = soundVolume;
}

void AudioManager::setMusicVolume(int musicVolume)
{
	this->musicVolume = musicVolume;
}


bool AudioManager::loadSound(const char *filename)
{
	if ( !engine->isAudioEnabled() )
	{
		return false;
	}

	sound[0] = Mix_LoadWAV( filename );

	if ( sound[0] == NULL )
	{
		return false;
	}

	return true;
}

bool AudioManager::loadMusic(const char *filename)
{
	if ( !engine->isAudioEnabled() )
	{
		return false;
	}

	music[0] = Mix_LoadMUS( filename );

	if ( music[0] == NULL )
	{
		std::ofstream myfile;
		myfile.open("error.txt");
		myfile << Mix_GetError() << " " << filename;
		myfile.close();
		exit ( 1000001 );
		return false;
	}

	return true;
}


void AudioManager::playSound(int sound)
{
	Mix_Volume(-1, soundVolume);

	Mix_PlayChannel(-1, this->sound[0], 0);
}

void AudioManager::playMusic(int music)
{
	if ( engine->isAudioEnabled() )
	{
		Mix_PlayMusic( this->music[0], -1 );
		Mix_VolumeMusic(musicVolume);
	}
}

void AudioManager::playMusicOnce()
{
	if ( engine->isAudioEnabled() )
	{
		Mix_PlayMusic( music[0], 0 );
		Mix_VolumeMusic(musicVolume);
	}
}


void AudioManager::pause()
{
	if ( engine->isAudioEnabled() )
	{
		Mix_PauseMusic();
	}
}

void AudioManager::resume()
{
	if ( engine->isAudioEnabled() )
	{
		Mix_ResumeMusic();
	}
}

void AudioManager::stopMusic()
{
	if ( engine->isAudioEnabled() )
	{
		Mix_HaltMusic();
	}
}

void AudioManager::fadeMusic()
{
	if ( engine->isAudioEnabled() )
	{
		Mix_FadeOutMusic( 3500 );
	}
}


void AudioManager::free()
{
	for (int i=0; i<10; i++)
	{
		if ( this->sound != NULL )
		{
			Mix_FreeChunk(sound[i]);
			sound[i] = NULL;
		}
	}

	for (int i=0; i<2; i++)
	{
		if (music[i] != NULL)
		{
			Mix_HaltMusic();
			SDL_Delay(5);
			Mix_FreeMusic(music[i]);
			music[i] = NULL;
		}
	}

	Mix_CloseAudio();
}

void AudioManager::destroy()
{
	this->free();
}

} //end namespace Rocket