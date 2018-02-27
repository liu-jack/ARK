// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: AFMsgURl.proto

#ifndef PROTOBUF_AFMsgURl_2eproto__INCLUDED
#define PROTOBUF_AFMsgURl_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_AFMsgURl_2eproto {
// Internal implementation detail -- do not use these members.
struct LIBPROTOC_EXPORT TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void LIBPROTOC_EXPORT AddDescriptors();
void LIBPROTOC_EXPORT InitDefaultsPackSURLParamImpl();
void LIBPROTOC_EXPORT InitDefaultsPackSURLParam();
inline void LIBPROTOC_EXPORT InitDefaults() {
  InitDefaultsPackSURLParam();
}
}  // namespace protobuf_AFMsgURl_2eproto
namespace AFMsg {
class PackSURLParam;
class PackSURLParamDefaultTypeInternal;
LIBPROTOC_EXPORT extern PackSURLParamDefaultTypeInternal _PackSURLParam_default_instance_;
}  // namespace AFMsg
namespace AFMsg {

// ===================================================================

class LIBPROTOC_EXPORT PackSURLParam : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:AFMsg.PackSURLParam) */ {
 public:
  PackSURLParam();
  virtual ~PackSURLParam();

  PackSURLParam(const PackSURLParam& from);

  inline PackSURLParam& operator=(const PackSURLParam& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  PackSURLParam(PackSURLParam&& from) noexcept
    : PackSURLParam() {
    *this = ::std::move(from);
  }

  inline PackSURLParam& operator=(PackSURLParam&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const PackSURLParam& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const PackSURLParam* internal_default_instance() {
    return reinterpret_cast<const PackSURLParam*>(
               &_PackSURLParam_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(PackSURLParam* other);
  friend void swap(PackSURLParam& a, PackSURLParam& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline PackSURLParam* New() const PROTOBUF_FINAL { return New(NULL); }

  PackSURLParam* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const PackSURLParam& from);
  void MergeFrom(const PackSURLParam& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(PackSURLParam* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string strUrl = 1;
  void clear_strurl();
  static const int kStrUrlFieldNumber = 1;
  const ::std::string& strurl() const;
  void set_strurl(const ::std::string& value);
  #if LANG_CXX11
  void set_strurl(::std::string&& value);
  #endif
  void set_strurl(const char* value);
  void set_strurl(const char* value, size_t size);
  ::std::string* mutable_strurl();
  ::std::string* release_strurl();
  void set_allocated_strurl(::std::string* strurl);

  // string strGetParams = 2;
  void clear_strgetparams();
  static const int kStrGetParamsFieldNumber = 2;
  const ::std::string& strgetparams() const;
  void set_strgetparams(const ::std::string& value);
  #if LANG_CXX11
  void set_strgetparams(::std::string&& value);
  #endif
  void set_strgetparams(const char* value);
  void set_strgetparams(const char* value, size_t size);
  ::std::string* mutable_strgetparams();
  ::std::string* release_strgetparams();
  void set_allocated_strgetparams(::std::string* strgetparams);

  // string strBodyData = 3;
  void clear_strbodydata();
  static const int kStrBodyDataFieldNumber = 3;
  const ::std::string& strbodydata() const;
  void set_strbodydata(const ::std::string& value);
  #if LANG_CXX11
  void set_strbodydata(::std::string&& value);
  #endif
  void set_strbodydata(const char* value);
  void set_strbodydata(const char* value, size_t size);
  ::std::string* mutable_strbodydata();
  ::std::string* release_strbodydata();
  void set_allocated_strbodydata(::std::string* strbodydata);

  // string strCookies = 4;
  void clear_strcookies();
  static const int kStrCookiesFieldNumber = 4;
  const ::std::string& strcookies() const;
  void set_strcookies(const ::std::string& value);
  #if LANG_CXX11
  void set_strcookies(::std::string&& value);
  #endif
  void set_strcookies(const char* value);
  void set_strcookies(const char* value, size_t size);
  ::std::string* mutable_strcookies();
  ::std::string* release_strcookies();
  void set_allocated_strcookies(::std::string* strcookies);

  // string strRsp = 6;
  void clear_strrsp();
  static const int kStrRspFieldNumber = 6;
  const ::std::string& strrsp() const;
  void set_strrsp(const ::std::string& value);
  #if LANG_CXX11
  void set_strrsp(::std::string&& value);
  #endif
  void set_strrsp(const char* value);
  void set_strrsp(const char* value, size_t size);
  ::std::string* mutable_strrsp();
  ::std::string* release_strrsp();
  void set_allocated_strrsp(::std::string* strrsp);

  // double fTimeOutSec = 5;
  void clear_ftimeoutsec();
  static const int kFTimeOutSecFieldNumber = 5;
  double ftimeoutsec() const;
  void set_ftimeoutsec(double value);

  // int64 nRet = 7;
  void clear_nret();
  static const int kNRetFieldNumber = 7;
  ::google::protobuf::int64 nret() const;
  void set_nret(::google::protobuf::int64 value);

  // int64 nReqID = 8;
  void clear_nreqid();
  static const int kNReqIDFieldNumber = 8;
  ::google::protobuf::int64 nreqid() const;
  void set_nreqid(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:AFMsg.PackSURLParam)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr strurl_;
  ::google::protobuf::internal::ArenaStringPtr strgetparams_;
  ::google::protobuf::internal::ArenaStringPtr strbodydata_;
  ::google::protobuf::internal::ArenaStringPtr strcookies_;
  ::google::protobuf::internal::ArenaStringPtr strrsp_;
  double ftimeoutsec_;
  ::google::protobuf::int64 nret_;
  ::google::protobuf::int64 nreqid_;
  mutable int _cached_size_;
  friend struct ::protobuf_AFMsgURl_2eproto::TableStruct;
  friend void ::protobuf_AFMsgURl_2eproto::InitDefaultsPackSURLParamImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PackSURLParam

// string strUrl = 1;
inline void PackSURLParam::clear_strurl() {
  strurl_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PackSURLParam::strurl() const {
  // @@protoc_insertion_point(field_get:AFMsg.PackSURLParam.strUrl)
  return strurl_.GetNoArena();
}
inline void PackSURLParam::set_strurl(const ::std::string& value) {
  
  strurl_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:AFMsg.PackSURLParam.strUrl)
}
#if LANG_CXX11
inline void PackSURLParam::set_strurl(::std::string&& value) {
  
  strurl_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:AFMsg.PackSURLParam.strUrl)
}
#endif
inline void PackSURLParam::set_strurl(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  strurl_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:AFMsg.PackSURLParam.strUrl)
}
inline void PackSURLParam::set_strurl(const char* value, size_t size) {
  
  strurl_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:AFMsg.PackSURLParam.strUrl)
}
inline ::std::string* PackSURLParam::mutable_strurl() {
  
  // @@protoc_insertion_point(field_mutable:AFMsg.PackSURLParam.strUrl)
  return strurl_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PackSURLParam::release_strurl() {
  // @@protoc_insertion_point(field_release:AFMsg.PackSURLParam.strUrl)
  
  return strurl_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PackSURLParam::set_allocated_strurl(::std::string* strurl) {
  if (strurl != NULL) {
    
  } else {
    
  }
  strurl_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), strurl);
  // @@protoc_insertion_point(field_set_allocated:AFMsg.PackSURLParam.strUrl)
}

// string strGetParams = 2;
inline void PackSURLParam::clear_strgetparams() {
  strgetparams_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PackSURLParam::strgetparams() const {
  // @@protoc_insertion_point(field_get:AFMsg.PackSURLParam.strGetParams)
  return strgetparams_.GetNoArena();
}
inline void PackSURLParam::set_strgetparams(const ::std::string& value) {
  
  strgetparams_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:AFMsg.PackSURLParam.strGetParams)
}
#if LANG_CXX11
inline void PackSURLParam::set_strgetparams(::std::string&& value) {
  
  strgetparams_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:AFMsg.PackSURLParam.strGetParams)
}
#endif
inline void PackSURLParam::set_strgetparams(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  strgetparams_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:AFMsg.PackSURLParam.strGetParams)
}
inline void PackSURLParam::set_strgetparams(const char* value, size_t size) {
  
  strgetparams_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:AFMsg.PackSURLParam.strGetParams)
}
inline ::std::string* PackSURLParam::mutable_strgetparams() {
  
  // @@protoc_insertion_point(field_mutable:AFMsg.PackSURLParam.strGetParams)
  return strgetparams_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PackSURLParam::release_strgetparams() {
  // @@protoc_insertion_point(field_release:AFMsg.PackSURLParam.strGetParams)
  
  return strgetparams_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PackSURLParam::set_allocated_strgetparams(::std::string* strgetparams) {
  if (strgetparams != NULL) {
    
  } else {
    
  }
  strgetparams_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), strgetparams);
  // @@protoc_insertion_point(field_set_allocated:AFMsg.PackSURLParam.strGetParams)
}

// string strBodyData = 3;
inline void PackSURLParam::clear_strbodydata() {
  strbodydata_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PackSURLParam::strbodydata() const {
  // @@protoc_insertion_point(field_get:AFMsg.PackSURLParam.strBodyData)
  return strbodydata_.GetNoArena();
}
inline void PackSURLParam::set_strbodydata(const ::std::string& value) {
  
  strbodydata_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:AFMsg.PackSURLParam.strBodyData)
}
#if LANG_CXX11
inline void PackSURLParam::set_strbodydata(::std::string&& value) {
  
  strbodydata_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:AFMsg.PackSURLParam.strBodyData)
}
#endif
inline void PackSURLParam::set_strbodydata(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  strbodydata_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:AFMsg.PackSURLParam.strBodyData)
}
inline void PackSURLParam::set_strbodydata(const char* value, size_t size) {
  
  strbodydata_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:AFMsg.PackSURLParam.strBodyData)
}
inline ::std::string* PackSURLParam::mutable_strbodydata() {
  
  // @@protoc_insertion_point(field_mutable:AFMsg.PackSURLParam.strBodyData)
  return strbodydata_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PackSURLParam::release_strbodydata() {
  // @@protoc_insertion_point(field_release:AFMsg.PackSURLParam.strBodyData)
  
  return strbodydata_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PackSURLParam::set_allocated_strbodydata(::std::string* strbodydata) {
  if (strbodydata != NULL) {
    
  } else {
    
  }
  strbodydata_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), strbodydata);
  // @@protoc_insertion_point(field_set_allocated:AFMsg.PackSURLParam.strBodyData)
}

