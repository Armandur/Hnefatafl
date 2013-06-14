/*!
 * \file Serializer.hpp
 *
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 *
 * Declaration of Serializer class
 */
#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <string>

class Serializable;

/*!
 * \class Serializer
 *
 * \brief Static class to serializes a class that inherits Serializable
 * 
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 */
class Serializer
{
	public:
		/*!
		 * \brief Serializes serializable object
		 *
		 * \param[in] obj The object to serialize
		 * \param[out] output Stores the output of the serialization
		 * \return True on success
		 */
		static bool serialize(Serializable* obj, std::string& output);

		/*!
		 * \brief Deserializes serializable object
		 *
		 * \param[in] obj The object to deserialize
		 * \param[in] input The data to push to the object
		 * \return True on success
		 */
		static bool deSerialize(Serializable* obj, std::string& input);

	private:
		Serializer(void){}
};

#endif