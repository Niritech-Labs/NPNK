# Copyright (C) 2026 Niritech Labs
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
from NLUtils.Installer import NLInstaller


ti = NLInstaller('project.targets')

ti.RunTarget('Clean Final')
ti.RunTarget('Clean Subs')
ti.RunTarget('Make Nuklear WL')
ti.RunTarget('Make Nuklear Bingings WL')
ti.RunTarget('Make Backend WL')
ti.RunTarget('Install WL')

ti.RunTarget('Clean Subs')
ti.RunTarget('Make Nuklear WN')
ti.RunTarget('Make Nuklear Bingings WN')
ti.RunTarget('Make Backend WN')
ti.RunTarget('Install WN')
