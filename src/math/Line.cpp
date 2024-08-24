#include "pch.h"
#include "Vector3.h"
#include "Line.h"

namespace math_api
{
	Line::Line(const Vector3& v0, const Vector3& v1)
		: m_v0(v0)
	{
		Vector3::subtract(v1, v0, m_dir);
		m_dir.normalize();
	}

	Line::Line(const Line& other)
		: m_v0(other.m_v0)
		, m_dir(other.m_dir)
	{
	}

	Line& Line::operator=(const Line& other)
	{
		m_v0 = other.m_v0;
		m_dir = other.m_dir;
		return *this;
	}

	Line::Line(Line&& other) noexcept
		: m_v0(std::move(other.m_v0))
		, m_dir(std::move(other.m_dir))
	{
	}

	Line& Line::operator=(Line&& other) noexcept
	{
		if (this != &other)
		{
			m_v0 = std::move(other.m_v0);
			m_dir = std::move(other.m_dir);
		}
		return *this;
	}

	bool Line::intersect(const Line& other, Vector3& intersectionPoint) const
	{
		return false;
	}

	bool Line::intersect(const Line& line1, const Line& line2, Vector3& intersectionPoint)
	{
		//math_api::Vector3 v10(0.0f, 0.0f, 2001.34f);
		//math_api::Vector3 v11(101.32f, 101.32f, 2001.34f);
		//math_api::Vector3 dir1;
		//math_api::Vector3::subtract(v11, v10, dir1);
		//dir1.normalize();
		////Second line
		//math_api::Vector3 v20(101.32f, 0.0f, 2001.34f);
		//math_api::Vector3 v21(0.0f, 101.32f, 2001.34f);
		//math_api::Vector3 dir2;
		//math_api::Vector3::subtract(v21, v20, dir2);
		//dir2.normalize();

		//Get the cross product of both line directions
		math_api::Vector3 crossProd;
		math_api::Vector3::cross(line1.m_dir, line2.m_dir, crossProd);
		//If magnitude of cross product is zero, then lines are parallel and there is no intersection
		auto magniSq = math_api::Vector3::dot(crossProd, crossProd);
		//There might be some possible line intersection
		if (magniSq > FLT_TOLERANCE)
		{
			math_api::Vector3 lineOriginDiff(line2.m_v0), vLine1Cross, vLine2Cross;
			lineOriginDiff.subtract(line1.m_v0);
			math_api::Vector3::cross(lineOriginDiff, line1.m_dir, vLine1Cross);
			math_api::Vector3::cross(lineOriginDiff, line2.m_dir, vLine2Cross);
			auto t1 = vLine2Cross.dot(crossProd) / magniSq;
			auto t2 = vLine1Cross.dot(crossProd) / magniSq;

			math_api::Vector3 closestPt1(line1.m_dir);
			closestPt1.multiply(t1);
			closestPt1.add(line1.m_v0);

			math_api::Vector3 closestPt2(line2.m_dir);
			closestPt2.multiply(t2);
			closestPt2.add(line2.m_v0);

			closestPt1.subtract(closestPt2);
			auto closestDist = closestPt1.magnitude();
			if (closestDist < FLT_TOLERANCE)
			{
				//Lines are intersecting
				intersectionPoint = closestPt2;
				return true;
			}
		}

		return false;
	}
}