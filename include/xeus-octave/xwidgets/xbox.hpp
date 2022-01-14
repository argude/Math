/***************************************************************************
 * Copyright (c) 2022, Giulio Girardi
 *
 * Distributed under the terms of the GNU General Public License v3.
 *
 * The full license is in the file LICENSE, distributed with this software.
 ****************************************************************************/

#ifndef XEUS_OCTAVE_XBOX_HPP
#define XEUS_OCTAVE_XBOX_HPP

#include <xeus-octave/xwidgets.hpp>

namespace xeus_octave::widgets::xbox::utils {

using namespace xeus_octave::widgets::utils;

template <class W>
inline octave_value_list add(octave::interpreter&, const octave_value_list& args, int) {
	W* w = get_widget<W>(args(0).classdef_object_value());

	if (args(1).is_string())
		w->add(xeus::xguid(args(1).string_value()));
	else if (args(1).is_classdef_object())
		// TODO: handle classdef and extract id
		;

	return ovl();
}

// TODO: remove
// template <class W>
// inline octave_value_list remove(octave::interpreter& interpreter, const octave_value_list& args, int) {
// 	W* w = get_widget<W>(args(0).classdef_object_value());

// 	if (args(1).is_string())
// 		w->remove(xeus::xguid(args(1).string_value()));
// 	else if (args(1).is_classdef_object())
// 		// TODO: handle classdef and extract id
// 		;

// 	return ovl();
// }

template <class W>
inline octave_value_list clear(octave::interpreter&, const octave_value_list& args, int) {
	get_widget<W>(args(0).classdef_object_value())->clear();
	return ovl();
}

template <class W>
inline void xwidgets_inherit_xbox(octave::interpreter& interpreter, octave::cdef_class& cls) {
	octave::cdef_manager& cm = interpreter.get_cdef_manager();

	xwidgets_add_property<W, &W::box_style>(interpreter, cls, "BoxStyle");
	// TODO: add children

	xwidgets_add_method(interpreter, cls, "add", add<W>);
	// xwidgets_add_method(interpreter, cls, "remove", remove<W>);
	xwidgets_add_method(interpreter, cls, "clear", clear<W>);
}

}  // namespace xeus_octave::widgets::xbox::utils

#endif