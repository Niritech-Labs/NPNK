# Copyright (C) 2026 Niritech Labs
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
from NLUtils.Installer import NLInstaller
import sys

ti = NLInstaller('project.targets')

ti.RunTarget('Clean All')
#ti.RunTarget('Make Nuklear')
#ti.RunTarget('Install Nuklear')
#ti.RunTarget('Make Nuklear Bingings')
#ti.RunTarget('Make Backend')
#ti.RunTarget('Install')