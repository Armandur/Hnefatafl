/*!
 * \file Serializer.cpp
 *
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 *
 * Definition of serializer class
 */
#include <json/json.h>

#include "Serializer.hpp"
#include "Serializable.hpp"

bool Serializer::serialize(Serializable* obj, std::string& output)
{
	if(obj == nullptr)
	{
		return false;
	}

	Json::Value serializeRoot;
	obj->serialize(serializeRoot);
	
	Json::StyledWriter writer;
	output = writer.write(serializeRoot);

	return true;
}

bool Serializer::deSerialize(Serializable* obj, std::string& input)
{
	if(obj == nullptr)
	{
		return false;
	}

	Json::Value deserializeRoot;
	Json::Reader reader;

	if ( !reader.parse(input, deserializeRoot) )
		return false;

	obj->deSerialize(deserializeRoot);

	return true;
}