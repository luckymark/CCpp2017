#ifndef BOOK_STRINGHELPERS_HPP
#define BOOK_STRINGHELPERS_HPP

#include <sstream>

// Since std::to_string doesn't work on MinGW we have to implement
// our own to support all platforms.
template <typename T>
std::string toString(const T& value);


template <typename T>
std::string toString(const T& value)
{
	std::stringstream stream;
	stream << value;
	return stream.str();
}
#endif // BOOK_STRINGHELPERS_HPP
