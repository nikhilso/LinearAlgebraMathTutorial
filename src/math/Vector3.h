#pragma once

namespace math_api
{
    class MATH_API Vector3
    {
    public:
        // Constructor
        Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);

        // Copy constructor
        Vector3(const Vector3& other);

        // Assignment operator
        Vector3& operator=(const Vector3& other);

        // Move constructor
        Vector3(Vector3&& other) noexcept;

        // Move assignment operator
        Vector3& operator=(Vector3&& other) noexcept;

        // Operator overloading for array access
        float& operator[](int index); 

        // Operator overloading for array access
        const float& operator[](int index) const;

        // Function to find the magnitude of the vector
        float magnitude() const;

		// Function to normalize the vector
		void normalize();

        // Function to calculate the dot product of this vector with another vector
        // and store the result in this vector
        float dot(const Vector3& v);

        // Function to add another vector to this vector
        // and store the result in this vector
        void add(const Vector3& v);

        // Function to subtract another vector from this vector
        // and store the result in this vector
        void subtract(const Vector3& v);

		// Function to divide this vector by a scaler
		void divide(float scaler);
        
        // Function to multiple this vector by a scaler
        void multiply(float scaler);

		// Calculate the dot product of two vectors and return the result
		static float dot(const Vector3& v1, const Vector3& v2);

        // Add one vector to another and store the result in the output vector
        static void add(const Vector3& v1, const Vector3& v2, Vector3& out);

        // subtract one vector from another and store the result in the output vector
        static void subtract(const Vector3& v1, const Vector3& v2, Vector3& out);
    
		// divide a vector by a scaler and store the result in the output vector
        static void divide(const Vector3& v1, float scaler, Vector3& out);

        // multiple a vector by a scaler and store the result in the output vector
        static void multiply(const Vector3& v1, float scaler, Vector3& out);

        // cross product of 2 normalized vectors
        static void cross(const Vector3& v1, const Vector3& v2, Vector3& out);

    private:
        float m_values[3]; // Member variable for float array of size 3
    };
}
