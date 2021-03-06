// Copyright 2014-2015 the openage authors. See copying.md for legal info.

#ifndef OPENAGE_AUDIO_HASH_FUNCTIONS_H_
#define OPENAGE_AUDIO_HASH_FUNCTIONS_H_

#include <tuple>

#include "category.h"

namespace std {

template<>
struct hash<::openage::audio::category_t> {
	size_t operator()(const ::openage::audio::category_t &c) const {
		return static_cast<int>(c);
	}
};

template<>
struct hash<std::tuple<::openage::audio::category_t,int>> {
	size_t operator()(const std::tuple<::openage::audio::category_t,int> &t) const {
		return static_cast<size_t>(std::get<0>(t)) << (sizeof(size_t) * 8 - 2) | std::get<1>(t);
	}
};

}

#endif
