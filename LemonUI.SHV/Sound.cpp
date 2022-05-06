#include "pch.h"

#include "Sound.hpp"

namespace LemonUI
{
	Sound::Sound(const char* name, const char* ref) : m_name{ const_cast<char*>(name) }, m_ref{ const_cast<char*>(ref) }
	{}
	Sound::Sound(const std::string& name, const std::string& ref) : m_name{ const_cast<char*>(name.c_str()) }, m_ref{ const_cast<char*>(ref.c_str()) }
	{}

	std::string Sound::GetName() const
	{
		return this->m_name;
	}

	void Sound::SetName(const std::string& name)
	{
		this->m_name = const_cast<char*>(name.c_str());
	}

	std::string Sound::GetRef() const
	{
		return this->m_ref;
	}

	void Sound::SetRef(const std::string& ref)
	{
		this->m_ref = const_cast<char*>(ref.c_str());
	}

	void Sound::PlayFrontend()
	{
		AUDIO::PLAY_SOUND_FRONTEND(-1, this->m_name, this->m_ref, FALSE);
		AUDIO::RELEASE_SOUND_ID(AUDIO::GET_SOUND_ID());
	}
}
