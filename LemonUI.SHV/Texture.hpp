#pragma once
#include "Vectors.hpp"

#include <string>

namespace LemonUI
{
	class Texture
	{
	public:
		Texture(const std::string& dict, const std::string& name);
		Texture() = default;

		Vec2 GetSize() const;

		void Set(const std::string& dict, const std::string& name);

		void EnsureLoaded() const;

		void Render(const Vec2& pos) const;
		void Render(const Vec2& pos, const Vec2& size) const;
		void Render(const Vec2& pos, const Vec2& size, const float& heading) const;
		void Render(const Vec2& pos, const Vec2& size, const float& heading, const Vec4& color) const;

	private:
		std::string m_dict = "";
		std::string m_name = "";
	};
}