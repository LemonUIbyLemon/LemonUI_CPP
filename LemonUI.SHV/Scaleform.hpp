#pragma once
#include "IScaleform.hpp"
#include "Vectors.hpp"

#include <string>

namespace LemonUI
{
	class Scaleform : public IScaleform
	{
	public:
		Scaleform(const std::string& name, const Vec2& pos, const Vec2& size);
		Scaleform(const std::string& name);
		~Scaleform();

		void Set(const Vec2& pos, const Vec2& size);

		bool IsValid() const;
		bool IsLoaded() const;

		void CallFunction(const std::string& name) const;

		void StartFunction(const std::string& name) const;

		void PushParam(const std::string& param) const;
		void PushParam(const int& param) const;
		void PushParam(const float& param) const;
		void PushParam(const bool& param) const;

		void FinishFunction() const;

		void DrawFullScreen() const override;
		void Draw() const override;

	private:
		int m_handle = 0;

		Vec2 m_pos{};
		Vec2 m_size{};
	};
}