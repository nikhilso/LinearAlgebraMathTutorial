#ifndef MATH_EXPORTS_H
#define MATH_EXPORTS_H

#ifdef _WIN32
	#ifdef MATH_EXPORTS
		#define MATH_API __declspec(dllexport)
	#else
		#define MATH_API __declspec(dllimport)
	#endif
#else
	#define MATH_API
#endif

#endif // MATH_EXPORTS_H