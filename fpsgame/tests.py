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