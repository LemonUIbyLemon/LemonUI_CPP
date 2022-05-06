#include "pch.h"
#include "Sound.hpp"

#include <natives.hpp>

namespace LemonUI
{
	Sound::Sound(std::string set, std::string file) : set{set}, file{file}
	{}

	std::string Sound::GetSet() const
	{
		return this->set;
	}

	void Sound::SetSet(const std::string& file)
	{
		this->set = set;
	}

	std::string Sound::GetFile() const
	{
		return this->file;
	}

	void Sound::SetFile(const std::string& file)
	{
		this->file = file;
	}

	void Sound::PlayFrontend()
	{
		AUDIO::PLAY_SOUND_FRONTEND(-1, file.c_str(), set.c_str(), FALSE);
		AUDIO::RELEASE_SOUND_ID(AUDIO::GET_SOUND_ID());
	}
}
