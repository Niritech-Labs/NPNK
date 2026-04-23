# Copyright (C) 2026 Niritech Labs
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
add_library(nuklear SHARED nuklear.c)
set_target_properties(nuklear PROPERTIES POSITION_INDEPENDENT_CODE ON)