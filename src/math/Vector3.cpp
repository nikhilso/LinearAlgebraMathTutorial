#include "pch.h"
#include "Vector3.h"

namespace math_api
{
    Vector3::Vector3(float x, float y, float z)
    {
        m_values[0] = x;
        m_values[1] = y;
        m_values[2] = z;
    }

    Vector3::Vector3(const Vector3& other)
    {
        m_values[0] = other.m_values[0];
        m_values[1] = other.m_values[1];
        m_values[2] = other.m_values[2];
    }

    Vector3& Vector3::operator=(const Vector3& other)
    {
        m_values[0] = other.m_values[0];
        m_values[1] = other.m_values[1];
        m_values[2] = other.m_values[2];
        return *this;
    }

    Vector3::Vector3(Vector3&& other) noexcept
		: m_values{ *other.m_values }
    {
    }

    Vector3& Vector3::operator=(Vector3&& other) noexcept
    {
        if (this != &other)
        {
            m_values[0] = other.m_values[0];
            m_values[1] = other.m_values[1];
            m_values[2] = other.m_values[2];
        }
		return *this;
    }

    float& Vector3::operator[](int index)
    {
        return m_values[index];
    }

    const float& Vector3::operator[](int index) const
    {
        return m_values[index];
    }

    float Vector3::magnitude() const
    {
        auto dotProd = dot(*this, *this);
        return std::sqrt(dotProd);
    }

    void Vector3::normalize() 
    {
        auto mag = magnitude();
		divide(mag);
    }

    float Vector3::dot(const Vector3& v)
    {
		return Vector3::dot(*this, v);
    }

    float Vector3::dot(const Vector3& v1, const Vector3& v2)
    {
		return (v1[0] * v2[0]) + (v1[1] * v2[1]) + (v1[2] * v2[2]);
    }

    void Vector3::add(const Vector3& v)
    {
        Vector3::add(*this, v, *this);
    }

    void Vector3::add(const Vector3& v1, const Vector3& v2, Vector3& out)
    {
        out[0] = v1[0] + v2[0];
        out[1] = v1[1] + v2[1];
        out[2] = v1[2] + v2[2];
    }

    void Vector3::subtract(const Vector3& v)
    {
        Vector3::subtract(*this, v, *this);
    }

    void Vector3::divide(float scaler)
    {
		Vector3::divide(*this, scaler, *this);
    }

    void Vector3::multiply(float scaler)
    {
        Vector3::multiply(*this, scaler, *this);
    }

    void Vector3::multiply(const Vector3& v1, float scaler, Vector3& out)
    {
        out[0] = v1[0] * scaler;
        out[1] = v1[1] * scaler;
        out[2] = v1[2] * scaler;
    }

    void Vector3::subtract(const Vector3& v1, const Vector3& v2, Vector3& out)
    {
        out[0] = v1[0] - v2[0];
        out[1] = v1[1] - v2[1];
        out[2] = v1[2] - v2[2];
    }

    void Vector3::divide(const Vector3& v1, float scaler, Vector3& out)
    {
		out[0] = v1[0] / scaler;
		out[1] = v1[1] / scaler;
		out[2] = v1[2] / scaler;
    }

    void Vector3::cross(const Vector3& v1, const Vector3& v2, Vector3& out)
    {
        out[0] = v1[1] * v2[2] - v1[2] * v2[1];
        out[1] = v1[2] * v2[0] - v1[0] * v2[2];
        out[2] = v1[0] * v2[1] - v1[1] * v2[0];
    }
}