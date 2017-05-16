#pragma once
#ifndef RESOURSEHOLDER_H_
#define RESOURSEHOLDER_H_
#include"YOUneedTHIS.h"
namespace Resourse
{
	enum identifier { Landscape,Airplane,Missile };
}

template <typename Resourse,typename Identifier>
class ResourseHolder
{
private:
	std::map<Identifier, std ::unique_ptr<Resourse>> mResourseMap;
public:
	void load(Identifier id, const std::string filename);
	Resourse& get(Identifier id);
	const Resourse& get(Identifier id) const;
};
template<typename Resourse, typename Identifier>
inline void ResourseHolder<Resourse, Identifier>::load(Identifier id, const std::string filename)
{
	std::unique_ptr<Resourse> resourse(new Resourse());
	if (!resourse->loadFromFile(filename))
	{
		throw std::runtime_error("Failed to load " + filename);
	}
	mResourseMap.insert(std::make_pair(id, std::move(resourse)));
}

template<typename Resourse, typename Identifier>
inline Resourse & ResourseHolder<Resourse, Identifier>::get(Identifier id)
{
	auto found = mResourseMap.find(id);
	return *found->second;
	// TODO: insert return statement here
}

template<typename Resourse, typename Identifier>
inline const Resourse & ResourseHolder<Resourse, Identifier>::get(Identifier id) const
{
	auto found = mResourseMap.find(id);
	return *found->second;
	// TODO: insert return statement here
}
#endif