#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define FLT_TOLERANCE 0.0001f

namespace mathTests
{
	TEST_CLASS(LineTests)
	{
	public:
		
		TEST_METHOD(MagnitudeTest)
		{
			math_api::Vector3 v0(1.0f, 1.0f, 1.0f);
			math_api::Vector3 vZ(1.0f, 1.0f, 2.0f);
			math_api::Vector3 vDiff;
			math_api::Vector3::subtract(vZ, v0, vDiff);
			Assert::AreEqual(vDiff.magnitude(), 1.0f, FLT_TOLERANCE);
		}

		TEST_METHOD(ParallelVectors)
		{
			math_api::Vector3 v0(1.0f, 0.0f, 0.0f);
			math_api::Vector3 v1(-1.0f, 0.0f, 0.0f);
			auto dotProd = math_api::Vector3::dot(v0,v1);
			Assert::AreEqual( std::fabsf(dotProd), 1.0f, FLT_TOLERANCE);
		}

		TEST_METHOD(PerpendicularVectors)
		{
			math_api::Vector3 v0(1.0f, 0.0f, 0.0f);
			math_api::Vector3 v1(0.0f, -1.0f, 0.0f);
			auto dotProd = math_api::Vector3::dot(v0, v1);
			Assert::AreEqual( std::fabsf(dotProd), 0.0f, FLT_TOLERANCE);
		}

		TEST_METHOD(LineIntersection)
		{
			math_api::Line line1( math_api::Vector3(0.0f, 0.0f, 2001.34f), math_api::Vector3(101.32f, 101.32f, 2001.34f));
			math_api::Line line2( math_api::Vector3(101.32f, 0.0f, 2001.34f), math_api::Vector3(0.0f, 101.32f, 2001.34f));
			math_api::Vector3 intersectionPt;
			auto intersected = math_api::Line::intersect(line1, line2, intersectionPt);
			Assert::IsTrue(intersected);
			Assert::AreEqual(intersectionPt[0], 50.66f, FLT_TOLERANCE);
			Assert::AreEqual(intersectionPt[1], 50.66f, FLT_TOLERANCE);
			Assert::AreEqual(intersectionPt[2], 2001.34f, FLT_TOLERANCE);
		}
	};
}
