// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: card.proto

#include "card.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
constexpr card::card(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : legal_adress_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , title_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , occupation_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , year_of_foundation_(0)
  , foreign_economic_activity_(false){}
struct cardDefaultTypeInternal {
  constexpr cardDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~cardDefaultTypeInternal() {}
  union {
    card _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT cardDefaultTypeInternal _card_default_instance_;
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_card_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_card_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_card_2eproto = nullptr;

const uint32_t TableStruct_card_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::card, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::card, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::card, year_of_foundation_),
  PROTOBUF_FIELD_OFFSET(::card, legal_adress_),
  PROTOBUF_FIELD_OFFSET(::card, title_),
  PROTOBUF_FIELD_OFFSET(::card, occupation_),
  PROTOBUF_FIELD_OFFSET(::card, foreign_economic_activity_),
  3,
  0,
  1,
  2,
  4,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 11, -1, sizeof(::card)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_card_default_instance_),
};

const char descriptor_table_protodef_card_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\ncard.proto\"~\n\004card\022\032\n\022year_of_foundati"
  "on\030\001 \002(\005\022\024\n\014legal_adress\030\002 \002(\t\022\r\n\005title\030"
  "\003 \002(\t\022\022\n\noccupation\030\004 \001(\t\022!\n\031foreign_eco"
  "nomic_activity\030\005 \001(\010"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_card_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_card_2eproto = {
  false, false, 140, descriptor_table_protodef_card_2eproto, "card.proto", 
  &descriptor_table_card_2eproto_once, nullptr, 0, 1,
  schemas, file_default_instances, TableStruct_card_2eproto::offsets,
  file_level_metadata_card_2eproto, file_level_enum_descriptors_card_2eproto, file_level_service_descriptors_card_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_card_2eproto_getter() {
  return &descriptor_table_card_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_card_2eproto(&descriptor_table_card_2eproto);

// ===================================================================

class card::_Internal {
 public:
  using HasBits = decltype(std::declval<card>()._has_bits_);
  static void set_has_year_of_foundation(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_legal_adress(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_title(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_occupation(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_foreign_economic_activity(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static bool MissingRequiredFields(const HasBits& has_bits) {
    return ((has_bits[0] & 0x0000000b) ^ 0x0000000b) != 0;
  }
};

card::card(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:card)
}
card::card(const card& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  legal_adress_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    legal_adress_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (from._internal_has_legal_adress()) {
    legal_adress_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_legal_adress(), 
      GetArenaForAllocation());
  }
  title_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    title_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (from._internal_has_title()) {
    title_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_title(), 
      GetArenaForAllocation());
  }
  occupation_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    occupation_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (from._internal_has_occupation()) {
    occupation_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_occupation(), 
      GetArenaForAllocation());
  }
  ::memcpy(&year_of_foundation_, &from.year_of_foundation_,
    static_cast<size_t>(reinterpret_cast<char*>(&foreign_economic_activity_) -
    reinterpret_cast<char*>(&year_of_foundation_)) + sizeof(foreign_economic_activity_));
  // @@protoc_insertion_point(copy_constructor:card)
}

inline void card::SharedCtor() {
legal_adress_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  legal_adress_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
title_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  title_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
occupation_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  occupation_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&year_of_foundation_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&foreign_economic_activity_) -
    reinterpret_cast<char*>(&year_of_foundation_)) + sizeof(foreign_economic_activity_));
}

