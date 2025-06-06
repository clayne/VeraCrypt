/*
 Derived from source code of TrueCrypt 7.1a, which is
 Copyright (c) 2008-2012 TrueCrypt Developers Association and which is governed
 by the TrueCrypt License 3.0.

 Modifications and additions to the original source code (contained in this file)
 and all other portions of this file are Copyright (c) 2013-2025 AM Crypto
 and are governed by the Apache License 2.0 the full text of which is
 contained in the file License.txt included in VeraCrypt binary and source
 code distribution packages.
*/

#ifndef TC_HEADER_Core_HostDevice
#define TC_HEADER_Core_HostDevice

#include "Platform/Platform.h"
#include "Platform/Serializable.h"

namespace VeraCrypt
{
	struct HostDevice;
	typedef list < shared_ptr <HostDevice> > HostDeviceList;

	struct HostDevice : public Serializable
	{
		HostDevice ()
			: Removable (false),
			Size (0)
		{
		}

		virtual ~HostDevice ()
		{
		}

		TC_SERIALIZABLE (HostDevice);

		DirectoryPath MountPoint;
		wstring Name;
		DevicePath Path;
		bool Removable;
		uint64 Size;
		uint32 SystemNumber;

		HostDeviceList Partitions;
	};
}

#endif // TC_HEADER_Core_HostDevice
