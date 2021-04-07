#pragma once

#include "Th10Hook/Common.h"

#include "Th10Hook/Math/Vector2.h"

namespace th
{
	class AABB;
	class Laser;

	class OBB
	{
	public:
		OBB() = default;
		explicit OBB(const Laser& laser);

		bool collide(const AABB& other) const;

		vec2 leftTop;
		vec2 rightTop;
		vec2 leftBottom;
		vec2 rightBottom;
		vec2 axisX;	// 投影用的对称轴，单位向量
		vec2 axisY;
	};
}
