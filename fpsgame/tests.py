from ctypes import *
import sys
import os
import xml.etree.ElementTree as ET

binaries = '../../../binaries'

# Work out the platform-dependent library filename
dll_filename = {
	'posix': './libCollada_dbg.so',
	'nt': 'Collada_dbg.dll',
}[os.name]

# The DLL may need other DLLs which are in its directory, so set the path to that
# (Don't care about clobbering the old PATH - it doesn't have anything important)
os.environ['PATH'] = '%s/system/' % binaries