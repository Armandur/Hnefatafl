/*!
 * \file Printable.hpp
 *
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 *
 * Declaration of abstract class. Implements std::string toString() function
 */
#ifndef PRINTABLE_H
#define PRINTABLE_H

#include <string>

/*!
 * \class Printable
 *
 * \brief Abstract class implementing std::string toString() functionality
 *
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 */
class Printable
{
	public:
		//! Display information about the object
		virtual std::string toString() =0;
};

#endif