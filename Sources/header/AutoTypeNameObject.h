#pragma once
#include <string>
#include <typeinfo>

class AutoTypeNameObject {
public:
	virtual ~AutoTypeNameObject() = default;
	virtual std::string GetTypeName() const {
		return typeid(*this).name();
	}
};
