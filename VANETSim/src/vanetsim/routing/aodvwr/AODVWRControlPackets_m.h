//
// Generated file, do not edit! Created by nedtool 5.1 from vanetsim/routing/aodvwr/AODVWRControlPackets.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __INET_AODVWRCONTROLPACKETS_M_H
#define __INET_AODVWRCONTROLPACKETS_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0501
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

// cplusplus {{
#include "inet/networklayer/common/L3Address.h"
#include "inet/common/geometry/common/Coord.h"
#include "inet/common/geometry/common/EulerAngles.h"
// }}


namespace inet {

/**
 * Struct generated from vanetsim/routing/aodvwr/AODVWRControlPackets.msg:34 by nedtool.
 */
struct UnreachableAODVWRNode
{
    UnreachableAODVWRNode();
    L3Address addr;
    unsigned int seqNum;
};

// helpers for local use
void __doPacking(omnetpp::cCommBuffer *b, const UnreachableAODVWRNode& a);
void __doUnpacking(omnetpp::cCommBuffer *b, UnreachableAODVWRNode& a);

inline void doParsimPacking(omnetpp::cCommBuffer *b, const UnreachableAODVWRNode& obj) { __doPacking(b, obj); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, UnreachableAODVWRNode& obj) { __doUnpacking(b, obj); }

/**
 * Enum generated from <tt>vanetsim/routing/aodvwr/AODVWRControlPackets.msg:40</tt> by nedtool.
 * <pre>
 * enum AODVWRControlPacketType
 * {
 * 
 *     RREQ = 1;
 *     RREP = 2;
 *     RERR = 3;
 *     RREPACK = 4;
 * }
 * </pre>
 */
enum AODVWRControlPacketType {
    RREQ = 1,
    RREP = 2,
    RERR = 3,
    RREPACK = 4
};

/**
 * Class generated from <tt>vanetsim/routing/aodvwr/AODVWRControlPackets.msg:51</tt> by nedtool.
 * <pre>
 * //
 * // Base packet for AODVWR Control Packets
 * //
 * packet AODVWRControlPacket
 * {
 *     unsigned int packetType;
 * }
 * </pre>
 */
class AODVWRControlPacket : public ::omnetpp::cPacket
{
  protected:
    unsigned int packetType;

  private:
    void copy(const AODVWRControlPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const AODVWRControlPacket&);