// string strCookies = 4;
inline void PackSURLParam::clear_strcookies() {
  strcookies_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PackSURLParam::strcookies() const {
  // @@protoc_insertion_point(field_get:AFMsg.PackSURLParam.strCookies)
  return strcookies_.GetNoArena();
}
inline void PackSURLParam::set_strcookies(const ::std::string& value) {
  
  strcookies_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:AFMsg.PackSURLParam.strCookies)
}
#if LANG_CXX11
inline void PackSURLParam::set_strcookies(::std::string&& value) {
  
  strcookies_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:AFMsg.PackSURLParam.strCookies)
}
#endif
inline void PackSURLParam::set_strcookies(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  strcookies_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:AFMsg.PackSURLParam.strCookies)
}
inline void PackSURLParam::set_strcookies(const char* value, size_t size) {
  
  strcookies_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:AFMsg.PackSURLParam.strCookies)
}
inline ::std::string* PackSURLParam::mutable_strcookies() {
  
  // @@protoc_insertion_point(field_mutable:AFMsg.PackSURLParam.strCookies)
  return strcookies_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PackSURLParam::release_strcookies() {
  // @@protoc_insertion_point(field_release:AFMsg.PackSURLParam.strCookies)
  
  return strcookies_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PackSURLParam::set_allocated_strcookies(::std::string* strcookies) {
  if (strcookies != NULL) {
    
  } else {
    
  }
  strcookies_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), strcookies);
  // @@protoc_insertion_point(field_set_allocated:AFMsg.PackSURLParam.strCookies)
}

