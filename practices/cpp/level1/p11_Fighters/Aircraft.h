#pragma once
#ifndef AIRCRAFT_H_
#define AIRCRAFT_H_
class Aircraft {
public:
	enum Type{Eagle,Raptor};
private:
	Type mType;
public:
	explicit Aircraft(Type type);
};
#endif // !AIRCRAFT_H_
