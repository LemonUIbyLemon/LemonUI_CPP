#pragma once
#include <string>

namespace LemonUI
{
	class Sound
	{
	private:
		std::string set;
		std::string file;

	public:
		Sound(std::string set, std::string file);

		std::string GetSet() const;
		void SetSet(const std::string& file);
		std::string GetFile() const;
		void SetFile(const std::string& file);

		void PlayFrontend();
	};
}
