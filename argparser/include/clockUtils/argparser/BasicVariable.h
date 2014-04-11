#ifndef __CLOCKUTILS_ARGPARSER_BASICVARIABLE_H__
#define __CLOCKUTILS_ARGPARSER_BASICVARIABLE_H__

#include "clockUtils/argparser/argParserParameters.h"

#include <sstream>
#include <string>

namespace clockUtils {
namespace argparser {

	class CLOCK_ARGPARSER_API BasicVariable {
	public:
		BasicVariable(const std::string & name, const std::string & description);

		std::string getName() const {
			return _name;
		}

		virtual bool isBool() const = 0;

		virtual bool setValue(const std::string & value) = 0;

	private:
		std::string _name;
		std::string _description;
	};

	template<typename T>
	class Variable : public BasicVariable {
	public:
		Variable(const std::string & name, const std::string & description, T * reference) : BasicVariable(name, description), _reference(reference) {
		}

		bool isBool() const {
			return false;
		}

		bool setValue(const std::string & value) {
			std::stringstream ss(value);
			return !(ss >> (*_reference)).fail();
		}

	private:
		T * _reference;
	};

	template<>
	bool Variable<bool>::isBool() const {
		return true;
	}

} /* namespace argparser */
} /* namespace clockUtils */

#endif /* __CLOCKUTILS_ARGPARSER_BASICVARIABLE_H__ */
