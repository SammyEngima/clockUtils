#ifndef __CLOCKERRORS_H__
#define __CLOCKERRORS_H__

namespace clockUtils {

enum class ClockError {
	SUCCESS,
	// general
	NOT_READY,
	TIMEOUT,
	// sockets
	INVALID_IP,
	INVALID_PORT,
	CONNECTION_FAILED,
	//
	ERROR_COUNT
};

} /* namespace clockUtils */

#endif /* __CLOCKERRORS_H__ */