  public:
    AODVWRControlPacket(const char *name=nullptr, short kind=0);
    AODVWRControlPacket(const AODVWRControlPacket& other);
    virtual ~AODVWRControlPacket();
    AODVWRControlPacket& operator=(const AODVWRControlPacket& other);
    virtual AODVWRControlPacket *dup() const override {return new AODVWRControlPacket(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual unsigned int getPacketType() const;
    virtual void setPacketType(unsigned int packetType);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const AODVWRControlPacket& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, AODVWRControlPacket& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>vanetsim/routing/aodvwr/AODVWRControlPackets.msg:59</tt> by nedtool.
 * <pre>
 * //
 * // Represents an AODVWR Route Request
 * //
 * class AODVWRRREQ extends AODVWRControlPacket
 * {
 *     packetType = RREQ;
 *     bool joinFlag;
 *     bool repairFlag;
 *     bool gratuitousRREPFlag;
 *     bool destOnlyFlag;
 *     bool unknownSeqNumFlag;
 *     unsigned int hopCount;
 *     unsigned int rreqId;
 *     L3Address destAddr;
 *     unsigned int destSeqNum;
 *     L3Address originatorAddr;
 *     unsigned int originatorSeqNum;
 *     Coord position;
 *     Coord speed;
 *     Coord acceleration;
 *     EulerAngles direction;
 *     double twr;
 *     double expirationTime;
 * }
 * </pre>
 */
class AODVWRRREQ : public ::inet::AODVWRControlPacket
{
  protected:
    bool joinFlag;
    bool repairFlag;
    bool gratuitousRREPFlag;
    bool destOnlyFlag;
    bool unknownSeqNumFlag;
    unsigned int hopCount;
    unsigned int rreqId;
    L3Address destAddr;
    unsigned int destSeqNum;
    L3Address originatorAddr;
    unsigned int originatorSeqNum;
    Coord position;
    Coord speed;
    Coord acceleration;
    EulerAngles direction;
    double twr;
    double expirationTime;

  private:
    void copy(const AODVWRRREQ& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const AODVWRRREQ&);

  public:
    AODVWRRREQ(const char *name=nullptr);
    AODVWRRREQ(const AODVWRRREQ& other);
    virtual ~AODVWRRREQ();
    AODVWRRREQ& operator=(const AODVWRRREQ& other);
    virtual AODVWRRREQ *dup() const override {return new AODVWRRREQ(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual bool getJoinFlag() const;
    virtual void setJoinFlag(bool joinFlag);
    virtual bool getRepairFlag() const;
    virtual void setRepairFlag(bool repairFlag);
    virtual bool getGratuitousRREPFlag() const;
    virtual void setGratuitousRREPFlag(bool gratuitousRREPFlag);
    virtual bool getDestOnlyFlag() const;
    virtual void setDestOnlyFlag(bool destOnlyFlag);
    virtual bool getUnknownSeqNumFlag() const;
    virtual void setUnknownSeqNumFlag(bool unknownSeqNumFlag);
    virtual unsigned int getHopCount() const;
    virtual void setHopCount(unsigned int hopCount);
    virtual unsigned int getRreqId() const;
    virtual void setRreqId(unsigned int rreqId);
    virtual L3Address& getDestAddr();
    virtual const L3Address& getDestAddr() const {return const_cast<AODVWRRREQ*>(this)->getDestAddr();}
    virtual void setDestAddr(const L3Address& destAddr);
    virtual unsigned int getDestSeqNum() const;
    virtual void setDestSeqNum(unsigned int destSeqNum);
    virtual L3Address& getOriginatorAddr();
    virtual const L3Address& getOriginatorAddr() const {return const_cast<AODVWRRREQ*>(this)->getOriginatorAddr();}
    virtual void setOriginatorAddr(const L3Address& originatorAddr);
    virtual unsigned int getOriginatorSeqNum() const;
    virtual void setOriginatorSeqNum(unsigned int originatorSeqNum);
    virtual Coord& getPosition();
    virtual const Coord& getPosition() const {return const_cast<AODVWRRREQ*>(this)->getPosition();}
    virtual void setPosition(const Coord& position);
    virtual Coord& getSpeed();
    virtual const Coord& getSpeed() const {return const_cast<AODVWRRREQ*>(this)->getSpeed();}
    virtual void setSpeed(const Coord& speed);
    virtual Coord& getAcceleration();
    virtual const Coord& getAcceleration() const {return const_cast<AODVWRRREQ*>(this)->getAcceleration();}
    virtual void setAcceleration(const Coord& acceleration);
    virtual EulerAngles& getDirection();
    virtual const EulerAngles& getDirection() const {return const_cast<AODVWRRREQ*>(this)->getDirection();}
    virtual void setDirection(const EulerAngles& direction);
    virtual double getTwr() const;
    virtual void setTwr(double twr);
    virtual double getExpirationTime() const;
    virtual void setExpirationTime(double expirationTime);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const AODVWRRREQ& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, AODVWRRREQ& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>vanetsim/routing/aodvwr/AODVWRControlPackets.msg:84</tt> by nedtool.
 * <pre>
 * //
 * // Represents an AODVWR Route Reply
 * //
 * class AODVWRRREP extends AODVWRControlPacket
 * {
 *     packetType = RREP;
 *     bool repairFlag;
 *     bool ackRequiredFlag;
 *     unsigned int prefixSize;
 *     unsigned int hopCount;
 *     L3Address destAddr;
 *     unsigned int destSeqNum;
 *     L3Address originatorAddr;
 *     unsigned int originatorSeqNum;
 *     simtime_t lifeTime;
 *     Coord position;
 *     Coord speed;
 *     Coord acceleration;
 *     EulerAngles direction;
 *     double twr;
 *     double expirationTime;
 * }
 * </pre>
 */
class AODVWRRREP : public ::inet::AODVWRControlPacket
{
  protected:
    bool repairFlag;
    bool ackRequiredFlag;
    unsigned int prefixSize;
    unsigned int hopCount;
    L3Address destAddr;
    unsigned int destSeqNum;
    L3Address originatorAddr;
    unsigned int originatorSeqNum;
    ::omnetpp::simtime_t lifeTime;
    Coord position;
    Coord speed;
    Coord acceleration;
    EulerAngles direction;
    double twr;
    double expirationTime;

  private:
    void copy(const AODVWRRREP& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const AODVWRRREP&);

  public:
    AODVWRRREP(const char *name=nullptr);
    AODVWRRREP(const AODVWRRREP& other);
    virtual ~AODVWRRREP();
    AODVWRRREP& operator=(const AODVWRRREP& other);
    virtual AODVWRRREP *dup() const override {return new AODVWRRREP(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual bool getRepairFlag() const;
    virtual void setRepairFlag(bool repairFlag);
    virtual bool getAckRequiredFlag() const;
    virtual void setAckRequiredFlag(bool ackRequiredFlag);
    virtual unsigned int getPrefixSize() const;
    virtual void setPrefixSize(unsigned int prefixSize);
    virtual unsigned int getHopCount() const;
    virtual void setHopCount(unsigned int hopCount);
    virtual L3Address& getDestAddr();
    virtual const L3Address& getDestAddr() const {return const_cast<AODVWRRREP*>(this)->getDestAddr();}
    virtual void setDestAddr(const L3Address& destAddr);
    virtual unsigned int getDestSeqNum() const;
    virtual void setDestSeqNum(unsigned int destSeqNum);
    virtual L3Address& getOriginatorAddr();
    virtual const L3Address& getOriginatorAddr() const {return const_cast<AODVWRRREP*>(this)->getOriginatorAddr();}
    virtual void setOriginatorAddr(const L3Address& originatorAddr);
    virtual unsigned int getOriginatorSeqNum() const;
    virtual void setOriginatorSeqNum(unsigned int originatorSeqNum);
    virtual ::omnetpp::simtime_t getLifeTime() const;
    virtual void setLifeTime(::omnetpp::simtime_t lifeTime);
    virtual Coord& getPosition();
    virtual const Coord& getPosition() const {return const_cast<AODVWRRREP*>(this)->getPosition();}
    virtual void setPosition(const Coord& position);
    virtual Coord& getSpeed();
    virtual const Coord& getSpeed() const {return const_cast<AODVWRRREP*>(this)->getSpeed();}
    virtual void setSpeed(const Coord& speed);
    virtual Coord& getAcceleration();
    virtual const Coord& getAcceleration() const {return const_cast<AODVWRRREP*>(this)->getAcceleration();}
    virtual void setAcceleration(const Coord& acceleration);
    virtual EulerAngles& getDirection();
    virtual const EulerAngles& getDirection() const {return const_cast<AODVWRRREP*>(this)->getDirection();}
    virtual void setDirection(const EulerAngles& direction);
    virtual double getTwr() const;
    virtual void setTwr(double twr);
    virtual double getExpirationTime() const;
    virtual void setExpirationTime(double expirationTime);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const AODVWRRREP& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, AODVWRRREP& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>vanetsim/routing/aodvwr/AODVWRControlPackets.msg:107</tt> by nedtool.
 * <pre>
 * //
 * // Represents an AODVWR Route Error
 * //
 * class AODVWRRERR extends AODVWRControlPacket
 * {
 *     packetType = RERR;
 *     UnreachableAODVWRNode unreachableNodes[];
 *     bool noDeleteFlag;
 *     unsigned int destCount;
 * }
 * </pre>
 */
class AODVWRRERR : public ::inet::AODVWRControlPacket
{
  protected:
    UnreachableAODVWRNode *unreachableNodes; // array ptr
    unsigned int unreachableNodes_arraysize;
    bool noDeleteFlag;
    unsigned int destCount;

  private:
    void copy(const AODVWRRERR& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const AODVWRRERR&);

  public:
    AODVWRRERR(const char *name=nullptr);
    AODVWRRERR(const AODVWRRERR& other);
    virtual ~AODVWRRERR();
    AODVWRRERR& operator=(const AODVWRRERR& other);
    virtual AODVWRRERR *dup() const override {return new AODVWRRERR(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual void setUnreachableNodesArraySize(unsigned int size);
    virtual unsigned int getUnreachableNodesArraySize() const;
    virtual UnreachableAODVWRNode& getUnreachableNodes(unsigned int k);
    virtual const UnreachableAODVWRNode& getUnreachableNodes(unsigned int k) const {return const_cast<AODVWRRERR*>(this)->getUnreachableNodes(k);}
    virtual void setUnreachableNodes(unsigned int k, const UnreachableAODVWRNode& unreachableNodes);
    virtual bool getNoDeleteFlag() const;
    virtual void setNoDeleteFlag(bool noDeleteFlag);
    virtual unsigned int getDestCount() const;
    virtual void setDestCount(unsigned int destCount);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const AODVWRRERR& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, AODVWRRERR& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>vanetsim/routing/aodvwr/AODVWRControlPackets.msg:118</tt> by nedtool.
 * <pre>
 * //
 * // Represents an AODVWR Route Reply ACK
 * //
 * class AODVWRRREPACK extends AODVWRControlPacket
 * {
 *     packetType = RREPACK;
 * }
 * </pre>
 */
class AODVWRRREPACK : public ::inet::AODVWRControlPacket
{
  protected:

  private:
    void copy(const AODVWRRREPACK& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const AODVWRRREPACK&);

  public:
    AODVWRRREPACK(const char *name=nullptr);
    AODVWRRREPACK(const AODVWRRREPACK& other);
    virtual ~AODVWRRREPACK();
    AODVWRRREPACK& operator=(const AODVWRRREPACK& other);
    virtual AODVWRRREPACK *dup() const override {return new AODVWRRREPACK(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const AODVWRRREPACK& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, AODVWRRREPACK& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>vanetsim/routing/aodvwr/AODVWRControlPackets.msg:126</tt> by nedtool.
 * <pre>
 * //
 * // Represents a timer for a Route Reply packet
 * //
 * message WaitForRREPWR
 * {
 *     L3Address destAddr;
 *     unsigned int lastTTL;
 *     bool fromInvalidEntry;
 * }
 * </pre>
 */
class WaitForRREPWR : public ::omnetpp::cMessage
{
  protected:
    L3Address destAddr;
    unsigned int lastTTL;
    bool fromInvalidEntry;

  private:
    void copy(const WaitForRREPWR& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const WaitForRREPWR&);

  public:
    WaitForRREPWR(const char *name=nullptr, short kind=0);
    WaitForRREPWR(const WaitForRREPWR& other);
    virtual ~WaitForRREPWR();
    WaitForRREPWR& operator=(const WaitForRREPWR& other);
    virtual WaitForRREPWR *dup() const override {return new WaitForRREPWR(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual L3Address& getDestAddr();
    virtual const L3Address& getDestAddr() const {return const_cast<WaitForRREPWR*>(this)->getDestAddr();}
    virtual void setDestAddr(const L3Address& destAddr);
    virtual unsigned int getLastTTL() const;
    virtual void setLastTTL(unsigned int lastTTL);
    virtual bool getFromInvalidEntry() const;
    virtual void setFromInvalidEntry(bool fromInvalidEntry);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const WaitForRREPWR& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, WaitForRREPWR& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_AODVWRCONTROLPACKETS_M_H