card::~card() {
  // @@protoc_insertion_point(destructor:card)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void card::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  legal_adress_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  title_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  occupation_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void card::ArenaDtor(void* object) {
  card* _this = reinterpret_cast< card* >(object);
  (void)_this;
}
void card::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void card::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void card::Clear() {
// @@protoc_insertion_point(message_clear_start:card)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      legal_adress_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000002u) {
      title_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000004u) {
      occupation_.ClearNonDefaultToEmpty();
    }
  }
  if (cached_has_bits & 0x00000018u) {
    ::memset(&year_of_foundation_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&foreign_economic_activity_) -
        reinterpret_cast<char*>(&year_of_foundation_)) + sizeof(foreign_economic_activity_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* card::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // required int32 year_of_foundation = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _Internal::set_has_year_of_foundation(&has_bits);
          year_of_foundation_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // required string legal_adress = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_legal_adress();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "card.legal_adress");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // required string title = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_title();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "card.title");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional string occupation = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          auto str = _internal_mutable_occupation();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "card.occupation");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional bool foreign_economic_activity = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 40)) {
          _Internal::set_has_foreign_economic_activity(&has_bits);
          foreign_economic_activity_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* card::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:card)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required int32 year_of_foundation = 1;
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_year_of_foundation(), target);
  }

  // required string legal_adress = 2;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_legal_adress().data(), static_cast<int>(this->_internal_legal_adress().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "card.legal_adress");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_legal_adress(), target);
  }

  // required string title = 3;
  if (cached_has_bits & 0x00000002u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_title().data(), static_cast<int>(this->_internal_title().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "card.title");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_title(), target);
  }

  // optional string occupation = 4;
  if (cached_has_bits & 0x00000004u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_occupation().data(), static_cast<int>(this->_internal_occupation().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "card.occupation");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_occupation(), target);
  }

  // optional bool foreign_economic_activity = 5;
  if (cached_has_bits & 0x00000010u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(5, this->_internal_foreign_economic_activity(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:card)
  return target;
}

size_t card::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:card)
  size_t total_size = 0;

  if (_internal_has_legal_adress()) {
    // required string legal_adress = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_legal_adress());
  }

  if (_internal_has_title()) {
    // required string title = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_title());
  }

  if (_internal_has_year_of_foundation()) {
    // required int32 year_of_foundation = 1;
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_year_of_foundation());
  }

  return total_size;
}
size_t card::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:card)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x0000000b) ^ 0x0000000b) == 0) {  // All required fields are present.
    // required string legal_adress = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_legal_adress());

    // required string title = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_title());

    // required int32 year_of_foundation = 1;
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_year_of_foundation());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // optional string occupation = 4;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000004u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_occupation());
  }

  // optional bool foreign_economic_activity = 5;
  if (cached_has_bits & 0x00000010u) {
    total_size += 1 + 1;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData card::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    card::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*card::GetClassData() const { return &_class_data_; }

void card::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<card *>(to)->MergeFrom(
      static_cast<const card &>(from));
}


void card::MergeFrom(const card& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:card)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_legal_adress(from._internal_legal_adress());
    }
    if (cached_has_bits & 0x00000002u) {
      _internal_set_title(from._internal_title());
    }
    if (cached_has_bits & 0x00000004u) {
      _internal_set_occupation(from._internal_occupation());
    }
    if (cached_has_bits & 0x00000008u) {
      year_of_foundation_ = from.year_of_foundation_;
    }
    if (cached_has_bits & 0x00000010u) {
      foreign_economic_activity_ = from.foreign_economic_activity_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void card::CopyFrom(const card& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:card)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool card::IsInitialized() const {
  if (_Internal::MissingRequiredFields(_has_bits_)) return false;
  return true;
}

void card::InternalSwap(card* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &legal_adress_, lhs_arena,
      &other->legal_adress_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &title_, lhs_arena,
      &other->title_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &occupation_, lhs_arena,
      &other->occupation_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(card, foreign_economic_activity_)
      + sizeof(card::foreign_economic_activity_)
      - PROTOBUF_FIELD_OFFSET(card, year_of_foundation_)>(
          reinterpret_cast<char*>(&year_of_foundation_),
          reinterpret_cast<char*>(&other->year_of_foundation_));
}

::PROTOBUF_NAMESPACE_ID::Metadata card::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_card_2eproto_getter, &descriptor_table_card_2eproto_once,
      file_level_metadata_card_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::card* Arena::CreateMaybeMessage< ::card >(Arena* arena) {
  return Arena::CreateMessageInternal< ::card >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
