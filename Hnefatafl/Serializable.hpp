/*!
 * \file Serializable.hpp
 *
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 *
 * Declaration of virtual baseclass for serializing classes
 */

#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <json/json.h>

/*!
 * \class Serializable
 *
 * \brief Interface for serializing classes to JSON
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 */
class Serializable
{
	public:
		//! Virtual destructor
		virtual ~Serializable(void){}

		/*!
		 * \brief Pure virtual function to serialize a class
		 * \param[in] root ...
		 */
		virtual void serialize(Json::Value& root) =0;

		/*!
		 * \brief Pure virtual function to deserialize a class
		 * \param[in] root ...
		 */
		virtual void deSerialize(Json::Value& root) =0;
};

#endif