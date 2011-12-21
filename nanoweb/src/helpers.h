/// Contains various methods which might be used throughout the whole app.

#pragma once
#ifndef IPN_HELPERS_H_Y7SNIYWW
#define IPN_HELPERS_H_Y7SNIYWW

#include <QString>

namespace ipn
{
	namespace helpers
	{

		/** The cross-platform way to access the resources:
		 */
		QString resourcePath();

		/** Returns integer x which is  0 <= x <= maxNumber.
		 */
		int limitedRand(int maxNumber);

		/** Returns the minimum of integers a and b.
		 */
		int min(int a, int b);

		/** Returns the maximum of integers a and b.
		 */
		int max(int a, int b);

		/** Returns the minimum of floats a and b.
		 */
		float minf(float a, float b);

		/** Returns the maximum of floats a and b.
		 */
		float maxf(float a, float b);

		#if defined(Q_OS_SYMBIAN)
		// on a Nokia, fonts look larger due to the high-dpi-display, so scale them down
		const float fontSizeFactor = 0.5;
		#else
		const float fontSizeFactor = 1;
		#endif

	} // namespace helpers
} // namespace ipn

#endif /* end of include guard: IPN_HELPERS_H_Y7SNIYWW */
