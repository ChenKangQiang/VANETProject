//
// Generated file, do not edit! Created by nedtool 4.6 from inet/transportlayer/contract/tcp/TCPCommand.msg.
//

#ifndef _INET_TCPCOMMAND_M_H_
#define _INET_TCPCOMMAND_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef INET_API
#  if defined(INET_EXPORT)
#    define INET_API  OPP_DLLEXPORT
#  elif defined(INET_IMPORT)
#    define INET_API  OPP_DLLIMPORT
#  else
#    define INET_API
#  endif
#endif

// cplusplus {{
#include "inet/networklayer/common/L3Address.h"
// }}


namespace inet {

/**
 * Enum generated from <tt>inet/transportlayer/contract/tcp/TCPCommand.msg:34</tt> by nedtool.
 * <pre>
 * //
 * // TCP command codes, sent by the application to TCP. These constants
 * // should be set as message kind on a message sent to the TCP entity.
 * //
 * // @see ~TCPCommand, ~TCPOpenCommand, ~ITCP
 * //
 * enum TcpCommandCode
 * {
 * 
 *     TCP_C_OPEN_ACTIVE = 1;   // active open (must carry ~TCPOpenCommand)
 *     TCP_C_OPEN_PASSIVE = 2;  // passive open (must carry ~TCPOpenCommand)
 *     TCP_C_SEND = 3;          // send data (set on data packet)
 *     TCP_C_CLOSE = 5;         // "I have no more data to send"
 *     TCP_C_ABORT = 6;         // abort connection
 *     TCP_C_STATUS = 7;        // request status info (TCP_I_STATUS) from TCP
 *     TCP_C_QUEUE_BYTES_LIMIT = 8; // set send queue limit (in bytes)
 *     TCP_C_READ = 9;       // send request to TCP to deliver data
 * }
 * </pre>
 */
enum TcpCommandCode {
    TCP_C_OPEN_ACTIVE = 1,
    TCP_C_OPEN_PASSIVE = 2,
    TCP_C_SEND = 3,
    TCP_C_CLOSE = 5,
    TCP_C_ABORT = 6,
    TCP_C_STATUS = 7,
    TCP_C_QUEUE_BYTES_LIMIT = 8,
    TCP_C_READ = 9
};

/**
 * Enum generated from <tt>inet/transportlayer/contract/tcp/TCPCommand.msg:53</tt> by nedtool.
 * <pre>
 * //
 * // TCP indications, sent by TCP to the application. TCP will set these
 * // constants as message kind on messages it sends to the application.
 * //
 * // @see ~TCPCommand, ~TCPStatusInfo, ~ITCP
 * //
 * enum TcpStatusInd
 * {
 * 
 *     TCP_I_DATA = 1;              // data packet (set on data packet)
 *     TCP_I_URGENT_DATA = 2;       // urgent data (set on data packet)
 *     TCP_I_ESTABLISHED = 3;       // connection established
 *     TCP_I_PEER_CLOSED = 4;       // FIN received from remote TCP
 *     TCP_I_CLOSED = 5;            // connection closed normally (via FIN exchange)
 *     TCP_I_CONNECTION_REFUSED = 6; // connection refused
 *     TCP_I_CONNECTION_RESET = 7;  // connection reset
 *     TCP_I_TIMED_OUT = 8;         // conn-estab timer went off, or max retransm. count reached
 *     TCP_I_STATUS = 9;            // status info (will carry ~TCPStatusInfo)
 *     TCP_I_SEND_MSG = 10;         // send queue abated, send more messages
 *     TCP_I_DATA_NOTIFICATION = 11; // notify the upper layer that data has arrived
 * }
 * </pre>
 */
enum TcpStatusInd {
    TCP_I_DATA = 1,
    TCP_I_URGENT_DATA = 2,
    TCP_I_ESTABLISHED = 3,
    TCP_I_PEER_CLOSED = 4,
    TCP_I_CLOSED = 5,
    TCP_I_CONNECTION_REFUSED = 6,
    TCP_I_CONNECTION_RESET = 7,
    TCP_I_TIMED_OUT = 8,
    TCP_I_STATUS = 9,
    TCP_I_SEND_MSG = 10,
    TCP_I_DATA_NOTIFICATION = 11
};

/**
 * Enum generated from <tt>inet/transportlayer/contract/tcp/TCPCommand.msg:72</tt> by nedtool.
 * <pre>
 * //
 * // Currently not in use.
 * //
 * enum TCPErrorCode
 * {
 * 
 * }
 * </pre>
 */
enum TCPErrorCode {
};

/**
 * Class generated from <tt>inet/transportlayer/contract/tcp/TCPCommand.msg:91</tt> by nedtool.
 * <pre>
 * //
 * // Control info for TCP connections. This class is to be set as control info
 * // (see cMessage::setControlInfo()) on all messages exchanged between TCP and
 * // application, in both directions. Some commands and indications
 * // (TCP_C_OPEN_xxx, TCP_I_STATUS) use subclasses.
 * //
 * // connId identifies the connection locally within the application (internally,
 * // TCP uses the (app gate index, connId) pair to identify the socket).
 * // connId is to be chosen by the application in the open command.
 * //
 * //# TODO explain userId
 * //
 * // @see ~TcpCommandCode, ~TcpStatusInd, ~TCPOpenCommand, ~TCPStatusInfo, ~ITCP
 * //
 * class TCPCommand
 * {
 *     int connId = -1;   // identifies the socket within the application
 *     int userId = -1;   // id than can be freely used by the app
 * }
 * </pre>
 */
class INET_API TCPCommand : public ::cObject
{
  protected:
    int connId_var;
    int userId_var;

