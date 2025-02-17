// Copyright (C) 2018-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//
#include "openvino/c/ov_layout.h"

#include "common.h"

ov_status_e ov_layout_create(ov_layout_t** layout, const char* layout_desc) {
    if (!layout || !layout_desc) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        std::unique_ptr<ov_layout_t> _layout(new ov_layout_t);
        _layout->object = ov::Layout(layout_desc);
        *layout = _layout.release();
    }
    CATCH_OV_EXCEPTIONS
    return ov_status_e::OK;
}

void ov_layout_free(ov_layout_t* layout) {
    if (layout)
        delete layout;
}

const char* ov_layout_to_string(ov_layout_t* layout) {
    if (!layout) {
        return str_to_char_array("Error: null layout!");
    }

    auto str = layout->object.to_string();
    const char* res = str_to_char_array(str);
    return res;
}