// double fTimeOutSec = 5;
inline void PackSURLParam::clear_ftimeoutsec() {
  ftimeoutsec_ = 0;
}
inline double PackSURLParam::ftimeoutsec() const {
  // @@protoc_insertion_point(field_get:AFMsg.PackSURLParam.fTimeOutSec)
  return ftimeoutsec_;
}
inline void PackSURLParam::set_ftimeoutsec(double value) {
  
  ftimeoutsec_ = value;
  // @@protoc_insertion_point(field_set:AFMsg.PackSURLParam.fTimeOutSec)
}

// string strRsp = 6;
inline void PackSURLParam::clear_strrsp() {
  strrsp_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PackSURLParam::strrsp() const {
  // @@protoc_insertion_point(field_get:AFMsg.PackSURLParam.strRsp)
  return strrsp_.GetNoArena();
}
inline void PackSURLParam::set_strrsp(const ::std::string& value) {
  
  strrsp_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:AFMsg.PackSURLParam.strRsp)
}
#if LANG_CXX11
inline void PackSURLParam::set_strrsp(::std::string&& value) {
  
  strrsp_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:AFMsg.PackSURLParam.strRsp)
}
#endif
inline void PackSURLParam::set_strrsp(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  strrsp_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:AFMsg.PackSURLParam.strRsp)
}
inline void PackSURLParam::set_strrsp(const char* value, size_t size) {
  
  strrsp_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:AFMsg.PackSURLParam.strRsp)
}
inline ::std::string* PackSURLParam::mutable_strrsp() {
  
  // @@protoc_insertion_point(field_mutable:AFMsg.PackSURLParam.strRsp)
  return strrsp_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PackSURLParam::release_strrsp() {
  // @@protoc_insertion_point(field_release:AFMsg.PackSURLParam.strRsp)
  
  return strrsp_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PackSURLParam::set_allocated_strrsp(::std::string* strrsp) {
  if (strrsp != NULL) {
    
  } else {
    
  }
  strrsp_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), strrsp);
  // @@protoc_insertion_point(field_set_allocated:AFMsg.PackSURLParam.strRsp)
}

// int64 nRet = 7;
inline void PackSURLParam::clear_nret() {
  nret_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 PackSURLParam::nret() const {
  // @@protoc_insertion_point(field_get:AFMsg.PackSURLParam.nRet)
  return nret_;
}
inline void PackSURLParam::set_nret(::google::protobuf::int64 value) {
  
  nret_ = value;
  // @@protoc_insertion_point(field_set:AFMsg.PackSURLParam.nRet)
}

// int64 nReqID = 8;
inline void PackSURLParam::clear_nreqid() {
  nreqid_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 PackSURLParam::nreqid() const {
  // @@protoc_insertion_point(field_get:AFMsg.PackSURLParam.nReqID)
  return nreqid_;
}
inline void PackSURLParam::set_nreqid(::google::protobuf::int64 value) {
  
  nreqid_ = value;
  // @@protoc_insertion_point(field_set:AFMsg.PackSURLParam.nReqID)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace AFMsg

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_AFMsgURl_2eproto__INCLUDED