  private:
    void copy(const TCPCommand& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const TCPCommand&);

  public:
    TCPCommand();
    TCPCommand(const TCPCommand& other);
    virtual ~TCPCommand();
    TCPCommand& operator=(const TCPCommand& other);
    virtual TCPCommand *dup() const {return new TCPCommand(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getConnId() const;
    virtual void setConnId(int connId);
    virtual int getUserId() const;
    virtual void setUserId(int userId);
};

inline void doPacking(cCommBuffer *b, TCPCommand& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, TCPCommand& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/transportlayer/contract/tcp/TCPCommand.msg:101</tt> by nedtool.
 * <pre>
 * //
 * // Currently not in use.
 * //
 * class TCPErrorInfo extends TCPCommand
 * {
 *     int errorCode @enum(TCPErrorCode);
 *     string messageText;
 * }
 * </pre>
 */
class INET_API TCPErrorInfo : public ::inet::TCPCommand
{
  protected:
    int errorCode_var;
    opp_string messageText_var;

  private:
    void copy(const TCPErrorInfo& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const TCPErrorInfo&);

  public:
    TCPErrorInfo();
    TCPErrorInfo(const TCPErrorInfo& other);
    virtual ~TCPErrorInfo();
    TCPErrorInfo& operator=(const TCPErrorInfo& other);
    virtual TCPErrorInfo *dup() const {return new TCPErrorInfo(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getErrorCode() const;
    virtual void setErrorCode(int errorCode);
    virtual const char * getMessageText() const;
    virtual void setMessageText(const char * messageText);
};

inline void doPacking(cCommBuffer *b, TCPErrorInfo& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, TCPErrorInfo& obj) {obj.parsimUnpack(b);}

/**
 * Enum generated from <tt>inet/transportlayer/contract/tcp/TCPCommand.msg:120</tt> by nedtool.
 * <pre>
 * //
 * // Defines what to transmit as payload in TCP segments
 * //
 * // Currently you have the following choices:
 * //   - TCP_TRANSFER_BYTECOUNT:
 * //      TCP layer will transmit byte counts only.
 * //   - TCP_TRANSFER_OBJECT:
 * //      TCP layer will transmit the copy of application packet C++ objects
 * //   - TCP_TRANSFER_BYTESTREAM:
 * //      TCP layer will transmit bytes of the application packet.
 * //
 * // See ~ITCP (the TCP layer interface) for details.
 * //
 * enum TCPDataTransferMode
 * {
 * 
 *     TCP_TRANSFER_UNDEFINED = 0;         // Invalid value
 *     TCP_TRANSFER_BYTECOUNT = 1;         // Transmit byte counts only
 *     TCP_TRANSFER_OBJECT = 2;            // Transmit the application packet C++ objects
 *     TCP_TRANSFER_BYTESTREAM = 3;        // Transmit raw bytes
 * }
 * </pre>
 */
enum TCPDataTransferMode {
    TCP_TRANSFER_UNDEFINED = 0,
    TCP_TRANSFER_BYTECOUNT = 1,
    TCP_TRANSFER_OBJECT = 2,
    TCP_TRANSFER_BYTESTREAM = 3
};

/**
 * Class generated from <tt>inet/transportlayer/contract/tcp/TCPCommand.msg:154</tt> by nedtool.
 * <pre>
 * //
 * // Control info to be used for active or passive TCP open.
 * //
 * // localAddr, remoteAddr, localPort, remotePort should be self-explanatory.
 * // localAddr is optional because TCP can learn it from IP when a packet
 * // is received from the peer; localPort is optional because TCP supports
 * // ephemeral ports.
 * //
 * // The fork parameter is used with passive open, and controls what happens
 * // when an incoming connection is received. With fork=true, it emulates
 * // the Unix accept(2) syscall semantics: a new connection structure
 * // is created for the connection (with a new connId, see in ~TCPCommand),
 * // and the connection structure with the old connId remains listening.
 * // With fork=false, all the above does not happen: the first connection
 * // is accepted (with the original connId), and further incoming connections
 * // will be refused by TCP by sending an RST segment.
 * //
 * // The dataTransferMode and tcpAlgorithmClass fields
 * // allow per-connection TCP configuration.
 * // The dataTransferMode field set the
 * // The tcpAlgorithmClass field may contain name of class subclassed from
 * // TCPAlgorithm, respectively.
 * // If not set, module parameters with similar names are used.
 * //
 * // @see ~TcpCommandCode, ~ITCP
 * //
 * class TCPOpenCommand extends TCPCommand
 * {
 *     L3Address localAddr; // may be left empty
 *     L3Address remoteAddr;// required for active open
 *     int localPort = -1;       // required for passive open
 *     int remotePort = -1;      // required for active open
 *     bool fork = false;        // used only for passive open
 *     int dataTransferMode @enum(TCPDataTransferMode); // whether to transmit C++ objects, real bytes or just byte counts. See ~TCPDataTransferMode.
 *     string tcpAlgorithmClass; // TCP congestion control algorithm; leave empty for default
 * }
 * </pre>
 */
class INET_API TCPOpenCommand : public ::inet::TCPCommand
{
  protected:
    L3Address localAddr_var;
    L3Address remoteAddr_var;
    int localPort_var;
    int remotePort_var;
    bool fork_var;
    int dataTransferMode_var;
    opp_string tcpAlgorithmClass_var;

  private:
    void copy(const TCPOpenCommand& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const TCPOpenCommand&);

  public:
    TCPOpenCommand();
    TCPOpenCommand(const TCPOpenCommand& other);
    virtual ~TCPOpenCommand();
    TCPOpenCommand& operator=(const TCPOpenCommand& other);
    virtual TCPOpenCommand *dup() const {return new TCPOpenCommand(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual L3Address& getLocalAddr();
    virtual const L3Address& getLocalAddr() const {return const_cast<TCPOpenCommand*>(this)->getLocalAddr();}
    virtual void setLocalAddr(const L3Address& localAddr);
    virtual L3Address& getRemoteAddr();
    virtual const L3Address& getRemoteAddr() const {return const_cast<TCPOpenCommand*>(this)->getRemoteAddr();}
    virtual void setRemoteAddr(const L3Address& remoteAddr);
    virtual int getLocalPort() const;
    virtual void setLocalPort(int localPort);
    virtual int getRemotePort() const;
    virtual void setRemotePort(int remotePort);
    virtual bool getFork() const;
    virtual void setFork(bool fork);
    virtual int getDataTransferMode() const;
    virtual void setDataTransferMode(int dataTransferMode);
    virtual const char * getTcpAlgorithmClass() const;
    virtual void setTcpAlgorithmClass(const char * tcpAlgorithmClass);
};

inline void doPacking(cCommBuffer *b, TCPOpenCommand& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, TCPOpenCommand& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/transportlayer/contract/tcp/TCPCommand.msg:171</tt> by nedtool.
 * <pre>
 * //
 * // Control info to be used with the SEND command.
 * //
 * // @see ~TcpCommandCode, ~ITCP
 * //
 * class TCPSendCommand extends TCPCommand
 * {
 * }
 * </pre>
 */
class INET_API TCPSendCommand : public ::inet::TCPCommand
{
  protected:

  private:
    void copy(const TCPSendCommand& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const TCPSendCommand&);

  public:
    TCPSendCommand();
    TCPSendCommand(const TCPSendCommand& other);
    virtual ~TCPSendCommand();
    TCPSendCommand& operator=(const TCPSendCommand& other);
    virtual TCPSendCommand *dup() const {return new TCPSendCommand(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
};

inline void doPacking(cCommBuffer *b, TCPSendCommand& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, TCPSendCommand& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/transportlayer/contract/tcp/TCPCommand.msg:182</tt> by nedtool.
 * <pre>
 * //
 * // Sent with message kind TCP_I_ESTABLISHED, to let the app know
 * // about the local and remote IP address and port.
 * //
 * // @see ~TcpCommandCode, ~ITCP
 * //
 * class TCPConnectInfo extends TCPCommand
 * {
 *     L3Address localAddr;
 *     L3Address remoteAddr;
 *     int localPort;
 *     int remotePort;
 * }
 * </pre>
 */
class INET_API TCPConnectInfo : public ::inet::TCPCommand
{
  protected:
    L3Address localAddr_var;
    L3Address remoteAddr_var;
    int localPort_var;
    int remotePort_var;

  private:
    void copy(const TCPConnectInfo& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const TCPConnectInfo&);

  public:
    TCPConnectInfo();
    TCPConnectInfo(const TCPConnectInfo& other);
    virtual ~TCPConnectInfo();
    TCPConnectInfo& operator=(const TCPConnectInfo& other);
    virtual TCPConnectInfo *dup() const {return new TCPConnectInfo(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual L3Address& getLocalAddr();
    virtual const L3Address& getLocalAddr() const {return const_cast<TCPConnectInfo*>(this)->getLocalAddr();}
    virtual void setLocalAddr(const L3Address& localAddr);
    virtual L3Address& getRemoteAddr();
    virtual const L3Address& getRemoteAddr() const {return const_cast<TCPConnectInfo*>(this)->getRemoteAddr();}
    virtual void setRemoteAddr(const L3Address& remoteAddr);
    virtual int getLocalPort() const;
    virtual void setLocalPort(int localPort);
    virtual int getRemotePort() const;
    virtual void setRemotePort(int remotePort);
};

inline void doPacking(cCommBuffer *b, TCPConnectInfo& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, TCPConnectInfo& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/transportlayer/contract/tcp/TCPCommand.msg:198</tt> by nedtool.
 * <pre>
 * //
 * // Sent with message kind TCP_I_STATUS, in response to command TCP_C_STATUS.
 * // For explanation of variables, see RFC 793 or TCPStateVariables in
 * // TCPConnection.h.
 * //
 * // @see ~TcpStatusInd, ~TcpCommandCode, ~ITCP
 * //
 * class TCPStatusInfo extends TCPCommand
 * {
 *     int state;
 *     string stateName;
 * 
 *     L3Address localAddr;
 *     L3Address remoteAddr;
 *     int localPort;
 *     int remotePort;
 * 
 *     unsigned int snd_mss;
 * 
 *     unsigned int snd_una;
 *     unsigned int snd_nxt;
 *     unsigned int snd_max;
 *     unsigned int snd_wnd;
 *     unsigned int snd_up;
 *     unsigned int snd_wl1;
 *     unsigned int snd_wl2;
 *     unsigned int iss;
 * 
 *     unsigned int rcv_nxt;
 *     unsigned int rcv_wnd;
 *     unsigned int rcv_up;
 *     unsigned int irs;
 * 
 *     bool fin_ack_rcvd;
 * }
 * </pre>
 */
class INET_API TCPStatusInfo : public ::inet::TCPCommand
{
  protected:
    int state_var;
    opp_string stateName_var;
    L3Address localAddr_var;
    L3Address remoteAddr_var;
    int localPort_var;
    int remotePort_var;
    unsigned int snd_mss_var;
    unsigned int snd_una_var;
    unsigned int snd_nxt_var;
    unsigned int snd_max_var;
    unsigned int snd_wnd_var;
    unsigned int snd_up_var;
    unsigned int snd_wl1_var;
    unsigned int snd_wl2_var;
    unsigned int iss_var;
    unsigned int rcv_nxt_var;
    unsigned int rcv_wnd_var;
    unsigned int rcv_up_var;
    unsigned int irs_var;
    bool fin_ack_rcvd_var;

  private:
    void copy(const TCPStatusInfo& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const TCPStatusInfo&);

  public:
    TCPStatusInfo();
    TCPStatusInfo(const TCPStatusInfo& other);
    virtual ~TCPStatusInfo();
    TCPStatusInfo& operator=(const TCPStatusInfo& other);
    virtual TCPStatusInfo *dup() const {return new TCPStatusInfo(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getState() const;
    virtual void setState(int state);
    virtual const char * getStateName() const;
    virtual void setStateName(const char * stateName);
    virtual L3Address& getLocalAddr();
    virtual const L3Address& getLocalAddr() const {return const_cast<TCPStatusInfo*>(this)->getLocalAddr();}
    virtual void setLocalAddr(const L3Address& localAddr);
    virtual L3Address& getRemoteAddr();
    virtual const L3Address& getRemoteAddr() const {return const_cast<TCPStatusInfo*>(this)->getRemoteAddr();}
    virtual void setRemoteAddr(const L3Address& remoteAddr);
    virtual int getLocalPort() const;
    virtual void setLocalPort(int localPort);
    virtual int getRemotePort() const;
    virtual void setRemotePort(int remotePort);
    virtual unsigned int getSnd_mss() const;
    virtual void setSnd_mss(unsigned int snd_mss);
    virtual unsigned int getSnd_una() const;
    virtual void setSnd_una(unsigned int snd_una);
    virtual unsigned int getSnd_nxt() const;
    virtual void setSnd_nxt(unsigned int snd_nxt);
    virtual unsigned int getSnd_max() const;
    virtual void setSnd_max(unsigned int snd_max);
    virtual unsigned int getSnd_wnd() const;
    virtual void setSnd_wnd(unsigned int snd_wnd);
    virtual unsigned int getSnd_up() const;
    virtual void setSnd_up(unsigned int snd_up);
    virtual unsigned int getSnd_wl1() const;
    virtual void setSnd_wl1(unsigned int snd_wl1);
    virtual unsigned int getSnd_wl2() const;
    virtual void setSnd_wl2(unsigned int snd_wl2);
    virtual unsigned int getIss() const;
    virtual void setIss(unsigned int iss);
    virtual unsigned int getRcv_nxt() const;
    virtual void setRcv_nxt(unsigned int rcv_nxt);
    virtual unsigned int getRcv_wnd() const;
    virtual void setRcv_wnd(unsigned int rcv_wnd);
    virtual unsigned int getRcv_up() const;
    virtual void setRcv_up(unsigned int rcv_up);
    virtual unsigned int getIrs() const;
    virtual void setIrs(unsigned int irs);
    virtual bool getFin_ack_rcvd() const;
    virtual void setFin_ack_rcvd(bool fin_ack_rcvd);
};

inline void doPacking(cCommBuffer *b, TCPStatusInfo& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, TCPStatusInfo& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef _INET_TCPCOMMAND_M_H_

