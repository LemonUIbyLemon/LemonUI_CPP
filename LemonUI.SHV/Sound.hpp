#pragma once
#include <string>

namespace LemonUI
{
	class Sound
	{
	public:
		Sound(const std::string& set, const std::string& file);

		std::string GetSet();
		void SetSet(const std::string& set);
		std::string GetFile();
		void SetFile(const std::string& file);

		void PlayFrontend() const;

	private:
		std::string set;
		std::string file;
	};
}
