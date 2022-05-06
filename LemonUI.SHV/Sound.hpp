#pragma once
#include <string>

namespace LemonUI
{
	class Sound
	{
	private:
		char* m_name = nullptr;
		char* m_ref = nullptr;

	public:
		Sound(const char* name, const char* ref);
		Sound(const std::string& name, const std::string& ref);

		std::string GetName() const;
		void SetName(const char* name);
		void SetName(const std::string& name);
		std::string GetRef() const;
		void SetRef(const char* ref);
		void SetRef(const std::string& ref);

		void PlayFrontend();
	};
}
