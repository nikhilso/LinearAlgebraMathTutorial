#pragma once

namespace math_api
{
    class MATH_API Line
    {
    public:
        // Constructor
        Line(const Vector3& v0, const Vector3& v1);

        // Copy constructor
        Line(const Line& other);

        // Assignment operator
        Line& operator=(const Line& other);

        // Move constructor
        Line(Line&& other) noexcept;

        // Move assignment operator
        Line& operator=(Line&& other) noexcept;

		bool intersect(const Line& other, Vector3& intersectionPoint) const;

		static bool intersect(const Line& line1, const Line& line2, Vector3& intersectionPoint);

    private:
		Vector3 m_v0;
		Vector3 m_dir;
    };
}

//Minimum Distance between a Point and a Line
//https://paulbourke.net/geometry/pointlineplane/
