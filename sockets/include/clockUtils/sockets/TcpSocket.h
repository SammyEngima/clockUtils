#ifndef __SOCKETS_TCPSOCKET_H__
#define __SOCKETS_TCPSOCKET_H__

#include "clockUtils/sockets/socketsParameters.h"
#include "clockUtils/errors.h"

#include <cstdint>
#include <functional>
#include <string>
#include <vector>

namespace clockUtils {
namespace sockets {

class CLOCK_SOCKETS_API TcpSocket {
public:
	typedef std::function<void(TcpSocket &)> acceptCallback;

	TcpSocket();

	~TcpSocket();

	ClockError listen(uint16_t listenPort, unsigned int maxParallelConnections, bool acceptMultiple, const acceptCallback & acb); // bind, listen, [accept]+
	
	ClockError connect(const std::string & remoteIP, uint16_t remotePort, unsigned int timeout);
	
	void close();
	
	std::string getRemoteIP() const;
	
	uint16_t getRemotePort() const;
	
	static std::pair<std::string, std::string> enumerateLocalIPs();

	std::string getLocalIP() const;

	std::string getPublicIP() const;

	uint16_t getLocalPort() const;
	
	ClockError writePacket(const char * str, const size_t length);
	
	ClockError writePacket(const std::vector<uint8_t> & str);

	ClockError receivePacket(std::vector<uint8_t> & buffer);

	ClockError receivePacket(std::string & buffer);

	ClockError write(const char * str, size_t length);
	
	ClockError write(const std::vector<uint8_t> & str);
	
	ClockError read(std::vector<uint8_t> & buffer);

	ClockError read(std::string & buffer);	

	/* void operator<<(int a);
	
	void operator>>(int & a); */

private:
	TcpSocket(const TcpSocket &) = delete;
	TcpSocket & operator=(const TcpSocket &) = delete;
};

} /* namespace sockets */
} /* namespace clockUtils */

#endif /* __SOCKETS_TCP_SOCKET_H__ */
